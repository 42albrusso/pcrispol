/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:40:32 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/04 17:40:55 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	i;	

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char a[] = "cammellobello";
	char b[] = "botta";
	ft_memcpy(a, b, 4);
	printf("%s", a);
	return(0);
}*/
