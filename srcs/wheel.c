#include "../includes/push_swap.h"

void    _init_var(t_wheel *wheel)
{
    wheel->top_a = 0;
    wheel->top_b = 0;
    wheel->preaxe = 0;
}

static void    print_instr(int instr, int pres)
{
    if (pres == 0)
        ft_putstr_fd("sa\n", 1);
    if (pres == 1)
        ft_putstr_fd("sa\n", 1);
    if (pres == 2)
        ft_putstr_fd("pa\n", 1);
    if (pres == 3)
        ft_putstr_fd("pb\n", 1);
    if (pres == 4)
        ft_putstr_fd("ra\n", 1);
    if (pres == 5)
        ft_putstr_fd("rb\n", 1);
    if (pres == 6)
        ft_putstr_fd("rra\n", 1);
    if (pres == 7)
        ft_putstr_fd("rrb\n", 1);
    if (pres == 8)
        ft_putstr_fd("ss\n", 1);
    if (pres == 9)
        ft_putstr_fd("rr\n", 1);
    if (pres == 10)
        ft_putstr_fd("rrr\n", 1);
}

static int      _top(t_stack **stack, int data)
{
    int         i;
    int         l;
    int         ninstr;
    t_stack     *tmp;

    ninstr = 0;
    if (!stack || !*stack)
        return (0);
    l = lstsize2(*stack);
    i = lst_order(*stack, data);
    tmp = lstcpy(*stack);
    while (tmp->data != data)
    {
        if (i <= l / 2)
            r(&tmp);
        else
            rr(&tmp);
        ninstr++;
    }
    free_list(tmp);
    tmp = NULL;
    return (ninstr);
}

static void      _toping(t_stack **stack, int data, char s)
{
    int         i;
    int         l;
    t_stack     *tmp;

    if (!stack || !*stack)
        return ;
    tmp = *stack;
    l = lstsize2(*stack);
    i = lst_order(*stack, data);
    while ((*stack)->data != data)
    {
        if (i <= l / 2)
        {
            if (s == 'a')
                print_instr(r(stack), 4);
            if (s == 'b')
                print_instr(r(stack), 5);
        }
        else
        {
            if (s == 'a')
                print_instr(rr(stack), 6);
            if (s == 'b')
                print_instr(rr(stack), 7);
        }
    }
}

int     find_preaxe(t_stack *stack, int axe)
{
    size_t      l;
    int         i;
    int         *data;

    i = -1;
    if (!stack)
        return (0);
    push(&stack, axe);
    l = quicksort(stack, &data);
    while (++i < l && data[i] != axe)
        ;
    if (i == 0)
        return (data[l - 1]);
    return (data[i - 1]);
}

static int      s_scan(t_stack *a, t_stack *b, t_wheel wheel)
{
    t_stack     *tmp;
    int         i;
    int         l_a;
    int         l_b;
    int         index[lstsize2(a)];

    l_a = lstsize2(a);
    l_b = lstsize2(b);
    tmp = a;
    i = -1;
    while (++i < l_a)
    {
        wheel.preaxe = find_preaxe(b, tmp->data);
        wheel.top_a = _top(&a, tmp->data);
        wheel.top_b = _top(&b, wheel.preaxe);
        if ((lst_order(a, tmp->data) <= l_a / 2 && lst_order(b, wheel.preaxe) <= l_b / 2) ||
            (lst_order(a, tmp->data) > l_a / 2 && lst_order(b, wheel.preaxe) > l_b / 2))
        {
            if (wheel.top_a > wheel.top_b)
                index[i] = wheel.top_a;
            else
                index[i] = wheel.top_b;
            
        }
        else
            index[i] = wheel.top_a + wheel.top_b;
        tmp = tmp->next;
    }
    i = 0;
    wheel.smaller = index[i];
    wheel.top = 0;
    while (++i < l_a)
    {
        if (index[i] == wheel.smaller)
            if (lst_elem(a, i) < lst_elem(a, wheel.top))
                wheel.top = i;
        if (index[i] < wheel.smaller)
        {
            wheel.smaller = index[i];
            wheel.top = i;
        }
    }
    return (lst_elem(a, wheel.top));
}

void    sort(t_stack **a, t_stack **b)
{
    t_wheel wheel;
    int     top;
    int     *data;
    int     l;

    _init_var(&wheel);
    while (PHASE_1)
    {
        top = s_scan(*a, *b, wheel);
        _toping(a, top, 'a');
        _toping(b, find_preaxe(*b, top), 'b');
        print_instr(p(a, b), 3);
    }
    l = quicksort(*b, &data);
    while (PHASE_2)
    {
        _toping(b, data[l - 1], 'b');
        l--;
        print_instr(p(b, a), 2);
    }
}