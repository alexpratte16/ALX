#include "include/mem.h"
#include <stdio.h>
#include "include/instruction.h"
unsigned char get_num_args(){
	unsigned char out = *PC;
	out = out >> 6;
	printf("out = %d", out);
	if(out == 3){
		//printf("invalid # of args\n memory address# %d", (char)(PC - memory));
	}
	return out;
}
void inst_tick(){
unsigned char cur = get_num_args();
unsigned char args[cur];
int i;
unsigned char inst = *PC ;
inst &= ~(1 << 7); // turn off bit 7
inst &= ~(1 << 6); //turn off bit 6
printf("type of instruction = %d\n", (inst >> 4));
for(i = 0; i < cur; i++){
++PC;
args[i] = *PC;
}
unsigned char last = inst;
last &= ~(1 << 5);
last &= ~(1 << 4);
switch(inst >> 4){
case 0:
	arithmetic(last, args);
	break;
case 1:
	stack_mem(last, args);
	break;
case 2: 
	bit(last, args);
	break;
case 3:
	jump(last, args);
	break;
}
}
void arithmetic(char last4, char args[]){
switch(last4){
	case 1:
		//printf("arg[0] = %d = %d\n",((unsigned char) args[0]), *(memory + args[0]));
		//printf("arg[1] = %d = %d\n",((unsigned char) args[1]), *(memory + args[1]));
		*(memory+args[0]) += *(memory+args[1]);
		//printf("mem location %d = %d\n", args[0], *(memory+args[0])); 
		break;
	case 2:
		*(memory+args[0]) -= *(memory+args[1]);
		break;
	case 3:
		*(memory+args[0]) *= *(memory+args[1]);
		break;
	case 4:
		*(memory+args[0]) /= *(memory+args[1]);
		break;
	case 5:
		*(memory+args[0]) *= *(memory+args[0]);
		break;
	case 6:
		*(memory+args[0]) += 1;
		break;
	case 7:
		*(memory+args[0]) -= 1;
		break;
}
}
void stack_mem(char last4, char args[]){
}
void bit(char last4, char args[]){
}
void jump(char last4, char args[]){
}