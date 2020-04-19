#include "ft_marathon_03.h"
//
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		**view;
	int		i;
	int		j;

	if (!(view = ft_check_argv(argc, argv)))
	{
		ft_putstr("Error\n");
		return (0);
	}

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d-", view[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}


}

