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

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_len(long long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		n = n * -1;
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	do_itoa(unsigned int tmp, char *str, int len)
{
	while (tmp > 0)
	{
		str[len--] = (tmp % 10) + 48;
		tmp = tmp / 10;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	tmp;
	size_t			len;
	char			*str;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_len(n);
	if (n < 0)
	{
		tmp = n * -1;
		len++;
	}
	else
		tmp = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = 0;
	len--;
	if (n < 0)
		str[0] = '-';
	do_itoa(tmp, str, len);
	return (str);
}
