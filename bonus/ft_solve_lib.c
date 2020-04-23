#include "ft_marathon_03.h"

int		ft_check_left(int v1, int *line)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (++i < 4)
	{
		if (line[i] == 0)
			return (1);
		if (line[i] > max)
		{
			max = line[i];
			v1--;
		}
	}
	if (max == 4 && v1 != 0)
		return (0);
	return (1);
}

int		ft_check_right(int v2, int *line)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (++i < 4)
	{
		if (line[3 - i] == 0)
			return (1);
		if (line[3 - i] > max)
		{
			max = line[3 - i];
			v2--;
		}
	}
	if (max == 4 && v2 != 0)
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
	while (++i < 4)
		if (map[adr / 4][i] == num || map[i][adr % 4] == num)
			return (0);
	if ((adr / 4 == 0 || adr % 4 == 0) && num == 4)
		return (0);
	col = (int*)malloc(sizeof(int) * 4);
	i = -1;
	while (++i < 4)
		col[i] = map[i][adr % 4];
	col[adr / 4] = num;
	if (!ft_check_view(view[0][adr % 4], view[1][adr % 4], col))
		return (0);
	free(col);
	map[adr / 4][adr % 4] = num;
	if (!ft_check_view(view[2][adr / 4], view[3][adr / 4], map[adr / 4]))
	{
		map[adr / 4][adr % 4] = 0;
		return (0);
	}
	map[adr / 4][adr % 4] = 0;
	return (1);
}
