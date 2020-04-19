#ifndef FT_MARATHON_03_H
# define FT_MARATHON_03_H

# include <unistd.h>
# include <stdlib.h>

void		ft_putstr(char *str);
int			ft_n_numbers(char *str);
int			**ft_split_numbers(char *s);
int			**ft_check_argv(int argc, char **argv);

#endif
