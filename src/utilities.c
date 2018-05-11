/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:59:03 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/11 05:28:03 by rzarate          ###   ########.fr       */
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
	fdf->mlx->ptr = mlx_init();
	fdf->mlx->win = mlx_new_window(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	fdf->mlx->img = mlx_new_image(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	return(fdf);
}

void	validate_input(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]) && s[i] != ' ' && s[i] != '-' && s[i] != '+')
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
	while (++x < map->points)
	{
		if (x % map->width == 0)
			printf("\n");
		printf("{y: %d, x: %d, z: %d, w: %d, c: %d}", map->grid[x].y, map->grid[x].x, map->grid[x].z, map->grid[x].w, map->grid[x].c);
	}
	printf("\n");
}
