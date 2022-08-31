#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[0])
		return (0);
	ft_fdf(argv[1]);
	return (0);
}