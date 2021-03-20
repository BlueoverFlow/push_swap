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

void     is_diplucated(t_stack_a *stack_a)
{
    t_stack_a   *tmp;
    t_stack_a   *root;
    int         i;

    tmp = stack_a;
    root = stack_a;
    while (tmp->next)
    {
        stack_a = root;
        i = -1;
        while (stack_a)
        {
            if (stack_a->data == tmp->data)
            {
                i++;
                if (i)
                   out(-1);
            }
            stack_a = stack_a->next;
        }
        tmp = tmp->next;
    }
}

void push(t_stack_a **head, int data)
{
    t_stack_a *new;

    new = malloc(sizeof(*new));
    new->next = *head;
    new->data = data;
    *head = new;
}

void print_list(t_stack_a *head)
{
    while (head)
    {
        printf("%i, \n", head->data);
        head = head->next;
    }
}

