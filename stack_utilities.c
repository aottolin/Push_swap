#include "libpushswap.h"

t_list  *find_lastnode(t_list *st_a);

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

t_list	*find_lastnode(t_list *st_a)
{
	if (st_a == NULL)
		return (NULL);
	while (st_a->next)
		st_a = st_a->next;
	return (st_a);
}
