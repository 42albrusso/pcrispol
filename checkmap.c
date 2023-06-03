/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:21:27 by pcrispol          #+#    #+#             */
/*   Updated: 2023/06/04 01:28:54 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *all)
{
	int	i;

	i = 0;
	while (i < all->collen)
	{
		free (all->map[i]);
		i++;
	}
	free (all->map);
	all->map = NULL;
}

void	ft_checkmap(char *path, t_game *all, )
{
	int	i;

	i = 0;
	all->collen = ft_collen(path, all);
	all->rowlen = ft_rowlen(path, all);
	all->map = malloc(sizeof(char *) * all->collen);
	while (i < all->collen)
	{
		all->map[i] = malloc(all->rowlen + 1);
		i++;
	}
	fillmap(path, all);
	onlywalls(all);
	find_pos(all);
	c_num(all);
}

int	ft_rowlen(char *path, t_game *all)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		free_close(all, "Error\ninvalid file\n");
	i = 0;
	while (1)
	{
		str = ft_calloc(2, 1);
		read(fd, str, 1);
		if (str[0] == '\n')
			break ;
		i++;
		free(str);
	}
	free(str);
	close(fd);
	return (i);
}

int	ft_collen(char *path, t_game *all)
{
	int		i;
	int		fd;
	char	*str;

	str = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		free_close(all, "Error\ninvalid file\n");
	while (1)
	{
		str = ft_calloc(2, 1);
		read(fd, str, 1);
		if (str[0] == '\n')
			i++;
		if (str[0] == '\0')
			break ;
		free(str);
	}
	free(str);
	close(fd);
	return (i + 1);
}

void	fillmap_utils(t_game *all, int fd, int i)
{
	int		j;
	char	*str;

	j = 0;
	while (j <= all->rowlen)
	{
		str = ft_calloc(2, 1);
		read(fd, str, 1);
		if (str[0] == '\n')
		{
			all->map[i][j] = '\0';
			free(str);
			return ;
		}
		all->map[i][j] = str[0];
		free(str);
		j++;
	}
}

void	fillmap(char *path, t_game *all)
{
	int		i;
	int		j;
	int		fd;
	char	*str;

	i = 0;
	fd = open(path, O_RDONLY);
	while (i < all->collen)
	{
		fillmap_utils(all, fd, i);
		i++;
	}
	close(fd);
	valid_path(all);
}

void	checklinelen(t_game *all)
{
	int	i;

	i = 0;
	while (i < all->collen)
	{
		if (ft_strlen(all->map[i]) != all->rowlen)
			free_close(all, "Error\ninvalid length\n");
		i++;
	}
	if (all->collen == all->rowlen)
		free_close(all, "Error\nnot rectangular\n");
}

void	onlywalls_utils(t_game *all)
{
	int	i;

	i = 0;
	while (i < all->collen)
	{
		if (all->map[0][all->rowlen - 1] != '1')
			free_close(all, "Error\nno surrounding walls\n");
		i++;
	}
	i = 0;
	while (i < all->collen)
	{
		if (all->map[i][0] != '1')
			free_close(all, "Error\nno surrounding walls\n");
		i++;
	}
}

void	onlywalls(t_game *all)
{
	int	j;

	j = 0;
	while (all->map[0][j] != '\0')
	{
		if (all->map[0][j] != '1')
			free_close(all, "Error\nno surrounding walls\n");
		j++;
	}
	j = 0;
	while (all->map[all->collen - 1][j] != '\0')
	{
		if (all->map[all->collen - 1][j] != '1')
			free_close(all, "Error\nno surrounding walls\n");
		j++;
	}
}

void	put_assets_utils(t_game *all, int i, int j)
{
	if (all->map[i][j] == '1')
		mlx_put_image_to_window(all->mlx, all->win,
			all->img.wall, j * 32, i * 32);
	if (all->map[i][j] == '0')
		mlx_put_image_to_window(all->mlx, all->win,
			all->img.background, j * 32, i * 32);
	if (all->map[i][j] == 'P')
		mlx_put_image_to_window(all->mlx, all->win,
			all->img.knight, j * 32, i * 32);
	if (all->map[i][j] == 'E')
		mlx_put_image_to_window(all->mlx, all->win,
			all->img.exit, j * 32, i * 32);
	if (all->map[i][j] == 'C')
		mlx_put_image_to_window(all->mlx, all->win,
			all->img.key, j * 32, i * 32);
}

void	put_assets(t_game *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->collen)
	{
		j = 0;
		while (j < all->rowlen)
		{
			put_assets_utils(all, i, j);
			j++;
		}
		i++;
	}
}
