#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_checker       checker;
    t_stack_a       *stack_a = NULL;
    t_stack_b       *stack_b = NULL;

    init_(&checker, argc, argv);
    get_args(&checker, &stack_a);
    is_diplucated(stack_a);
    while (get_next_line(0, &checker.instr) > 0)
        stack_b = exec_instr(checker.instr, &stack_a);
    // is_sorted(checker);
    return (0);
}