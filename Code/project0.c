#include<unistd.h>
#include<stdio.h>
#include<stdint.h>

#define MEM_MAX  99 
#define BYTE_SIZE  4

int WriteByteToMemory(char location, char *ptr, char data)
{
	//add the byte to memory 
	ptr[location] = data;	
}


int WriteIntToMemory(char location, char *ptr, int data)
{
	//create int pointer
	int *intPtr;
	
	//set the int pointer to the memory address to write to
	intPtr = (int)ptr;

	//write the data to memory
	intPtr[location] = data;

	//debug
	//printf("memory written: %d", intPtr[location]);
}

int ReadByteFromMemory(int location, char *ptr)
{
	//read byte from memory
	return ptr[location];
}  

int ReadIntFromMemory(int location, char *ptr)
{
	//create an int pointer
	int *intPtr;

	//set the int pointer to the memory location
	intPtr = (int)ptr;

	//read memory
	return intPtr[location];	

}

int main(int argc, char * argv[])
{

	//create a char array of 100 bytes
	char memory[99];

	//add some chars to mem 
	WriteByteToMemory(0, memory, 1);
	char result = ReadByteFromMemory(0, memory);
	printf("result is: %d\n", (int)result);	

	//test integer fcts
	printf("testing int\n");
	
	WriteIntToMemory(0, memory, 65535);
	int intResult = ReadIntFromMemory(0, memory);
	printf("int result %d\n", intResult);


}
