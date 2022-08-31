#include "fdf.h"

int	ft_close(t_fdf *param)
{
	if (param->tab)
		free_coord(param->tab, param->count_y);
	if (param->mlx_ptr && param->image)
		mlx_destroy_image(param->mlx_ptr, param->image);
	if (param->mlx_ptr && param->win_ptr)
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	if (param->mlx_ptr)
		mlx_destroy_display(param->mlx_ptr);
	//close(param->fd);
	free(param->mlx_ptr);
	exit(0);
}

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_coord(int **map, int count_y)
{
	int	i;

	i = 0;
	while (i < count_y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_argv(char *argv)
{
	int	fd;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}