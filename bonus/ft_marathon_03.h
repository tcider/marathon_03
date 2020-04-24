#ifndef FT_MARATHON_03_H
# define FT_MARATHON_03_H

# include <unistd.h>
# include <stdlib.h>

# define SZ 4

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_n_numbers(char *str);
int		**ft_split_numbers(char *s);
int		**ft_check_argv(char **argv);
int		**ft_make_map(int **view);
int		ft_check_uniq(int **map);
int		ft_solve_map(int **view, int **map, int adr);
void	ft_print_map(int **p);
int		ft_check_field(int num, int adr, int **view, int **map);

#endif
