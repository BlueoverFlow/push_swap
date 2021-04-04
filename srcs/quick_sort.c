#include "../includes/push_swap.h"

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static void     fill_array(t_stack *stack, int **data, size_t l)
{
    t_stack     *tmp;
    int         i;

    if (!(*data = malloc(sizeof(int) * (l + 1))))
        out(-1);
    tmp = stack;
    i = -1;
    while (tmp)
    {
        (*data)[++i] = tmp->data;
        tmp = tmp->next;
    }
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

static void ginjitsu(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        ginjitsu(arr, low, pi - 1);
        ginjitsu(arr, pi + 1, high);
    }
}

size_t quicksort(t_stack *stack, int **data)
{
    size_t  l;

    l = lstsize2(stack);
    fill_array(stack, data, l);
    ginjitsu(*data, 0, l - 1);
    return (l);
}