#include "../includes/push_swap.h"

void    out(int i)
{
    if (i == -1)
        ft_putstr_fd("Error!\n", 1);
    else if (i == 0)
        ft_putstr_fd("KO!\n", 1);
    else
        ft_putstr_fd("OK!\n", 1);
    exit(0);
}

void    init_(t_checker *checker, int argc, char **argv)
{
    (*checker).argc = argc;
    (*checker).argv = argv;
}

void    get_args(t_checker *checker, t_stack_a **stack_a)
{
    int     i;

    if ((*checker).argc == 1)
        exit(0);
    i = 1;
    while (i < checker->argc)
    {
        is_num(checker->argv[i]);
        push(stack_a, ft_atoi(checker->argv[i]));
        stack_a = &((*stack_a)->next);
        i++;
    }
}

t_stack_b *exec_instr(char *str, t_stack_a **stack_a)
{
    if (ft_strcmp(str, "sa") == 0)
        sa();
    else if (ft_strcmp(str, "sb") == 0)
        sb();
    else if (ft_strcmp(str, "ss") == 0)
        ss();
    else if (ft_strcmp(str, "pa") == 0)
        pa();
    else if (ft_strcmp(str, "pb") == 0)
        pb();
    else if (ft_strcmp(str, "ra") == 0)
        ra();
    else if (ft_strcmp(str, "rb") == 0)
        rb();
    else if (ft_strcmp(str, "rr") == 0)
        rr();
    else if (ft_strcmp(str, "rra") == 0)
        rra();
    else
        out(-1);
}