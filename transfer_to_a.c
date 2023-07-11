/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:18:48 by ltalia            #+#    #+#             */
/*   Updated: 2022/03/27 20:18:50 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scoring_in_b(t_stack_elem *head_b)
{
	int	size;
	int	i;

	size = stack_size(head_b);
	i = 0;
	while (head_b)
	{
		head_b->b_score = i;
		head_b->b_rscore = size - i;
		i++;
		head_b = head_b->next;
	}
}

void	scoring_in_a(t_stack_elem *head_a, t_stack_elem *head_b)
{
	t_stack_elem	*save_point;
	int				size;
	int				i;
	int				prev;

	size = stack_size(head_a);
	save_point = head_a;
	while (head_b)
	{
		head_a = save_point;
		i = 0;
		prev = last_stack_elem(head_a)->value;
		while (head_a)
		{
			if (prev < head_b->value && head_a->value > head_b->value)
			{
				head_b->a_score = i;
				head_b->a_rscore = size - i;
			}
			i++;
			prev = head_a->value;
			head_a = head_a->next;
		}
		head_b = head_b->next;
	}
}

void	transfer_to_a(t_stack_elem **head_a, t_stack_elem **head_b)
{
	t_stack_elem	*best_rank_elem;
	int				transfer_type;

	scoring_in_b(*head_b);
	scoring_in_a(*head_a, *head_b);
	best_rank_elem = make_decision(*head_b, &transfer_type);
	process_decision(head_a, head_b, best_rank_elem, &transfer_type);
}
