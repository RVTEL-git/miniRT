#include "../includes/minirt.h"

static void	print_amb(t_amb amb)
{
	printf("====AMB====\n");
	printf("id = %c\n", amb.id);
	printf("ratio = %f\n", amb.amb_ratio);
	printf("red = %f\n", amb.color.red);
	printf("green = %f\n", amb.color.green);
	printf("blue = %f\n", amb.color.blue);
}

static void	print_cam(t_cam cam)
{
	printf("====CAM====\n");
	printf("id = %c\n", cam.id);
	printf("view (x)= %f\n", cam.view.x);
	printf("view (y) = %f\n", cam.view.y);
	printf("view (z) = %f\n", cam.view.z);
	printf("vec3 (x) = %f\n", cam.vec3.x);
	printf("vec3 (y) = %f\n", cam.vec3.y);
	printf("vec3 (z) = %f\n", cam.vec3.z);
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

// static void	print_it(t_obj *obj)
// {
// 	printf("id = %s\n", obj->id);
// 	printf("pos (x) = %f\n", obj->pos.x);
// 	printf("pos (y) = %f\n", obj->pos.y);
// 	printf("pos (z) = %f\n", obj->pos.z);
// 	if (obj->vec3.x)
// 	{
// 		printf("vec3 (x) = %f\n", obj->vec3.x);
// 		printf("vec3 (y) = %f\n", obj->vec3.y);
// 		printf("vec3 (z) = %f\n", obj->vec3.z);
// 	}
// 	if (obj->diameter)
// 		printf("diameter = %f\n", obj->diameter);
// 	if (obj->height)
// 		printf("height = %f\n", obj->height);
// 	printf("red = %f\n", obj->color.red);
// 	printf("green = %f\n", obj->color.green);
// 	printf("blue = %f\n", obj->color.blue);
// }

// static void	print_obj(t_obj *objects)
// {
// 	int	i;

// 	i = 1;
// 	while (objects != NULL)
// 	{
// 		printf("====OBJECT %d====\n", i);
// 		print_it(objects);
// 		i++;
// 		objects = objects->next;
// 	}
// }

void	print_struct(t_scene *scn)
{
	if (scn->a_light.id == 'A')
		print_amb(scn->a_light);
	if (scn->camera.id == 'C')
		print_cam(scn->camera);
	if (scn->light.id == 'L')
		print_light(scn->light);
	// print_obj(scn->object);
}
