#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<time.h>
#include"team.h"
void open_file()
{
	FILE* fcsv;
	/* char info[100];
	char* next_point;
	char* cut;

	int i = 1;
	int flag = 0;
	*/

	if (fopen_s(&fcsv, "ai2.csv", "r") == 0)
	{
		printf("���� ����");
		fclose(fcsv);
	}
	/*while (1)
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


		
	}*/

	fclose(fcsv);

}



void csv_file(char directory[100])	//�ּ� ���ڿ��� �Ű������� ����, ������ ������ �ϴ� �Լ�
{
	FILE* fcsv;			// ���� ������
	char info[100];		// �� �ٿ� �ִ� ���ڿ����� ��� ���Խ�Ű�� ���� ū ���ڸ� ����?
	char* next_point;		//�ؿ� ���� ��, ���� ���� ��
	char* cut;		//�ؿ� ���� ��, ���� ������
	

	int flag = 0;		// csv���� 0�࿡ �ִ� ���� ������� �ʱ� ���� .. 1��° ������� cut���	// 1�� �ϰ� flag++ �� �ٲٸ� error
	int flag2 = 0;		// csv���Ͽ��� ����, ȸ��, �̸�, �̸���, �б�, ������ �����ϱ� ����
	int i =0; // �� �ȿ� ,�� ���� ��츦 ���� ���� ����

	
	if (fopen_s(&fcsv, directory, "r") != 0)	//���� ���Ͽ� ���� ������ directory�� ������, ���� �����Ϳ� ���� ������ fcsv�Դϴ� �б���. ������ 0 ��ȯ
	{
		printf("���� ����");
		fclose(fcsv);
	}
	while (1)
	{
		if ((fgets(info, sizeof(info), fcsv) == NULL))		//�Է��� ��, �迭�� ũ��, ���� ������ ������ ���� �ְ� ���������Ϳ��� ���� �� �迭 ����� ���� ������̶�� �ǹ��ΰ�...���� �б� �����ϴµ� NULL ��, ����ĭ�� �ִٸ��̶�� �����Լ�
		{
			break; // ���� ������ �ѷ��� �ݺ��� Ż���>> if�� �ƴ϶� while Ż���̶�� ���� �߿�����Ʈ��
		}
		++flag;	//flag 1 �ø�, �� ó���̶�� flag=1 �� ���¿��� �Ʒ� if ���ƴٴϴ� ��..

		
		while (1)
		{
			if (info[i] == '\"')	//����ǥ �ִ� info[] ã�´ٸ�
			{
				info[i] = '?';		//����ǥ�� �ٲ��>> �ڿ��� ? ���� ����
				while (1)
				{
					if (info[i] == ',')		// "asd,asd"�������� ���� �ű� ������ �ȿ� ����ִ� , ã�Ƽ� �ݺ��Ұ�
					{

						info[i] = ' ';		// ����� �ٲ��� ���� ?asd asd"�����ΰ���, �긦 ȭ��Ʈ �����̽���� ��. enter, tab������ ����� ������ ��������.
						
				
					}else if(info[i] == '"') //�ٽ� ������ �� ������ ���� "�� �߰��Ѵٸ�
					{
						info[i] = '?';		//����ǥ�� �ٲ��� ������ ?asd asd?�� �Ǿ���
						i = -1;		//���� i�� �� ���� �� �����Ƿ� �� ã�� ���� ���� >> " , " ������ �ϳ��� �ִٴ� �� �˰� ����
						break;
					}
					++i;	// if ���� ���Դٸ� i�� �����ؼ� �ٽ� ���ƿ� ���̰� else if ���� ���Դٸ� -1�� ��
				}
			}

			if ((i == -1) || (i == 99))	//���� � info[i]�� ����ǥ�� ���� ������ ���� ��
			{
				break;	// 99�� �迭�� ���̰� -1�� �� �����ȣ ó���� �����ٴ� ���� �ǹ��� �״ϱ� 89�� while Ż��
			}
			++i; //99�� ��� 100�Ǽ� ���� ���� �ʳ�?????? >>��� while Ż�� �� ++����
		
		}
		i = 0;	// while ����ٸ� i �ʱ�ȭ

		//info[strlen(info) - 1] = '\0';	//���๮��(\n)���� �̷��� info�� �ִ� \n������

		cut = strtok_s(info, ",?", &next_point);	// info�� �о ,�� ?�� �ִٸ� /�Լ� ȣ�� ���� ��ġ ������ ���� �ϴ� �� ��� �˴ϴ�./ ���� ��ū�� ��ȯ�Ѵٴ� �� ��ū??
		//printf("%s", info);
		
		while (cut != NULL)					// ó�� ������ ��, info�� ���忩�� &next�� ������ ���ڵ�(,����) cut�� ���忩����  cut�� NULL�̶�� �� ���δ� �����ߴٴ� ���� �ǹ�
		{//flag=3�ε� �� ���� ���¿��� word>>>>>>�� ���� ������
			if (cut != NULL)
			{
				if (flag >= 2)		//�� ó������ flag =1 ���� ���̴� ����� �ǳʶ�
				{
					
					//printf("%s --- %d --- ", cut,flag); //<<����� �� �ʿ��� ������ ����
					
					
					if (strcmp(cut, "����") == 0)	//cmp: comparison ����, cut�̶� ���ؼ� ������
					{
						st[flag - 2].leader = 1;		//flag-2 �� �ߴ����.....flag�� 2�� �����ؼ� 0������ַ��� �ߴµ� �� 0�� �Ǿ������ st[0]�� �����ؼ�!!! ��ư �̰� ������
						
					}else{ ++flag2; }		//������ �ƴ϶�� �����̹Ƿ� �� ���� �׸��� ȸ�縦 ���غ� �����̴ϱ� flag1�� flag2
					
				

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


				cut = strtok_s(next_point, ",?", &next_point);	//flag2=1���� ������~~������ �����ϴ� ���忡�� ,�� ���� �������� cut�� �� �������� �����ͷ� �ٽ� &next �����ǰ� ���� ������ 
				
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
/*
time_t time(time_t* timer)
{
	time_t nowTime = time(NULL);
	struct tm* pTmNow = localtime(&nowTime);
	if (pTmNow)
		printf("%02d�� %02d�� %02d��\n", pTmNow->tm_hour, pTmNow->tm_min, pTmNow->tm_sec);
}*/

void input_file()
{
	FILE* fo;
	int i;

	// ������ ������ a ���� ����
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "results.txt", "w") != 0)
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
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "results.txt", "w") != 0)
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
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "results.txt", "w") != 0)
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
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "results.txt", "w") != 0)
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
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// ������ ������ w ���� ������ ���� ����
		if (fopen_s(&fo, "results.txt", "w") != 0)
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

