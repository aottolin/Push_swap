#include "libpushswap.h"

void	little_sort(t_list **a)
{
	t_list	*highestnode;

	highest_node = find_highest_node(*a)
	if (*a == highest_node)
		ra(a, false);
	else if ((a*)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	five_nodes(t_list **a, t_list **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
	}


}

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
			b->target_node 

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

void	init_nodes(t_list *a, t_list *b)
{
	set_posicion_actual(a);
	set_posicion_actual(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
