#include "ft_marathon_03.h"

int		**ft_full_line(int i, int **p)
{
	int		j;

	j = -1;
	if (i / 4 == 0)
		while (++j < 4)
			p[j][i % 4] = j + 1;
	if (i / 4 == 1)
		while (++j < 4)
			p[j][i % 4] = 4 - j;
	if (i / 4 == 2)
		while (++j < 4)
			p[i % 4][j] = j + 1;
	if (i / 4 == 3)
		while (++j < 4)
			p[i % 4][j] = 4 - j;
	return (p);
}

int		**ft_max_line(int i, int **p)
{
	if (i / 4 == 0)
		p[0][i % 4] = 4;
	if (i / 4 == 1)
		p[3][i % 4] = 4;
	if (i / 4 == 2)
		p[i % 4][0] = 4;
	if (i / 4 == 3)
		p[i % 4][3] = 4;
	return (p);
}

int		**ft_make_map(int **view)
{
	int		i;
	int		**p;

	p = (int**)malloc(sizeof(int*) * 4);
	i = -1;
	while (++i < 16)
	{
		if ((i % 4) == 0)
			p[i / 4] = (int*)malloc(sizeof(int) * 4);
		p[i / 4][i % 4] = 0;
	}
	while (--i >= 0)
	{
		if (view[i / 4][i % 4] == 4)
			p = ft_full_line(i, p);
		if (view[i / 4][i % 4] == 1)
			p = ft_max_line(i, p);
		if (view[i / 4][i % 4] == 3 && i / 4 < 2)
			if (view[i / 4 + 1 - 2 * ((i / 4) % 2)][i % 4] == 2)
				p[2 - ((i / 4) % 2)][i % 4] = 4;
		if (view[i / 4][i % 4] == 3 && i / 4 > 1)
			if (view[i / 4 + 1 - 2 * ((i / 4) % 2)][i % 4] == 2)
				p[i % 4][2 - ((i / 4) % 2)] = 4;
	}
	return (p);
}

int		ft_check_uniq(int **map)
{
	int		i;
	int		j;
	
	j = -1;
	while (++j < 16)
	{
		if (map[j / 4][j % 4] != 0)
		{
			i = -1;
			while (++i < 4)
			{
				if (map[j / 4][i] == map[j / 4][j % 4] && i != j % 4)
					return (0);
				if (map[i][j % 4] == map[j / 4][j % 4] && i != j / 4)
					return (0);
			}
		}
	}
	return (1);
}
