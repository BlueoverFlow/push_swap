#include "../includes/push_swap.h"

int    s(t_stack **stack)
{
    t_stack   **tmp;
    int         t;

    if (!*stack  || !(*stack)->next)
        return (0);
    *tmp = (*stack)->next;
    t = (*stack)->data;
    (*stack)->data = (*tmp)->data;
    (*tmp)->data = t;
    return (1);
}

int    p(t_stack **src, t_stack **dst)
{
    t_stack **tmp;

    if (!*src)
        return (0);
    *tmp = *src;
    push(dst, (*src)->data);
    *src = (*src)->next;
    free(*tmp);
    return (1);
}

int    r(t_stack **stack)
{
    t_stack **tmp;

    if (!s(stack))
        return (-1);
    *tmp = *stack;
    *stack = (*stack)->next;
    while (*stack)
    {
        s(stack);
        *stack = (*stack)->next;
    }
    *stack = *tmp;
}

void    rs(t_stack **a, t_stack **b, int code)
{
    if (code == 1)
    {
        r(a);
        r(b);
    }
    else
    {
        s(a);
        s(b);
    }  
}

void    exec_instr(char *str, t_stack **a, t_stack **b)
{
    if (ft_strcmp(str, "sa") == 0)
        s(a);
    else if (ft_strcmp(str, "sb") == 0)
        s(b);
    else if (ft_strcmp(str, "ss") == 0)
        rs(a, b, 2);
    else if (ft_strcmp(str, "pa") == 0)
        p(b, a);
    else if (ft_strcmp(str, "pb") == 0)
        p(a, b);
    else if (ft_strcmp(str, "ra") == 0)
        r(a);
    else if (ft_strcmp(str, "rb") == 0)
        r(b);
    else if (ft_strcmp(str, "rr") == 0)
        rs(a, b, 1);
    // else if (ft_strcmp(str, "rra") == 0)
    //     rra(a, b);
    else
        out(1);
    print_list(*a, *b);
}