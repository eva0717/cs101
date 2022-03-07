#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>

FILE* lottery_txt;
void get_6_RandNum(){
    int r[12];
    int i = 0, j, box;
    while(i<=5){
    	box = rand()%69+1;
    	for(j = 0; j < i; j++){
    		if(box == r[j])break;
		}
		if(j == i){
			r[i] = box;
			i++;
		}
	}
	for (int a = 0; a < 6; ++a) {
    	for (int b = 0; b < a; ++b) {
      		if (r[b] > r[a]) {
        	int temp = r[b];
        	r[b] = r[a];
        	r[a] = temp;
        	}	
   		}
	}
	r[6] = rand()%10+1;//special number
	for(j = 0; j <= 6; j++){
		fprintf(lottery_txt,"%02d ",r[j]);
	}
}

void Delay(unsigned int secs){
    unsigned int retTime = time(0) + secs;   
    while (time(0) < retTime);               
}

int main(){ 
	int a,i;
	
	printf("welcome to the lottery machine(?)\nhow many lottery you wanna buy:");
	scanf("%d", &i);
	for(int t = 1; t <= 3; t++){
		Delay(1);
		printf(".");
	}
	Delay(1);
	printf("\noutput you %d set(s) of lottery to lotto.txt\n", i);
	
	srand(time(NULL));
	lottery_txt = fopen("lotto.txt","w+");
	time_t now;
	time(&now);
	char* dt = ctime(&now);
	dt[strlen(dt)-1]=0;
	fprintf(lottery_txt,"========= lotto649 =========\n= %s =\n", dt);
	for(a = 1; a <= i; a++){
		fprintf(lottery_txt,"= [%d]:", a);
		get_6_RandNum();
		fprintf(lottery_txt,"=\n");
	}
	for(; a <= 5; a++)fprintf(lottery_txt,"= [%d]:== == == == == == == =\n", a);
	fprintf(lottery_txt,"========= csie@CGU =========\n");
	fclose(lottery_txt);
} 
