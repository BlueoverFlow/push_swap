#include "../includes/push_swap.h"

static void init_(t_checker *checker, int argc, char **argv, t_stack **a)
{
    (*checker).argc = argc;
    (*checker).argv = argv;
    get_args(checker, a);
    is_diplucated(*a);
}

int main(int argc, char **argv)
{
    t_checker   checker;
    t_stack     *a = NULL;
    t_stack     *b = NULL;

    action = 0;
    init_(&checker, argc, argv, &a);
    print_list(a, b);
    sort(&a, &b);
    printf("## actions: %i##\n", action);
    return (0);
}
