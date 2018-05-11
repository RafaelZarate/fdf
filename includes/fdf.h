/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:31:22 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/10 18:48:06 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "../src/libft/libft.h"
# include <math.h>
# include <fcntl.h>

/*
**	MACROS
*/

# define ERROR_MESSAGE "An error ocurred."


/*
**	STRUCTURES
*/

typedef struct			s_node
{
		char			*s;
		struct s_node	*next;
}						t_node;

typedef struct			s_queue
{
		t_node			*first;
		t_node			*last;
		int				count;
		int				length;
}						t_queue;

typedef struct	s_map
{
	int					**grid;
	size_t				width;
	size_t				height;
	intmax_t			depth;
	int					min_z;
	int					max_z;
}						t_map;

typedef struct			s_keys
{
	int					keys;
}						t_keys;

typedef struct			s_fdf
{
	t_map				*map;

}						t_fdf;

/*
**	FUNCTIONS
*/

t_queue		*parser(char *name_file);
t_map		*generate_map(t_queue *input);

t_fdf		*initialize_fdf(t_queue	*input);
void		exit_error(void);

t_queue		*init_queue(void);
void		enqueue(t_queue *queue, char *content);
char		*dequeue(t_queue *queue);;


#endif