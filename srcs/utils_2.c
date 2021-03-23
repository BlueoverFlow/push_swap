#include "../includes/push_swap.h"

void     is_diplucated(t_list *stack_a)
{
    t_list   *tmp;
    t_list   *root;
    int         i;

    tmp = stack_a;
    root = stack_a;
    while (tmp->next)
    {
        stack_a = root;
        i = -1;
        while (stack_a)
        {
            if (stack_a->content == tmp->content)
            {
                i++;
                if (i)
                   out(-1);
            }
            stack_a = stack_a->next;
        }
        tmp = tmp->next;
    }
}

void push(t_list **head, void *content)
{
    t_list *new;

    new = malloc(sizeof(*new));
    new->next = *head;
    new->content = content;
    *head = new;
}

void    print_list(t_list *stack_a, t_list *stack_b)
{
    printf("\t*\n\t*\n\t*\n");
    printf("******************\n");
    printf("stack a:\tstack b:\n");
    while (stack_a || stack_b)
    {
        if (stack_a)
        {
            printf("%10ld\t", (intptr_t)stack_a->content);
            stack_a = stack_a->next;
        }
        else if (!stack_a)
            printf("%10s\t", " ");
        if (stack_b)
        {
            printf("%10ld,\n", (intptr_t)stack_b->content);
            stack_b = stack_b->next;
        }
        else if (!stack_b)
            printf("%10s,\n", " ");
    }
    printf("******************\n");
}