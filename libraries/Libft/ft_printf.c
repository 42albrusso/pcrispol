/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:54:14 by pcrispol          #+#    #+#             */
/*   Updated: 2023/01/23 14:54:28 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_length;
	va_list	args;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (print_length);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_c(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_s(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_p(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_di(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_x(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += write(1, "%", 1);
	return (print_length);
}

int	ft_putchar(char c)
{
	int	i;

	i = write (1, &c, 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	long	temp;
	char	tab[10];
	int		i;

	i = 0;
	temp = nb;
	if (temp == 0)
		ft_putchar('0');
	if (temp < 0)
		ft_putchar('-');
	if (temp < 0)
		temp = -temp;
	while (temp > 0)
	{
		tab[i] = temp % 10 + '0';
		temp = temp / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(tab[i]);
		i--;
	}
	return (0);
}
