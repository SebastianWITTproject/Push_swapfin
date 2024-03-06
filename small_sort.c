/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: switt <switt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:02:23 by switt             #+#    #+#             */
/*   Updated: 2023/08/07 20:09:45 by switt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest(t_stack **stack)
{
	int		highest;
	t_stack	*tmp;
	t_stack	*highest_node;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	highest = INT_MIN;
	while (tmp)
	{
		if (tmp->value > highest)
		{
			highest = tmp->value;
			highest_node = tmp;
		}
		tmp = tmp->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack **stack)
{
	t_stack	*highest_node;

	if (is_sorted(*stack))
		return ;
	highest_node = find_highest(stack);
	if (*stack == highest_node)
		do_ra(stack);
	else if ((*stack)->next == highest_node)
		do_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		do_sa(stack);
}
