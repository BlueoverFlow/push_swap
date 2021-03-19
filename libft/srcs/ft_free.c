#include "../includes/libft.h"

void    ft_free(char **s)
{
        if (s && *s)
        {
                free(*s);
                *s = NULL;
        }
}
