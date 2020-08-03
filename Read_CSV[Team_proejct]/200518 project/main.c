#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"team.h"

/*struct team {
	int num;
	char name[30];
	char comp[30];

};

void input_info(struct team* t);

void sort_name(struct team* t);
void sort_comp(struct team* t);
void sort_num(struct team* t);

void input_file(struct team* t1);*/

int main(void) {


	team t1[6];
	int i, chk;



	input_info(t1);

	//정렬 후 -- 정렬 알고리즘 넣어서 출력.
	print_info(t1);

	




	return 0;

}



