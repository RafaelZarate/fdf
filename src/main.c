/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:58:16 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/14 17:19:53 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	general_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx->ptr, fdf->mlx->win);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_queue	*input;

	if (ac != 2)
		exit_error();
	fdf = init_fdf();
	fdf->fp = fopen(FILE_NAME, "w");
	input = parser(av[1]);
	fdf->map = generate_map(input);
	print_grid(fdf);
	generate_image(fdf);
	mlx_put_image_to_window(fdf->mlx->ptr, fdf->mlx->win, fdf->mlx->img, 0, 0);
	fclose(fdf->fp);
	mlx_hook(fdf->mlx->win, 17, 0, general_exit, fdf);
	mlx_loop(fdf->mlx->ptr);
	return (EXIT_SUCCESS);
}