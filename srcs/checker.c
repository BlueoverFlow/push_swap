#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_checker   checker;
    t_stack_a     *stack_a = NULL;

    init_(&checker, argc, argv);
    if (get_args(&checker, &stack_a) <= 0 ||
        diplucated(stack_a) <= 0)
            return (0);
    print_list(stack_a);
    // while (get_next_line(0, &checker.instr) > 0)
    // {
    //     // check_input(checker);
    //     // exec_instr(&checker);
    //     ;printf("%s\n", checker.instr);
    // }
    // is_sorted(checker);
    return (0);
}