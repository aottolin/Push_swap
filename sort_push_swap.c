#include "libpushswap.h"

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


