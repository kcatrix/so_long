/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:58:37 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/21 14:29:12 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	deal_key(int key, t_data *img)
{
	char	*relative_path = "/Users/kevyn/Desktop/so_long/img/WALL.xpm";
	if(key == 53)
		exit('exit');
	if(key == 13)
	{
		if (img->map[img->p_l - 1][img->p_c] == '1')
			return (0);
		if (img->map[img->p_l - 1][img->p_c] == 'C')
			img->c--;
		if (img->map[img->p_l - 1][img->p_c] == 'E' && img->c == 0)
			exit('exit');
		if (img->map[img->p_l - 1][img->p_c] == 'E' && img->c > 0)
			return (0);
		mlx_clear_window(img->mlx, img->mlx_win);
		img->map[img->p_l][img->p_c] = '0';
		img->map[img->p_l - 1][img->p_c] = 'P';
		img->p_l--;
		create_windows(img);
	}
	if(key == 1)
	{
		if (img->map[img->p_l + 1][img->p_c] == '1')
			return (0);
		if (img->map[img->p_l + 1][img->p_c] == 'C')
			img->c--;
		if (img->map[img->p_l + 1][img->p_c] == 'E' && img->c == 0)
			exit('exit');
		if (img->map[img->p_l + 1][img->p_c] == 'E' && img->c > 0)
			return (0);
		mlx_clear_window(img->mlx, img->mlx_win);
		img->map[img->p_l][img->p_c] = '0';
		img->map[img->p_l + 1][img->p_c] = 'P';
		img->p_l++;
		create_windows(img);
	}
	if(key == 0)
	{
		if (img->map[img->p_l][img->p_c - 1] == '1')
			return (0);
		if (img->map[img->p_l][img->p_c - 1] == 'C')
			img->c--;
		if (img->map[img->p_l][img->p_c - 1] == 'E' && img->c == 0)
			exit('exit');
		if (img->map[img->p_l][img->p_c - 1] == 'E' && img->c > 0)
			return (0);
		mlx_clear_window(img->mlx, img->mlx_win);
		img->map[img->p_l][img->p_c] = '0';
		img->map[img->p_l][img->p_c - 1] = 'P';
		img->p_c--;
		create_windows(img);
	}
	if(key == 2)
	{
		if (img->map[img->p_l][img->p_c + 1] == '1')
			return (0);
		if (img->map[img->p_l][img->p_c + 1] == 'C')
			img->c--;
		if (img->map[img->p_l][img->p_c + 1] == 'E' && img->c == 0)
			exit('exit');
		if (img->map[img->p_l][img->p_c + 1] == 'E' && img->c > 0)
			return (0);
		mlx_clear_window(img->mlx, img->mlx_win);
		img->map[img->p_l][img->p_c] = '0';
		img->map[img->p_l][img->p_c + 1] = 'P';
		img->p_c++;
		create_windows(img);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;
	int i;
	
	i = 0;
	if (argc != 2)
		return (0);
	parse(&img, argv[1]);
	img.fake = 0;
	create_windows(&img);
	//img.map[img.p_l][img.p_c + 32] = 'P';
	//create_windows(&img);
	//mlx_loop_hook(img.mlx, render_next_frame(&img), &img);
	mlx_key_hook(img.mlx_win, deal_key, &img);
	mlx_loop(img.mlx);
}
