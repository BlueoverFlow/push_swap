#include "../includes/push_swap.h"

void     is_diplucated(t_stack *a)
{
    t_stack   *tmp;
    t_stack   *root;
    int         i;

    tmp = a;
    root = a;
    while (tmp->next)
    {
        a = root;
        i = -1;
        while (a)
        {
            if (a->data == tmp->data)
            {
                i++;
                if (i)
                   out(-1);
            }
            a = a->next;
        }
        tmp = tmp->next;
    }
}

void push(t_stack **head, int data)
{
    t_stack *new;

    new = malloc(sizeof(*new));
    new->next = *head;
    new->data = data;
    *head = new;
}

void    print_list(t_stack *a, t_stack *b)
{
    printf("\t*\n\t*\n\t*\n");
    printf("******************\n");
    printf("stack a:\tstack b:\n");
    while (a || b )
    {
        if (a)
        {
            printf("%10i\t", a->data);
            a = a->next;
        }
        else if (!a)
            printf("%10c\t", ' ');
        if (b)
        {
            printf("%10i,\n", b->data);
            b = b->next;
        }
        else if (!b)
            printf("%10c,\n", ' ');
    }
    printf("******************\n");
}

int		lstsize2(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void    free_list(t_stack *lst)
{
    t_stack *tmp;

    if (lst == NULL)
        return ;
    tmp = lst->next;
    free(lst);
    lst = NULL;
    free_list(tmp);
}

t_stack         *lstcpy(t_stack *lst)
{
    t_stack *cpy;

    if (lst == NULL)
        return (NULL);
    if (!(cpy = malloc(sizeof(*cpy))))
        out(-1);
    cpy->data = lst->data;
    cpy->next = lstcpy(lst->next);
    return (cpy);
}