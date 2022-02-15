/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:45:10 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/15 15:13:33 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_windows(t_data *img)
{
	img->ligne_win = img->nombredeligne * 32;
	img->col_win = img->nombredecarct * 32;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->col_win, img->ligne_win, "Hello world!");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
		&img->endian);
	img->taille_img = 32;
	affiche_wall(img);
}

void	affiche_wall(t_data *img)
{
	int i;
	int x;
	int z;
	int y;
	int size;
	char *relative_path = "/Users/kcatrix/Desktop/so_long/img/WALL.xpm";

	i = 0;
	y = 0;
	x = 0;
	z = 0;
	size = 32;
	while(i < img->nombredeligne)
	{
		while(img->map[i][y] != '\n' && img->map[i][y])
		{
			printf("[i][y] = %c", img->map[i][y]);
			if (img->map[i][y] == '1')
			{
				printf(" (x = %d z = %d) \n", x, z);
				
				img->img = mlx_xpm_file_to_image(img->mlx, relative_path, &size, &size);
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, x, z);	
			}
			x += 32;
			y++;
		}
		x = 0;
		y = 0;
		z += 32;
		i++;
	}
}