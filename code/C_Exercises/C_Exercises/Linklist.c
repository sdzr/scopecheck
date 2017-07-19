#include<stdlib.h>
#include<stdio.h>
#include <string.h>
struct node
{
	char str[1000];
	struct node *next;
};

////创建node。用于插入到链表中。
//struct node * creatNode(char *str)
//{
//	struct node *newnode;
//	newnode=(struct node*)malloc
//}

//创建链表。
struct node *createList()
{
	struct node *head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	head->str[1000] = '\0';
	head->next = NULL;
	return head;
}

//从尾部插入新节点。
void tailInsert(struct node *pnode,struct node *head)
{
	struct node *newnode;
	struct node *temp;
	temp = head;
	newnode = (struct node*)malloc(sizeof(struct node));
	strcpy(newnode->str, pnode->str);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = NULL;	
	return;
}

//指定位置插入节点。在第i个节点插入节点pnode，到链表head中。
void indexInsert(int i, struct node *pnode, struct node *head)
{
	struct node *temp;
	temp = head;
	if (head->next == NULL)
	{
		printf("链表为空，无法在指定节点前插入节点");
		return;
	}
	for (int j = 0; j < i-1; j++)
	{
		temp = temp->next;
	}
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	strcpy(newnode->str, pnode->str);
	newnode->next = temp->next;
	temp->next = newnode;
	return;
}

//获取链表的长度。
int getlength(struct node *head)
{
	struct node *temp;
	temp = head;
	int len = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		len++;
	}
	return len;
}

//从链表尾部删除节点。
struct node *tailDelete(struct node *head)
{
	if (head->next == NULL)
	{
		printf("节点为空，无法从尾部删除，删除失败，返回为空指针\n");
		return NULL;
	}
	struct node *temp;
	struct node *ret;
	temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	ret = temp->next;
	temp->next = NULL;
	return ret;
}

//删除指定位置的head的节点。返回被删除的节点。
struct node* indexDelete(int i, struct node *head)
{
	struct node *temp;
	struct node *ret;
	temp = head;
	if (head->next == NULL)
	{
		printf("链表为空，删除失败，返回空指针");
		return NULL;
	}
	if (i == getlength(head))
	{
		return ret = tailDelete(head);
	}
	if (i > getlength(head))
	{
		printf("索引位置超出，删除失败，返回空指针\n");
		return NULL;
	}
	for (int j = 0; j < i-1; j++)
	{
		temp = temp->next;
	}
	ret = temp->next;
	temp->next = temp->next->next;
	ret->next = NULL;
	return ret;
}

//打印链表。
void listPrint(struct node *head)
{
	struct node *temp;
	temp = head;
	int i = 1;
	if (temp->next == NULL)
	{
		printf("链表为空!\n");
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		printf("第 %d 节点内容：  ", i);
		puts(temp->str);
		i++;
	}
	return;
}

//保存链表到指定文件下。str为文件名称字符串。
void saveList(char *str, struct node *head)
{
	struct node *temp;
	int i=1;
	temp = head;
	FILE *fp;
	if ((fp = fopen(str, "w")) == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	if (temp->next == NULL)
	{
		printf("链表为空!没有写入\n");
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		fprintf(fp,"第 %d节点内容：", i);
		fputs(temp->str, fp);
		fprintf(fp,"\n");
		i++;
	}
	fclose(fp);
	return;
}
//此函数有误，要再改改。按照strcmp来排序。i位排序的正反，i=-1或1；
void listSort(struct node *head,int i)
{
	struct node *temp;
	char arr[1000];
	temp = head;
	if (temp->next == NULL)
	{
		printf("链表空\n");
		return;
	}
	if (getlength(head) == 1)
	{
		return;
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
		if (strcmp(temp->str, temp->next->str) == i)
		{
			strcpy(arr, temp->str);
			strcpy(temp->str, temp->next->str);
			strcpy(temp->next->str, arr);
		}
	}
	return;
}
//字符匹配查询。
struct node *listCheck(char *str,struct node *head)
{
	struct node *temp;
	char *ret;
	temp = head;
	if (head->next == NULL)
	{
		printf("链表为空，不包含该字符\n");
		return NULL;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		ret = strstr(temp->str, str);
		if (ret != NULL)
		{
			return temp;
		}
	}
	printf("链表不包含该字符\n");
	return NULL;
}
//链表逆转。
void listReverse(struct node *head)
{
	struct node *temp;
	struct node *tp;
	char arr[100];
	int i = 0;
	i = getlength(head);
	temp = head;
	if (temp->next == NULL)
	{
		printf("链表为空");
		return;
	}
	if (temp->next->next == NULL)
	{
		return;
	}
	for (int j = 1; j <= i / 2; j++)
	{
		tp = head;
		temp = temp->next;
		for (int k = 1; k <= i-j+1;k++)
		{
			tp = tp->next;
		}
		strcpy(arr, temp->str);
		strcpy(temp->str, tp->str);
		strcpy(tp->str, arr);
	}
	return;
}
//链表文件读取。返回一个链表头结点的指针。
struct node *fileRead(char *str)
{
	struct node *List;
	char read[1000];
	List = createList();
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	FILE *fp;
	if ((fp = fopen(str, "r")) == NULL)
	{
		printf("无法打开指定文件：\n");
		return NULL;
	}
	while (fgets(read, 1000, fp)!=NULL)
	{
		strcpy(temp->str, read+15);
	    tailInsert(temp, List);
	}
	

	free(temp);
	fclose(fp);
	return List;
}

int main()
{
	//初始化链表。
	int i = 0;
	struct node *List;
	char arr[] = "D:\\txt\\A.txt";
	List = fileRead(arr);
	//List = createList();

	////创建节点，用于插入等操作。
	//struct node no1;
	//char str1[] = "agdfgwafs";
	//strcpy(no1.str, str1);

	//struct node no2;
	//char str2[] = "13233a";
	//strcpy(no2.str, str2);

	//struct node no3;
	//char str3[] = "ooozxvzb";
	//strcpy(no3.str, str3);

	//tailInsert(&no1, List);
	//tailInsert(&no2, List);
	//tailInsert(&no3, List);

	//listSort(List, 1);
	listPrint(List);

	//listReverse(List);
	//listSort(List, -1);
	//i = getlength(List);
	//printf("%d", i);
	//listPrint(List);

	/*struct node *no4;
	no4 = listCheck(&no2, List);*/
	//char arr[] = "D:\\txt\\A.txt";
	/*puts(no4->str);*/

	//saveList(arr, List);
	system("pause");
	return 0;
}