/*
 * cwelt001_clee244_lab5_part1.c
 *
 * Created: 1/28/2020 12:14:42 PM
 * Author : Carson Welty (cwelt001)
 * Partner: Christian Lee (clee244)
 */ 

#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0xFF;
	PORTB = 0x00;
	
	unsigned char tank;
	unsigned char tmpB = 0x00;
    while (1) 
    {
		tank = ~PINA & 0x0F;
		
		if((tank == 0x01) || (tank == 0x02)){
			tmpB = 0x60;
		}
		else if ((tank == 0x03) || (tank == 0x04)){
			tmpB = 0x70;
		}
		else if ((tank == 0x05) || (tank == 0x06)){
			tmpB = 0x38;
		}
		else if ((tank == 0x07) || (tank == 0x08) || (tank == 0x09)){
			tmpB = 0x3C;
		}
		else if ((tank == 0x0A) || (tank == 0x0B) || (tank == 0x0C)){
			tmpB = 0x3E;
		}
		else if ((tank == 0x0D) || (tank == 0x0E) || (tank == 0x0F)){
			tmpB = 0x3F;
		}
		
		tmpB = tmpB & 0x7F;
		
		if (GetBit(~PINA,4) && GetBit(~PINA,5) && !GetBit(~PINA,6)){
			tmpB = SetBit(tmpB,7,1);
		}
		PORTB = tmpB;
    }
	return 0;
}


