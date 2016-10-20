#include<stdio.h>

int main(int argc,char *argv[]){

	int a = 100;

	int *b = &a;
	int **bb = &b;
	int *c = NULL;
	int d;
	//int aa = 101;
	//*bb = 123;
	//d = &aa - &a;
	//c = &a+d;
	printf("%X-&a\r\n",&a);
	printf("%X-b\r\n",b);
	printf("%X-&b\r\n",&b);
	printf("%X-bb\r\n",bb);
	printf("%X-*bb\r\n",*bb);
	printf("%X-&bb\r\n",&bb);	
	printf("%d-**bb\r\n",**bb);	
	//printf("%Xa\r\n",&a);
	//printf("%Xaa\r\n",&aa);
	//printf("%dc\r\n",*c);
	return 0;
}
