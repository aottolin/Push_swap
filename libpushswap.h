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
// Para anadir dentro de stack a:
void		add_node(t_list **st_a, int nbr);



#endif
