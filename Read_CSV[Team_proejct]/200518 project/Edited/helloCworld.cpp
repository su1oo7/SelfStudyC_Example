#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct team {
	int num;
	char name[30];
	char comp[30];

};

void input_info(struct team* t);

void sort_name(struct team* t);
void sort_comp(struct team* t);
void sort_num(struct team* t);

void input_file(struct team* t1);

int main(void) {


	struct team t1[6];


	int i, chk;



	input_info(t1);

	//���� �� -- ���� �˰��� �־ ���.
	printf("��ȣ�� ���� �� 1 �Է�, ���� ���� �� 2 �Է�, ȸ��� ���� �� 3 �Է�  : ");
	scanf_s("%d", &chk);

	switch (chk)
	{
		// ��ȣ�� ����
	case 1:

		sort_num(t1);

		break;

		// ���� ����
	case 2:

		sort_name(t1);

		break;

		// ȸ��� ����
	case 3:

		sort_comp(t1);

		break;
	}




	return 0;

}

void input_file(struct team *t1)
{
	FILE* fo;
	int i;

	fopen_s(&fo, "team.txt", "w");

	for (i = 0; i < 6; i++)
	{
		fprintf(fo, "%d   %s   %s\n", t1[i].num, t1[i].name, t1[i].comp);
	}


	fclose(fo);
	
}


void  input_info(struct team* t12)
{
	int i;

	for (i = 0; i < 6; i++)
	{
		printf("%d ��° ���� �Է� : ", (i + 1));
		t12[i].num = i + 1;
		scanf_s("%s", t12[i].name, sizeof(t12[i].name));
		printf("ȸ��� �Է� : ");
		scanf_s("%s", t12[i].comp, sizeof(t12[i].comp));
		printf("=======================\n");

	}

}

void sort_num(struct team* t1)
{
	int i;
	printf("��ȣ   ����   ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", t1[i].num, t1[i].name, t1[i].comp);
	}

	input_file(t1);
}

void sort_name(struct team* t)
{
	int i, j;
	team cmp[6];
	team tmp;

	for (i = 0; i < 6; i++)
	{
		cmp[i] = t[i];
	}

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (strcmp(cmp[j].name, cmp[j + 1].name) > 0)
			{
				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;

			}
		}

	}

	printf("��ȣ    ����    ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}

void sort_comp(struct team* t)
{
	int i, j;
	team cmp[6];
	team tmp;



	for (i = 0; i < 6; i++)
	{
		cmp[i] = t[i];
	}

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (strcmp(cmp[j].comp, cmp[j + 1].comp) > 0)
			{

				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;


			}
		}

	}

	printf("��ȣ    ����    ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d      %s      %s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}