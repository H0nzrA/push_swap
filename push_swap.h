#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef enum e_strat
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}		t_strat;

void	parsing(t_list **list, char *str);
void	error(void);

int		is_valid_digit(const char *str);
int		is_strategy(const char *str);
t_strat	get_strategy(const char *str);

int		ft_strcmp(const char *s1, const char *s2);

#endif
