#include "../includes/push_swap.h"

void    _init_var(t_wheel *wheel)
{
    wheel->top_a = 0;
    wheel->top_b = 0;
    wheel->preaxe = 0;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    int j = low - 1;
 
    while (++j <= high - 1)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

static void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

static int     *fill_array(t_stack *stack, int *data, size_t l)
{
    t_stack     *tmp;
    int         i;

    if (!(data = malloc(sizeof(int) * (l + 1))))
        out(-1);
    tmp = stack;
    i = -1;
    while (tmp)
    {
        data[++i] = tmp->data;
        tmp = tmp->next;
    }
    return (data);
}

static int     lst_order(t_stack *stack, int data)
{
    int i;

    i = 0;
    if (!stack)
        return (0);
    while (stack->data != data && stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}

static int      lst_elem(t_stack *stack, int i)
{
    int j;

    j = -1;
    while (++j != i)
        stack = stack->next;
    return (stack->data);
}

static int      _top(t_stack **stack, int data) // fully functional
{
    int         i;
    int         l;
    int         ninstr;
    t_stack     *tmp;

    i = 0;
    ninstr = 0;
    if (!stack || !*stack)
        return (0);
    tmp = *stack;
    l = lstsize2(*stack);
    while (tmp->data != data && ++i <= l)
        tmp = tmp->next;
    tmp = lstcpy(*stack);
    while (tmp->data != data)
    {
        if (i <= l / 2)
            r(&tmp);
        else
            rr(&tmp);
        ninstr++;
    }
    free_list(tmp);
    tmp = NULL;
    action -= ninstr;
    return (ninstr);
}

static void      _toping(t_stack **stack, int data) // fully functional
{
    int         i;
    int         l;
    t_stack     *tmp;

    i = 0;
    if (!stack || !*stack)
        return ;
    tmp = *stack;
    l = lstsize2(*stack);
    while (tmp->data != data && ++i <= l)
        tmp = tmp->next;
    while ((*stack)->data != data)
    {
        if (i <= l / 2)
            r(stack);
        else
            rr(stack);
    }
}

static int     find_preaxe(t_stack *stack, int axe)
{
    size_t      l;
    int         i;
    int         *data;

    i = -1;
    if (!stack)
        return (0);
    push(&stack, axe);
    l = lstsize2(stack);
    data = fill_array(stack, data, l);
    quickSort(data, 0, l - 1);
    while (++i < l && data[i] != axe)
        ;
    if (i == 0)
        return (data[l - 1]);
    return (data[i - 1]);
}

static int      s_scan(t_stack *a, t_stack *b, t_wheel wheel)
{
    t_stack     *tmp;
    int         i;
    int         l_a;
    int         l_b;
    int         index[lstsize2(a)];

    l_a = lstsize2(a);
    l_b = lstsize2(b);
    tmp = a;
    i = -1;
    while (++i < l_a)
    {
        wheel.preaxe = find_preaxe(b, tmp->data);
        wheel.top_a = _top(&a, tmp->data);
        wheel.top_b = _top(&b, wheel.preaxe);
        printf("###\n\tvar %15s: %i\t###\n", "tmp->data:", tmp->data);
        printf("###\tvar %15s: %i\t###\n", "top_a:", wheel.top_a);
        printf("###\tvar %15s: %i\t###\n", "top_b:", wheel.top_b);
        printf("###\tvar %15s: %i\t###\n", "preaxe", wheel.preaxe);
        if ((lst_order(a, tmp->data) <= l_a / 2 && lst_order(b, wheel.preaxe) <= l_b / 2) ||
            (lst_order(a, tmp->data) > l_a / 2 && lst_order(b, wheel.preaxe) > l_b / 2))
        {
            if (wheel.top_a > wheel.top_b)
                index[i] = wheel.top_a;
            else
                index[i] = wheel.top_b;
            
        }
        else
            index[i] = wheel.top_a + wheel.top_b;
        tmp = tmp->next;
        printf("###\tvar %15s: %i\t###\n", "index", index[i]);
    }
    i = 0;
    wheel.smaller = index[i];
    wheel.top = 0;
    while (++i < l_a)
    {
        if (index[i] == wheel.smaller)
            if (lst_elem(a, i) < lst_elem(a, wheel.top))
                wheel.top = i;
        if (index[i] < wheel.smaller)
        {
            wheel.smaller = index[i];
            wheel.top = i;
        }
    }
    printf("###\tvar %15s: %i\t###\n\n", "to be toped:", lst_elem(a, wheel.top));
    return (lst_elem(a, wheel.top));
}

void    sort(t_stack **a, t_stack **b)
{
    t_wheel wheel;
    int     top;
    int     *data;
    int     l;

    _init_var(&wheel);
    p(a, b);
    p(a, b);
    print_list(*a, *b);
    while (a && *a)
    {
        top = s_scan(*a, *b, wheel);
        _toping(a, top);
        print_list(*a, *b);
        _toping(b, find_preaxe(*b, top));
        p(a, b);
        print_list(*a, *b);
    }
    l = lstsize2(*b);
    data = fill_array(*b, data, l);
    quickSort(data, 0, l - 1);
    while (b && *b)
    {
        _toping(b, data[l - 1]);
        l--;
        p(b, a);
        print_list(*a, *b);
    }
}

