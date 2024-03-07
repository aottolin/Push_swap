#include "libpushswap.h"

void	set_target_node(t_list *a, t_list *b)
{
	t_list	*actual_a;
	t_list	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		actual_a = a;
		while (actual_a)
		{
			if (actual_a->value > b->value && actual_a->value < best_match)
			{
				best_match = actual_a->value;
				target_node = actual_a;
			}
			actual_a = actual_a->next;
		}
		if (LONG_MAX == best_match)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_posicion_actual(t_list *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->posicion_actual = i;
		if (i <= centerline)
			stack->arriba_mitad = true;
		else
			stack->arriba_mitad = false;
		stack = stack->next;
		++i;
	}
}

void	set_costo(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_costo = b->posicion_actual;
		if (!(b->arriba_mitad))
			b->push_costo = len_b - (b->posicion_actual);
		if (b->target_node->arriba_mitad)
			b->push_costo += b->target_node->posicion_actual;
		else
			b->push_costo =+ len_a - (b->target_node->posicion_actual);
		b = b->next;
	}
}

void	set_cheapest(t_list *b)
{
	long	best_match;
	t_list	*best_match_node;

	if (b == NULL)
		return ;
	best_match = LONG_MAX;
	while (b)
	{
		if (b->push_costo < best_match)
		{
			best_match = b->push_costo;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	init_nodes(t_list *a, t_list *b)
{
	set_posicion_actual(a);
	set_posicion_actual(b);
	set_target_node(a, b);
	set_costo(a, b);
	set_cheapest(b);
}
