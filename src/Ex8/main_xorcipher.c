#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "xorcipher.h"


int main()
{
	srand(time(NULL));

	// uint32_t confidentiality_key = 0x00000000;
	uint32_t confidentiality_key = rand();

	uint32_t copy_key = confidentiality_key;

	char cryptme[] = "This is a test string to try";
	int stringlen = ((strlen(cryptme) + 1) / sizeof(uint32_t)) + ((strlen(cryptme) + 1) % sizeof(uint32_t) ? 1 : 0);

	printf("%d", stringlen);

	printf("Randomly seeded confidentiality_key: 0x%08x\n", confidentiality_key);	

	printf("Before ciphered: %s\n", cryptme);
	print_uint32_hex(cryptme, stringlen);

	confidentiality_xor(confidentiality_key,(void*)cryptme, stringlen);

	printf("After ciphered: %s\n", cryptme);
	print_uint32_hex(cryptme, stringlen);

	confidentiality_xor(copy_key,(void*)cryptme,8);

	printf("After deciphered: %s\n", cryptme);
	print_uint32_hex(cryptme, stringlen);

	copy_key = confidentiality_key;

	printf("Before ciphered: %s\n", cryptme);

	confidentiality_xor_shift(confidentiality_key,(void*)cryptme, stringlen);

	printf("After ciphered with shift: %s\n", cryptme);
	print_uint32_hex(cryptme, stringlen);

	confidentiality_xor_shift(copy_key,(void*)cryptme,8);

	printf("After decciphered with shift: %s\n", cryptme);
	print_uint32_hex(cryptme, stringlen);


	return 0;
}