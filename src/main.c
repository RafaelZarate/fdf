/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:58:16 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/19 12:55:53 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	char	*reader(char *file)
{
	int		fd;
	char	*line;
	char	*input;
	int		i;
	int		i2;

	i2 = -1;
	i = -1;
	fd = open(file, O_RDONLY);
	input = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
		input = ft_strjoin(input, line);
	close(fd);
	return (input);
}

int	main(int ac, char **av)
{
	char	*input;

	if (ac == 2)
	{
		input = reader(av[1]);
		ft_putstr(input);
	}
	else
		ft_putstr("Usage: blah blah blah");
	return (0);
}