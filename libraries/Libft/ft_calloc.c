/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:51:37 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/12 19:51:39 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (size > SIZE_MAX / count)
		return (NULL);
	i = size * count;
	ptr = malloc(i);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, i);
	return (ptr);
}
