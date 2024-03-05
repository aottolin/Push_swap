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


}
