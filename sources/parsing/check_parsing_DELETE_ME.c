
#include "../../includes/rt.h"

void		check_parsing(t_scene *rt)
{
	int n = 0;
	printf("\e[92;4mCamera:\n\e[0m");
	printf("Rotate:\t\t\tPlase:\n");
	printf("x %f\t\tx %f\n", rt->camera.rotate.anglex, rt->camera.place.x);
	printf("y %f\t\ty %f\n", rt->camera.rotate.angley,rt->camera.place.y);
	printf("z %f\t\tz %f\n", rt->camera.rotate.anglez,rt->camera.place.z);
	printf("\n");
	printf("\e[92;4mLights:\n\e[0m");
	printf("Type:\t\tPlase:\t\tDirection:\tIntensity:\n");
	while (rt->lights[n] != NULL)
	{
		printf("%d\t\tx %f\tx %f\t\t%f\n", rt->lights[n]->type,rt->lights[n]->position.x,rt->lights[n]->direction.x, rt->lights[n]->intens);
		printf("\t\ty %f\ty %f\n", rt->lights[n]->position.y,rt->lights[n]->direction.y);
		printf("\t\tz %f\tz %f\n", rt->lights[n]->position.z, rt->lights[n]->direction.z);

		printf("Color:\n");
		printf("r %c\n", rt->lights[n]->color.r);
		printf("g %c\n", rt->lights[n]->color.g);
		printf("b %c\n", rt->lights[n]->color.b);
		printf("\n");
		n++;
	}
	n = 0;
	printf("\e[92;4mObjects:\n\e[0m");

	while (rt->object[n] != NULL)
	{
		printf("Type:\t\tRadius:\t\t\tAngel:\t\tHigh:\n");
		printf("\e[93;4m%d\e[0m\t\t%f\t\t%f\t\t%d\n", rt->object[n]->type,rt->object[n]->radius, rt->object[n]->angle, rt->object[n]->high);
		printf("Specularity:\tReflection:\t\tRefraction:\n");
		printf("%d\t\t%f\t\t%f\n", rt->object[n]->specular, rt->object[n]->reflection, rt->object[n]->refraction);
		printf("Position:\t\tColor:\t\tNormal:\t\tNormal Angel:\n");
		printf("x %f\t\tr %c\t\tx %f\t\tx %f\n", rt->object[n]->center.x, rt->object[n]->color.r, rt->object[n]->axis.x, rt->object[n]->axis_angle.x);
		printf("y %f\t\tg %c\t\ty %f\t\ty %f\n", rt->object[n]->center.y, rt->object[n]->color.g, rt->object[n]->axis.y, rt->object[n]->axis_angle.y);
		printf("z %f\t\tb %c\t\tz %f\t\tz %f\n", rt->object[n]->center.z, rt->object[n]->color.b, rt->object[n]->axis.z, rt->object[n]->axis_angle.z);
		printf("\n");
		n++;
	}
}
