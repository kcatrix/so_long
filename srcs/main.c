/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:58:37 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/21 17:38:10 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	ciao(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

int	deal_key(int key, t_data *img)
{
	if (key == 53)
		exit('exit');
	if (key == 13)
		up(img);
	if (key == 1)
		down(img);
	if (key == 0)
		left(img);
	if (key == 2)
		right(img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;
	int		i;

	i = 0;
	img.compteur = 0;
	if (argc != 2)
		return (0);
	if (parse(&img, argv[1]) == 0)
		exit (1);
	img.fake = 0;
	create_windows(&img);
	mlx_key_hook(img.mlx_win, deal_key, &img);
	mlx_hook(img.mlx_win, 17, 1L<< 0, ciao, &img);
	mlx_loop(img.mlx);
}
