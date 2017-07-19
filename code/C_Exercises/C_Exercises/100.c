//#include<stdlib.h>
//#include<stdio.h.> 
//struct student
//{
//	int  ID;
//	char  name[20];
//	int  math;
//	int  english;
//	int  chinese;
//	int  average;
//};
//int main()
//{
//	FILE *fp;
//	struct student stu[5];
//	printf("请输入5个学生的信息：学生号，姓名，3门课成绩：\n");
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%d,%s,%d,%d,%d", &stu[i].ID, stu[i].name, &stu[i].math,&stu[i].english,&stu[i].chinese);
//		stu[i].average = (stu[i].math+stu[i].english+stu[i].chinese) / 3;
//	}
//	if ((fp = fopen("D:\\txt\\stud", "w")) == NULL)
//	{
//		perror("不能打开此文件！\n");
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		fprintf(fp, "%d %s %d %d %d %d\n", &stu[i].ID, stu[i].name, &stu[i].math, &stu[i].english, &stu[i].chinese, &stu[i].average);
//	}
//	fclose(fp);
//	system("pause");
//	return 0;
//}
