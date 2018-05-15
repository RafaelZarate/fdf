/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:50:32 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/14 22:13:58 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	draw_line(t_fdf *fdf)
// {
// 	t_line	*bres;
// 	int 	*img;

// 	bres = fdf->bres;
// 	img = fdf->mlx->returned_img;
// 	bres->dx = (uint32_t)ABS(bres->x2 - bres->x1);
// 	bres->dy = (uint32_t)ABS(bres->y2 - bres->y1);
// 	bres->i1 = ABS(bres->x1);
// 	bres->i2 = ABS(bres->x2);
// 	bres->e = ABS((bres->dy * (1 - (bres->x1 - bres->i1))) - (bres->dx *(1 - (bres->y1 - bres->j))));
// 	bres->j = bres->y1;
// 	bres->i = bres->x1;
// 	while (bres->i < bres->i2 - 1)
// 	{
// 		// img[(SL * 2) + bres->x1 * 15 + 30 + (bres->y1 * SL * 2)] = 0x00ff00;
// 		img[bres->i * 15 + 30 + (bres->j * SL * 2)] = 0x00ff00;
// 		if (bres->e >= 0)
// 		{
// 			bres->j++;
// 			bres->e -= bres->dx;
// 		}
// 		bres->i++;
// 		bres->e += bres->dy;
// 	}
// }

void	set_x_and_y(t_line *bres, t_point a, t_point b, t_map *map, t_fdf *fdf)
{
	fprintf(fdf->fp, "SET_X_AND_Y: \na.x: %zu, a.y: %zu, b.x: %zu, b.y: %zu\nx1: %zu, y1: %zu, x2: %zu, y2: %zu\n", a.x, a.y, b.x, b.y, bres->x1, bres->y1, bres->x2, bres->y2);
	bres->x1 = a.x;
	bres->y1 = a.y;
	bres->x2 = b.x;
	bres->y2 = b.y;
	bres->c1 = a.z / map->depth;
	bres->c2 = b.z / map->depth;
	fprintf(fdf->fp, "SET_X_AND_Y: \na.x: %zu, a.y: %zu, b.x: %zu, b.y: %zu\nx1: %zu, y1: %zu, x2: %zu, y2: %zu\n", a.x, a.y, b.x, b.y, bres->x1, bres->y1, bres->x2, bres->y2);
}

void	draw_line_horizontal(t_fdf *fdf, int i, int i2)
{
	t_line	*bres;
	int 	*img;

	set_x_and_y(fdf->bres, fdf->map->grid[i], fdf->map->grid[i2], fdf->map, fdf);
	bres = fdf->bres;
	img = fdf->mlx->returned_img;
	bres->dx = (uint32_t)ABS(bres->x2 - bres->x1);
	bres->dy = (uint32_t)ABS(bres->y2 - bres->y1);
	bres->i1 = bres->x1;
	bres->i2 = bres->x2;
	bres->e = ABS((bres->dy * (1 - (bres->x1 - bres->i1))) - (bres->dx *(1 - (bres->y1 - bres->j))));
	while (bres->i1 < bres->i2)
	{
		fprintf(fdf->fp, "i1: %zu, i2: %zu, y1: %zu, e: %d, dx: %d, dy: %d\n", bres->i1, bres->i2, bres->y1, bres->e, bres->dx, bres->dy);
		img[(SL * 2) + bres->i1 + 30 + (bres->y1 * SL / 4)] = 0xffff00;
		if (bres->e >= 0)
		{
			// bres->y1++;
			bres->e -= bres->dx;
		}
		bres->i1++;
		bres->e += bres->dy;
	}
}

void	draw_line_vertical(t_fdf *fdf, int i, int i2)
{
	t_line	*bres;
	int 	*img;

	set_x_and_y(fdf->bres, fdf->map->grid[i], fdf->map->grid[i2], fdf->map, fdf);
	bres = fdf->bres;
	img = fdf->mlx->returned_img;
	bres->dx = (uint32_t)ABS(bres->x2 - bres->x1);
	bres->dy = (uint32_t)ABS(bres->y2 - bres->y1);
	bres->i1 = bres->y1;
	bres->i2 = bres->y2;
	bres->e = ABS((bres->dy * (1 - (bres->x1 - bres->i1))) - (bres->dx *(1 - (bres->y1 - bres->j))));
	while (bres->i1 < bres->i2)
	{
		fprintf(fdf->fp, "i1: %zu, i2: %zu, x1: %zu, e: %d, dx: %d, dy: %d\n", bres->i1, bres->i2, bres->x1, bres->e, bres->dx, bres->dy);
		// fprintf(fdf->fp, "index: %d\n", (SL * 2) + 30 + bres->x1 + (bres->i1 * SL / 4));
		img[(SL * 2) + 30 + bres->x1 + (bres->i1 * SL / 4)] = 0xffff00;
		if (bres->e >= 0)
		{
			// bres->x1++;
			bres->e += bres->dy;
		}
		bres->i1++;
		bres->e -= bres->dx;
	}
}

void	draw_lines(t_fdf *fdf)
{
	size_t	i;

	i = -1;
	while (++i < fdf->map->points)
	{
		fprintf(fdf->fp, "i: %zu, x: %zu, y: %zu\n", i, fdf->map->grid[i].x, fdf->map->grid[i].y);
		write(1, "HEY\n", 4); // delete later
		if (fdf->map->grid[i].x < (fdf->map->width * SCALE_WIDTH) - (SCALE_WIDTH))
			draw_line_horizontal(fdf, i, i + 1);
		if (fdf->map->grid[i].y < ((fdf->map->height * SCALE_HEIGHT) - SCALE_HEIGHT))
		{
			write(1, "\n", 1);
			write(1, ft_itoa(i + fdf->map->width), 4);
			write(1, "\n", 1);
			draw_line_vertical(fdf, i, i + fdf->map->width);
		}
		write(1, "HEY2\n", 5); // delete later
	}
}

void	generate_image(t_fdf *fdf)
{
	fdf->mlx->ptr = mlx_init();
	fdf->mlx->win = mlx_new_window(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	fdf->mlx->img = mlx_new_image(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	fdf->mlx->returned_img = (int *)mlx_get_data_addr(fdf->mlx->img, &BPP, &SL, &ENDIAN);
	draw_lines(fdf);
	// int x = -1;
	// int y = -1;
	// while (++x < 1000)
	// {
	// 	while (++y < 500)
	// 		fdf->mlx->returned_img[x + (y * SL / 4)] = 0x123456;
	// 	y = -1;
	// }
}
