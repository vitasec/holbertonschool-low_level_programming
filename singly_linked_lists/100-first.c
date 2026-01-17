#include <stdio.h>

/**
 * first - prints a specific string before main is executed
 *
 * Description: uses the constructor attribute to run before main
 */
void __attribute__((constructor)) first(void)
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}
