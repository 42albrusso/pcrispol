/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:55:44 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/04 15:56:08 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = str;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (str);
}
/*int main()
{
    char str[8] = "fester1";
    ft_memset(str, '$', 1);
    printf("%s\n", str);
}*/
