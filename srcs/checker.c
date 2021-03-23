#include "../includes/push_swap.h"

static void init_(t_checker *checker, int argc, char **argv, t_list **stack_a)
{
    (*checker).argc = argc;
    (*checker).argv = argv;
    get_args(checker, stack_a);
    is_diplucated(*stack_a);
}

static void    exec_instr(char *str, t_list **stack_a, t_list **stack_b)
{
    if (!ft_strcmp(str, "sa"))
        s(stack_a);
    else if (!ft_strcmp(str, "sb"))
        s(stack_b);
    else if (!ft_strcmp(str, "ss"))
        both(stack_a, stack_b, 1);
    else if (!ft_strcmp(str, "pa"))
        p(stack_b, stack_a);
    else if (!ft_strcmp(str, "ra"))
        r(stack_a);
    else if (!ft_strcmp(str, "rb"))
        r(stack_b);
    else if (!ft_strcmp(str, "rr"))
        both(stack_a, stack_b, 2);
    else if (!ft_strcmp(str, "pb"))
        p(stack_a, stack_b);
    else if (!ft_strcmp(str, "rra"))
        rr(stack_a);
    else if (!ft_strcmp(str, "rrb"))
        rr(stack_b);
    else if (!ft_strcmp(str, "rrr"))
        both(stack_a, stack_b, 3);
    else
        out(-1);
    print_list(*stack_a, *stack_b);
}

void static is_sorted(t_list *stack_a, t_list *stack_b)
{
    t_list *tmp;

    if (stack_b)
        out(0);
    tmp = stack_a;
    while (tmp->next)
    {
        if (tmp->next && (tmp->content > tmp->next->content))
            out(0);
        tmp = tmp->next;
    }
    out(1);
}

static void minus(int i)
{
    i -= 1;
}

int main(int argc, char **argv)
{
    t_checker   checker;
    t_list     *stack_a = NULL;
    t_list     *stack_b = NULL;

    init_(&checker, argc, argv, &stack_a);
    print_list(stack_a, stack_b);
    while (get_next_line(0, &checker.instr) > 0)
        exec_instr(checker.instr, &stack_a, &stack_b);
    print_list(stack_a, stack_b);
    return (0);
}