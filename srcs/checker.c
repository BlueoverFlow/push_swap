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

    init_(&checker, argc, argv, &a);
    print_list(a, b);
    while (get_next_line(0, &checker.instr) > 0)
        exec_instr(checker.instr, &a, &b);
    // is_sorted(checker);
    return (0);
}