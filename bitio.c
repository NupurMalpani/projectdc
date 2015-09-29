#include<stdio.h>
#include<stdlib.h>
#include "bitio.h"
#include "errhand.h"
BIT_FILE *OpenInputBitFile( char *name ){
	BIT_FILE *bit_file;
	bit_file =(BIT_FILE)malloc(sizeof(BIT_FILE));
	if(!bit_file)
		return(bit_file);
	bit_file->file = fopen(name, "rb");
	bit_file->rack = 0;
	bit_file->mask = 0x80;
	bit_file->pacifier_counter = 0;
	return(bit_file);
}
BIT_FILE *OpenOutputBitFile( char *name ){
	BIT_FILE *bit_file;
	bit_file =(BIT_FILE)malloc(sizeof(BIT_FILE));
	if(!bit_file)
		return(bit_file);
	bit_file->file = fopen(name, "rb");
	bit_file->rack = 0;
	bit_file->mask = 0x80;
	bit_file->pacifier_counter = 0;
	return(bit_file);
}
void OutputBit( BIT_FILE *bit_file, int bit ) {
	if(bit)
		bit_file->rack |=bit_file->mask;
	bit_file->mask >>= 1;
	if(bit_file->mask == 0) {
		if(putc(bit_file->rack, bit_file->file) != bit_file->file) != bit_file->rack)
			fatal_error("Fatal error in OutputBit! \n");
		else
			if((bit_file->packifier_counter++ & 4095) == 0)
				putc('.', stdout);
		bit_file->rack = 0;
		bit_file->mask = 0x80;
		}
}
void OutputBits( BIT_FILE *bit_file, unsigned long code, int count ){
 	unsigned long mask;
 	mask = 1L << (count - 1);
 	while(mask != 0) {
 		if(mask & code)
 			bit_file->rack |= bit_file->mask;
 	bit_file->mask >>+ 1;
 	if(bit_file->mask == 0) {
 		if(putc(bit_file->rack, bit_file->file) != bit_file->file) != bit_file->rack)
			fatal_error("Fatal error in OutputBit! \n");
		else if((bit_file->packifier_counter++ & 2047) == 0){
			putc('.', stdout);
			bit_file->rack = 0;
			bit_file->mask = 0x80;
		}
	}
		mask >>= 1;
	}
}
int  InputBit( BIT_FILE *bit_file ) {
	int value;
	if(bit_file->mask == 0x80) {
		bit_file->rack = getc(bit_file->file);
		if(bit_file->rack == EOF)
			fatal_error("Fatal error in InputBit!\n);
		if((bit_file->pacifier_counter++ & 2047) == 0)
			putc('.',stdout);
	}
	value = bit_file->rack & bit_file->mask;
	bit_file->mask >>= 1;
	if(bit_file->mask == 0)
		bit_file->mask = 0x80;
	return(value ? 1 : 0);
}
unsigned long InputBits( BIT_FILE *bit_file, int bit_count ){
	unsigned long mask;
	unsigned long return_value;
 	mask = 1L << (bit_count - 1);
 	return_value = 0;
 	while(mask != 0) {
 		if(bit_file->mask == 0x80) {
 			bit_file->rack = getc(bit_file->file);
 			if(bit_file->rack ==EOF)
 				fatal_error("Fatal error in InputBit!\n);
 			if((bit_file->pacifier_counter++ & 2047) == 0)
			putc('.',stdout);
		}
		if(bit_file->rack & bit_file->mask )
			return_value |= mask;
		mask >>= 1;
		bit_file->mask >>= 1;
		if(bit_file->mask = 00)
			bit_file->mask = 0x80;
	}
	return return_value;
}
void CloseInputBitFile( BIT_FILE *bit_file ){
	fclose(bit_file->file);
	free((char*)bit_file);
}	
void CloseOutputBitFile( BIT_FILE *bit_file ){
	if(bit_file->mask != 0x80)
		if(putc(bit_file->rack, bit_file->file) != bit_file->rack)
			fatal_error("fatal error in closebitfile!\n");
	fclose(bit_file->file);
	free((char*) bit_file);
}
void FilePrintBinary( FILE *file, unsigned int code, int bits ){
	unsigned int mask;
	mask = 1 << (bits - 1);
	while( mask != 0) {
		if(code & mask)
			fput('1', file);
		else
			fputc('0', file);
		mask >>= 1;
	}
}
	

