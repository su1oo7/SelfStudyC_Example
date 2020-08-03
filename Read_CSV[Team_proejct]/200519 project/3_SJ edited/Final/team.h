#include <stdio.h>

typedef struct {
	
	int leader;
	/*
	char* email;	//
	char* name;	//  4가지는 검색 가능하게.
	char* comp;	//
	char* sch;	//
	char* major;
	*/
	
	char email[30];	//
	char name[30];	//  4가지는 검색 가능하게.
	char comp[30];	//
	char sch[30];	//
	char major[50];
	
}student;

student st[24];

//함수 선언
void open_file();
void output_file();
void csv_file(char directory[100]);
void input_info(struct team* t);

//변경 한 함수
void print_info();

//변경이 필요한 함수
void input_file();

//새로 추가한 함수
void search_name(char name[20]);
void search_company(char name[20]);
void search_school(char name[20]);
void search_leader(char name[20]);


//시간 함수
time_t time(time_t* timer);