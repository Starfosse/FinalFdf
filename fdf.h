#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFFER_SIZE 500
# define HAUTEUR 1000
# define LARGEUR 1500

typedef struct s_data
{
	int		dx;
	int		dy;
	int		slope_director;
	int		slope_error;
	int		x_increment;
	int		y_increment;
}			t_data_slope;

typedef struct s_fdf
{
	int		count_y;
	int		count_x;
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	int		t;
	char	*data;
	int		color;
	int		bpp;
	int		endian;
	int		i;
	int		j;
	char	*line;
	char	**lines;
	int		zoom;
	int		**tab;
}			t_fdf;

typedef struct s_segment
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}		t_segment;

char	*get_next_line(int fd);
void	ft_fdf(char *argv);
int	check_argv(char *argv);
t_fdf	ft_init(char *argv);
int	ft_close(t_fdf *param);
void	ft_draw_the_map(int x, int y, int **tab, t_fdf *f);
t_segment	get_seg(int **tab, int i, int j, t_fdf *f);
t_segment	get_seg2(int **tab, int i, int j, t_fdf *f);
int	expose_hook(t_fdf *f);
size_t	ft_strlen1(char *str);
char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char *s, char *c);
void	free_coord(int **map, int count_y);
void	clean_split(char **split);
void	print_map(int **map, int count_x, int count_y);
void	draw_segment(t_fdf *fdf, t_segment s);

#endif