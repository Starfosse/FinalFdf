#include "fdf.h"

void	zoom_up(t_fdf *fdf)
{
	//fdf->zoom += 1;
	fdf->t += 10;
	mlx_expose_hook(fdf->win_ptr, expose_hook, fdf);
	expose_hook(fdf);
}

int	key_press(int keycode, void *param)
{
	if (keycode == 65307)
		ft_close(param);
	else
		printf("keycode == %d\n", keycode);
	if(keycode == 122 || keycode == 100 || keycode ==  115 || keycode == 113)
		zoom_up(param);
	return (0);
}

void	init_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 1L << 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_close, fdf);

}

int	expose_hook(t_fdf *f)
{
	if (f->image)
		mlx_destroy_image(f->mlx_ptr, f->image);
	f->image = mlx_new_image(f->mlx_ptr, LARGEUR, HAUTEUR);
	f->data = mlx_get_data_addr(f->image, &f->bpp, &f->t, &f->endian);
	ft_draw_the_map(f->count_x, f->count_y, f->tab, f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->image, 0, 0);
	return (0);
}

void	ft_fdf(char *argv)
{
	t_fdf	fdf;
	if (!check_argv(argv))
		return ;
	fdf = ft_init(argv);
	fdf.mlx_ptr = mlx_init();
	if (!fdf.mlx_ptr)
		ft_close(&fdf);
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, LARGEUR, HAUTEUR, "mlx 42");
	if (!fdf.win_ptr)
		ft_close(&fdf);
	fdf.color = 0xABCDEF;
	init_controls(&fdf);
	mlx_expose_hook(fdf.win_ptr, expose_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
}