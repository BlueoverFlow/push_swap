# push_swap

This project is about sorting data on a stack, with a limited set of instructions and using
the lowest possible number of actions for an optimized data sorting.
• The first program, named checker takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.
• The second one called push_swap. it calculates and displays on the standard
output the smallest program using Push_swap instruction language that sorts integer arguments received.

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

To run tester.sh use: bash <(curl https://raw.githubusercontent.com/BlueoverFlow/push_swap/main/tester.sh?token=AOWCBBJ3PRARTPWP2A7SDFLAU6BBU)
