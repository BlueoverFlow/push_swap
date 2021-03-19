#include "../includes/push_swap.h"

void        out(int i)
{
    if (i == -1)
     return (ft_putstr_fd("Error!\n", 1));
    else if (i == 0)
        return (ft_putstr_fd("KO!\n", 1));
    else
        return (ft_putstr_fd("OK!\n", 1));
}

void    init_(t_checker *checker, int argc, char **argv)
{
    (*checker).argc = argc;
    (*checker).argv = argv;
}

// void    check_input(t_checker checker)
// {

    
// }

void    get_args(t_checker *checker, t_stack_a **stack_a)
{
    int     i;
    t_stack_a ***reference;

    reference = &stack_a;
    if ((*checker).argc == 1)
        out(-1);
    i = 1;
    while (i < (*checker).argc)
    { 
        if (!is_num((*checker).argv[i]))
                out(-1);
        push(*reference, ft_atoi((*checker).argv[i]));
        *reference = &((**reference)->next);
        i++;
    }
    // if (!diplucated((*checker).stack.a[i])
    //     out(-1);
}



