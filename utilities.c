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
