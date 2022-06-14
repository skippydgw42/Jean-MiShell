#include "../inclds/JeanMiShell.h"

int ft_isallnum(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void    ft_exit(t_args *lstargs)
{
    if(ft_atoi(lstargs->str) == 0 || ft_atoi(lstargs->str) == -1 || !ft_isallnum(lstargs->str))
    {
        g_val_rtn = 255;
        printf("%s : numeric argument required", lstargs->str);
    }
    else
        g_val_rtn = (unsigned char)ft_atoi(lstargs->str);
    printf("exit\n");
    exit(g_val_rtn);
}
