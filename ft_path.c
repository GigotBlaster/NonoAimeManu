/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <npetitpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:04:50 by npetitpi          #+#    #+#             */
/*   Updated: 2023/01/25 18:34:51 by npetitpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	recursive(char **map, int y, int x, int *dest)
{
	map[y][x] = '1';
	if (y == dest[0] && x == dest[1])
		return (1);
	if (map[y][x - 1] != '1')
		if (recursive(map, y, x - 1, dest))
			return (1);
	if (map[y - 1][x] != '1')
		if (recursive(map, y - 1, x, dest))
			return (1);
	if (map[y][x + 1] != '1')
		if (recursive(map, y, x + 1, dest))
			return (1);
	if (map[y + 1][x] != '1')
		if (recursive(map, y + 1, x, dest))
			return (1);
	return (0);
}

char	**create_map_tmp(t_data *game)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (i < game->map.height)
	{
		tmp[i] = ft_strdup(game->map.map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	free_map_tmp(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	is_map_possible_shorten(t_data *data, int *dest, int y, int x)
{
	char	**map_tmp;

	map_tmp = create_map_tmp(data);
	dest[0] = y;
	dest[1] = x;
	if (!recursive(map_tmp, data->p_pos.y, data->p_pos.x, dest))
		return (free(dest), free_map_tmp(map_tmp), 0);
	free_map_tmp(map_tmp);
	return (1);
}


int	recursive2(char **map, int y, int x, int *dest)
{
	map[y][x] = '1';
	if (y == dest[0] && x == dest[1])
		return (1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E')
		if (recursive2(map, y, x - 1, dest))
			return (1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E')
		if (recursive2(map, y - 1, x, dest))
			return (1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E')
		if (recursive2(map, y, x + 1, dest))
			return (1);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E')
		if (recursive2(map, y + 1, x, dest))
			return (1);
	return (0);
}

int	is_map_possible_shorten2(t_data *data, int *dest, int y, int x)
{
	char	**map_tmp;

	map_tmp = create_map_tmp(data);
	dest[0] = y;
	dest[1] = x;
	if (!recursive2(map_tmp, data->p_pos.y, data->p_pos.x, dest))
		return (free(dest), free_map_tmp(map_tmp), 0);
	free_map_tmp(map_tmp);
	return (1);
}

int	is_map_possible(t_data *data)
{
	int		y;
	int		x;
	int		*dest;

	y = 0;
	dest = ft_calloc(2, sizeof(int));
	if (!dest)
		return (0);
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.map[y][x] == 'C')
			{
				if (!is_map_possible_shorten2(data, dest, y, x))
					return (0);
			}
			if (data->map.map[y][x] == 'E')
			{
				if (!is_map_possible_shorten(data, dest, y, x))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (free(dest), 1);
}

