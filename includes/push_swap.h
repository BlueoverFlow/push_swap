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

void        out(int i);
void        push(t_stack **head, int data);
void        is_num(char *str);
void        get_args(t_checker *checker, t_stack **a);
void        print_list(t_stack *a, t_stack *b);
void        is_diplucated(t_stack *a);
void        check_input(char *str);
void        exec_instr(char *str, t_stack **a, t_stack **b);
int         s(t_stack **stack);
int         r(t_stack **stack);
void        rs(t_stack **a, t_stack **b, int code);
int         p(t_stack **src, t_stack **dst);

#endif