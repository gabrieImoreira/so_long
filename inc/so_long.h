#ifndef SO_LONG_H
# define SO_LONG_H
# include "./get_next_line.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define ESC 65307

enum e_player
{
	PLAYER_LEFT,
	PLAYER_RIGHT,
};

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	t_img	*mlx_img;

}	t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	char	*path[2];
	char	*map;
	int		map_width;
	int		map_height;
	int		numb_move;
	int		total_line;
	int		total_column;
	int		exit_is_free;
	int		player_side;
	int		aux_num;
	int		size_line;
	int		error;
	int		fd;
	int		x;
	int		y;
}	t_game;	

void	check_args(int argc, char **argv);
void	check_map_elements(char *map_read);
void 	check_errors(t_game *game, char *map_read);
void	check_walls(t_game *game, char *line);
void	errors(char *nature, char *whole_chars);
void	initializing_texture(t_game *game);
void	set_image(t_game *game, t_img **img, char *path);
int		create_trgb(int t, int r, int g, int b);
int		draw_map(t_game *game);
int		end_game(t_game *game);
int		key_hook(int keycode, t_game *game);

#endif