#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int store_val(unsigned int *bit_array, int value)
{
	unsigned int index = 0;
	if(bit_array == NULL)
		return -1;
	index= value/(8*sizeof(unsigned int));
	int bit_index=value%(8*sizeof(unsigned int));
	// Store the value but firxt indexing into the  bit_array + index of the 
	// int. For e.g. if we are storing 32, our index is 0, the bit index is 32
	// 
	*(bit_array+index) = *(bit_array+index) | (1<<bit_index);
	return 0;	
}


void print_val(unsigned int *bit_array, unsigned int array_size)
{
	unsigned int i =0;
	unsigned int multiplier = (8*sizeof(unsigned int));
	if(bit_array == NULL)
		return ;
	for(i=0;i<array_size;i++){
		for(unsigned int j=0;j<multiplier;j++){
			if(bit_array[i] & (1<<j)){
				printf("value %d\n", i*multiplier+j);
			}
			else{
				printf("value %d\n", 0);
			}
		}
	}	
}

int main(int argc, char **argv){
	
	unsigned int *bit_array=NULL;
	unsigned int allocate_size = 0;	
	unsigned size = 0;
	unsigned int i=0;
	if( argc == 1 || argc > 2 ){
		printf("Usage: bit_array biggest_number\n");
		return -1;
	}
	size = atoi(argv[1]);
	allocate_size=size/(8*sizeof(unsigned int));
	allocate_size=(size %(8*sizeof(unsigned int)) ? allocate_size+1 : allocate_size);
	
	bit_array=(int *)malloc(sizeof(unsigned int)*allocate_size);
	if(bit_array == NULL){
		printf("Failed to allocate bit array\n");
		exit(-2);
	}
	memset(bit_array,0,allocate_size);
	/* for(i=0;i<allocate_size;i++){
		printf("Element %d, value %d \n",i,bit_array[i]);
	}*/
	store_val(bit_array,0);
	print_val(bit_array,allocate_size);	
	return 0;		

}


