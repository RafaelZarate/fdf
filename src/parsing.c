/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:45:22 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/10 22:21:53 by rzarate          ###   ########.fr       */
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
		else if (input->length != ft_strlen(line))
			exit_error();
		input->count++;
		enqueue(input, ft_strdup(line));
		free(line);
	}
	close(fd);
	return (input);
}

int		*get_integers(char *line)
{
	char	**numbers;
	int		*arr;
	int		i;

	i = -1;
	

}

int		**create_grid(t_queue *input, int *width)
{
	int		**grid;
	char	*tmp;
	int		i;
	
	if (!(grid = (int **)ft_memalloc(sizeof(int *) * input->count)))
		exit_error();
	while (++i < input->count)
	{
		grid[i] = (int *)ft_memalloc(sizeof(int) * input->length);
		tmp = dequeue(input);

		exit_error();
	}
}

t_map	*generate_map(t_queue *input)
{
	int		i;
	t_map	*map;
	
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		exit_error();
	
	map->height = input->count;
	map->grid = create_grid(input, &map->width);

}