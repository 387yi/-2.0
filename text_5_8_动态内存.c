#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int main()
{
	//���ڴ�����40���ռ�	
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		//��ӡ����ķ���
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d\n", *(p + i));
		}
	}
	//ʹ����󷵻��ڴ�
	free(p);
	//p������ָ��ռ��ַ
	//��p����Ϊ��ָ���ֹ������
	p = NULL;
	return 0;
	//realloc //��һ���Ļ��������������ֽ�
	int* p2 = realloc(p, 20);
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
		free(p);
		p = NULL;
	}
	//calloc��malloc����������һ�����ʼ�������ж�������
	int *p=calloc(10, sizeof(int));
	free(p);
	p = NULL;
	return 0;
}