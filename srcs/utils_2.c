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