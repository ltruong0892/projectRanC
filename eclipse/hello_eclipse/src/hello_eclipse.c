/*
 ============================================================================
 Name        : hello_eclipse.c
 Author      : vtruong92
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("Hello World !\n"); /* prints !!!Hello World!!! */
	int age=0;
	printf("How old are you? ");
	fflush(stdout);
	scanf("%d",&age);
	printf("You are %d years old",age);
	return 0;
}
