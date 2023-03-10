/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:34:53 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/24 18:27:55 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_winner(t_data *game)
{
	if (game->map.collectible == 0)
	{
		write(1, "Congratulations! You won!\n", 26);
		ft_clear_images(game);
		ft_free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

int	ft_key_press(int key, t_data *game)
{
	if (key == ESC)
	{
		ft_clear_images(game);
		ft_free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	else
		ft_move(key, game);
	return (0);
}

int	ft_press_x(t_data *game)
{
	ft_key_press(ESC, game);
	return (0);
}
