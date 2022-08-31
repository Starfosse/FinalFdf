#include "fdf.h"

void	draw_pixel(t_fdf *fdf, int x1, int y1)
{
	size_t	index;
	if (y1 >= HAUTEUR || x1 >= LARGEUR || x1 < 0 || y1 < 0)
		return ;
	printf("%d %d\n", x1, y1);
	index = (y1 * fdf->size_l) + x1 * (fdf->bpp / 8);
	fdf->data[index + 3] = (fdf->color & 0xFF000000) >> 24;
	fdf->data[index + 2] = (fdf->color & 0x00FF0000) >> 16;
	fdf->data[index + 1] = (fdf->color & 0x0000FF00) >> 8;
	fdf->data[index] = fdf->color & 0x000000FF;
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-1 * value);
	return (value);
}

void	draw_segment2(t_fdf *fdf, t_segment s, t_data_slope data)
{
	while (!(s.x1 == s.x2 && s.y1 == s.y2))
	{
		if (s.x1 < 1500 && s.x1 > 0 && s.y1 < 1000 && s.y1 > 0)
			draw_pixel(fdf, s.x1, s.y1);
		data.slope_director = 2 * data.slope_error;
		if (data.slope_director >= data.dy)
		{
			data.slope_error += data.dy;
			s.x1 += data.x_increment;
		}
		if (data.slope_director <= data.dx)
		{
			data.slope_error += data.dx;
			s.y1 += data.y_increment;
		}
	}
}

void	draw_segment(t_fdf *fdf, t_segment s)
{
	t_data_slope	data;

	data.dx = ft_abs(s.x2 - s.x1);
	data.dy = -ft_abs(s.y2 - s.y1);
	data.slope_director = 0;
	data.slope_error = data.dx + data.dy;
	data.x_increment = 0;
	data.y_increment = 0;
	if (s.x1 < s.x2)
		data.x_increment = 1;
	else
		data.x_increment = -1;
	if (s.y1 < s.y2)
		data.y_increment = 1;
	else
		data.y_increment = -1;
	draw_segment2(fdf, s, data);
}

void	ft_draw_the_map(int x, int y, int **tab, t_fdf *f)
{
	int	i;
	int	j;
    f->t = 50;
	i = 0;
	j = 0;
	//t_segment	s;
	/*s.x1 = 100;
	s.y1 = 100;
	s.x2 = 900;
	s.y2 = 600;
	draw_segment(f, s);*/
    printf("x == %d et y == %d\n", x, y);
	//printf("zzzz\n");
	//print_map(f->tab, f->count_x, f->count_y);
	while (j < y - 1)
	{
		while (i < x - 1)
		{
			draw_segment(f, get_seg(tab, i, j, f));
			//s = get_seg(tab, i, j, f);
			//printf("seg 1/s.x1 == %d // s.y1 == %d // s.x2 == %d // s.y2 == %d\n", s.x1, s.y1, s.x2, s.y2);
			draw_segment(f, get_seg2(tab, i, j, f));
            //printf("[%d] ", tab[j][i]);
			i++;
		}
		draw_segment(f, get_seg2(tab, i, j, f));
		i = 0;
		j++;
        printf("\n");
	}
	while (i < x - 1)
	{
		draw_segment(f, get_seg(tab, i, j, f));
		i++;
	}
}