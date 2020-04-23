#include "ft_marathon_03.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

int		ft_n_numbers(char *str)
{
	int		i;
	int		counter;
	char	spaceflag;

	counter = 0;
	i = 0;
	spaceflag = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ')
		{
			if (spaceflag == 0)
				counter++;
			spaceflag = 1;
		}
		else
			spaceflag = 0;
		i++;
	}
	return (counter);
}

int		ft_l_word(char *w)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (w[i] == '\t' || w[i] == ' ')
		i++;
	while (w[i] && w[i] != '\t' && w[i] != ' ')
	{
		l++;
		i++;
	}
	return (l);
}

int		**ft_split_numbers(char *s)
{
	int		i;
	int		k;
	int		**p;

	p = (int**)malloc(sizeof(int*) * 4);
	i = -1;
	k = 0;
	while (++i < 16)
	{
		if (ft_l_word(&s[k]) > 1)
			return NULL;	
		if ((i % 4) == 0)
			p[i / 4] = (int*)malloc(sizeof(int) * 4);
		while (s[k] == '\t' || s[k] == ' ')
			k++;
		if (s[k] && s[k] != '\t' && s[k] != ' ')
		{
			if (s[k] > '0' && s[k] < '5')
				p[i / 4][i % 4] = s[k++] - '0';
			else
				return NULL;
		}
	}
	return (p);
}
