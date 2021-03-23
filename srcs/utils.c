#include "../includes/push_swap.h"

static void     is_num(char *str)
{
    int i;
    int n;

    i = 0;
    n = 1;
    if (str[0] == '-')
    {
        n = -1;
        i++;
    }
    while(str[i])
    {
        if (!ft_isdigit(str[i]))
            out(-1);
        i++;
    }
}

void    out(int i)
{
    if (i == -1)
        ft_putstr_fd("Error!\n", 1);
    else if (i == 0)
        ft_putstr_fd("KO!\n", 1);
    else if (i == 1)
        ft_putstr_fd("OK!\n", 1);
    exit(0);
}

void    get_args(t_checker *checker, t_list **stack_a)
{
    int     i;
    int     n;

    if ((*checker).argc == 1)
        exit(0);
    i = 1;
    while (i < checker->argc)
    {
        is_num(checker->argv[i]);
        n = ft_atoi(checker->argv[i]);
        push(stack_a, n);
        stack_a = &((*stack_a)->next);
        i++;
    }
}