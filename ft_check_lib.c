#include "ft_marathon_03.h"

int		ft_c_num(int x, int *arr)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] == x)
			j++;
		i++;
	}
	return (j);
}

int		ft_check_corner(int **p)
{
	if ((p[0][0] == 1 && p[2][0] != 1) || (p[2][0] == 1 && p[0][0] != 1))
		return (1);
	if ((p[1][0] == 1 && p[2][3] != 1) || (p[2][3] == 1 && p[1][0] != 1))
		return (1);
	if ((p[3][0] == 1 && p[0][3] != 1) || (p[0][3] == 1 && p[3][0] != 1))
		return (1);
	if ((p[1][3] == 1 && p[3][3] != 1) || (p[3][3] == 1 && p[1][3] != 1))
		return (1);
	return (0);
}

int		**ft_check_argv(char **argv)
{
	int		**arr;
	int		i;
	int		j;

	if (ft_n_numbers(argv[1]) != 16)
		return NULL;
	if (!(arr = ft_split_numbers(argv[1])))
		return NULL;
	i = -1;
	while (++i < 4)
	{
		if (ft_c_num(1, arr[i]) > 1 || ft_c_num(4, arr[i]) > 1)
			return NULL;
		if (ft_c_num(2, arr[i]) > 3 || ft_c_num(3, arr[i]) > 2)
			return NULL;
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] + arr[i + 1 - 2 * (i % 2)][j] > 5)
				return NULL;
			if (arr[i][j] == 1 && (j == 0 || j == 3) && ft_check_corner(arr))
				return NULL;
		}
	}
	return (arr);
}
