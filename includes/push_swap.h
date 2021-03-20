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
int     out(int i);
void    push(t_stack_a **head, int data);
int     is_num(char *str);
void    init_(t_checker *checker, int argc, char **argv);
int     get_args(t_checker *checker, t_stack_a **stack_a);
void    print_list(t_stack_a *head);
int     diplucated(t_stack_a *stack_a);
#endif