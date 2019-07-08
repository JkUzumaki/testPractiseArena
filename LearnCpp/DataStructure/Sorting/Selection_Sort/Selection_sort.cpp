#include <iostream>
int main()
{
        const int size = 5;
        int arr[size] = {30, 40, 50, 20, 10};
        int temp = 0;
        int min = 0;
        int pos = 0;
        int j = 0;
        int flag = 0;
        for(int i = 0; i < size ; i++){
                //Find the min element based on linear search
		flag = 0;
                for(j = i; j < size; j++){
                        if(flag == 0){
                                min = arr[j];
                                pos = j;
                        }
                        if(min > arr[j]){
                                min = arr[j];
                                pos = j;
                        }
			flag = 1;
                }
                //Swap the element
                if(flag == 1){
                        temp = arr[i];
                        arr[i] = arr[pos];
                        arr[pos] = temp;
                }
        }
        std::cout << "The selection sorted array:\n";
        temp = 0;
        while(temp != size){
                std::cout << arr[temp] << " ";
                temp++;
        }
        std::cout << "\n";
        return 0;
}
