#include <stdio.h>

typedef struct {
	int num;	// 팀 ID
	char name[30];	// 팀 명
	char comp[30];	// 회사 명

}team;

//함수 선언
void input_file(struct team* t);
void input_info(struct team* t);
void print_info(struct team* t);
void sort_nums(struct team* t);
void sort_name(struct team* t);	//매개 변수로 구조체 포인터 
void sort_comp(struct team* t);