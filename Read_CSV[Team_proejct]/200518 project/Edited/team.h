#include <stdio.h>
#define true 1
#define false 0

typedef struct {
	
	int leader;
	char comp[30];

}company;


typedef struct {
	
	company c;

	char email[30];	//
	char name[30];	//  4������ �˻� �����ϰ�.
	char comp[30];	//
	char sch[30];	//
	char major[30];

}search_team;

typedef struct {

	int num;
	char name[30];	//  4������ �˻� �����ϰ�.
	char comp[30];	//
	

}team;

search_team st[6];

//�Լ� ����
<<<<<<< Updated upstream
=======
void test_open_file();
void output_file();
void csv_file(char directory[50]);
>>>>>>> Stashed changes
void input_file(struct team* t);
void input_info(struct team* t);
void print_info(struct team* t);
void sort_nums(struct team* t);
void sort_name(struct team* t);	//�Ű� ������ ����ü ������ 
void sort_comp(struct team* t);