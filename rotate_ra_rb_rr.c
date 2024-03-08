#include "libpushswap.h"
/*
 * Top node to bottom position
*/

static void	rotate(t_list **stack)
{
	t_list	*lastnode;
	int		len;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	lastnode = find_lastnode(*stack);
	lastnode->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	lastnode->next->prev = lastnode;
	lastnode->next->next = NULL;
}

void	ra(t_list **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
