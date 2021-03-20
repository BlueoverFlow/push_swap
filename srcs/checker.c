#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_checker   checker;
    t_stack     *a = NULL;
    t_stack     *b = NULL;

    init_(&checker, argc, argv);
    get_args(&checker, &a);
    is_diplucated(a);
    print_list(a, b);
    while (get_next_line(0, &checker.instr) > 0)
        exec_instr(checker.instr, &a, &b);
    // is_sorted(checker);
    return (0);
}