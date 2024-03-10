#include "libpushswap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*lastnode;
	int		len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	lastnode = find_lastnode(*stack);
	lastnode->prev->next = NULL;
	lastnode->next = *stack;
	lastnode->prev = NULL;
	*stack = lastnode;
	lastnode->next->prev = lastnode;
}

void	rra(t_list **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
