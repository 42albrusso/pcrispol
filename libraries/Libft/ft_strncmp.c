/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:41:19 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/10 18:41:21 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (p1[i] != '\0' && p1[i] == p2[i] && i < n - 1)
	{
		i++;
	}
	return (p1[i] - p2[i]);
}
/*int main()
{
char s1[] = "ACVM";
char s2[] = "ACVH";
int n = 4;
int	c;
c = ft_strncmp(s1,s2,n);
printf("%d\n", c);
}*/
