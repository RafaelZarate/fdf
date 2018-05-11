/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:41:26 by rzarate           #+#    #+#             */
/*   Updated: 2018/05/10 18:48:07 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_queue		*init(void)
{
	t_queue	*new_queue;

	if (!(new_queue = ft_memalloc(sizeof(struct s_queue))))
		exit_error();
	new_queue->first = NULL;
	new_queue->last = NULL;
	return (new_queue);
}

void		enqueue(t_queue *queue, char *content)
{
	t_node	 *node;

	if (!(node = ft_memalloc(sizeof(t_node))))
		exit_error();
	node->s = content;
	node->next = NULL;
	if (!queue->first)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}	
}

char		*dequeue(t_queue *queue)
{
	t_node	*tmp_node;
	char	*tmp_s;

	if (!queue || !queue->first)
		return (NULL);
	else
	{
		tmp_node = queue->first;
		queue->first = queue->first->next;
		if (!queue->first)
			queue->last = NULL;
		tmp_s = tmp_node->s;
		free(tmp_node);
		return (tmp_s);
	}
}
