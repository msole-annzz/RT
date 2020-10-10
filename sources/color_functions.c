#include "../../includes/rt.h"

int		get_light(int color1, int color2, float coefficient)
{
	if (coefficient > 1.0)
		coefficient = 1.0;
	return ((int)(color1 * (1.0 - coefficient) + color2 * coefficient));
}

int		result_color(int color1, int color2, float coefficient)
{
	float	red;
	float	green;
	float	blue;

	if (color1 == color2 || color2 < 0 || coefficient == 0)
		return (color1);
	red = get_light((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, coefficient);
	green = get_light((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, coefficient);
	blue = get_light(color1 & 0xFF, color2 & 0xFF, coefficient);
	return (((int)red << 16) | ((int)green << 8) | (int)blue);
}
