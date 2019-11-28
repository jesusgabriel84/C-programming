#include <stdio.h>
#include <string.h>
#include "bits.h"


int op_bit_get(const unsigned char* data, int i){
	return (data[i/8]>>(7-i%8))&0x1;
}

void op_bit_set(unsigned char* data, int i){
	data[i/8] = data[i/8] | (0x80 >> i%8);
}

void op_bit_unset(unsigned char* data, int i){
	if(op_bit_get(data,i)==0){}
	else data[i/8] = data[i/8] ^ (0x80 >> i%8);
}

unsigned char op_bit_get_sequence(const unsigned char* data, int i, int how_many){
	unsigned char seq[]={0x00};
	int j,k;
	//7-how_many
	if(how_many<8){
		for(j=0;j<how_many;j++){
			if(op_bit_get(data,i+j)==1) op_bit_set(seq,7-how_many+j); 
		}
	}
	else{
		for(k=0;k<8;k++){
			if(op_bit_get(data,i+k)==1) op_bit_set(seq,k); 
		}
	}
	return seq[0];

}

void op_print_byte(unsigned char b){
	for (int i = 7; i >= 0; i--) {
		if (b & (1 << i)) printf("1");
		else printf("0");
	}
}