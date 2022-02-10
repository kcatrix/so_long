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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fake;
}				t_data;

int		main(int argc, char **argv);
int		parse(t_data *img, char *arg);
int		avance(t_data *img, char *arg);
int		verif_ber(char *arg, int i);
int		stock_map(t_data *img);
int		verif_ligne_first_last(char **str, t_data *img);

#endif
