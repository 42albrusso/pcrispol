/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:13:28 by pcrispol          #+#    #+#             */
/*   Updated: 2023/01/30 18:13:32 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_p(unsigned long p)
{
	int	print_length;

	print_length = 0;
	if (!p)
		print_length += write (1, "(nil)", 5);
	else
	{
		print_length += write(1, "0x", 2);
		if (p == 0)
			print_length += write(1, "0", 1);
		else
		{
			ft_put_ptr(p);
			print_length += ft_ptr_len(p);
		}
	}
	return (print_length);
}
