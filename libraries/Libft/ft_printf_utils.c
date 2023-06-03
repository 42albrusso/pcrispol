/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:37:46 by pcrispol          #+#    #+#             */
/*   Updated: 2023/01/23 16:37:48 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_print_di(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_s(num);
	free(num);
	return (len);
}
