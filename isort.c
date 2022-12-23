#include<stdio.h>
#define SIZE 50


void shift_element(int* arr, int i){
    for ( int k = i-1 ; k >=0 ; k--){
        int temp = *(arr+k);
        *(arr+k) = *(arr+k+1);
        *(arr+k+1) = temp;
    }
}

void insertion_sort(int* arr, int len){
    for (int i = 1; i < len ; i++){
       int current = *(arr+i);
       int j = i-1;

       while (j>=0 && *(arr+ j) > current){
            shift_element(arr+j, 1);
            j--;
       }
       *(arr+j+1) = current;
    }
}


int main(){
    int arr[SIZE];
    for (int i = 0 ; i < SIZE ; i++){
        scanf("%d",&arr[i]);
    }

    insertion_sort(arr, SIZE);

    for (int i = 0 ; i < SIZE ; i++){
        if (i < SIZE){
            printf("%d,", *(arr+i));
        }
        else if (i==SIZE){
            printf("%d", *(arr+i));
        }
    }
    return 0;
}