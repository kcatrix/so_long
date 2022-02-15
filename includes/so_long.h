#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../lib/GNL/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		nombredeligne;
	int		nombredecarct;
	int		ligne_win;
	int		col_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		p_l;
	int		p_c;
	int		e;
	int		c;
	int 	taille_img;
	int		fake;
	char	**map;
}				t_data;

int		main(int argc, char **argv);
int		parse(t_data *img, char *arg);
int		avance(t_data *img, char *arg);
int		verif_ber(char *arg, int i);
int		stock_map(t_data *img);
int		verif_wall(char **str, t_data *img);
int		verif_ligne_first(char **str, t_data *img);
int		verif_ligne_last(char **str, t_data *img);
int		verif_nbcaract(char **str, t_data *img);
int		verif_item(char **str, t_data *img);
void    stock_map_s(char **str, t_data *img);
void	affiche_wall(t_data *img);
void	create_windows(t_data *img);

#endif
