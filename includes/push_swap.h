#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct          s_stack
{
    int                 data;
    struct s_stack      *next;
}                       t_stack;

typedef struct s_checker
{
    char        *instr;
    int         argc;
    char        **argv;
}               t_checker;

char        **realloc_2d(char **str, int d);
void        out(int i);
void        push(t_stack **head, int data);
void        is_num(char *str);
void        init_(t_checker *checker, int argc, char **argv);
void        get_args(t_checker *checker, t_stack **a);
void        print_list(t_stack *a, t_stack *b);
void        is_diplucated(t_stack *a);
void        check_input(char *str);
void        exec_instr(char *str, t_stack **a, t_stack **b);
int         sa(t_stack **a, t_stack **b);
int         sb(t_stack **a, t_stack **b);
int         ss(t_stack **a, t_stack **b);
int         pa(t_stack **a, t_stack **b);
int         pb(t_stack **a, t_stack **b);
int         ra(t_stack **a, t_stack **b);
int         rb(t_stack **a, t_stack **b);
int         rr(t_stack **a, t_stack **b);

#endif