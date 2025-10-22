#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"

typedef struct s_app {
	void *mlx;
	void *win;
} t_app;

int on_key(int keycode, t_app *a)
{
	if (keycode == 65307) {
		mlx_destroy_window(a->mlx, a->win);
		exit(0);
	}
	return (0);
}

int on_destroy(t_app *a)
{
	(void)a;
	exit(0);
	return (0);
}

int main(void)
{
	t_app a;

	a.mlx = mlx_init();
	if (!a.mlx)
		return (1);
	a.win = mlx_new_window(a.mlx, 640, 480, "mini window");
	if (!a.win)
		return (1);
	mlx_hook(a.win, 2, 1L<<0, on_key, &a);
	mlx_hook(a.win, 17, 0, on_destroy, &a);
	mlx_loop(a.mlx);
	return (0);
}

