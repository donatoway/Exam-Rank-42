#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define conversion "sxd"

int        ft_abs(int nb)
{
    if (nb < 0)
        nb = -nb;
    return (nb);
}



char    *ft_itoa_base(long long value, int base)
{
    char    *str;
    int        size;
    char    *tab;
    int        flag;
    long long        tmp;
    flag = 0;
    size = 0;
    tab = "0123456789abcdef";
    if (base < 2 || base > 16)
        return (0);
    if (value < 0 && base == 10)
        flag = 1;
    tmp = value;
    while (tmp /= base)
        size++;
    size = size + flag + 1;
    str = (char *)malloc(sizeof(char) * size  + 1);
    str[size] = '\0';
    if (flag == 1)
        str[0] = '-';
    while (size > flag)
    {
        str[size - 1] = tab[ft_abs(value % base)];
        size--;
        value /=base;
    }
    return (str);
}





int     ft_atoi(char *s, int i)
{
    int num = 0;
    while (s[i] >=  '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - 48);
        i++;
    }
    return (num);
}


void    ft_putstr(char *s)
{
    int i = 0;
    while (s[i])
        write(1, &s[i++], 1);
}


int  ft_strlen(char *s)
{
    int i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

int ft_strchr(char c, char *convers)
{
    int i = 0;
    while (convers[i])
    {
        if (convers[i] == c)
            return (1);
        i++;
    }
    return (0);
}


int     ft_printf(const char *format, ...)
{
    int     width = 0;
    int     precision = -1;
    int     i = 0;
    char    *str;
    char *s = (char*)format;
    va_list arg;
    int     ret = 0;
    
    va_start(arg, format);
    
    if (!format[0])
    {
        write(1, "", 0);
        return (0);
    }
    if (s[0] == '%' && ft_strlen(s) == 1)
        return (0);
    while (s[i])
    {
        precision = -1;
        width = 0;
        if (s[i] == '%')
        {
            i++;
            if (ft_strchr(s[i], conversion) == 0)
            {
                if (s[i] >= '0' && s[i] <= '9')
                    width = ft_atoi(s, i);
                while (s[i] >= '0' && s[i] <= '9')
                    i++;
                while (s[i] == '.')
                {
                    precision = 0;
                    i++;
                }
                if (precision == 0)
                {
                    if (s[i] >= '0' && s[i] <= '9')
                        precision = ft_atoi(s, i);
                    while (s[i] >= '0' && s[i] <= '9')
                        i++;
                }
            }
            if (s[i] == 's')
            {
                str = va_arg(arg, char*);
                if (str == NULL)
                    str = "(null)";
                if (precision < ft_strlen(str) && precision != -1)
                {
                    char *nstr = malloc(sizeof(char)*(precision + 1));
                    int j = 0;
                    while (j < precision)
                    {
                        nstr[j] = str[j];
                        j++;
                    }
                    nstr[j] = '\0';
                    str = nstr;
                    free(nstr);
                }
                if (width > ft_strlen(str))
                {
                    int diff = width - ft_strlen(str);
                    
                    while (diff--)
                    {
                        write(1, " ", 1);
                        ret++;
                    }
                }
                ft_putstr(str);
                ret += ft_strlen(str);
            }
            if (s[i] == 'd')
            {
                int d = va_arg(arg, int);
                if (d == '\0')
                    str = "0";
                if (d == '\0' && precision == 0)
                    str = "";
                else
                    str = ft_itoa_base(d, 10);
                if (d < 0 && precision > ft_strlen(str) && precision != 0)
                {
                    char *nstr = malloc(sizeof(char)*(precision + 1));
                    int i = 1;
                    int diff = precision - ft_strlen(str) + 1;
                    int j = 1;
                    nstr[0] = '-';
                    while (diff--)
                        nstr[i++] = '0';
                    while (str[j])
                        nstr[i++] = str[j++];
                    nstr[i] = '\0';
                    str = nstr;
                    free(nstr);
                }
                else if (precision > ft_strlen(str))
                {
                    int diff = precision - ft_strlen(str);
                    char *nstr = malloc(sizeof(char)*(precision + 1));
                    int j = 0;
                    int x = 0;
                    
                    while (diff--)
                        nstr[j++] = '0';
                    while (j < precision)
                        nstr[j++] = str[x++];
                    nstr[j] = '\0';
                    str = nstr;
                    free(nstr);
                }
                if (width > ft_strlen(str))
                {
                    int diff = width - ft_strlen(str);
                    while (diff--)
                    {
                        write(1, " ", 1);
                        ret++;
                    }
                }
              
                ft_putstr(str);
                ret += ft_strlen(str);
            }
            if (s[i] == 'x')
            {
                long long hex = va_arg(arg, unsigned int);
                if (hex == '\0')
                    str = "0";
                if (hex == '\0' && precision == 0)
                    str = "";
                else
                    str = ft_itoa_base(hex, 16);
                if (precision > ft_strlen(str))
                {
                    int diff = precision - ft_strlen(str);
                    char *nstr = malloc(sizeof(char)*(precision + 1));
                    int j = 0;
                    int x = 0;
                    
                    while (diff--)
                        nstr[j++] = '0';
                    while (j < precision)
                        nstr[j++] = str[x++];
                    nstr[j] = '\0';
                    str = nstr;
                    free(nstr);
                }
                if (width > ft_strlen(str))
                {
                    int diff = width - ft_strlen(str);
                    while (diff--)
                    {
                        write(1, " ", 1);
                        ret++;
                    }
                }
                ft_putstr(str);
                ret += ft_strlen(str);
            }
            if (ft_strchr(s[i], conversion) == 0)
                return (-1);
        }
        else
        {
            write(1, &s[i], 1);
            ret++;
        }
        i++;
    }
    va_end(arg);
    return (ret);
}
