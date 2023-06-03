/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:48:52 by pcrispol          #+#    #+#             */
/*   Updated: 2023/06/04 00:40:07 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libraries/Libft/libft.h"

typedef struct s_data
{
	void	*wall;
	void	*key;
	void	*knight;
	void	*exit;
	void	*background;
	int		height;
	int		width;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		collen;
	int		rowlen;
	int		c_number;
	int		c_progress;
	int		n_moves;
	int		x;
	int		y;
	char	**map;
	t_data	img;
}			t_game;

int		check_path(t_game *all, char **maps);
int		close_win(t_game *all);
int		ft_collen(char *path, t_game *all);
int		ft_rowlen(char *path, t_game *all);
int		key_hook(int keycode, void *r);
int		valid_move(t_game *all, char c);
int		valid_path(t_game *all);
void	checklinelen(t_game *all);
void	c_num(t_game *all);
void	do_move(int keycode, t_game *all);
void	fillmap(char *path, t_game *all);
void	floodfill(int x, int y, char **map);
void	free_new_map(char **maps, int y);
void	find_pos(t_game *all);
void	free_close(t_game *all, char *str);
void	free_map(t_game *all);
void	ft_checkmap(char *path, t_game *all);
void	init_game(t_game *all);
void	move_down(t_game *all);
void	move_up(t_game *all);
void	move_right(t_game *all);
void	move_left(t_game *all);
void	onlywalls(t_game *all);
void	put_assets(t_game *all);
void	swap_img(int keycode, t_game *all);
#endif