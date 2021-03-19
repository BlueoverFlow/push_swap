#include "../includes/push_swap.h"

int     is_num(char *str)
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
            return (0);
        i++;
    }
    return (1);
}

// int     dipucated(int *s)
// {
//     int i;

//     i = (*checker).argc;
//     while (--i)
//     {
//         j = 1;
//         while (++j)
//             if ((*checker).argv[i] == (*checker).argv[i])

// }

void push(t_stack_a **head, int data)
{
    t_stack_a *new;

    new = malloc(sizeof(*new));
    new->next = *head;
    new->data = data;
    *head = new;
}

void print_list(t_stack_a *head)
{
    while (head)
    {
        printf("%i, \n", head->data);
        head = head->next;
    }
}