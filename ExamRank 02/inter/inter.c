#include <stdio.h>
#include <unistd.h>

int main(int argc, const char **argv)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int print  = 0;
    
    if (argc == 3)
    {
        while (argv[1][i])
        {
            j = 0;
            print = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    x = 0;
                    while (x < i)
                    {
                        if (argv[1][x] == argv[1][i])
                            print = -1;
                        x++;
                    }
                    if (print != -1)
                        write(1, &argv[1][i], 1);
                    break;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}





