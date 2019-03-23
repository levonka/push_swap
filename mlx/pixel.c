#include "../inc/push_swap.h"

t_pixel		init_pixel(double x, double y, unsigned int color)
{
    t_pixel pix;

	pix.x = x;
    pix.y = y;
    pix.color = color;
    return (pix);
}
