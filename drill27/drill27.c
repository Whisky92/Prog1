#include<string.h>
#include<stdio.h>

void valami(char*p, int x){
	printf("p is \"%s\" and x is %i \n",p,x );
		// s = String of characters
		// i = Signed decimal integer
		// % = Character
}

int main(){
	printf("Hello World!\n");
	char* h = "Hello";
	char* w = "World!";
	printf("%s %s\n",h,w );
	valami("foo",7);
	valami("Szia",19);
	valami("Uram",999);
}