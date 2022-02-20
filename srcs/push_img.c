/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:06:56 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/16 16:48:05 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	push_destroy(t_data *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx,
		img->relative_path, &img->size_img, &img->size_img);
	mlx_put_image_to_window(img->mlx,
		img->mlx_win, img->img, img->x, img->z);
	mlx_destroy_image(img->mlx, img->img);
}

void	affiche_back(t_data *img)
{
	int		i;
	int		y;

	img->relative_path = "/Users/kevyn/Desktop/so_long/img/back.xpm";
	i = 0;
	y = 0;
	while (i < img->nombredeligne)
	{
		while (img->map[i][y] != '\n' && img->map[i][y])
		{
			if (img->map[i][y] == '0')	
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