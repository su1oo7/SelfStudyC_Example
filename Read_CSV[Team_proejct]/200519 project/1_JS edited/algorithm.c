#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<time.h>
#include"team.h"

void test_open_file()
{
	FILE* fcsv;
	char info[100];
	char* next_point;
	char* cut;

	int i = 1;
	int flag = 0;


	if (fopen_s(&fcsv, "C:\\Users\\Sub\\Desktop\\AI\\KSA.csv", "r") != 0)
	{
		printf("���� ����");
		fclose(fcsv);
	}
	while (1)
	{
		if ((fgets(info, sizeof(info), fcsv) == NULL))
		{

			break;
		}

		if (info[0] == '\"')
		{
			printf("asdaf");
			while (1)
			{
				if (info[i] == '"')
				{
					printf("1");
					break;
				}
				else if (info[i] == ',')
				{
					printf("2");
					info[i] = ' ';
				}
				++i;
			}
		}

		printf("%s", info);


		
	}

	fclose(fcsv);

}



void csv_file(char directory[50])
{
	FILE* fcsv;
	char info[100];
	char* next_point;
	char* cut;
	

	int flag = 0;		// csv���� 0�࿡ �ִ� ���� ������� �ʱ� ���� .. 1��° ������� cut���
	int flag2 = 0;		// csv���Ͽ��� ����, ȸ��, �̸�, �̸���, �б�, ������ �����ϱ� ����
	int i =0; // �� �ȿ� ,�� ���� ��츦 ���� ���� ����

	
	if (fopen_s(&fcsv, directory, "r") != 0)
	{
		printf("���� ����");
		fclose(fcsv);
	}
	while (1)
	{
		if ((fgets(info, sizeof(info), fcsv) == NULL))
		{

			
			break;
		}
		++flag;

		
		
		while (1)
		{
			if (info[i] == '\"')
			{
				info[i] = '?';
				while (1)
				{
					if (info[i] == ',')
					{

						info[i] = ' ';
						
				
					}else if(info[i] == '"')
					{
						info[i] = '?';
						i = -2;
						break;
					}
					++i;
				}
			}

			if ((i == -1) || ( i == 99))
			{
				break;
			}
			++i;
		
		}
		i = 0;

		info[strlen(info) - 1] = '\0';

		cut = strtok_s(info, ",?", &next_point);
		//printf("%s", info);
		
		while (cut != NULL)
		{
			if (cut != NULL)
			{
				if (flag >= 2) 
				{
					
					//printf("%s --- %d --- ", cut,flag); //<<����� �� �ʿ��� ������ ����
					
					
					if (strcmp(cut, "����") == 0)
					{
						st[flag - 2].leader = 1;
						
					}else{ ++flag2; }
					
				

					switch (flag2)
					{
					case 1:
						strcpy_s(st[flag - 2].comp,sizeof(st[flag - 2].comp), cut);
						
						break;
					
					case 2:
						strcpy_s(st[flag - 2].name,sizeof(st[flag - 2].name), cut);
						
						break; 

					case 3:
						strcpy_s(st[flag - 2].email, sizeof(st[flag - 2].email), cut);
						
						break; 

					case 4:
						strcpy_s(st[flag - 2].sch, sizeof(st[flag - 2].sch), cut);
						
						break; 

					case 5:
						strcpy_s(st[flag - 2].major, sizeof(st[flag - 2].major), cut);
						flag2 = 0;
						break;
					}
					
				}


				cut = strtok_s(next_point, ",?", &next_point);
				
			}

			//printf("\n"); // ����� ��  �ʿ��� ������ ����
		}

	}

	/*
	for (i = 0; i < 24; i++)
	{
		printf("%d == %s == %s == %s == %s == %s\n", st[i].leader, st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);

	}
	*/
	
	fclose(fcsv);

}
void output_file()
{
	FILE* fr;
	char str[30],*num,*name[30],*comp[30];
	char* slice = NULL;
	char* next_point = NULL;
	int flag = 0;
	fopen_s(&fr, "team.txt", "r");

	while (1)
	{
		if (fgets(str, sizeof(str), fr) == NULL)
		{
			break;
		}
		str[strlen(str) - 1] = '\0';
		printf("%s", str);

		slice = strtok_s(str, "   ", &next_point);
		flag = 0;
		while (slice != NULL)
		{
			if (slice != NULL)
			{
				//printf(" %s\n", slice); << ������ ����

				//3���� �и�����. num�� ������ ���ڷ� ��ȯ�ϱ�. name�̶� comp�� �迭�� �����ϴ��� �ϱ�.
				if (flag == 0) { num = slice; printf("=%c=", *num); }
				if (flag == 1) { *name = slice; printf("=%s=", *name); }
				if (flag == 2) { *comp = slice; printf("=%s=", *comp); }
				++flag;
				slice = strtok_s(NULL, "   ", &next_point);
			}
		}
		

	}
}


