#include <unistd.h>

int	main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int print = 0;
	
	if (ac == 3)
	{
		while (av[1][i])
		{
			print = 0;
			x = 0;
			while (x < i)
			{
				if (av[1][i] == av[1][x])
					print = -1;
				x++;
			}
			if (print == 0)
				write(1, &av[1][i], 1);
			i++;
		}
		i = 0;

		while (av[2][j])
		{
			print = 0;
			i = 0;
			while (av[1][i])
			{
				if (av[1][i] == av[2][j])
					print = -1;
				i++;
			}
			if (print == 0)
			{
				x = 0;
				while (x < j)
				{
					if (av[2][j] == av[2][x])
						print = -1;
					x++;
				}
				if (print == 0)
                               		write(1, &av[2][j],1);

			}
			j++;
		}		

	}
	write(1, "\n", 1);
}







