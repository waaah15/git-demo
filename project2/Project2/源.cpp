#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int age;
}student;

typedef struct node{
	student stu;
	struct node* next;
}node;//������Ľڵ�����

//��������
void copevalue(student *s1, student *s2) {
	s1->age = s2->age;
}

//�������
node *created(student *stu) {
    //�����ڴ�ռ�
	node* p = (node*)malloc(sizeof(node));
	// �ж��Ƿ����뵽�ڴ�ռ�
	if (!p) {
		printf("�ڴ治��\n");
		return NULL;
	}
	//��ʼ������е����ݣ�ѧ����Ϣ
	copevalue(&p->stu, stu);
	p->next = NULL;
	//���ش����Ľ��
	return p;
}

//��������Ϣ����
void inputvalue(student *stu) {
	if (!stu) {
		return;
	}
	printf("����ѧ��������\n");
	scanf_s("%d", &stu->age);
}

//��������
node *createlink() {
	student stu = { 0 };
	//����ͷ���
	node *head=created(&stu);
	if (!head) {
		exit(-1);
	}
	//����������㣬��������ͷ���
	int tag = 0;
	node* pnew;
	node* tail = head;
	printf("�Ƿ�����½�㣬�����������½ڵ㣬����1������ӣ�����0\n");
	scanf_s("%d", &tag);
	while (tag != 0) {
		inputvalue(&stu);
		pnew=created(&stu);
		if (!pnew)break;//���pnew=0����ֹ
		tail->next = pnew;
		tail = pnew;
		printf("�Ƿ�����½�㣬�����������½ڵ㣬����1������ӣ�����0");
		scanf_s("%d", &tag);
	}
	//��������
	return head;
}

//��������
void freelink(node *head) {
	//�ж������Ƿ�Ϊ�գ�Ϊ�գ��򷵻�
	if (head == NULL) {
		return;
	}
	//�����Ϊ�գ�����ڵ��ͷ�
	node* a;
	node* b;
	a = head;
	if (a->next != NULL) {
		b = a->next;
		a->next = b->next;
		free(b);
	}
	//�ͷ�ͷ�ڵ�
	free(head);
}

//���ÿ���ڵ����Ϣ
void displaystudent(student* stu) {
	if (!stu) {
		return;
	}
	printf("age=%d\n", stu->age);
}

//��������
void displaylink(node *head){
	//�ж������Ƿ�Ϊ��
	if (head == NULL) {
		return;
	}
	//��ӡ��Ա��Ϣ
	node* c = head->next;
	while (c != NULL) {
		displaystudent(&c->stu);
		c = c->next;
	}
}

//��ָ��λ�ò�����
void inset(node* head, node* pnew,int i) {//i�ǲ����λ��
	//�ж������Ƿ�Ϊ�գ���Ϊ�գ��ܾ�����
	if (!head)return;
	//�жϲ���Ľ���Ƿ�Ϊ�գ���Ϊ�գ��ܾ�����
	if (!pnew)return;
	//���������ҵ������λ��
	node* p = head;
	int n = 0;
	for (n = 0; n < i && p->next != NULL; n++) {
		p = p->next;
	}
	//������
	pnew->next = p->next;
	p->next = pnew;
}
//ɾ�����
void deletevalue(node* head, int i) {
	if (!head)return;
	if (i < 0)return;
	node* p=head;
	node* q;
	int n = 0;
	for (n = 1; n < i && p->next != NULL; n++) {
		p = p->next;
	}
	if (!p)return;
	q = p->next;
	p->next = q->next;
	free(q);
}

int main() {
	node* head = createlink();
	displaylink(head);
	//printf("���뵥������½��\n");
	//student stu;
	//inputvalue(&stu);
	//node* pnew = created(&stu);
	//inset(head,pnew,2);
	printf("ɾ��ָ��λ�ý��ĵ�����\n");
	deletevalue(head, 2);
	displaylink(head);

	freelink(head);
	return 0;
}