/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:45:10 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/16 12:05:49 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_windows(t_data *img)
{
	img->ligne_win = img->nombredeligne * 32;
	img->col_win = img->nombredecarct * 32;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->col_win,
			img->ligne_win, "Hello world!");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->taille_img = 32;
	affiche_wall(img);
	img->z = 0;
	affiche_caractere(img);
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
			{	
				img->img = mlx_xpm_file_to_image(img->mlx,
						img->relative_path, &img->size_img, &img->size_img);
				mlx_put_image_to_window(img->mlx,
					img->mlx_win, img->img, img->x, img->z);
			}
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
			{	
				img->img = mlx_xpm_file_to_image(img->mlx,
						img->relative_path, &img->size_img, &img->size_img);
				mlx_put_image_to_window(img->mlx,
					img->mlx_win, img->img, img->x, img->z);
			}
			img->x += 32;
			y++;
		}
		img->x = 0;
		y = 0;
		img->z += 32;
		i++;
	}
}
