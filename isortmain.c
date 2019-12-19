#include<stdio.h>
#include "sort.h"
#define SIZE 50

int main() {
	 int Array [SIZE] ; 
	 printf("enter %d number to Array \n" , SIZE);
	for(int i =0; i<SIZE; i++){
		scanf("%d",Array+i);
	}
 
insertion_sort(Array, SIZE);
printf("the sorted Array is : \n");
printArray(Array,SIZE);
 

 return 0;
}