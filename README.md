*This project has been created as part of the 42 curriculum by tiana-an, trakotoz.*

# Push_swap
> Because Swap_push doesn’t feel as natural.

## Description

push_swap is an algorithmic project that involves sorting a list of integers using two stacks and a limited set of predefined instructions.

> The objective is to obtain the sequence sorted in ascending order with the minimum possible operations, optimizing the complexity and the sorting strategy.

### Project objectives

-   Implement an efficient sorting algorithm.

-   Handle two batteries (a and b) with specific operations.

-   Generate the shortest sequence of instructions possible.

-   Manage errors (duplicates, invalid characters, int overflow / underflow, no arguments)

### Authorized operations

-   `sa` / `sb`: swap the first two elements of the a/b stack

-   `ss`: sa and sb at the same time

-   `pa` / `pb`: push from b to a / from a to b

-   `ra` / `rb`: upward rotation

-   `rr`: ra and rb at the same time

-   `rra` / `rrb`: downward rotation

-   `rrr`: rra and rrb at the same time.

### Compilation
```bash
    make
```
***This is an usage example:***
```bash
    ARG="4 67 3 87 23"; ./push_swap --simple $ARG | wc -l
```

## Team Contributions

### tiana-an
- Implementation of stack operations (`sa`, `sb`, `ra`, `rra`, etc.)
- Development of the medium and adaptive strategy (`chunked_based_sort`)
- Participation in the design of `minmax_sort`
- Co-development of `compute_disorder`

### trakotoz
- Error handling and argument parsing
- Implementation of the complex strategy (`radix_lsd_sort`)
- Benchmark implementation and performance testing
- Participation in the design of `minmax_sort`
- Co-development of `compute_disorder`

> The simple strategy (**minmax_sort**), the disorder computation logic and the remaining implementation details were designed and implemented collaboratively.