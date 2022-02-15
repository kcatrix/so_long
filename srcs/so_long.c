/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:45:10 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/15 12:03:54 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_windows(t_data *img)
{
	img->ligne_win = img->nombredeligne * 16;
	img->col_win = img->nombredecarct * 16;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->col_win, img->ligne_win, "Hello world!");
}