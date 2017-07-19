//#include <stdlib.h>
//#include <stdio.h>
//int main()
//{
//	FILE *fp1;
//	FILE *fp2,*fp3;
//	char str1[5], str2[100];
//	if ((fp1 = fopen("D:\\txt\\A.txt", "r")) == NULL)
//	{
//		perror("无法打开文件A.txt");
//		exit(0);
//	}
//	if ((fp2 = fopen("D:\\txt\\B.txt", "r")) == NULL)
//	{
//		perror("无法打开文件B.txt");
//		exit(0);
//	}
//
//	fgets(str1, 5 , fp1);
//	fgets(str2, 100, fp2);
//	strcat(str1,str2);
//	for (int i = strlen(str1) - 1; i > 1; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (str1[j]> str1[j + 1])
//			{
//				str1[j] = str1[j] ^ str1[j + 1];
//				str1[j + 1] = str1[j + 1] ^ str1[j];
//				str1[j] = str1[j] ^ str1[j + 1];
//			}
//		}
//	}
//	if ((fp3 = fopen("D:\\txt\\C.txt", "w")) == NULL)
//	{
//		perror("无法打开文件C.txt");
//	}
//	fputs(str1, fp3);
//	
//	
//
//	fclose(fp3);
//	fclose(fp1);
//	fclose(fp2);
//	system("pause");
//	return 0;
//}