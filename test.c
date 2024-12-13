
//# include <libc.h>
//# include <stdio.h>
//# include <math.h>
//double degree_radian(double degree, int type)
//{
//	if (!type) // type == 0 => degree to rad
//		return (degree * (M_PI / 180));
//	return (degree * (180 / M_PI));
//}
//int main(int ac , char **av)
//{
//	printf("degree[%d], radian[%f]\n", atoi(av[1]), degree_radian(atoi(av[1]), 0));
//}