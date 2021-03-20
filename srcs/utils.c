#include "../includes/push_swap.h"

int       out(int i)
{
    if (i == -1)
        ft_putstr_fd("Error!\n", 1);
    else if (i == 0)
        ft_putstr_fd("KO!\n", 1);
    else
        ft_putstr_fd("OK!\n", 1);
    return (-1);
}

void    init_(t_checker *checker, int argc, char **argv)
{
    (*checker).argc = argc;
    (*checker).argv = argv;
}

int    get_args(t_checker *checker, t_stack_a **stack_a)
{
    int     i;

    if ((*checker).argc == 1)
        return (out(-1));
    i = 1;
    while (i < checker->argc)
    { 
        if (!is_num(checker->argv[i]))
            return (out(-1));
        push(stack_a, ft_atoi(checker->argv[i]));
        stack_a = &((*stack_a)->next);
        i++;
    }
    return(1);
}
