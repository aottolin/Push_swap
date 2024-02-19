#ifndef LIBPUSHSWAP_H
#define LIBPUSHSWAP_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct	s_list
{
	int				value;
	struct	s_list *target_node;
	struct	s_list *next;
	struct	s_list *prev;
}	t_list;

int			ft_strlen(char *str);
int			ft_atoi(char *str);
int			error_syntax(char *argv_nb);
int			error_free(t_list **a, char **argv, bool flag_argc_2);
int			error_rep(t_list *a, int nbr);
char		**ft_split(char *str, char delim);
void		stack_init(t_list **a, char **argv, bool flag_argc_2);


#endif
