#include "fdf.h"

t_segment	get_seg(int **tab, int x, int y, t_fdf *f)
{
	t_segment	s;

	s.x1 = f->t + (f->t * x) - (f->t / 2 * y);
	s.y1 = f->t + (f->t * y) - ((f->t / 2) * (tab[y][x])) + ((f->t / 2) * x);
	s.x2 = f->t + (f->t * (x + 1)) - (f->t / 2 * y);
	s.y2 = f->t + (f->t * y) - ((f->t / 2) * (tab[y][(x + 1)])) + ((f->t / 2) * (x + 1));
	//printf("seg 1/s.x1 == %d // s.y1 == %d // s.x2 == %d // s.y2 == %d\n", s.x1, s.y1, s.x2, s.y2);
	return (s);
}

t_segment	get_seg2(int **tab, int x, int y, t_fdf *f)
{
	t_segment	s;

	s.x1 = f->t + (f->t * x) - (f->t / 2 * y);
	s.y1 = f->t + (f->t * y) - ((f->t / 2) * (tab[y][x])) + ((f->t / 2) * x);
	s.x2 = f->t + (f->t * (x)) - (f->t / 2 * y);;
	s.y2 = f->t + (f->t * y) - ((f->t / 2) * (tab[y + 1][x])) + ((f->t / 2) * (x + 1));
	//printf("seg 2/ s.x1 == %d // s.y1 == %d // s.x2 == %d // s.y2 == %d\n", s.x1, s.y1, s.x2, s.y2);
	return (s);
}