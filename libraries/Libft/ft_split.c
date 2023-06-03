/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:33:22 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/24 15:33:24 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_num(const char *str, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && str[i] != 0)
		{
			num++;
			while (str[i] != c && str[i] != 0)
				i++;
		}
		else if (str[i] != 0)
			i++;
	}
	return (num);
}

void	ft_strcpy(char *dst, const char *src, int start, int last)
{
	int	i;

	i = 0;
	while (start < last)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = 0;
}

static	void	*free_mem(char **allocated_mem, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(allocated_mem);
		i++;
	}
	free(allocated_mem);
	return (NULL);
}

static	void	do_split(const char *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			start = i;
			while (s[i] != c && s[i] != 0)
				i++;
			str[j] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (str[j] == 0)
			{
				free_mem(str, j);
				return ;
			}
			ft_strcpy(str[j], s, start, i);
			j++;
		}
		else if (s[i] != 0)
			i++;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	n;

	if (s == 0)
		return (0);
	n = get_num(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (str == 0)
		return (0);
	str[n] = 0;
	if (n == 0)
		return (str);
	do_split(s, c, str);
	return (str);
}

/*int	main()
{
	char **arr;
	char	*s = "sarumanhotel";
	char	c = 'h';
	size_t	i = 0;
	
	arr = ft_split(s, c);
	while(arr)
	{
	printf("%s", arr[i]);
		i++;
	}
	return (0);
}*/
