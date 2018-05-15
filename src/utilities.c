/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:59:03 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/14 17:22:14 by rzarate          ###   ########.fr       */
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

void	print_grid(t_fdf *fdf)
{
	size_t	x;

	x = -1;
	fprintf(fdf->fp, "Points: %zu, Height: %zu, Width: %zu, Depth: %zu, Min_z: %d, Max_z: %d", fdf->map->points, fdf->map->height, fdf->map->width, fdf->map->depth, fdf->map->min_z, fdf->map->max_z);
	while (++x < fdf->map->points)
	{
		if (x % fdf->map->width == 0)
			fprintf(fdf->fp, "\n");
		fprintf(fdf->fp, "{y: %zu, x: %zu, z: %d, w: %d, c: %d} ", fdf->map->grid[x].y, fdf->map->grid[x].x, fdf->map->grid[x].z, fdf->map->grid[x].w, fdf->map->grid[x].c);
	}
	fprintf(fdf->fp, "\n\n\n\n");
}
