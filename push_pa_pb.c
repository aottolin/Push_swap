#include "libpushswap.h"

static void	push(t_list **dest, t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	if (*dest == NULL)
	{
		*dest = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dest;
		tmp->next->prev  = tmp;
		*dest = tmp;
	}
}

void	pa(t_list **a, t_list **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
