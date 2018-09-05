#include<stdint.h>
#include<stdio.h>
#include<string.h>




void parseBySpace()
{
char ptr[] = "this is the string to parse";

//create a save pointer that will save the place in the string during each parse
char *saveptr = ptr;

//create pointer to save result in
char *token;

//create pointer to hold delimiter
char *delimiter =(char *) ' ';

do
{
token = strtok_r(saveptr," ", &saveptr);
printf("%s\n", token);
}while(token);
}






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

while(letter != EOF)
{
letter = (char)fgetc(fptr);
//printf("%c", letter);
}

//create a string to be parsed
char* sentance = "this is the string to be parsed";
//pass the string to the function to be parsed
parseBySpace();




return 0;
}
