#include "../inc/push_swap.h"

t_img   init_img(void *mlx, int width, int height)
{
    t_img   img;
    img.width = width;
    img.height = height;
    img.img = mlx_new_image(mlx, img.width, img.height);
    if(!img.img)
    {
        img.data = NULL;
        return (img);
    }
    img.data = (unsigned int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,
                                                &img.size_line, &img.end);
    return(img);
}

int    draw_img(void *mlx, void *win, t_img img)
{
    return (mlx_put_image_to_window(mlx, win, img.img, 0, 0));
}

int put_pix_img(void *mlx, void *mx, t_pixel p, unsigned int color)
{
    t_mlx *m;
    t_img *img;
    // unsigned int color;

    m = (t_mlx *)mx;
    img = &(m->img);
   // color = mlx_get_color_value(mlx, p.color);
    // color = 0xFFFFFF;
	if ((p.y <= img->height) &&  (p.y > 0) && (p.x <= img->width) &&  (p.x > 0))
        img->data[(int)p.y * img->width + (int)p.x] = color;
    return (1);
}