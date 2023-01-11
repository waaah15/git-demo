#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int age;
}student;

typedef struct node{
	student stu;
	struct node* next;
}node;//单链表的节点类型

//拷贝函数
void copevalue(student *s1, student *s2) {
	s1->age = s2->age;
}

//创建结点
node *created(student *stu) {
    //申请内存空间
	node* p = (node*)malloc(sizeof(node));
	// 判断是否申请到内存空间
	if (!p) {
		printf("内存不足\n");
		return NULL;
	}
	//初始化结点中的内容，学生信息
	copevalue(&p->stu, stu);
	p->next = NULL;
	//返回创建的结点
	return p;
}

//输入结点信息函数
void inputvalue(student *stu) {
	if (!stu) {
		return;
	}
	printf("输入学生的年龄\n");
	scanf_s("%d", &stu->age);
}

//创建链表
node *createlink() {
	student stu = { 0 };
	//创建头结点
	node *head=created(&stu);
	if (!head) {
		exit(-1);
	}
	//创建其他结点，并连接至头结点
	int tag = 0;
	node* pnew;
	node* tail = head;
	printf("是否添加新结点，如果继续添加新节点，输入1，不添加，输入0\n");
	scanf_s("%d", &tag);
	while (tag != 0) {
		inputvalue(&stu);
		pnew=created(&stu);
		if (!pnew)break;//如果pnew=0，终止
		tail->next = pnew;
		tail = pnew;
		printf("是否添加新结点，如果继续添加新节点，输入1，不添加，输入0");
		scanf_s("%d", &tag);
	}
	//返回链表
	return head;
}

//销毁链表
void freelink(node *head) {
	//判断链表是否为空，为空，则返回
	if (head == NULL) {
		return;
	}
	//如果不为空，逐个节点释放
	node* a;
	node* b;
	a = head;
	if (a->next != NULL) {
		b = a->next;
		a->next = b->next;
		free(b);
	}
	//释放头节点
	free(head);
}

//输出每个节点的信息
void displaystudent(student* stu) {
	if (!stu) {
		return;
	}
	printf("age=%d\n", stu->age);
}

//遍历链表
void displaylink(node *head){
	//判断链表是否为空
	if (head == NULL) {
		return;
	}
	//打印成员信息
	node* c = head->next;
	while (c != NULL) {
		displaystudent(&c->stu);
		c = c->next;
	}
}

//在指定位置插入结点
void inset(node* head, node* pnew,int i) {//i是插入的位置
	//判断链表是否为空，若为空，拒绝插入
	if (!head)return;
	//判断插入的结点是否为空，若为空，拒绝插入
	if (!pnew)return;
	//遍历链表，找到插入的位置
	node* p = head;
	int n = 0;
	for (n = 0; n < i && p->next != NULL; n++) {
		p = p->next;
	}
	//插入结点
	pnew->next = p->next;
	p->next = pnew;
}
//删除结点
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
	//printf("插入单链表的新结点\n");
	//student stu;
	//inputvalue(&stu);
	//node* pnew = created(&stu);
	//inset(head,pnew,2);
	printf("删除指定位置结点的单链表\n");
	deletevalue(head, 2);
	displaylink(head);

	freelink(head);
	return 0;
}