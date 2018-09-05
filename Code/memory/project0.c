#include<unistd.h>
#include<stdio.h>
#include<stdint.h>

#define MEM_MAX  99 
#define BYTE_SIZE  4


int MoveInteger(char fromLocation, char toLocation, char *ptr)
{
	//create an int pointer
	int *intPtr;

	//set the char ptr to the location to be moved
	//ptr = ptr[fromLocation];

	//set the int ptr to the char ptr
	intPtr = (int*)ptr;

	//copy the contents of the memory location at the int pointer 
	int temp = intPtr[fromLocation];

	//write the data to the new memory location
	intPtr[toLocation] = temp;	
}
	



int WriteByteToMemory(char location, char *ptr, char data)
{
	//add the byte to memory 
	ptr[location] = data;	
}


int WriteIntToMemory(int location, char *ptr, int data)
{
	//create int pointer
	int *intPtr;
	
	//set the int pointer to the memory address to write to
	intPtr = (int*)ptr;

	//write the data to memory
	intPtr[location] =data; 

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
	intPtr = (int*)ptr;

	//read memory
	return intPtr[location];	

}

int main(int argc, char * argv[])
{

	//create a char array of 100 bytes
	char memory[99];

	//add some chars to mem 
	int test = 'abcd';	
	printf("test = %s\n", test);
	WriteIntToMemory(0, memory, test );
	int data = ReadIntFromMemory(0, memory);
		
	printf("data is: %d\n", data);

	MoveInteger(0, 10, memory);
	data = ReadIntFromMemory(10, memory);
	printf("data is: %d\n", data);

}
