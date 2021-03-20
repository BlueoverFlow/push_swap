#include "../includes/push_swap.h"

void     is_num(char *str)
{
    int i;
    int n;

    i = 0;
    n = 1;
    if (str[0] == '-')
    {
        n = -1;
        i++;
    }
    while(str[i])
    {
        if (!ft_isdigit(str[i]))
            out(-1);
        i++;
    }
}

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
            printf("%10s\t", " ");
        if (b)
        {
            printf("%10i,\n", b->data);
            b = b->next;
        }
        else if (!b)
            printf("%10s,\n", " ");
    }
    printf("******************\n");
}

int    sa(t_stack **a, t_stack **b)
{
    t_stack   **tmp;
    int         t;

    if (!*a  || !(*a)->next)
        return (-1);
    *tmp = (*a)->next;
    t = (*a)->data;
    (*a)->data = (*tmp)->data;
    (*tmp)->data = t;
    print_list(*a, *b);
    return (1);
}

int    sb(t_stack **a, t_stack **b)
{
    t_stack   **tmp;
    int         t;

    if (!*b  || !(*b)->next)
        return (-1);
    *tmp = (*b)->next;
    t = (*b)->data;
    (*b)->data = (*tmp)->data;
    (*tmp)->data = t;
    print_list(*a, *b);
    return (1);
}

int    ss(t_stack **a, t_stack **b)
{
    sa(a, b);
    sb(a, b);
}

int    pa(t_stack **a, t_stack **b)
{
    t_stack **tmp;

    if (!*b)
        return (-1);
    *tmp = *b;
    push(a, (*b)->data);
    *b = (*b)->next;
    free(*tmp);
    print_list(*a, *b);
}

int    pb(t_stack **a, t_stack **b)
{
    t_stack **tmp;

    if (!*a)
        return (-1);
    *tmp = *a;
    push(b, (*a)->data);
    *a = (*a)->next;
    free(*tmp);
    print_list(*a, *b);
}

int    ra(t_stack **a, t_stack **b)
{
    t_stack **tmp;

    sa(a, b);
    *tmp = (*a);
    *a = (*a)->next;
    while (*a)
    {
        if (sa(a, b))
            *a = (*a)->next;
    }
    *a = *tmp;
    print_list(*a, *b);
}

int    rb(t_stack **a, t_stack **b)
{
    t_stack **tmp;

    sb(a, b);
    *tmp = (*b);
    *b = (*b)->next;
    while (*b)
    {
        sb(a, b);
        *b = (*b)->next;
    }
    *b = *tmp;
    print_list(*a, *b);
}

int     rr(t_stack **a, t_stack **b)
{
    ra(a, b);
    // rb(a, b);
}