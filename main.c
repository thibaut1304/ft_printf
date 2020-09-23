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

void 	ft_printf(const char *src, ...)
{
	void	(*ft_function[3]) (va_list *);
	char 	tab[4];
	int 	temp;
	va_list	list;
	int 	i;

	i = 0;
	temp = 0;
	tab[0] = 's';
	tab[1] = 'c';
	tab[2] = 'd';
	tab[3] = 0;
	ft_function[0] = &ft_function_string;
	ft_function[1] = &ft_function_char;
	ft_function[2] = &ft_function_int;
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

}

int		main()
{
	ft_printf("Test %c %s %d\n", 'c', "Salut", 42);
	return (0);
}




















