#include "fdf.h"

int	**get_tab(int count_x, int count_y, int fd)
{
	int	    i;
	int     j;
	char	*line;
	char    **lines;
	int	    **tab;

    i = 0;
    j = 0;
	tab = (int **) malloc (sizeof(int *) * count_y);
	ft_bzero(tab, sizeof(int **));
	while(i < count_y)
	{
		tab[i] = (int *) malloc (sizeof(int) * count_x);
		line = get_next_line(fd);
		lines = ft_split(line, ' ');
		while(j < count_x)
		{
			tab[i][j] = ft_atoi(lines[j]);
			j++;
		}
		j = 0;
		i++;
		clean_split(lines);
		free(line);
	}
	return(tab);
}

void    get_columns_and_lines(t_fdf *fdf, int fd)
{
    int		i;
	char	*line;
	char	**columns;
    int     count;

    count = 0;
	i = 0;
	line = get_next_line(fd);
	columns = ft_split(line, ' ');
	while (columns[i])
		i++;
	clean_split(columns);
    fdf->count_x = i;
    while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
    fdf->count_y = count;
}

void	print_map(int **map, int count_x, int count_y) {
 	int y;
 	int x;

 	y = 0;
 	x = 0;
 	while (y < count_y) {
 		while (x < count_x) {
 			x++;
 			printf("[%d]", map[y][x]);
 		}
		printf("\n");
 		y++;
 		x = 0;
 	}
}

t_fdf	ft_init(char *argv)
{
	t_fdf	fdf;

	ft_bzero(&fdf, sizeof(t_fdf));
	fdf.fd = open(argv, O_RDONLY);
	if (fdf.fd == -1)
		ft_close(&fdf);
    get_columns_and_lines(&fdf, fdf.fd);
	close(fdf.fd);
    fdf.fd = open(argv, O_RDONLY);
    fdf.tab = get_tab(fdf.count_x, fdf.count_y, fdf.fd);
    printf("fdf.count_x == %d, fdf.count_y == %d\n", fdf.count_x, fdf.count_y);
    print_map(fdf.tab, fdf.count_x, fdf.count_y);
    close(fdf.fd);
	return (fdf);
}