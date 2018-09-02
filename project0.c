#include<unistd.h>
#include<stdio.h>
#include<stdint.h>

#define MEM_MAX  99 
#define BYTE_SIZE  4

int WriteToMemory(char location, char *ptr, char data)
{
	//add the value to memory
	ptr[location] = data;	
	printf("value = %d\n", (int)data);

	//increment the pointer to the next word
	ptr = ptr+5;
	printf("ptr location is %d\n", (int)ptr);
}


int WriteIntToMemory(char location, char *ptr, int data)
{
	//create 4 char variables to hold each byte of the integer		
	uint8_t byte_array[4];

	//seperate each byte from the integer with an logical AND
	for(uint8_t i = 0; i <= 3; i++)
	{
		byte_array[i] = data & 0xff;
		
		//right shift the right-most byte off
		data = data >> 8;
	}

	for(uint8_t i = 0; i <= 3; i++)
	{
		printf("byte %d = %d\n", (int)i, (int) byte_array[i]);
	}
	

	//store each byte in memory
	for(uint8_t i = 0; i <= 3; i++)
	{
		ptr[location+i] = byte_array[i];
	}	

}

int ReadByteFromMemory(int location, char *ptr)
{
//variable to hold the value from memory
uint8_t mem_value;

mem_value = ptr[location];
printf("value = %u\n",mem_value);

}  

int ReadIntFromMemory(int location, char *ptr)
{
	//variable to hold a byte 
	uint32_t mem_value = 0;
	
	//variable to hold an int
	uint32_t int_mem_value = 0;

	//reconstruct the number
	mem_value = ptr[location];
	int_mem_value = mem_value & 0x000000ff;
	printf("read memory value = %u\n", int_mem_value);

	mem_value = ptr[location+1];
	mem_value = mem_value << 8;
	mem_value = mem_value | int_mem_value;
	int_mem_value = mem_value & 0x0000ffff;
	printf("read memory value = %u\n", int_mem_value);

	mem_value = ptr[location+2];
	mem_value = mem_value << 16;
	mem_value = mem_value | int_mem_value;
	int_mem_value = mem_value & 0x00ffffff;
	printf("read memory value = %u\n", int_mem_value);

	mem_value = ptr[location+3];
	mem_value = mem_value << 24;
	mem_value = mem_value | int_mem_value;
	int_mem_value = mem_value & 0xffffffff;
	printf("read memory value = %u\n", int_mem_value);
}

int main(int argc, char * argv[])
{

	//create a char array of 100 bytes
	char memory[99];

	//add some chars to mem 
	WriteIntToMemory(4, memory, 4294967295);
	ReadByteFromMemory(0, memory);
	ReadByteFromMemory(1, memory);	
	ReadByteFromMemory(2, memory);
	ReadByteFromMemory(3, memory);
	ReadIntFromMemory(0, memory);
}





