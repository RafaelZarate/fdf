/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:45:22 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/11 05:53:20 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define CURRENT_INDEX (map->width*n)+j

t_queue	*parser(char *name_file)
{
	int		fd;
	char	*line;
	t_queue	*input;

	input = init_queue();
	if ((fd = open(name_file, O_RDONLY)) == -1)
		exit_error();
	while (get_next_line(fd, &line) > 0)
	{
		input->count++;
		enqueue(input, ft_strdup(line));
		free(line);
	}
	close(fd);
	return (input);
}

void	get_points(char *line, t_map *map, size_t n)
{
	char	**numbers;
	int32_t	num;
	size_t	i;
	int		j;

	i = 0;
	j = -1;
	validate_input(line);
	numbers = ft_strsplit(line, ' ');
	while (numbers[i])
		i++;
	if (i != map->width)
		exit_error();
	while (numbers[++j])
	{
		num = ft_atoi(numbers[j]);
		map->grid[CURRENT_INDEX].x = j;
		map->grid[CURRENT_INDEX].y = n;
		map->grid[CURRENT_INDEX].z = num;
		(num < map->min_z) ? map->min_z = num : 0;
		(num > map->max_z) ? map->max_z = num : 0;
		ft_strdel(&numbers[j]);
	}
	free(numbers);
}

size_t	get_width(char *s)
{
	char	**numbers;
	size_t	i;

	i = 0;
	numbers = ft_strsplit(s, ' ');
	while (numbers[i])
	{
		ft_strdel(&numbers[i]);
		i++;
	}
	free(numbers);
	return (i);
}

void	create_grid(t_queue *input, t_map *map)
{
	char	*tmp;
	size_t	i;
	
	i = 0;
	map->width = get_width(peek_queue(input));
	map->points = map->width * map->height;
	map->grid = (t_point *)ft_memalloc(sizeof(t_point) * map->points);
	while (i++ < map->height)
	{
		tmp = dequeue(input);
		get_points(tmp, map, i);
		ft_strdel(&tmp);
	}
	free(input);
}

t_map	*generate_map(t_queue *input)
{
	t_map	*map;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit_error();
	map->height = input->count;
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	create_grid(input, map);
	map->depth = ABS(map->max_z - map->min_z);
	return (map);
}
