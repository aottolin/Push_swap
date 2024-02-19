#include "libpushswap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv  = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, 2 == argc);
	return (0);
}
