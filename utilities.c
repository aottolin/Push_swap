#include "libpushswap.h"

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

int	stack_len(t_list *stack)
{
	int	len;

	len = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);

}

t_list	*find_lastnode(t_list *st_a)
{
	if (st_a == NULL)
		return (NULL);
	while (st_a->next)
		st_a = st_a->next;
	return (st_a);
}

static t_list	*find_highest_node(t_list *st)
{
	t_list	*highest_node;
	int		high;

	high = INT_MIN;
	if (st == NULL)
		return (NULL);
	while (st)
	{
		if (st->value > high)
		{
			high = st->value;
			highest_node = st;
		}
		st = st->next;
	}
	return (highest_node)
}
