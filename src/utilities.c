/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:59:03 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/14 07:20:18 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;
	
	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		exit_error();
	if (!(fdf->mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		exit_error();
	if (!(fdf->mlx->img_data = (t_img *)ft_memalloc(sizeof(t_img))))
		exit_error();
	if (!(fdf->bres = (t_line *)ft_memalloc(sizeof(t_line))))
		exit_error();
	return(fdf);
}

void	validate_input(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+' && s[i] != ',' && s[i] != 'x' && !(s[i] >= 'A' && s[i] <= 'F'))
			exit_error();
}

void	exit_error(void)
{
	write(1,ERROR_MESSAGE, 18);
	exit(EXIT_FAILURE);
}

void	print_grid(t_map *map)
{
	size_t	x;

	x = -1;
	printf("Points: %zu, Height: %zu, Width: %zu, Depth: %zu, Min_z: %d, Max_z: %d", map->points, map->height, map->width, map->depth, map->min_z, map->max_z);
	// while (++x < map->points)
	// {
	// 	if (x % map->width == 0)
	// 		printf("\n");
	// 	printf("{y: %zu, x: %zu, z: %d, w: %d, c: %d}", map->grid[x].y, map->grid[x].x, map->grid[x].z, map->grid[x].w, map->grid[x].c);
	// }
	printf("\n");
}
