/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:18:19 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/04 17:18:45 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*h;

	h = s;
	while (n > 0)
	{
		*h = '\0';
		n--;
		h++;
	}
}
/*int main()
{
    char s[8] = "fester1";
    ft_bzero(s, 2);
    printf("%s\n", s);
}*/
