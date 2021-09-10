/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:24:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/09 23:52:42 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	move_left(t_game *game)
{
	char	*ptr;

	ptr = ft_strchr(game->map, 'P');
	if (*--ptr != '1' && *ptr != 'E')
	{
		*++ptr = '0';
		*--ptr = 'P';
		game->player_side = 0;
		game->numb_move += 1;
		ft_putnbr_fd(game->numb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (game->exit_is_free == 1 && *ptr == 'E')
		end_game(game);
}

void	move_right(t_game *game)
{
	char	*ptr;

	ptr = ft_strchr(game->map, 'P');
	if (*++ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		*--ptr = '0';
		game->player_side = 1;
		game->numb_move += 1;
		ft_putnbr_fd(game->numb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (game->exit_is_free == 1 && *ptr == 'E')
		end_game(game);
}

void	move_up(t_game *game)
{
	char	*ptr;
	int		i;

	i = -1;
	ptr = ft_strchr(game->map, 'P');
	while (++i < game->total_line)
		--ptr;
	if (*ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		while (--i >= 0)
			++ptr;
		*ptr = '0';
		game->numb_move += 1;
		ft_putnbr_fd(game->numb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (game->exit_is_free == 1 && *ptr == 'E')
		end_game(game);
}

void	move_down(t_game *game)
{
	char	*ptr;
	int		i;

	i = -1;
	ptr = ft_strchr(game->map, 'P');
	while (++i < game->total_line)
		++ptr;
	if (*ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		ptr = ft_strchr(game->map, 'P');
		*ptr = '0';
		game->numb_move += 1;
		ft_putnbr_fd(game->numb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (game->exit_is_free == 1 && *ptr == 'E')
		end_game(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		end_game(game);
	else if (keycode == 'a')
		move_left(game);
	else if (keycode == 'd')
		move_right(game);
	else if (keycode == 's')
		move_down(game);
	else if (keycode == 'w')
		move_up(game);
	if (ft_strchr(game->map, 'C') == NULL)
		game->exit_is_free = 1;
	draw_map(game);
	return (1);
}
