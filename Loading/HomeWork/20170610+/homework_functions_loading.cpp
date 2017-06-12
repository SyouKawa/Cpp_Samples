#include<stdio.h>
#include<iostream>
#include"homework_functions_loading.h"

using namespace std;

link_list *CreateList_Front() {
	
	char c;
	link_list *head, *new_node;
	head = NULL;

	printf("Please input data of char type(end with Enter):");
	while ((c = getchar()) != '\n') {
		new_node = (link_list*)malloc(sizeof(link_list));
		new_node->data = c;
		new_node->next = head;
		head = new_node;
	}
	return head;
}

link_list *CreateList_End() {
	char c;
	link_list *head, *new_node, *end;

	head = NULL;
	end = NULL;
	printf("Please input data of char type(end with Enter):");
	while ((c=getchar())!='\n') {
		new_node = (link_list*)malloc(sizeof(link_list));
		new_node->data = c;
		if (head == NULL) head = new_node;
		else end->next = new_node;
		end = new_node;
	}
	if (end != NULL) end->next = NULL;
	return head;
}

void output_link_list(link_list *head,char*type) {
	link_list *node;
	node = head;//head need const
	while (node != NULL) {
		if(strcmp(type,"char")==0) printf("%c", node->data);
		if (strcmp(type, "int") == 0) printf("%d", node->data);
		node = node->next;
		if (node != NULL) printf("->");
	}
	printf("\n");
}

link_list* delete_node(link_list* node,char deldata) {
	link_list *prev_node=node;
	link_list *check = node;
	while(check->data == deldata) {//head node
		node = node->next;
		check = node;
	}
	while (check != NULL) {
		prev_node = check;
		if (check->data == deldata) {
			node->next = check->next;
		}
		check = check->next;
	}
	return node;
}

int length(link_list*head) {
	link_list *ptrl = head;
	int i = 0;
	while (ptrl!=NULL) {//只写ptrl，则NULL也被计入
		ptrl = ptrl->next;
		i++;
	}
	return i;
}

link_list* reverse(link_list*node) {
	link_list *check=node;
	link_list *temp=node->next;
	link_list *Prev = temp->next;
	int count=0;
	while (check!= NULL) {
		Prev = check;
		check = check->next;
		count++;
	}
	check = Prev;//check为最后一个元素。
	check->next = node;
	temp = node->next;//原先的头节点
	while (temp!=check) {
		Prev=temp->next;//为下一次做准备,因为下一个挪的就是原本temp的后续元素。
		//temp的后事办好之后转身。
		temp->next = node;//然后再建立node之后节点和Prev（last）的关系
		check->next = temp;
		//变换node 的头结点，也就是下次的插入点。
		node = temp;
		//此时，node 和temp 是一个节点
		
		temp = Prev;//将存好的temp原本的next节点，还给temp。
	}
	//exchange
	for (;count>=0;count--) {
		check = check->next;
	}
	check->next = NULL;
	node = temp;
	//output_link_list(node);
	return node;
}

link_list middle(link_list* node,link_list a_node) {
	int middle=length(node);
	middle /= 2;
	for (int i = 0; i < middle; i++) {
		node = node->next;
	}
	a_node = *node;
	return a_node;
}

link_list *Create_in_order(link_list *head,int number) {

	//新加入节点的初始化
	link_list *new_node=(link_list*)malloc(sizeof(link_list));
	new_node->data = number;
	new_node->next = NULL;

	//中间变量，及其初始化
	link_list *Prev = NULL;
	link_list *temp = head;//temp是基准线，而每次都是从再生成的新表头开始比的。

	if (NULL == head) {
		head = new_node;
		return head;
	}
	if (new_node->data < head->data) {//小于，放在head之前。
		new_node->next = head;
		head = new_node;
	}
	else {//大于，放在head或其他元素之后，需要循环比较。
		while (temp!=NULL) {
			if (new_node->data >= temp->data) {
				Prev = temp;
				temp = temp->next;
				continue;
			}
			if (new_node->data < temp->data) {
				Prev->next = new_node;
				new_node->next = temp;
				break;
			}
		}
		if (temp == NULL) {
			Prev->next= new_node;
			new_node->next = NULL;
		}
	}

	return head;
}

link_list *get_list_in_order(link_list *head) {
	int number = 0;
	printf("Please input numbers: ");
	scanf("%d", &number);
	while (number != -1) {
		head = Create_in_order(head, number);
		scanf("%d", &number);
	}
	char head_type[] = "int";
	output_link_list(head, head_type);

	return head;
}

link_list *list_together(link_list*link1,link_list *link2) {
	
	link_list *Prev = NULL;
	link_list *temp = link2;
	link_list *result = link1;

	//消耗的是谁，谁指向下一个。
	while (link2 != NULL) {
		while (link1 != NULL) {
			if (link1->data < temp->data) {
				Prev = link1;
				link1 = link1->next;
				continue;
			}
			if (link1->data >= temp->data) {
				if (Prev == NULL) {
					temp->next = link1;
					Prev = temp;
					link2 = link2->next;
					temp = link2;
					continue;
				}
				if (Prev != NULL) {
					Prev->next = temp;
					link2 = link2->next;//link2不能放在temp替换之后，因为temp的next会影响temp；
					temp->next = link1;
					temp = link2;
					continue;
				}
			}
		}
		if (link1 == NULL) {
			Prev->next = link2;
			break;
		}
	}
	return result;
}

link_list last_4(link_list*head) {
	int count = 0;
	link_list last_4;
	link_list *temp=head;
	for (;head!=NULL;count++) {
		head = head->next;
	}
	count = count - 4;
	head = temp;
	for (; count != 0; count--) {
		temp = temp->next;
	}
	return *temp;
}
