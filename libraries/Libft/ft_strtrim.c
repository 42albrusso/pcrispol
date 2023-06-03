/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:56:31 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/24 16:56:33 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_end(const char *s1, const char *set, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < s_len && ft_strchr(set, s1[s_len - i - 1]))
		i++;
	return (s_len - i);
}

size_t	ft_start(const char *s1, const char *set, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < s_len && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	s_len;
	size_t	start;
	size_t	end;
	char	*str;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	s_len = ft_strlen(s1);
	start = ft_start(s1, set, s_len);
	end = ft_end(s1, set, s_len);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
