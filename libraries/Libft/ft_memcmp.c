/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:42:59 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/12 19:43:05 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*st1;
	size_t				i;
	unsigned const char	*st2;

	st1 = s1;
	st2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && st1[i] == st2[i])
		i++;
	return (st1[i] - st2[i]);
}
/*(st1[i] == '\0' && st2[i] == '\0')
int main()
{
	char s[] = {-128, 0, 127, 0};
        char sCpy[] = {-128, 0, 127, 0};
        char s2[] = {0, 0, 127, 0};
        char s3[] = {0, 0, 42, 0};
        printf("%d\n",(ft_memcmp(s2, s3, 4) != 0));
        printf("%d\n",memcmp(s2, s3, 4) != 0);
}*/
