#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// char *print_result(int i, int j)
// {
//     char *  str;

//     if (i == j)
//     {
//         str = "\033[32m*** OK ***\033[0m";
//     }
//     else
//         str = "\033[33m*** KO ***\033[0m";
//     return (str);
// }

int ft_printf(const char *src, ...);

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
    // char *s;
    // printf("%ld\n", (long)str);
    // printf("%lx\n", (long)str);
    // printf("%p\n", str);

    // printf(">>>>>>>%05\n");
    // ft_printf(">>>>>>>%05\n");
	// char str[] = "hey";

    // int x = ft_printf("Salghjkjhghjkjhut++=%s=%d=\n","tesfghjklhgfdfghjktahah", 1000000);
	// int z =	printf("Salghjkjhghjkjhut++=%s=%d=\n","tesfghjklhgfdfghjktahah", 1000000);
    // int t = ft_printf("Test%*.*d\n", 1, 5, 42);
    // int g = printf("Test%*.*d\n", 1, 5, 42);
    // char *str = "|%010%|\n";
    // int a = ft_printf(str, 2);
    // int b =    printf(str, 2);
    // printf("a = %d\n", a);
    // printf("b = %d\n", b);

    // printf("X = %d\n", x);
	// printf("Z = %d\n", z);
    // printf("T = %d\n", t);
    // printf("G = %d\n", g);
    char *print = "|%+-9.1i|\n";

    int a = ft_printf(print, 10, 54);
    int b = printf(print, 10, 54);
    // int i = printf("S6 : %0*.*s\n", 4, 3, "test");
    // int j = ft_printf("S6 : %0*.*s\n", 4, 3, "test");

    printf("ft_printf == %d\n", a);
    printf("   printf == %d\n", b);

	return 0;
}