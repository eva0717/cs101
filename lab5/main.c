#include<stdio.h>
#include<stdlib.h> 

int* getIntArray(int n){
	return(int*)calloc(n, sizeof(int));
} 

void setValue(int *p, int v){
	*p = v;
}

void printArray(int *p, int n){
	printf("[");
	for (int i = 0; i < n-1 ; i++){
		printf("%d, ", *p+i);
	}
	printf("%d]\n", *p+n-1);
}

typedef struct arrayList{
	int variable;
	int* (*first)(int);
	void (*second)(int*, int);
	void (*third)(int*, int);
}arrayList_t;

int main(){
	
	printf("No.1---------------\n");
	int n = 10;
	int* ip1 = getIntArray(n);
	
	for (int i = 0; i < n ; i++){
		setValue(ip1+i, i+1);
	}
	
	printArray(ip1, n);
	free(ip1);
	
	printf("No.2----------------\n");
	arrayList_t a;
	a.variable = 10;
	a.first = getIntArray;
	a.second = setValue;
	a.third = printArray;
	int* ip2 = a.first(a.variable);
	
	for (int i = 0; i < a.variable ; i++){
		a.second(ip2+i, i+1);
	}
	
	a.third(ip2, a.variable);
	free(ip2);
	return 0;
}
