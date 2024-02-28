#include "libpushswap.h"

void	ra(t_list **a, t_list **b, bool checker)
{
	rotate(a, b);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, t_list **a, bool checker)
{
	rotate(b, a);
	if (!checker)
		write(1, "rb\n", 3);
}
