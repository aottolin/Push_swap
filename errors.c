#include "libpushswap.h"

void	free_matriz(char **arg)
{
	int	i;

	i = -1;
	if (NULL == arg || NULL == *arg)
		return ;
	while (arg[i])
		free(arg[i++]);
	free(arg - 1);
}

void	free_tlist(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_list **a, char **argv, bool flag_argc_2)
{
	free_tlist(a);
	if (flag_argc_2)
		free_matriz(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *argv_nb)
{
	if (!(*argv_nb == '+' || *argv_nb == '-'
			|| (*argv_nb >= '0' && *argv_nb <= '9')))
		return (1);
	if ((*argv_nb == '+' || *argv_nb == '-')
		&& !(argv_nb[1] >= '0' && argv_nb[1] <= '9'))
		return (1);
	while (*++argv_nb)
	{
		if (!(*argv_nb >= '0' && *argv_nb <= '9'))
			return (1);
	}
	return (0);
}

int	error_rep(t_list *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
