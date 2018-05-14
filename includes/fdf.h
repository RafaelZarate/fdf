/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:31:22 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/14 07:52:47 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "../src/libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <limits.h>

/*
**	MACROS
*/

# define ABS(N) ((N<0)?(-N):(N))
# define ERROR_MESSAGE "An error ocurred."
// Small screen
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
// Full screen
// # define WIN_WIDTH 2560
// # define WIN_HEIGHT	1440
# define WIN_NAME "My fdf"

# define BPP fdf->mlx->img_data->bits_per_pixel
# define SL fdf->mlx->img_data->size_line
# define ENDIAN fdf->mlx->img_data->endian

/*
**	STRUCTURES
*/

typedef	struct			s_line
{
	int32_t				x1;
	int32_t				y1;
	int32_t				x2;
	int32_t				y2;
	uint32_t			dx;
	uint32_t			dy;
	uint32_t			da;
	int32_t				j;
	int32_t				i1;
	int32_t				i2;
	int32_t				e;
	int32_t				c1;
	int32_t				c2;
	int32_t				gradient;
}						t_line;

typedef	struct			s_point
{
	size_t				x;
	size_t				y;
	int32_t				z;
	int32_t				w;
	int32_t				c;
}						t_point;

typedef struct			s_node
{
	char				*s;
	struct s_node		*next;
}						t_node;

typedef struct			s_queue
{
	t_node				*first;
	t_node				*last;
	int					count;
}						t_queue;

typedef struct	s_map
{
	t_point				*grid;
	size_t				width;
	size_t				height;
	size_t				points;
	size_t				depth;
	int32_t				min_z;
	int32_t				max_z;
}						t_map;

typedef struct			s_keys
{
	int					keys;
}						t_keys;

typedef struct			s_img
{
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	void				*img;
	t_img				*img_data;
	int					*returned_img;
}						t_mlx;

typedef struct			s_fdf
{
	t_map				*map;
	t_mlx				*mlx;
	t_line				*bres;
}						t_fdf;

/*
**	FUNCTIONS
*/

t_queue					*parser(char *name_file);
t_map					*generate_map(t_queue *input);
void					generate_image(t_fdf *fdf);
int						general_exit(t_fdf *fdf);


t_fdf					*init_fdf(void);
void					validate_input(char *s);
void					exit_error(void);
void					print_grid(t_map *map);


t_queue					*init_queue(void);
void					enqueue(t_queue *queue, char *content);
char					*dequeue(t_queue *queue);
char					*peek_queue(t_queue *queue);


#endif