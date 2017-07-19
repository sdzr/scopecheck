//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	char str1[100];
//	int length1 = 0;
//	int length2 = 0;
//	int j = 0, k = 0;
//	char str2[20];
//	int count = 0;
//	printf("请输入字符串待查询字符串1：\n");
//	gets(str1);
//	printf("请输入字符串待查询字符串1：\n");
//	gets(str2);
//	length1 = strlen(str1);
//	length2 = strlen(str2);
//	for (int i = 0; i <= (length1 - length2); i++)
//	{
//		for (j = 0, k = i; j < length2&&str1[k] == str2[j]; j++, k++);
//		if (j == length2)
//		{
//			count++;
//		}
//	}
//
//	printf("%d", count);
//
//
//
//	system("pause");
//	return 0;
//}