#include <stdio.h>

//Sa se scrie codul in limbaj de asamblare care inverseaza bitii  unui numar

void main(){
	char number;
	number = 140;

	_asm{
		mov al,number
		xor cl,cl

		mov bl,al
		and bl,00000001b
		shl bl,7
		or cl, bl

		mov bl,al
		and bl,00000010b
		shl bl,5
		or cl, bl

		
		mov bl,al
		and bl,00000100b
		shl bl,3
		or cl, bl
		
		mov bl,al
		and bl,00001000b
		shl bl,1
		or cl, bl
		
		mov bl,al
		and bl,00010000b
		shr bl,1

		mov bl,al
		and bl,00100000b
		shr bl,3

		mov bl,al
		and bl,01000000b
		shr bl,5
		or cl, bl

		mov bl,al
		and bl,10000000b
		shr bl,7
		or cl, bl
		
		mov number,cl
	}
	if( number != 49)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");	
}
