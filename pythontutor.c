# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
#include <stdio.h>

typedef struct t_list
{
    int                    value;
    int                    current_position;
    int                    final_index;
    int                    push_price;
    bool                above_median;
    bool                cheapest;
    struct t_list    *target_node;
    struct t_list    *next;
    struct t_list    *prev;
}                t_list;    

t_list    *find_lastnode(t_list *st_a)
{
    if (st_a == NULL)
        return (NULL);
    while (st_a->next)
        st_a = st_a->next;
    return (st_a);
}

int    stack_len(t_list *stack)
{
    int    len;

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

static void    rotate(t_list **stack)
{
    t_list    *last_node;
    int                len;

    len = stack_len(*stack);
    if (NULL == stack || NULL == *stack || 1 == len)
        return ;
    last_node = find_last_node(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}    
int main() 
{
 t_list *a;
 
 a = malloc(sizeof(t_list));
 a->next = malloc(sizeof(t_list));
 a->next->next = malloc(sizeof(t_list));
 a->value = 17;
 a->next->value = 20;
 a->next->next->value = 30;
 a->prev = NULL;
 a->next->prev = a;
 a->next->next->prev = a->next;
 a->next->next->next = NULL;
 rotate(&a);
  return (0);
}
