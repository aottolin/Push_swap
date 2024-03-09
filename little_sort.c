#include "libpushswap.h"

bool	stack_sorted(t_list *stack)
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

static t_list	*find_highest_node(t_list *st)
{
	t_list	*highest_node;
	int		high;

	if (st == NULL)
		return (NULL);
	high = INT_MIN;
	while (st)
	{
		if (st->value > high)
		{
			high = st->value;
			highest_node = st;
		}
		st = st->next;
	}
	return (highest_node);
}

t_list	*find_smallest(t_list *stack)
{
	t_list	*small;
	long	smallest;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			small = stack;
		}
		stack = stack->next;
	}
	return (small);
}

void	little_sort(t_list **a)
{
	t_list	*highest_node;

	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	five_nodes(t_list **a, t_list **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		stop_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
