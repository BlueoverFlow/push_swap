#include "../includes/push_swap.h"

int    s(t_list **stack)
{
    int         t;

    if (!*stack  || !(*stack)->next)
        return (0);
    t = (intptr_t)(*stack)->content;
    (*stack)->content = ((*stack)->next)->content;
    ((*stack)->next)->content = &t;
    return (1);
}

int    p(t_list **src, t_list **dst)
{
    t_list *tmp;

    if (!*src)
        return (0);
    tmp = *src;
    push(dst, (*src)->content);
    *src = (*src)->next;
    free(tmp);
    return (1);
}

int    r(t_list **stack)
{
    t_list *tmp;

    if (!s(stack))
        return (-1);
    tmp = *stack;
    *stack = (*stack)->next;
    while (*stack)
    {
        s(stack);
        *stack = (*stack)->next;
    }
    *stack = tmp;
}

void    both(t_list **stack_a, t_list **stack_b, int code)
{
    if (code == 1)
    {
        s(stack_a);
        s(stack_b);
    }
    else if (code == 2)
    {
        r(stack_a);
        r(stack_b);
    }
    else if (code == 3)
    {
        rr(stack_a);
        rr(stack_b);
    }
}

int    rr(t_list **stack)
{
    t_list *tmp;
    t_list *root;

    if (!*stack || !(*stack)->next)
        return (0);
    root = *stack;
    while (((*stack)->next)->next)
        *stack = (*stack)->next;
    tmp = (*stack)->next;
    (*stack)->next = NULL;
    tmp->next = root;
    *stack = tmp;
    return (1);
}