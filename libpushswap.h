#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	int				value;
	int				posicion_actual;
	int				push_costo;
	bool			arriba_mitad;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

char			**ft_split(char *str, char delim);
int				error_syntax(char *argv_nb);
void			free_matriz(char **arg);
void			error_free(t_list **a, char **argv, bool flag_argc_2);
int				error_rep(t_list *a, int nbr);
void			free_tlist(t_list **stack);
long			ft_atol(char *str);
void			stack_init(t_list **a, char **argv, bool flag_argc_2);
void			add_node(t_list **st_a, int nbr);
t_list			*find_lastnode(t_list *st_a);
int				ft_strlen(char *str);
int				stack_len(t_list *stack);
bool			stack_sorted(t_list *stack);
void			little_sort(t_list **a);
void			five_nodes(t_list **a, t_list **b);
t_list			*return_cheapest(t_list *stack);
t_list			*find_smallest(t_list *stack);
void			set_target_node(t_list *a, t_list *b);
void			set_posicion_actual(t_list *stack);
void			set_costo(t_list *a, t_list *b);
void			set_cheapest(t_list *b);
void			init_nodes(t_list *a, t_list *b);
void			push_swap(t_list **a, t_list **b);
void			stop_rotation(t_list **stack, t_list *top_node,
					char stack_name);
void			sa(t_list **a, bool checker);
void			sb(t_list **b, bool checker);
void			ss(t_list **a, t_list **b, bool checker);
void			ra(t_list **a, bool checker);
void			rb(t_list **b, bool checker);
void			rr(t_list **a, t_list **b, bool checker);
void			rra(t_list **a, bool checker);
void			rrb(t_list **b, bool checker);
void			rrr(t_list **a, t_list **b, bool checker);
void			pa(t_list **a, t_list **b, bool checker);
void			pb(t_list **b, t_list **a, bool checker);
#endif
