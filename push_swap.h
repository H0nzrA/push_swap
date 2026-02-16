#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>

void	push_swap(int argc, char **argv);
void	error(void);

int		evaluate_arguments(int argc, char **argv);

int		is_all_digit(const char *str);

#endif
