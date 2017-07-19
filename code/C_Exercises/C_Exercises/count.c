//#include <stdio.h>
//#include <string.h>
//
//
//int main()
//{
//	int count[65536];
//	memset(count, 0, sizeof(count));//数组初始化为0；
//	FILE *fp;
//	if ((fp = fopen("D:\\txt\\test.txt", "rb")) == NULL)
//	{
//		perror("无法打开test.txt文件！");
//		return -1;
//	}
//	unsigned short x = 0;
//	while (!feof(fp)) {
//		fread(&x, 2, 1, fp);
//		count[x] += 1;
//	}
//	fclose(fp);
//	if ((fp = fopen("D:\\txt\\count.txt", "wb")) == NULL) {
//		perror("无法打开count.txt文件！");
//		return -1;
//	}
//	x = 0xFEFF;
//	fwrite(&x, 2, 1, fp);//x写在文件的开头，意思是：本文件是以unicode编码的，以little endian存放的。
//	unsigned short space = 0x20;//空格的unicode码对应打的整数。
//	unsigned short cr = 0x000A;//对应换行。
//	//unsigned short lf = 0x000D;
//	unsigned short num0 = 0x0030;
//	
//	for (unsigned short i = 0; i != 65535; ++i) {//接下来写入的（0-65535）的整数都代表一个unicode编码所对应的字符。
//		if (count[i] > 0) {
//			fwrite(&i, 2, 1, fp);
//			unsigned short num = count[i] + num0;//数字所对应的unicode码。
//			fwrite(&space, 2, 1, fp);//将space写入fp中，一个元素，每个元素两个字节。
//			fwrite(&num, 2, 1, fp);
//			fwrite(&cr, 2, 1, fp);
//			//fwrite(&lf, 2, 1, fp);
//		}
//	}
//	fclose(fp);
//	return 0;
//}