/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:45:22 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/10 18:46:48 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_queue	*parser(char *name_file)
{
	int		fd;
	char	*line;
	t_queue	*input;

	input = init_queue();
	if ((fd = open(name_file, O_RDONLY) == -1))
		exit_error();
	while (get_next_line(fd, &line) > 0)
	{
		if (input->length == 0)
			input->length == ft_strlen(line);
		input->count++;
		enqueue(input, ft_strdup(line));
		free(line);
	}
	close(fd);
	return (input);
}

t_map	*generate_map(t_queue *input)
{
	int		i;
	t_map	*map;
	
	if (!(map->grid = (int **)ft_memalloc(sizeof(int *) * input->count)))
		exit_error(); 	
	while (++i < input->count)
	{
		map->grid[i] = (int *)ft_memalloc(sizeof(int) * input->length);
		exit_error();
	}
	map->
}