#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_strat	strat;
	t_list	*list;
	int		i;

	strat = ADAPTIVE;
	i = 1;
	if (argc < 2)
		error();
	if (is_strategy(argv[i]))
		strat = get_strategy(argv[i++]);
	list = ft_lstnew(NULL);
	while (i < argc)
	{
		parsing(&list, argv[i]);
		i++;
	}
	ft_lstclear(&list, free);
	return (0);
}
