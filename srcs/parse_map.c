/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:15:40 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/10 11:38:27 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	stock_map(t_data *img)
{
	int fd;
	int i;
	int j;
	char **str;
	char *s;
	
	i = 0;
	
	fd = open("map/map.ber", O_RDONLY);
	while (get_next_line(fd, &s))
		i++;
	img->nombredeligne = i;
	close(fd);
	str = malloc(sizeof(char *) * i);
	j = 0;
	fd = open("map/map.ber", O_RDONLY);
	while(j < i)
	{
		str[j] = get_next_line(fd, &str[j]);
		j++;
	}
	j = 0;
	if (verif_ligne(str, img) == 0)
		return(0);
	return (1);
}

int	verif_ligne(char **str, t_data *img)
{
	int i;
	
	i = 0;
	while (i < img->nombredeligne)
		printf("%s", str[i++]);
	i = 0;
	while(str[0][i] != '\n' && str[0][i])
	{
		if (str[0][i] != '1')
		{
			printf(" erreur sur la ligne 1");
			return(0);
		}
		i++;
	}
	return (1);
}