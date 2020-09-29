#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int 	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10 && nb >= 0)
		ft_putchar(nb + '0');
}

void	ft_function_string(va_list *list)
{
	char 	*str;

	str = va_arg(*list, char *);
	write(1, str, ft_strlen(str));
}

void		ft_function_char(va_list *list)
{
	char 	c;

	c = va_arg(*list, int);
	ft_putchar(c);
}

void	ft_function_int(va_list *list)
{
	int 	nb;

	nb = va_arg(*list, int);
	ft_putnbr(nb);
	// printf("%d\n", nb);
}

// void	ft_function_pointer(va_list *list)
// {
// 	char 	*p;
// 	int 	i;

// 	i = 0;
// 	p = va_arg(*list, char*);
// 	while (p[i])
// 		ft_putchar(p[i++]);
// }

int 	ft_find(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int 	ft_printf(const char *src, ...)
{
	void	(*ft_function[4]) (va_list *);
	char 	tab[5];
	int 	temp;
	va_list	list;
	int 	i;

	i = 0;
	temp = 0;
	tab[0] = 's';
	tab[1] = 'c';
	tab[2] = 'd';
	// tab[3] = 'p';
	tab[3] = 0;
	ft_function[0] = &ft_function_string;
	ft_function[1] = &ft_function_char;
	ft_function[2] = &ft_function_int;
	// ft_function[3] = &ft_function_pointer;
	va_start(list, src);
	while (src[i])
	{
		if (i != 0 && src[i - 1] == '%')
		{
			temp = ft_find(tab, src[i]);
			if (temp != -1)
				(*ft_function[temp]) (&list);
		}
		else if (src[i] != '%')
			ft_putchar(src[i]);
		i++;
	}
return (1);
}

int		main()
{
	ft_printf("Test %s %d\n", "Salut", 42);
	return (0);
}




















