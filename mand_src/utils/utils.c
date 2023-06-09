/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 03:50:21 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/03 02:55:34 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_msg(int status)
{
	write(2, "Error\n", 7);
	exit(status);
}

void	free_stacks(t_data *data)
{
	clear_node(&data->s_a->head);
	clear_node(&data->s_b->head);
	free(data->s_a);
	free(data->s_b);
	return ;
}

void	index_stack(t_node *head, int stk_size)
{
	t_node	*tmp;
	int		*arr;
	int		i;
	int		k;

	i = -1;
	arr = (int *)malloc(stk_size * sizeof(int));
	tmp = head;
	while (++i < stk_size)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
	}
	opt_bubble_sort(arr, stk_size);
	i = -1;
	k = 0;
	tmp = head;
	__assign_idx(head, arr, stk_size);
	free(arr);
	return ;
}

void	current_index_instack(t_node *head, int n)
{
	t_node	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (i < n)
	{
		tmp->cur_idx = 0;
		tmp->cur_idx = i;
		i++;
		tmp = tmp->next;
	}
	return ;
}

bool	if_sorted_stop(t_node *head, int n)
{
	t_node	*node;
	int		i;

	i = n;
	node = head;
	while (i-- > 0)
	{
		if (node->next && (node->data < node->next->data))
			node = node->next;
		else
			break ;
	}
	if (i == 0)
		return (1);
	return (0);
}
