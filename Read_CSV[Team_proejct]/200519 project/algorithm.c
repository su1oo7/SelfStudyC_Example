#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"team.h"
void test_open_file()
{
	FILE* fcsv;
	char info[100];
	char* next_point;
	char* cut;

	int i = 1;
	int flag = 0;


	if (fopen_s(&fcsv, "C:\\resert\\LJS.csv", "r") != 0)
	{
		printf("열기 실패");
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

	int flag = 0;		// csv파일 0행에 있는 줄을 출력하지 않기 위해 .. 1번째 실행부터 cut출력
	int i =0; // 셀 안에 ,가 들어가는 경우를 위한 변수 선언

	
	if (fopen_s(&fcsv, directory, "r") != 0)
	{
		printf("열기 실패");
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
					printf("%s --- %d", cut,flag); //<< 지우지 말기

					

				}

				cut = strtok_s(next_point, ",?", &next_point);
				
			}

			printf("\n");
		}

	}
	
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
				//printf(" %s\n", slice); << 지우지 말기

				//3개로 분리했음. num에 받은걸 숫자로 변환하기. name이랑 comp는 배열에 저장하던가 하기.
				if (flag == 0) { num = slice; printf("=%c=", *num); }
				if (flag == 1) { *name = slice; printf("=%s=", *name); }
				if (flag == 2) { *comp = slice; printf("=%s=", *comp); }
				++flag;
				slice = strtok_s(NULL, "   ", &next_point);
			}
		}
		

	}
}


void input_file(team* t1)
{
	FILE* fo;
	int i;

	fopen_s(&fo, "team.txt", "a");


	for (i = 0; i < 6; i++)
	{
		fprintf(fo, "%d   %s   %s\n", t1[i].num, t1[i].name, t1[i].comp);
	}


	fclose(fo);

}


void  input_info(team* t12)
{
	int i;

	for (i = 0; i < 6; i++)
	{
		printf("%d 번째 팀명 입력 : ", (i + 1));
		t12[i].num = i + 1;
		scanf_s("%s", t12[i].name, sizeof(t12[i].name));
		printf("회사명 입력 : ");
		scanf_s("%s", t12[i].comp, sizeof(t12[i].comp));
		printf("=======================\n");

	}

}

void print_info(team* t1)
{
	int chk;
	

	while (1)
	{
		printf("번호로 정렬 시 1 입력, 팀명 정렬 시 2 입력, 회사명 정렬 시 3 입력, 종료 시 4 입력 : ");
	scanf_s("%d", &chk);
	switch (chk)
	{
		// 번호로 정렬
	case 1:

		sort_nums(t1);

		break;

		// 팀명 정렬
	case 2:

		sort_name(t1);

		break;

		// 회사명 정렬
	case 3:

		sort_comp(t1);

		break;
	}
	if (chk == 4)
	{
		break;
	}
	}
	
}


void sort_nums(team* t1)
{
	int i;
	printf("번호		   팀명			  회사명\n");
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

	printf("번호		   팀명			  회사명\n");
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

	printf("번호		   팀명			  회사명\n");
	for (i = 0; i < 6; i++)
	{
		printf("%d			 %s			%s\n", cmp[i].num, cmp[i].name, cmp[i].comp);
	}

	input_file(cmp);

}