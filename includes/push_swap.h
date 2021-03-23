#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_checker
{
    char        *instr;
    int         argc;
    char        **argv;
}               t_checker;

void        out(int i);
void        push(t_list **head, void *content);
void        get_args(t_checker *checker, t_list **stack_a);
void        print_list(t_list *stack_a, t_list *stack_b);
void        is_diplucated(t_list *stack_a);
void        check_input(char *str);
int         s(t_list **stack);
int         r(t_list **stack);
void        both(t_list **stack_a, t_list **stack_b, int code);
int         p(t_list **src, t_list **dst);
int         rr(t_list **stack);

#endif