/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:06:56 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/16 16:08:02 by kevyn            ###   ########.fr       */
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