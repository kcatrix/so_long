/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:17:56 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/21 17:21:28 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../lib/GNL/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		nombredeligne;
	int		nombredecarct;
	int		ligne_win;
	int		col_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		p;
	int		p_l;
	int		p_c;
	int		p_l_save;
	int		p_c_save;
	int		e;
	int		c;
	int		taille_img;
	int		fake;
	int		size_img;
	int		x;
	int		z;
	int		compteur;
	char	*relative_path;
	char	**map;
	int		i;
	int 	y;
}				t_data;

int		main(int argc, char **argv);
int		parse(t_data *img, char *arg);
int		avance(t_data *img, char *arg);
int		verif_ber(char *arg, int i);
int		stock_map(t_data *img, char *arg);
int		verif_wall(char **str, t_data *img);
int		verif_ligne_first(char **str, t_data *img);
int		verif_ligne_last(char **str, t_data *img);
int		verif_nbcaract(char **str, t_data *img);
int		verif_item(char **str, t_data *img);
void	stock_map_s(char **str, t_data *img);
void	push_destroy(t_data *img);
void	affiche_back(t_data *img);
void	affiche_wall(t_data *img);
void	affiche_caractere(t_data *img);
void	affiche_item(t_data *img);
void	affiche_exit(t_data *img);
void	create_windows(t_data *img);
int		up(t_data *img);
int		down(t_data *img);
int		left(t_data *img);
int		right(t_data *img);
int		test_directory(int fd, char *arg);
int		stock_map2(int i, int fd, t_data *img);
int		verif_item2(t_data *img, char **str);
int		verif_item_3(t_data *img, char **str);

#endif
