#include "minirt.h"

static void	print_amb(t_amb amb)
{
	printf("====AMB====\n");
	printf("id = %c\n", amb.id);
	printf("ratio = %f\n", amb.ratio);
	printf("r = %f\n", amb.rgb.rd);
	printf("g = %f\n", amb.rgb.grn);
	printf("b = %f\n", amb.rgb.blu);
}

void	print_cam(t_cam cam)
{
	printf("====CAM====\n");
	printf("id = %c\n", cam.id);
	printf("pos (x)= %f\n", cam.pos.x);
	printf("pos (y) = %f\n", cam.pos.y);
	printf("pos (z) = %f\n", cam.pos.z);
	printf("v (x) = %f\n", cam.look.x);
	printf("v (y) = %f\n", cam.look.y);
	printf("v (z) = %f\n", cam.look.z);
	printf("FOV = %d\n", cam.fov);
}

static void	print_light(t_light lgt)
{
	printf("====LIGHT====\n");
	printf("id = %c\n", lgt.id);
	printf("point (x) = %f\n", lgt.point.x);
	printf("point (y) = %f\n", lgt.point.y);
	printf("point (z) = %f\n", lgt.point.z);
	printf("bright = %f\n", lgt.bright);
}

static void	print_it(t_obj *obj)
{
	printf("id = %s\n", obj->id);
	printf("pos (x) = %f\n", obj->pos.x);
	printf("pos (y) = %f\n", obj->pos.y);
	printf("pos (z) = %f\n", obj->pos.z);
	if (obj->v.x)
	{
		printf("v (x) = %f\n", obj->v.x);
		printf("v (y) = %f\n", obj->v.y);
		printf("v (z) = %f\n", obj->v.z);
	}
	if (obj->diameter)
		printf("diameter = %f\n", obj->diameter);
	if (obj->height)
		printf("height = %f\n", obj->height);
	printf("r = %f\n", obj->rgb.rd);
	printf("g = %f\n", obj->rgb.grn);
	printf("b = %f\n", obj->rgb.blu);
}

void	print_obj(t_obj *objects)
{
	int	i;

	i = 1;
	while (objects != NULL)
	{
		printf("====OBJECT %d====\n", i);
		print_it(objects);
		i++;
		objects = objects->next;
	}
}

void	print_struct(t_scene *scn)
{
	if (scn->a_light.id == 'A')
		print_amb(scn->a_light);
	if (scn->camera.id == 'C')
		print_cam(scn->camera);
	if (scn->light.id == 'L')
		print_light(scn->light);
	print_obj(scn->object);
}
