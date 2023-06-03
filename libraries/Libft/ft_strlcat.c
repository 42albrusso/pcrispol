/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:27:59 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/05 19:28:03 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	c;
	size_t	d;

	c = 0;
	d = 0;
	while (dest[c] && c < size)
		c++;
	while (src[d] && (c + d + 1) < size)
	{
		dest[c + d] = src[d];
		d++;
	}
	if (c < size)
	{
		dest [c + d] = '\0';
		d = 0;
	}
	while (src[d])
		d++;
	return (c + d);
}

/*int	main(void)
{
	char dest[20] = "123111";
	char src[] = "4567890";
	unsigned int size = 15;
	unsigned int result;

	printf("-----\ndest = %s\nsrc = %s\nnb = %d\n\n", dest, src, size);
	result = ft_strlcat(dest, src, size);
	printf("dest (cat) = %s\nresult = %d\n-----\n", dest, result);

	return (0);
}*/
