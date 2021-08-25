#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3
# define ESC 65307

/* image */
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

/* window */
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/* map checks */
typedef struct s_map
{
	int	lines;
	int correct_lines;
	int	col_max;
}				t_map;

/* player */
typedef struct s_player
{
	t_data	img;
	int		x;
	int		y;
	float	smooth_x;
	float	smooth_y;
	bool	is_found;
}				t_player;

/* collectables */
typedef struct s_collectible_elem
{
	int							pos_x;
	int							pos_y;
	bool						is_touched;
	struct s_collectible_elem	*next;
}				t_collectible_elem;

/* collectables list */
typedef struct s_collectible_list
{
	t_collectible_elem	*first;
	bool				is_empty;
	t_data				img;
}				t_collectible_list;

/* exits */
typedef struct s_exit_elem
{
	int					pos_x;
	int					pos_y;
	bool				is_touched;
	struct s_exit_elem	*next;
}				t_exit_elem;

/* exits list */
typedef struct s_exit_list
{
	t_data		img;
	t_exit_elem	*first;
	bool		is_empty;
}				t_exit_list;

typedef struct s_v
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	an;
}				t_v;

/* position return */
typedef struct s_draw
{
	int		x;
	int		y;
	float	r_x;
	float	r_y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;
}				t_draw;

/* aux reference */
typedef struct s_mem
{
	t_player			*p;
	t_collectible_list	*c;
	t_exit_list			*e;
	t_data				*data;
	t_data				*floor;
	t_data				*bottom;
	t_vars				*vars;
	t_map				*map;
	char				**map2d;
	int					moves;
	unsigned int		frame;
}	

#endif