/**
* Memory Access: The program explores how data is stored in the memory.
*
* Scottie YANG Miaoyi
* Feb 13, 2021
*/

#include <stdio.h>
#include <stdlib.h>

/* define every type, then explore its storage sturcture in memory.
*/ 
int main (int arg, char *argv[]) {
    char c = 'a';
    short sh = 5600;
    int i = 980000;
    long l = 6900000001;
    float f = 3.1415;
    double d = 2.71828182845;

    unsigned char *ptr_c = (unsigned char *)&(c);
	for(int i=0; i<sizeof(char); i++) {
	    printf("char %d: %02X\n", i, ptr_c[i]);
	}
    unsigned char *ptr_sh = (unsigned char *)&(sh);
    for(int i=0; i<sizeof(short); i++) {
	    printf("short %d: %02X\n", i, ptr_sh[i]);
	}
    unsigned char *ptr_i = (unsigned char *)&(i);
    for(int i=0; i<sizeof(int); i++) {
	    printf("int %d: %02X\n", i, ptr_i[i]);
	}
    unsigned char *ptr_l = (unsigned char *)&(l);
    for(int i=0; i<sizeof(long); i++) {
	    printf("long %d: %02X\n", i, ptr_l[i]);
	}
    unsigned char *ptr_f = (unsigned char *)&(f);
    for(int i=0; i<sizeof(float); i++) {
	    printf("float %d: %02X\n", i, ptr_f[i]);
	}
    unsigned char *ptr_d = (unsigned char *)&(d);
    for(int i=0; i<sizeof(double); i++) {
	    printf("double %d: %02X\n", i, ptr_d[i]);
	}
}