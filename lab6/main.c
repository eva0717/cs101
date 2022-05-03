#include<stdio.h>
#include<stdlib.h>

int _sum(int x, int y){
    return x+y;
}
int _sub(int x, int y){
    return x-y;
}
int _mult(int x, int y){
    return x*y;
}
int _div(int x, int y){
    return x/y;
}
int _pow(int x, int y){
    int num = 1;
    for(int i = 0; i < y;i++)num=num*x;
    return num;
}

int main(){
    int x, y, choice;
    int(*ope[5])(int, int);
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _pow;
    
    printf("Enter two interger:");
    scanf("%d%d", &x, &y);
    
    printf("enter the choice:");
    scanf("%d", &choice);
    
    printf("%d", ope[choice](x,y));
    return 0;
}
