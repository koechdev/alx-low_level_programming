#include "main.h"
/**
 *  print_alphabet - print all alphabet in lowercase,followed by a new line
 */

void print_alphabet(void);
{
	char letter;

	for (la = 'a'; la <= 'z'; la++)
		_putchar(la);
	_putchar('\n');
}
