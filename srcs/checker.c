#include "../includes/push_swap.h"

static void init_(t_checker *checker, int argc, char **argv, t_stack **a)
{
    (*checker).argc = argc;
    (*checker).argv = argv;
    get_args(checker, a);
    is_diplucated(*a);
}

static void    exec_instr(char *str, t_stack **a, t_stack **b)
{
    if (!ft_strcmp(str, "sa"))
        s(a);
    else if (!ft_strcmp(str, "sb"))
        s(b);
    else if (!ft_strcmp(str, "ss"))
        both(a, b, 1);
    else if (!ft_strcmp(str, "pa"))
        p(b, a);
    else if (!ft_strcmp(str, "ra"))
        r(a);
    else if (!ft_strcmp(str, "rb"))
        r(b);
    else if (!ft_strcmp(str, "rr"))
        both(a, b, 2);
    else if (!ft_strcmp(str, "pb"))
        p(a, b);
    else if (!ft_strcmp(str, "rra"))
        rr(a);
    else if (!ft_strcmp(str, "rrb"))
        rr(b);
    else if (!ft_strcmp(str, "rrr"))
        both(a, b, 3);
    else
        out(-1);
}

void static is_sorted(t_stack *a, t_stack *b)
{
    t_stack *tmp;

    if (b)
        out(0);
    tmp = a;
    while (tmp->next)
    {
        if (tmp->next && (tmp->data > tmp->next->data))
            out(0);
        tmp = tmp->next;
    }
    out(1);
}

int main(int argc, char **argv)
{
    t_checker   checker;
    t_stack     *a = NULL;
    t_stack     *b = NULL;

    init_(&checker, argc, argv, &a);
    print_list(a, b);
    action = 0;
    while (get_next_line(0, &checker.instr) > 0)
    {
        exec_instr(checker.instr, &a, &b);
        print_list(a, b);
        action++;
    }
    printf("actions: %d\n", action);
    is_sorted(a, b);
    return (0);
}