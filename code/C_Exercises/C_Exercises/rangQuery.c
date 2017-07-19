//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#define  size  10000000   //点的规模
//#define   pi    3.14159265358979323846 
//#define   r    6356
//
//double distance(double longitudea, double latitudea, double longitudeb, double latitudeb, double sem)
//{
//	latitudea += 90;
//	latitudea = latitudea*pi / 180;
//	latitudeb += 90;
//	latitudeb = latitudeb*pi / 180;
//	longitudea = longitudea*pi / 180;
//	longitudeb = longitudeb*pi / 180;
//	double dist = 0;
//	dist = sem*acos(sin(latitudea)*sin(latitudeb)*cos(longitudea - longitudeb) + cos(latitudea)*cos(latitudeb));
//	return dist;
//}
//int main()
//{
//	double x = 0, y = 0, radius = 0;//radius为查询半径，单位为千米。
//	unsigned int seed = 100;
//	double(*node)[2] = (double(*)[2])malloc(sizeof(double)*size * 2);
//	int id = 0;
//	char judge = '\0';
//	//memset(node, 0, sizeof(node));
//
//	srand(seed);//生成一个每次结果都一样的随机浮点坐标集[0,200]x[0,200]。共10000个点。
//	for (; id < size; id++)
//	{
//			node[id][0] = 360 * rand() / (double)(RAND_MAX)-180;
//			node[id][1] = 180 * rand() / (double)(RAND_MAX)-90;
//		
//	}
//	printf("赋值结束!\n");
//
//	//file *fp;  //将在radius范围内的点存到文件node.txt中。
//	//if ((fp = fopen("d:\\txt\\node.txt", "w")) == null)
//	//{
//	//	printf("无法打开文件node.txt");
//	//	exit(0);
//	//}
//	while (1)
//	{
//		printf("请输入范围在[-180,180]的浮点数地球经度x：\n");//默认东经为正值，西经为负值。
//		scanf("%lf", &x);
//		printf("请输入范围在[-90,90]的浮点数地球纬度y：\n");//北纬为负值，南纬为正值。
//		scanf("%lf", &y);
//		printf("请输入大于0的浮点数查询半径：\n");
//		scanf("%lf", &radius);
//		printf("查询结果为：\n");
//		for (id = 0; id < size; id++)
//		{
//			if (abs(x - node[id][0])*r*pi / 180 > radius&&abs(y - node[id][1])*r*pi / 180> radius)
//			{
//				continue;
//			}
//			if (distance(x, y, node[id][0], node[id][1], r)<=radius)
//			{
//				printf("%d: <%lf , %lf >\n", id, node[id][0], node[id][1]);
//
//			}
//			
//		}
//
//		printf("是否继续查询？，是请输入：y，否请输入：n\n");
//		getchar();
//		scanf("%c", &judge);
//		if (judge == 'n')
//		{
//			exit(0);
//		}
//
//	}
//	free(node);
//	//fclose(fp);
//	system("pause");
//	return 0;
//
//
//}
