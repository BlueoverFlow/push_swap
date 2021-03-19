#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct          s_stack_a
{
    int                 data;
    struct s_stack_a    *next;
}                       t_stack_a;

typedef struct s_checker
{
    char        *instr;
    int         argc;
    char        **argv;
}               t_checker;

char    **realloc_2d(char **str, int d);
void    out();
void    push(t_stack_a **head, int data);
int     is_num(char *str);
void    init_(t_checker *checker, int argc, char **argv);
void    get_args(t_checker *checker, t_stack_a **stack_a);
void    print_list(t_stack_a *head);

#endif