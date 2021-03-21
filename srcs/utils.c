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

void    get_args(t_checker *checker, t_stack **a)
{
    int     i;

    if ((*checker).argc == 1)
        exit(0);
    i = 1;
    while (i < checker->argc)
    {
        is_num(checker->argv[i]);
        push(a, ft_atoi(checker->argv[i]));
        a = &((*a)->next);
        i++;
    }
}