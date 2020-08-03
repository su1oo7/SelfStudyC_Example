#include <stdio.h>

typedef struct {
	
	int leader;
	/*
	char* email;	//
	char* name;	//  4������ �˻� �����ϰ�.
	char* comp;	//
	char* sch;	//
	char* major;
	*/
	
	char email[30];	//
	char name[30];	//  4������ �˻� �����ϰ�.
	char comp[30];	//
	char sch[30];	//
	char major[50];
	
}student;

student st[24];

//�Լ� ����
void open_file();
void output_file();
void csv_file(char directory[100]);
void input_info(struct team* t);

//���� �� �Լ�
void print_info();

//������ �ʿ��� �Լ�
void input_file();

//���� �߰��� �Լ�
void search_name(char name[20]);
void search_company(char name[20]);
void search_school(char name[20]);
void search_leader(char name[20]);


//�ð� �Լ�
time_t time(time_t* timer);