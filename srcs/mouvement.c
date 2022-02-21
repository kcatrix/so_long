/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:31:57 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/21 16:12:02 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	up(t_data *img)
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
	img->compteur++;
	printf("%d\n", img->compteur);
	return(1);	
}

int	down(t_data *img)
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
	img->compteur++;
	printf("%d\n", img->compteur);
	return(1);
}

int	left(t_data *img)
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
	img->compteur++;
	printf("%d\n", img->compteur);
	return(1);
}

int right(t_data *img)
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
	img->compteur++;
	printf("%d\n", img->compteur);
	return(1);
}