#include "libpushswap.h"

bool	stack_sorted(t_list *stack);
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

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
