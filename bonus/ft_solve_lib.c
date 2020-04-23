#include "ft_marathon_03.h"

int		ft_check_left(int v1, int *line)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (++i < SZ)
	{
		if (line[i] == 0)
			return (1);
		if (line[i] > max)
		{
			max = line[i];
			v1--;
		}
	}
	if (max == SZ && v1 != 0)
		return (0);
	return (1);
}

int		ft_check_right(int v2, int *line)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (++i < SZ)
	{
		if (line[SZ - 1 - i] == 0)
			return (1);
		if (line[SZ - 1 - i] > max)
		{
			max = line[SZ - 1 - i];
			v2--;
		}
	}
	if (max == SZ && v2 != 0)
		return (0);
	return (1);
}

int		ft_check_view(int v1, int v2, int *line)
{
	if (ft_check_left(v1, line) && ft_check_right(v2, line))
		return (1);
	return (0);
}

int		ft_check_field(int num, int adr, int **view, int **map)
{
	int		i;
	int		*col;

	i = -1;
	while (++i < SZ)
		if (map[adr / SZ][i] == num || map[i][adr % SZ] == num)
			return (0);
	if ((adr / SZ == 0 || adr % SZ == 0) && num == SZ)
		return (0);
	col = (int*)malloc(sizeof(int) * SZ);
	i = -1;
	while (++i < SZ)
		col[i] = map[i][adr % SZ];
	col[adr / SZ] = num;
	if (!ft_check_view(view[0][adr % SZ], view[1][adr % SZ], col))
		return (0);
	free(col);
	map[adr / SZ][adr % SZ] = num;
	if (!ft_check_view(view[2][adr / SZ], view[3][adr / SZ], map[adr / SZ]))
	{
		map[adr / SZ][adr % SZ] = 0;
		return (0);
	}
	map[adr / SZ][adr % SZ] = 0;
	return (1);
}