void input_file()
{
	FILE* fo;
	int i;

	// ������ ������ a ���� ����
	if (fopen_s(&fo, "data.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "data.txt", "w") != 0)
		{
			printf("���� ���� ����");
			fclose(fo);
		}
	}

					// �ؽ�Ʈ ������ �Է��� �� �Լ� ������ �Ϸ��ϵ��� ���ĺ���.//
/*	for (i = 0; i < count; i++)
	{

		if (st[i].leader == 1)
		{
			fprintf(fo, "���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			
		}
		else
		{
			fprintf(fo, "���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			
		}

	}


	fclose(fo);*/

}


void  input_info(team* t12)
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

void print_info()
{
	int chk,i;
	char name[20];

	while (1)
	{
		printf("\n���� �˻� �� 1 �Է�\nȸ��� �˻� �� 2 �Է�\n�̸� �˻� �� 3 �Է�\n�б� �˻� �� 4 �Է�\n����� 5 �Է�\n>>> ");
		scanf_s("%d", &chk);
	switch (chk)
	{
		// ���� �˻�
	case 1:

		printf("===================\n");
		for (i = 0; i < 24; i++)
		{
			if (st[i].leader == 1)
			{
				printf("%s\n",st[i].name);
			}
			
		}
		printf("���� �̸��� �Է��ϼ��� : ");
		scanf_s("%s", name, sizeof(name));
		printf("\n");

		search_leader(name);


		break;



		// ȸ��� �˻�
	case 2:

		printf("===================\n");
		for (i = 0; i < 24; i++)
		{
			if (strcmp(st[i].comp, st[i + 1].comp) != 0)
			{
				printf("%s\n", st[i].comp);
			}

		}

		printf("ȸ����� �Է��ϼ��� : ");
		scanf_s("%s", name, sizeof(name));
		printf("\n");

		search_company(name);


		break;



		// �̸� �˻�
	case 3:

		printf("===================\n");
		
		for (i = 0; i < 24; i++)
		{
			printf("%s\n", st[i].name);
		}
		
		printf("�̸��� �Է��ϼ��� : ");
		scanf_s("%s", name, sizeof(name));
		printf("\n");

		search_name(name);


		break;



		// �б� �˻�
	case 4:

		printf("===================\n");

		printf("�б� �̸��� �Է��ϼ��� (ex ��ϴ��б�) : ");
		scanf_s("%s", name, sizeof(name));
		printf("\n");

		search_school(name);

		break;
	}
	if (chk == 5)
	{
		break;
	}
	}
	
}

void search_leader(char name[20])
{
	int i;
	int count=0;
	char company_name[20];

									//======/�ؽ�Ʈ ���� �Է� �����ϱ�/======//
	FILE* fo;


	// ������ ������ a ���� ����
	if (fopen_s(&fo, "data.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "data.txt", "w") != 0)
		{
			printf("���� ���� ����");
			fclose(fo);
		}
	}

	// ī������ ���� �˻��� ������ �̸��� ����ü �迭���� �� ��°�� �ִ��� ã�Ƴ�.
	while (1)
	{
		if (strcmp(st[count].name, name) == 0)
		{
			strcpy_s(company_name, sizeof(company_name), st[count].comp);
			break;
		}
		++count;
	}

							//�ڡ١ڡ١ڡ١ڡ١ڡٱ����� �ϵ��ڵ��ڡ١ڡ١ڡ١ڡ١ڡ�//
	while (strcmp(st[count].comp, st[count + 1].comp) == 0)
	{
		if (st[count].leader == 1)
		{
			printf("���� == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
			fprintf(fo, "���� == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
		}
		else
		{
			printf("���� == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
			fprintf(fo, "���� == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
		}

		count++;
	}

	printf("���� == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
	fprintf(fo, "���� == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);

	

	fclose(fo);
}

void search_school(char name[20])
{
	int i;
	int chk = 0;  // �� ���� ������ �˻��ߴ��� Ȯ��

									//======/�ؽ�Ʈ ���� �Է� �����ϱ�/======//
	FILE* fo;
	

	// ������ ������ a ���� ����
	if (fopen_s(&fo, "data.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "data.txt", "w") != 0)
		{
			printf("���� ���� ����");
			fclose(fo);
		}
	}

	for (i = 0; i < 24; i++)
	{
		if (strcmp(st[i].sch, name) == 0)
		{

			if (st[i].leader == 1)
			{
				printf("���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo,"���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				++chk;
			}
			else
			{
				printf("���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo,"���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				++chk;
			}

		}
	}

	fclose(fo);
}

void search_company(char name[20])
{
	int i;

									//======/�ؽ�Ʈ ���� �Է� �����ϱ�/======//
	FILE* fo;
	

	// ������ ������ a ���� ����
	if (fopen_s(&fo, "data.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "data.txt", "w") != 0)
		{
			printf("���� ���� ����");
			fclose(fo);
		}
	}
	
	for (i = 0; i < 24; i++)
	{
		if (strcmp(st[i].comp, name) == 0)
		{

			if (st[i].leader == 1)
			{
				printf("���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo, "���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			}
			else
			{
				printf("���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo,"���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			}
			
		}
	}

	fclose(fo);
	
}


void search_name(char name[20])
{
	int i;

								//======/�ؽ�Ʈ ���� �Է� �����ϱ�/======//
	FILE* fo;
	

	// ������ ������ a ���� ����
	if (fopen_s(&fo, "data.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "data.txt", "w") != 0)
		{
			printf("���� ���� ����");
			fclose(fo);
		}
	}

	for (i = 0; i < 24; i++)
	{
		if (strcmp(st[i].name, name) == 0)
		{
			if (st[i].leader == 1)
			{
				printf("���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo, "���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			}
			else
			{
				printf("���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo, "���� == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			}

		}
	}

	fclose(fo);
}


void sort_nums(team* t1)
{
	int i;
	printf("��ȣ		   ����			  ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d			 %s			%s\n", t1[i].num, t1[i].name, t1[i].comp);
	}

	input_file(t1);
}

void sort_name(team* t)
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
		for (j = 0; j < 5; j++)
		{
			if (strcmp(cmp[j].name, cmp[j + 1].name) > 0)
			{
				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;

			}
		}

	}

	printf("��ȣ		   ����			  ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d			 %s			%s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}

void sort_comp(team* t)
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
		for (j = 0; j < 5; j++)
		{
			if (strcmp(cmp[j].comp, cmp[j + 1].comp) > 0)
			{

				tmp = cmp[j];
				cmp[j] = cmp[j + 1];
				cmp[j + 1] = tmp;


			}
		}

	}

	printf("��ȣ		   ����			  ȸ���\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d			 %s			%s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}