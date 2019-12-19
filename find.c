#include<stdio.h>
#include<string.h>
#include "find.h"
#define LINE 256
#define WORD 30

int Getline(char s[]){ 
	int i = 0;
	int counter = 0;
		while(s[i] != '\n') {
			counter++;
			i++;
		}
	return counter;
}

int getword(char w[]){
	int i = 0;
	int counter = 0;
		while(w[i] != '\n' && w[i] != '\t' && w[i] != ' ') {
			counter++;
			i++;
		}
	return counter;
}
		
int substring(char *str1 , char *str2){
	int flag = 0;
	int j = 0;
	char *temp;
	char *temp2;
	for( int i = 0 ; i <LINE ; i++){
		if(*str1 == *str2){
			temp = str1;
			temp2 = str2;
			for(j = 0 ; j <strlen(str2) ; j++){
				if(*temp == *temp2){
					temp++;
					temp2++;
				}
				else break;
			}
			temp2 = str2;
			if(j == strlen(str2)){ // we finish to over all str2
				flag = 1;
				break;
			}
		}
		str1++;
	}
	return flag;
}

int similar(char *s , char *t , int n){
	printf("the word  : %s\n",s);
	int i = 0;
	int count = 0;
	int sizeS = strlen(s);
	if(sizeS < strlen(t)){
		return 0;
	}
	while(i < sizeS){
		//printf("s is  :%s\n" , s); //test for me
		//printf("t is  :%s\n" , t);
			if(*s == *t ){
				s++;
				t++;
			}
			else{
				count++;
				s++;
			}

		i++;
	}
	if( count <= n ) return 1;
	else return 0;
}

void print_lines(char *str){
	char s[LINE];
	char w[WORD];
	fgets(s, LINE , stdin); // to skip the second line
	while( fgets(s, LINE , stdin)){
		int j=0;
		for(int i = 0 ; i < LINE && s[i] != '\n' ; i++){
			if( s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0'){
				w[j] = s[i];
				j++;
			}
			else {
				if(substring(w,str)){
					printf("%s",s);
					break;
				}
				j=0;
			}
		}
	}
	//printf("%s",s); // test
	
}


void print_similar_words(char *str){
	char s[LINE];
	char w[WORD];
	fgets(s, LINE , stdin);
	while( fgets(s, LINE , stdin)){
		//printf("s is  :%s..\n",s); //test for me
		int j=0;
		int lenline = strlen(s);
		//printf("len is  : %d\n",lenline);
		for(int i = 0 ; i < lenline  ; i++){
			if( s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0'){
				w[j] = s[i];
				j++;
				
			}
			else{
				//printf("the word  : %s\n",w); //test for me
				printf("similiar is?  : %d\n",similar(w, str , 1)); //test for me
				char *temp = w;
				if (similar(w, str , 1)){
					printf("%s\n",temp);
				}
				j=0;
				memset(w , 0 , WORD); // reset the word
			}
		}
	}

}



