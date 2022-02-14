/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:09:03 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/14 14:52:40 by operculesan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse(t_data *img, char *arg)
{
	if(avance(img , arg) == 0)
	{
		write(1, "erreur dans le nom de la map", 28);
		return(0);
	}
	if (stock_map(img) == 0)
		return (0);
	return(1);
}

int	avance(t_data *img, char *arg)
{
	int i;

	i = 0;
	while(arg[i])
	{
		if(arg[i] == '.')
		{
			if (verif_ber(arg, i) == 0)
				return 0;
		}
		i++;
	}
	return 1;
}

int	verif_ber(char *arg, int i)
{
	int j;
	int f;

	f = 0;
	j = i;
	while(arg[i])
	{
		i++;
		f++;
	}
	if(f > 4)
		return 0;
	if (arg[++j] != 'b')
		return 0;
	if (arg[++j] != 'e')
		return 0;
	if (arg[++j] != 'r')
		return 0;
	return(1);
}

int	verif_item(char **str, t_data *img)
{
	int i;
	int y;
	
	i = 0;
	y = 0;
	img->fake = 0;
	img->c = 0;
	img->e = 0;
	img->p_c = 0;
	while (i < img->nombredeligne)
	{
		while(str[i][y] != '\n' && str[i][y])
		{
			if (str[i][y] == 'C')
				img->c++;
			if (str[i][y] == 'E')
				img->e++;
			if (str[i][y] == 'P')
			{
				img->fake++;
				img->p_l = i;
				img->p_c = y;
			}
			y++;
		}
		y = 0;
		i++;
	}
	if (img->c == 0 || img->e == 0 || img->fake == 0)
	{
		printf("Erreur manque un ou plusieur caractéres\n");
		return(0);
	}
	return(1);
}
