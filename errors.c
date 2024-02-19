#include "libpushswap.h"

//no se
void	free_matriz(char **arg)
{
	int	x;

	i = -1;
	if (NULL == arg || NULL == *arg)
		return ;
	while (arg[i])
		free(arg[i++]);
	free(arg - 1);
}

// no se
void	free_tlist(t_list **stacka)
{
	t_list	*tmp;
	t_list	*current;

	if (NULL == stacka)
		return ;
	current = *stacka;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stacka = NULL;
}

// para imprimir mensaje de error y limpiar la memoria 
void	error_free(t_list **a, char **argv, bool flag_argc_2)
{
	free_tlist(a);
	if (flag_argc_2)
		free_matriz(argv);
	write(2, "Error\n", 6);
	exit(1);
}

// compruebo que no haya errores en la sintaxis del argv. es decir al
// escribir el argumentos desde la terminal. Si hay error, envio a la funcion free
//para que la memoria se limpie.  y muestre un mensaje de error.
int	error_syntax(char *argv_nb)
{
	if (!(*argv_nb == '+' 
				|| *argv_nb == '-'
				|| (*argv_nb >= '0' && *argv_nb <= '9')))
		return (1);
	if ((*argv_nb == '+'
				|| *argv_nb == '-')
				&& !(argv_nb[1] >= '0' && argv_nb[1] <= '9'))
		return (1);
	while (*++argv_nb)
	{
		if (!(*argv_nb >= '0' && *argv_nb <= '9'))
			return (1);
	}
	return (0);
}

// comprobar que cuando se pasen los argumentos no se repita ningun valor
int	error_rep(t_list *a, int nbr)
{
	if (a == NULL)
		return (NULL);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
