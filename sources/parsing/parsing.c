
#include "../../includes/rt.h"

void	camera_parsing(char *str, int *index, t_scene *rt)
{
	int checker;

	checker = 0;
	while (((checker % 2) == 0) && (checker < 4))
	{
		if (find_quotes(str, index, "\"position\"\0"))
		{
			rt->camera.place = parsing_coordinates(str, index);
			*index += 1;
			checker++;
		}
		else if (find_quotes(str, index, "\"direction\"\0"))
		{
			rt->camera.rotate = parsing_angles(str, index);
			checker++;
		}
		else
			file_contents_error();
		checker++;
	}
}

void	check_normals(t_scene *rt)
{
	int n;

	n = 0;
	while (rt->object[n] != NULL)
	{
		if ((rt->object[n]->type == 2) || (rt->object[n]->type == 3) ||\
			(rt->object[n]->type == 4))
			if ((rt->object[n]->axis.x == 0) &&\
			(rt->object[n]->axis.y == 0) && \
			(rt->object[n]->axis.z == 0))
				file_contents_error();
		n++;
	}
}

void	parsing_cont(char *str, int *index, t_scene *rt)
{

	if (find_quotes(str, index, "\"objects\"\0"))
	{
		*index += 1;
		objects_parsing(str, index, rt);
	//	printf("ob");
	}
	else
		file_contents_error();
	check_normals(rt);
}

void	parsing(char *str, t_scene *rt)
{
	int *index;
	int x;

	x = 1;
	index = &x;
	if (find_quotes(str, index, "\"camera\"\0"))
	{
		*index += 2;
		camera_parsing(str, index, rt);
		//printf("cam");
	}
	else
		file_contents_error();
	if (find_quotes(str, index, "\"lights\"\0"))
	{
		*index += 1;
		lights_parsing(str, index, rt);
		//printf("li");
	}
	else
		file_contents_error();
	parsing_cont(str, index, rt);
}
