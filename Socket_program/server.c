#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int max(int a,int b)
{
    if(a>b)
         return a;
    else
         return b;
}


int main()
{
      int fd,listenfd;
      fd=0;
      listenfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
      
      struct sockaddr_in serveraddr,clientaddr;
      serveraddr.sin_family=AF_INET;
      serveraddr.sin_port=htons(5555);
      serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);

      bind(listenfd,&serveraddr,sizeof(serveraddr));

      listen(listenfd,5);
      socklen_t len;

      int sockfd=accept(listenfd,&clientaddr,&len);

     fd_set reset;
     int maxfd=max(fd,sockfd)+1;

     for(;;)
     {
             FD_ZERO(&reset);
             FD_SET(fd,&reset);
             FD_SET(sockfd,&reset);
            
             select(maxfd,&reset,0,0,0);
             if(FD_ISSET(fd,&reset))
             {
                    char sendbuf[100]={0};
                    int n=read(fd,sendbuf,100);
                    write(sockfd,sendbuf,n);
             }
             
             if(FD_ISSET(sockfd,&reset))
             {
                   char recvbuf[100]={0};
                   int n=read(sockfd,recvbuf,100);
                   write(1,recvbuf,n);
             }
     }
}
