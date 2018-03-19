/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:58:16 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/19 12:40:40 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	char	**parser(char *file)
{
	int		fd;
	int		x;
	char	*line;
	char	*unparsed_input;
	char	**input;
	int		i;

	i = -1;
	fd = open(file, O_RDONLY);
	unparsed_input = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		x = ft_strlen(line);
		unparsed_input = ft_strjoin(unparsed_input, line);
	}
	
	while (unparsed_input[++i])
	{
		if (i % x == 0)
		{

		}
	}
	close(fd);
}

int	main(int ac, char **av)
{
	int		x;
	int		y;
	char	**input;

	if (ac == 2)
	{
		input = parser(av[1], &input);
	}
	else
		ft_putstr("Usage: blah blah blah");
	return (0);
}