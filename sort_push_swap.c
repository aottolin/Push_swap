#include "libpushswap.h"

static void	rotate_ambos(t_list **a,
						t_list **b,
						t_list *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b, false);
	set_posicion_actual(*a);
	set_posicion_actual(*b);
}

static void	reverse_rotate_ambos(t_list **a,
								t_list **b,
								t_list *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b, false);
	set_posicion_actual(*a);
	set_posicion_actual(*b);
}

void	stop_rotation(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->arriba_mitad)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->arriba_mitad)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->arriba_mitad
		&& cheapest_node->target_node->arriba_mitad)
		rotate_ambos(a, b, cheapest_node);
	else if (!(cheapest_node->arriba_mitad)
		&& !(cheapest_node->target_node->arriba_mitad))
		reverse_rotate_ambos(a, b, cheapest_node);
	stop_rotation(b, cheapest_node, 'b');
	stop_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_list **a, t_list **b)
{
	t_list	*small;
	int		len;

	len = stack_len(*a);
	if (len == 5)
		five_nodes(a, b);
	else
	{
		while (len-- > 3)
			pb(b, a, false);
	}
	little_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_posicion_actual(*a);
	small = find_smallest(*a);
	if (small->arriba_mitad)
		while (*a != small)
			ra(a, false);
	else
		while (*a != small)
			rra(a, false);
}
