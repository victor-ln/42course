/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:18:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/20 15:50:16 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	load_game(game, check_input(argc, argv[argc - 1]));
	mlx_hook(game->screen, 17, 0L, close_window, game);
	mlx_key_hook(game->screen, key_press, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
}
