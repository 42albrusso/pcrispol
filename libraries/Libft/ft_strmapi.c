/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:53:41 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/24 18:53:43 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	if (s == 0)
		return (0);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
