#include <stdio.h>

typedef struct {
	int num;	// �� ID
	char name[30];	// �� ��
	char comp[30];	// ȸ�� ��

}team;

//�Լ� ����
void input_file(struct team* t);
void input_info(struct team* t);
void print_info(struct team* t);
void sort_nums(struct team* t);
void sort_name(struct team* t);	//�Ű� ������ ����ü ������ 
void sort_comp(struct team* t);