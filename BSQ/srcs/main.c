#include "bsq.h"

void	ft_put_error(void)
{
	write(1, "map error.\n", 11);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*filename;

	i = 0;
	while (++i < argc)
	{
		if (argc == 1)
			filename = ft_create_map();
		else
			filename = argv[i];
		if (ft_checkmap(filename) == -1)
			ft_put_error();
	}
	return (0);
}
