#include <string.h>
#include <stdio.h>
//gcc -g -m32 -fno-stack-protector -z execstack -o test test.c

void secret() {
 printf("Secret function\n");
}

void public(char *str){
 char buffer[8];
// printf("Stack before strcpy:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
 strcpy(buffer, str);
// printf("Stack after strcpy:\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n\n");
}

int main(int argc, char *argv[])
{
// printf("public function address = %p\n", public);
// printf("secret function address = %p\n", secret);
 if (argc != 2 ) {
   printf("Please enter a string as an argument!\n");
   return -1;
 }
 public(argv[1]);
 printf("Executed normally\n");
}
