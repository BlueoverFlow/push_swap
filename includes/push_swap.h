#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct          s_stack
{
    int                 data;
    int                 index;
    struct s_stack      *next;
}                       t_stack;

typedef struct s_checker
{
    char        *instr;
    int         argc;
    char        **argv;
}               t_checker;

typedef struct s_wheel
{
    int         top_a;
    int         top_b;
    int         top;
    int         smaller;
    int         preaxe;
}               t_wheel;


void        out(int i);
void        push(t_stack **head, int data);
void        get_args(t_checker *checker, t_stack **a);
void        print_list(t_stack *a, t_stack *b);
void        is_diplucated(t_stack *a);
void        check_input(char *str);
int         s(t_stack **stack);
int         r(t_stack **stack);
void        both(t_stack **a, t_stack **b, int code);
int         p(t_stack **src, t_stack **dst);
int         rr(t_stack **stack);
void        sort(t_stack **a, t_stack **b);
int		    lstsize2(t_stack *lst);
t_stack     *lstcpy(t_stack *lst);
void        free_list(t_stack *lst);

int action;

#endif