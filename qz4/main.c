#include <stdio.h>
#include <stdlib.h>

void swap (int* n, int* m){
    int tmp;
    tmp = *n;
    *n = *m;
    *m = tmp;
}
void swapArray (int a[], int b[], int len){
    int tmp;
    for(int i=0; i<len;i++){
        tmp = *(a+i);
        *(a+i) = *(b+i);
        *(b+i) = tmp;
    }

}
void printArraay(int a[], int size){
    for(int i=0;i<size-1;i++) 
        printf("%d, ", *(a+i));
    printf("%d]\n",*(a+size-1));
}
char* copy_string (char* s){
    int len = 0;
    while (*(s+len) != '\0') len++;
    char* New = calloc (len+1, sizeof(char));
    for (int i=0; i<=len; i++)  *(New+i) = *(s+i);
    return New;
}
int main (){
    int n = 1, m = 2;
    swap(&n, &m);
    int size = 10;
    int source [10]= {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    swapArray (source, dest, size);
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("No.1------------\n");
    printf("after swap, n=%d, m=%d\n", n, m);
    printf("No.2------------\n");
    printf("after swap array, source array = [");
    printArraay(source, size);
    printf("after swap array, dest array = [");
    printArraay(dest, size);
    printf("No.3------------\n");
    printf("copy string = %s\n", cp_str);
    free(cp_str);
    cp_str = NULL;
}
