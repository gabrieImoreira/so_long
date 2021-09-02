#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3
# define ESC 65307

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	t_img	*mlx_img;

}	t_mlx;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_game
{
	t_mlx	mlx;
	int		map_width;
	int		map_height;
	int		numb_move;
	t_img	*floor;
	t_img	*player;
	t_img	*collectible;
	t_img	*wall;
	t_img	*exit;
	char	*map;
	int		total_line_char;
	int		line_number;
	char	*player_position;
	int		nb_exit;
	int		numb;
	int		endline;
	int		fd;
	int		x;
	int		y;
}	t_game;	

void	check_args(int argc, char **argv);
void	check_map_elements(char *map_read);
void	check_walls(char *line);
void	errors(char *nature, char *whole_chars);
void	initializing_texture(t_game *game);
void	set_image(t_game *game, t_img **img, char *path);

#endif