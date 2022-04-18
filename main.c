#include "include/ft_printf.h"
#include <stdio.h>

int main (void)
{
	char *p;

	printf("%c, %d, %p, %p\n", 'c', 42, NULL, &p);
	ft_printf("%c, %d, %p, %p\n", 'c', 42, NULL, &p);
}

//gcc -Wall -Wextra -Werror -I ./include main.c -L . -lftprintf