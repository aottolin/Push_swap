#include "libpushswap.h"

void	stack_init(t_list **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;
	int		len;

	i = 0;
	while (argv[i])
	{
		len = ft_strlen(argv[i]);
		if (argv[i][0] == '-')
			len--;
		if (len > 12)
			error_free(a, argv, flag_argc_2);
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_rep(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		add_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_matriz(argv);
}

long	ft_atol(char *str)
{
	int		x;
	int		signo;
	long	result;

	result = 0;
	signo = 1;
	x = 0;
	while ((str[x] == 32) || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			signo *= -1;
		x++;
	}
	while (str[x] && str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10 + str[x] - '0';
		x++;
	}
	return (result * signo);
}

void	add_node(t_list **st_a, int nbr)
{
	t_list	*node;
	t_list	*last_node;

	if (st_a == NULL)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*st_a == NULL)
	{
		*st_a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_lastnode(*st_a);
		last_node->next = node;
		node->prev = last_node;
	}
}
