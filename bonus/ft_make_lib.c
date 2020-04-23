#include "ft_marathon_03.h"

int		**ft_1234_line(int i, int **p)
{
	int		j;

	j = -1;
	if (i / SZ == 0)
		while (++j < SZ)
			p[j][i % SZ] = j + 1;
	if (i / SZ == 1)
		while (++j < SZ)
			p[j][i % SZ] = SZ - j;
	if (i / SZ == 2)
		while (++j < SZ)
			p[i % SZ][j] = j + 1;
	if (i / SZ == 3)
		while (++j < SZ)
			p[i % SZ][j] = SZ - j;
	return (p);
}

int		**ft_4xxx_line(int i, int **p)
{
	if (i / SZ == 0)
		p[0][i % SZ] = SZ;
	if (i / SZ == 1)
		p[SZ - 1][i % SZ] = SZ;
	if (i / SZ == 2)
		p[i % SZ][0] = SZ;
	if (i / SZ == 3)
		p[i % SZ][SZ - 1] = SZ;
	return (p);
}

int		**ft_make_map(int **view)
{
	int		i;
	int		**p;

	p = (int**)malloc(sizeof(int*) * SZ);
	i = -1;
	while (++i < SZ * SZ)
	{
		if ((i % SZ) == 0)
			p[i / SZ] = (int*)malloc(sizeof(int) * SZ);
		p[i / SZ][i % SZ] = 0;
	}
	i = -1;
	while (++i < SZ * 4)
	{
		if (view[i / SZ][i % SZ] == SZ)
			p = ft_1234_line(i, p);
		if (view[i / SZ][i % SZ] == 1)
			p = ft_4xxx_line(i, p);
	}
	return (p);
}

int		ft_check_uniq(int **map)
{
	int		i;
	int		j;
	
	j = -1;
	while (++j < SZ * SZ)
	{
		if (map[j / SZ][j % SZ] != 0)
		{
			i = -1;
			while (++i < SZ)
			{
				if (map[j / SZ][i] == map[j / SZ][j % SZ] && i != j % SZ)
					return (0);
				if (map[i][j % SZ] == map[j / SZ][j % SZ] && i != j / SZ)
					return (0);
			}
		}
	}
	return (1);
}
