#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tcpheader.h"
#include "bits.h"








/*
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
*/


int getSourcePort(const unsigned char *tcp_hdr){
	int SourcePort=0;
	for(int i=0;i<16;i++){
		SourcePort=SourcePort + (op_bit_get(tcp_hdr,i)*pow(2,15-i));
	}
	return SourcePort;
}
int getDestinationPort(const unsigned char *tcp_hdr){
	int DestinationPort=0;
	for(int i=16;i<32;i++){
		DestinationPort=DestinationPort + (op_bit_get(tcp_hdr,i)*pow(2,31-i));
	}
	return DestinationPort;
}

int getAckFlag(const unsigned char *tcp_hdr){
	return op_bit_get(tcp_hdr,107);
}

int getDataOffset(const unsigned char *tcp_hdr){
	int DataOffset=0;
	for(int i=96;i<100;i++){
		DataOffset=DataOffset + (op_bit_get(tcp_hdr,i)*pow(2,99-i));
	}
	return DataOffset;
}

void setSourcePort(unsigned char *tcp_hdr, int port){
	for (int i = 15; i >= 0; i--)
  		{
    		if ((port>>i) & 1) op_bit_set(tcp_hdr,15-i);
    		else op_bit_unset(tcp_hdr,15-i);
  		}
}

void setDestinationPort(unsigned char *tcp_hdr, int port){
	for (int i = 16; i < 32; i++)
  		{
    		if ((port>>(31-i)) & 1) op_bit_set(tcp_hdr,i);
    		else op_bit_unset(tcp_hdr,i);
  		}
}

void setAckFlag(unsigned char *tcp_hdr, int flag){
	if (flag==1) op_bit_set(tcp_hdr,107);
    else op_bit_unset(tcp_hdr,107);
}

void setDataOffset(unsigned char *tcp_hdr, int offset){
	for (int i=96;i<100;i++)
  		{
    		if ((offset>>(99-i)) & 1) op_bit_set(tcp_hdr,i);
    		else op_bit_unset(tcp_hdr,i);
  		}
}