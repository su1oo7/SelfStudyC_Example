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
		printf("열기 실패");
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



void csv_file(char directory[100])	//주소 문자열이 매개변수로 들어가는, 파일을 열려고 하는 함수
{
	FILE* fcsv;			// 파일 포인터
	char info[100];		// 한 줄에 있는 문자열들을 모두 포함시키기 위해 큰 숫자를 넣음?
	char* next_point;		//밑에 적을 것, 아직 이해 못
	char* cut;		//밑에 적을 것, 조금 이해함
	

	int flag = 0;		// csv파일 0행에 있는 줄을 출력하지 않기 위해 .. 1번째 실행부터 cut출력	// 1로 하고 flag++ 로 바꾸면 error
	int flag2 = 0;		// csv파일에서 조장, 회사, 이름, 이메일, 학교, 전공을 구분하기 위해
	int i =0; // 셀 안에 ,가 들어가는 경우를 위한 변수 선언

	
	if (fopen_s(&fcsv, directory, "r") != 0)	//열린 파일에 대한 포인터 directory를 수신할, 파일 포인터에 대한 포인터 fcsv입니다 읽기모드. 성공시 0 반환
	{
		printf("열기 실패");
		fclose(fcsv);
	}
	while (1)
	{
		if ((fgets(info, sizeof(info), fcsv) == NULL))		//입력할 거, 배열의 크기, 파일 포인터 순으로 집어 넣고 파일포인터에서 읽은 읽 배열 사이즈를 보고 출력함이라는 의미인가...행을 읽기 시작하는데 NULL 값, 공백칸이 있다면이라는 이프함수
		{
			break; // 가장 가까이 둘러싼 반복문 탈출어>> if가 아니라 while 탈출이라는 것이 중요포인트임
		}
		++flag;	//flag 1 올림, 맨 처음이라면 flag=1 인 상태에서 아래 if 돌아다니는 거..

		
		while (1)
		{
			if (info[i] == '\"')	//따옴표 있는 info[] 찾는다면
			{
				info[i] = '?';		//물음표로 바꿔라>> 뒤에서 ? 제거 예정
				while (1)
				{
					if (info[i] == ',')		// "asd,asd"형식으로 있을 거기 때문에 안에 들어있는 , 찾아서 반복할거
					{

						info[i] = ' ';		// 띄어쓰기로 바꿔줌 현재 ?asd asd"상태인거임, 얘를 화이트 스페이스라고 함. enter, tab눌러서 생기는 공간도 마찬가지.
						
				
					}else if(info[i] == '"') //다시 돌렸을 때 언젠가 끝의 "를 발견한다면
					{
						info[i] = '?';		//물음표롤 바꿔줌 이제는 ?asd asd?가 되었다
						i = -1;		//이제 i는 할 일을 다 했으므로 더 찾지 않을 예정 >> " , " 묶음은 하나만 있다는 걸 알고 만듬
						break;
					}
					++i;	// if 에서 나왔다면 i는 증가해서 다시 돌아올 것이고 else if 에서 나왔다면 -1일 것
				}
			}

			if ((i == -1) || (i == 99))	//이제 어떤 info[i]가 따옴표가 없기 때문에 오는 곳
			{
				break;	// 99는 배열의 끝이고 -1은 저 문장기호 처리가 끝났다는 것을 의미함 그니까 89행 while 탈출
			}
			++i; //99일 경우 100되서 오버 나지 않나?????? >>노논 while 탈출 시 ++안함
		
		}
		i = 0;	// while 벗어났다면 i 초기화

		//info[strlen(info) - 1] = '\0';	//개행문자(\n)제거 이러면 info에 있던 \n삭제됨

		cut = strtok_s(info, ",?", &next_point);	// info를 읽어서 ,나 ?가 있다면 /함수 호출 간의 위치 정보를 저장 하는 데 사용 됩니다./ 다음 토큰을 반환한다는 데 토큰??
		//printf("%s", info);
		
		while (cut != NULL)					// 처음 돌렸을 때, info는 조장여부 &next는 나머지 글자들(,포함) cut은 조장여부임  cut이 NULL이라는 건 전부다 제거했다는 것을 의미
		{//flag=3인데 막 들어온 상태에서 word>>>>>>과 같은 상태임
			if (cut != NULL)
			{
				if (flag >= 2)		//맨 처음에는 flag =1 유지 중이니 여기는 건너뜀
				{
					
					//printf("%s --- %d --- ", cut,flag); //<<디버깅 시 필요함 지우지 말기
					
					
					if (strcmp(cut, "조장") == 0)	//cmp: comparison 약자, cut이랑 비교해서 같으면
					{
						st[flag - 2].leader = 1;		//flag-2 왜 했더라아.....flag값 2로 시작해서 0만들어주려고 했는데 왜 0이 되어야했지 st[0]에 들어가야해서!!! 암튼 이게 조장임
						
					}else{ ++flag2; }		//조장이 아니라면 조원이므로 그 다음 항목인 회사를 비교해볼 차례이니까 flag1은 flag2
					
				

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


				cut = strtok_s(next_point, ",?", &next_point);	//flag2=1에서 한주형~~전공을 포함하던 문장에서 ,를 뜯어내고 한주형만 cut에 들어감 나머지는 포인터로 다시 &next 보낸건가 절대 노이해 
				
			}

			//printf("\n"); // 디버깅 시  필요함 지우지 말기
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
		printf("%02d시 %02d분 %02d초\n", pTmNow->tm_hour, pTmNow->tm_min, pTmNow->tm_sec);
}*/

void input_file()
{
	FILE* fo;
	int i;

	// 파일이 있으면 a 모드로 개방
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// 파일이 없으면 w 모드로 파일을 만들어서 개방
		if (fopen_s(&fo, "results.txt", "w") != 0)
		{
			printf("파일 열기 실패");
			fclose(fo);
		}
	}

					// 텍스트 파일의 입력을 이 함수 내에서 완료하도록 고쳐보기.//
/*	for (i = 0; i < count; i++)
	{

		if (st[i].leader == 1)
		{
			fprintf(fo, "조장 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			
		}
		else
		{
			fprintf(fo, "조원 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			
		}

	}


	fclose(fo);*/

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

void print_info()
{
	int chk,i;
	char name[20];

	while (1)
	{
		printf("\n조장 검색 시 1 입력\n회사명 검색 시 2 입력\n이름 검색 시 3 입력\n학교 검색 시 4 입력\n종료시 5 입력\n>>> ");
		scanf_s("%d", &chk);
	switch (chk)
	{
		// 조장 검색
	case 1:

		printf("===================\n");
		for (i = 0; i < 24; i++)
		{
			if (st[i].leader == 1)
			{
				printf("%s\n",st[i].name);
			}
			
		}
		printf("조장 이름을 입력하세요 : ");
		scanf_s("%s", name, sizeof(name));
		printf("\n");

		search_leader(name);


		break;



		// 회사명 검색
	case 2:

		printf("===================\n");
		for (i = 0; i < 24; i++)
		{
			if (strcmp(st[i].comp, st[i + 1].comp) != 0)
			{
				printf("%s\n", st[i].comp);
			}

		}

		printf("회사명을 입력하세요 : ");
		scanf_s("%s", name, sizeof(name));
		printf("\n");

		search_company(name);


		break;



		// 이름 검색
	case 3:

		printf("===================\n");
		
		for (i = 0; i < 24; i++)
		{
			printf("%s\n", st[i].name);
		}
		
		printf("이름을 입력하세요 : ");
		scanf_s("%s", name, sizeof(name));
		printf("\n");

		search_name(name);


		break;



		// 학교 검색
	case 4:

		printf("===================\n");

		printf("학교 이름을 입력하세요 (ex 경북대학교) : ");
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

									//======/텍스트 파일 입력 수정하기/======//
	FILE* fo;


	// 파일이 있으면 a 모드로 개방
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// 파일이 없으면 w 모드로 파일을 만들어서 개방
		if (fopen_s(&fo, "results.txt", "w") != 0)
		{
			printf("파일 열기 실패");
			fclose(fo);
		}
	}

	// 카운팅을 통해 검색한 조장의 이름이 구조체 배열에서 몇 번째에 있는지 찾아냄.
	while (1)
	{
		if (strcmp(st[count].name, name) == 0)
		{
			strcpy_s(company_name, sizeof(company_name), st[count].comp);
			break;
		}
		++count;
	}

							//★☆★☆★☆★☆★☆기적의 하드코딩★☆★☆★☆★☆★☆//
	while (strcmp(st[count].comp, st[count + 1].comp) == 0)
	{
		if (st[count].leader == 1)
		{
			printf("조장 == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
			fprintf(fo, "조장 == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
		}
		else
		{
			printf("조원 == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
			fprintf(fo, "조원 == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
		}

		count++;
	}

	printf("조원 == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);
	fprintf(fo, "조원 == %s == %s == %s == %s == %s\n", st[count].comp, st[count].name, st[count].email, st[count].sch, st[count].major);

	

	fclose(fo);
}

void search_school(char name[20])
{
	int i;
	int chk = 0;  // 몇 명의 정보를 검색했는지 확인

									//======/텍스트 파일 입력 수정하기/======//
	FILE* fo;
	

	// 파일이 있으면 a 모드로 개방
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// 파일이 없으면 w 모드로 파일을 만들어서 개방
		if (fopen_s(&fo, "results.txt", "w") != 0)
		{
			printf("파일 열기 실패");
			fclose(fo);
		}
	}

	for (i = 0; i < 24; i++)
	{
		if (strcmp(st[i].sch, name) == 0)
		{

			if (st[i].leader == 1)
			{
				printf("조장 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo,"조장 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				++chk;
			}
			else
			{
				printf("조원 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo,"조원 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				++chk;
			}

		}
	}

	fclose(fo);
}

void search_company(char name[20])
{
	int i;

									//======/텍스트 파일 입력 수정하기/======//
	FILE* fo;
	

	// 파일이 있으면 a 모드로 개방
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// 파일이 없으면 w 모드로 파일을 만들어서 개방
		if (fopen_s(&fo, "results.txt", "w") != 0)
		{
			printf("파일 열기 실패");
			fclose(fo);
		}
	}
	
	for (i = 0; i < 24; i++)
	{
		if (strcmp(st[i].comp, name) == 0)
		{

			if (st[i].leader == 1)
			{
				printf("조장 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo, "조장 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			}
			else
			{
				printf("조원 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo,"조원 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			}
			
		}
	}

	fclose(fo);
	
}


void search_name(char name[20])
{
	int i;

								//======/텍스트 파일 입력 수정하기/======//
	FILE* fo;
	

	// 파일이 있으면 a 모드로 개방
	if (fopen_s(&fo, "results.txt", "a") != 0)
	{
		// 파일이 없으면 w 모드로 파일을 만들어서 개방
		if (fopen_s(&fo, "results.txt", "w") != 0)
		{
			printf("파일 열기 실패");
			fclose(fo);
		}
	}

	for (i = 0; i < 24; i++)
	{
		if (strcmp(st[i].name, name) == 0)
		{
			if (st[i].leader == 1)
			{
				printf("조장 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo, "조장 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			}
			else
			{
				printf("조원 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
				fprintf(fo, "조원 == %s == %s == %s == %s == %s\n", st[i].comp, st[i].name, st[i].email, st[i].sch, st[i].major);
			}

		}
	}

	fclose(fo);
}

