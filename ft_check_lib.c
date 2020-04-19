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

int		**ft_check_argv(int argc, char **argv)
{
	int		**arr;
	int		i;
	int		j;

	if (argc != 2)
		return NULL;
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
			if (arr[i][j] == 4 && arr[i + 1 - 2 * (i % 2)][j] != 1)
				return NULL;
	}
	return (arr);
}
