#include "../includes/push_swap.h"

int    s(t_stack **stack)
{
    int         t;

    if (!*stack  || !(*stack)->next)
        return (0);
    t = (*stack)->data;
    (*stack)->data = ((*stack)->next)->data;
    ((*stack)->next)->data = t;
    return (1);
}

int    p(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if (!*src)
        return (0);
    tmp = *src;
    push(dst, (*src)->data);
    *src = (*src)->next;
    free(tmp);
    return (1);
}

int    r(t_stack **stack)
{
    t_stack *tmp;

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

void    both(t_stack **a, t_stack **b, int code)
{
    if (code == 1)
    {
        s(a);
        s(b);
    }
    else if (code == 2)
    {
        r(a);
        r(b);
    }
    else if (code == 3)
    {
        rr(a);
        rr(b);
    }
}

int    rr(t_stack **stack)
{
    t_stack *tmp;
    t_stack *root;

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