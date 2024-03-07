#include "libpushswap.h"

static void	swap(t_list **stack)
{
	t_list	*swap;
	int	len;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	swap = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    (*stack)->next->prev = swap;
    swap->next = (*stack)->next;
    (*stack)->next = swap;
    swap->prev = *stack;	
}

void	sa(t_list **a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
