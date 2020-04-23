#include "ft_marathon_03.h"

void	ft_print_map(int **p)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		ft_putchar(p[i / 4][i % 4] + '0');
		if ((i + 1) % 4 == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
}

int		ft_solve_map(int **view, int **map, int adr)
{
	int		num;

	num = 1;
	if (adr == 16)
		return (1);
	if (map[adr / 4][adr % 4] != 0)
		return (ft_solve_map(view, map, adr + 1));
	while (num <= 4)
	{
		if (ft_check_field(num, adr, view, map))
		{
			map[adr / 4][adr % 4] = num;
			if (ft_solve_map(view, map, adr + 1))
				return (1);
			else
				map[adr / 4][adr % 4] = 0;
		}
		num++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		**view;
	int		**map;
	
	if (argc == 2 && (view = ft_check_argv(argv)))
	{
		map = ft_make_map(view);
		if (ft_check_uniq(map))
			if (ft_solve_map(view, map, 0))
			{
				ft_print_map(map);
				return (0);
			}
	}
	ft_putstr("Error\n");
	return (0);
}
