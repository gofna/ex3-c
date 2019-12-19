#include<stdio.h>
#define SIZE 50

void shift_element(int *arr , int i) { 
	
	while(i > 0 ){
		i--;
		int *temp = arr + i;
		*(arr+i+1) = *(temp);

	}
	*(arr) = 999;
}

void insertion_sort(int *arr, int len){
	for(int i = 1 ; i<len ; i++){
		int index = i; // save the index from where to shift
		int count = 0; // count how many to do shift
		int temp = 0; // to save the corrent value
		for(int j = i-1 ; j>=0 ; j--){
			temp = *(arr+i);
			if(*(arr+i) < *(arr+j)){
				count++;
				index = j;
			}
		}
		shift_element(arr+index , i-index);
		*(arr+index) = temp;	
			//printArray(arr , len); //test print
			//printf("\n");
	}
}																			

void printArray(int arr[] , int size) {
	for(int i = 0; i < size; i++) { 
		if( i != size-1){
			printf("%d," , *(arr+i));
		}
		else{
			printf("%d \n" , *(arr+i));
		}
	}

}
