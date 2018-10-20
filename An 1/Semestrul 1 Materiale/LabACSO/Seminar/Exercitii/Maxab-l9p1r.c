#include <stdio.h>

//Completati exemplul urmator astfel incat functia max sa returneze maximun dintre a si b

int max(int a, int b){
 int maxim;
 _asm{
	//completati
	 mov eax, a
	 mov ebx, b
	 cmp eax,ebx
	 jg a_is_greater
	 mov maxim, ebx
	 jmp _done
a_is_greater:
	 mov maxim,eax
_done:

 }
 return maxim;
}

void main(){
 int a,b;
 printf("a = ");
 scanf("%d",&a);
 printf("b = ");
 scanf("%d",&b);
 printf("MAX(a,b) = %d",max(a,b));
}
