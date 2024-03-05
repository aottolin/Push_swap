#ifndef LIBPUSHSWAP_H
#define LIBPUSHSWAP_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_list
{
	int				value;
	struct	s_list *target_node;
	struct	s_list *next;
	struct	s_list *prev;
}	t_list;

// Para tratar y dividir los argumentos:
int			ft_strlen(char *str);
char		**ft_split(char *str, char delim);
void		stack_init(t_list **a, char **argv, bool flag_argc_2);
long		ft_atol(char *str);
// Para comprobar errores de los argumentos y liberar memoria:
int			error_syntax(char *argv_nb);
void		free_matriz(char **arg);
void		error_free(t_list **a, char **argv, bool flag_argc_2);
int			error_rep(t_list *a, int nbr);
//  Utilies para stack y listas:
void		add_node(t_list **st_a, int nbr);
t_list	*find_lastnode(t_list *st_a);
static t_list	*find_highest_node(t_list *st);

// Para ordenar los stacks:
bool	stack_sorted(t_list *stack);
void	little_sort(t_list **a);
static void	swap(t_list **stack);
void	sa(t_list **a, bool checker);
void	sb(t_list **b, bool checker);
void	ss(t_list **a, t_list **b, bool checker);
static void	rotate(t_list **stack);
void	ra(t_list **a, bool checker);
void	rb(t_list **b, bool checker);
void	rr(t_list **a, t_list **b, bool checker);
static void	reverse_rotate(t_list **stack);
void	rra(t_list **a, bool checker);
void	rrb(t_list **b, bool checker);
void	rrr(t_list **a, t_list **b, bool checker);
static void	push(t_list **dest, t_list **stack);
void	pa(t_list **a, t_list **b, bool checker);
void	pb(t_list **b, t_list **a, bool checker);

#endif
