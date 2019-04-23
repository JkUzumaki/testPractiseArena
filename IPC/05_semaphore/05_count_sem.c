#include<semaphore.h>

sem_t s;

int main()
{
	sem_init(&s, 0, 10);
	sem_wait(&s);
	sem_post(&s);
	sem_destroy(&s);
}
