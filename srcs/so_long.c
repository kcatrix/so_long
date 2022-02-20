/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:45:10 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/16 17:30:02 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_windows(t_data *img)
{
	img->ligne_win = img->nombredeligne * 32;
	img->col_win = img->nombredecarct * 32;
	if (img->fake == 0)
		img->mlx = mlx_init();
	if (img->fake == 0)
	{
		img->mlx_win = mlx_new_window(img->mlx, img->col_win,
				img->ligne_win, "Hello world!");
	}
	img->taille_img = 32;
	//affiche_back(img);
	img->z = 0;
	affiche_wall(img);
	img->z = 0;
	affiche_caractere(img);
	img->z = 0;
	affiche_item(img);
	img->z = 0;
	affiche_exit(img);
	img->fake++;
}

void	affiche_wall(t_data *img)
{
	int		i;
	int		y;

	img->relative_path = "/Users/kevyn/Desktop/so_long/img/WALL.xpm";
	i = 0;
	y = 0;
	while (i < img->nombredeligne)
	{
		while (img->map[i][y] != '\n' && img->map[i][y])
		{
			if (img->map[i][y] == '1')	
				push_destroy(img);
			img->x += 32;
			y++;
		}
		img->x = 0;
		y = 0;
		img->z += 32;
		i++;
	}
}

void	affiche_caractere(t_data *img)
{
	int		i;
	int		y;

	img->relative_path = "/Users/kevyn/Desktop/so_long/img/caractere.xpm";
	i = 0;
	y = 0;
	while (i < img->nombredeligne)
	{
		while (img->map[i][y] != '\n' && img->map[i][y])
		{
			if (img->map[i][y] == 'P')
				push_destroy(img);
			img->x += 32;
			y++;
		}
		img->x = 0;
		y = 0;
		img->z += 32;
		i++;
	}
}

void	affiche_item(t_data *img)
{
	int		i;
	int		y;

	img->relative_path = "/Users/kevyn/Desktop/so_long/img/item.xpm";
	i = 0;
	y = 0;
	while (i < img->nombredeligne)
	{
		while (img->map[i][y] != '\n' && img->map[i][y])
		{
			if (img->map[i][y] == 'C')
				push_destroy(img);
			img->x += 32;
			y++;
		}
		img->x = 0;
		y = 0;
		img->z += 32;
		i++;
	}
}

void	affiche_exit(t_data *img)
{
	int		i;
	int		y;

	img->relative_path = "/Users/kevyn/Desktop/so_long/img/Exit.xpm";
	i = 0;
	y = 0;
	while (i < img->nombredeligne)
	{
		while (img->map[i][y] != '\n' && img->map[i][y])
		{
			if (img->map[i][y] == 'E')
				push_destroy(img);
			img->x += 32;
			y++;
		}
		img->x = 0;
		y = 0;
		img->z += 32;
		i++;
	}
}
