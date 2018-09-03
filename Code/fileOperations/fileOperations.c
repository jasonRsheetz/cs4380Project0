#include<stdint.h>
#include<stdio.h>














int main(int argc, char *argv[])
{
//declare a file pointer
FILE *fptr;

//open the file
if((fptr = fopen("shakespeare.txt", "r")) == NULL)
{
	perror("bad file name");
	return -1;

}

char letter;
do
{
letter = (char)fgetc(fptr);
printf("%c", letter);
}while(letter != EOF);







return 0;
}
