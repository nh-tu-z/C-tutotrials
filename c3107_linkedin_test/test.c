#include <stdio.h>

int f1(int d, int c);

union Cars{
	char make[20];
	char model[30];
	short year;
} car;

int main(){
	f1(10,20);
	return 0;
}
int f1(int a, int b){
	if(a>b){
		printf("A is greater than B\n");
		return 1;
	}
	else {
		printf("B is greater than A\n");
		return 0;
	}
}
