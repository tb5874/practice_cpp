///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��ũ�� ����Ʈ : malloc���� ����� ����Ʈ //
// 1. ��ũ�� ����Ʈ �����غ���
#include <stdio.h>
#include <stdlib.h>

// _node��� �̸��� ����ü�� ��Ī Node�� �����Ѵ�.
// struct _node* next; �� '�ڱ����� ����ü'��� �Ѵ�.
// �ڽŰ� ���� ����ü�� �ּҸ� ������ �� �ִ�.
typedef struct _node
{
	int data;
	struct _node* next;
} Node;

int main(void)
{

	// Node ����ü 3���� �̸� �����Ѵ�.
	Node* head = NULL;
	Node* newNode = NULL;
	Node* tail = NULL;

	int readData;
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);

		if (readData < 1)
		{
			break;
		}

		// �Ź� ���Ӱ� ��带 ����
		newNode = (Node*)malloc(sizeof(Node));
		// �� �Է�
		newNode->data = readData;
		// ���� ������� ����� �ڱ����� ����ü�� �׻� �������� NULL�� ����Ų��.
		newNode->next = NULL;

		if (head == NULL)
		{
			// 1. ù��° ������� Node�� head�� �ִ´�.
			// head = ù��° Node.
			// ù��° Node�� next �� NULL.
			head = newNode;
		}
		else
		{
			tail->next = newNode;
			// 3. ù��° ������� Node�� ���� tail�̰� next�� �ι�° ������� ��带 ����Ű�� �Ѵ�.
				// head = ù��° Node.
				// tail = ù��° Node.
				// ù��° Node�� next = �ι�° ���
				// �ι�° Node�� next �� NULL.
			// 5. �ι�° ������� Node�� ���� tail�̰� next�� ����° ������� ��带 ����Ű�� �Ѵ�.
				// head = ù��° Node.
				// tail = �ι�° Node.
				// ù��° Node�� next = �ι�° ���
				// �ι�° Node�� next = ����° ���
				// ����° Node�� next �� NULL.
		}

		tail = newNode;
		// 2. ù��° ����������ϱ� 1���ۿ� ��� tail�� head�� ����.
			// head = ù��° Node.
			// tail = ù��° Node.
			// ù��° Node�� next �� NULL.
		// 4. �ι�° ������� Node�� tail�� �ȴ�.
			// head = ù��° Node.
			// tail = �ι�° Node.
			// ù��° Node�� next = �ι�° ���
			// �ι�° Node�� next �� NULL.
		// 6. ����° ������� Node�� tail�� �ȴ�.
			// head = ù��° Node.
			// tail = ����° Node.
			// ù��° Node�� next = �ι�° ���
			// �ι�° Node�� next = ����° ���
			// ����° Node�� next �� NULL.
	}
	printf("\n");


	/**** �Է� ���� �������� ��°��� ****/
	Node* cur = NULL;
	printf("�Է� ���� �������� ��ü���! \n");

	if (head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		cur = head;
		printf("%d  ", cur->data);   // ù ��° ������ ���

		while (cur->next != NULL)    // �� ��° ������ ������ ���
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	if (head == NULL)
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);    // ù ��° ����� ����

		while (delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ���
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);    // �� ��° ������ ��� ����
		}
	}

	return 0;
}

// �� �ڵ�� First In First Out ���� ��������� ( head�� ���� ù��° ������ ��, tail�� ������ ���� ���� )
// ��κ��� ��ũ�� ����Ʈ�� Last In First Out�� �����Ѵ�. ( head�� ���� �������� ������ ��, head�� ������ ���� ����, tail�̶�� ���� �ʿ���� )
// Last In First Out ���� ����Ϸ��� �Ʒ��� ���� �����Ѵ�.
	// �� ù��° ���� head�̰� next�� NULL�̸�
	// �ι�° ���� head(=ù��° ���)�� ����Ű�� �ϰ�
	// �ι�° ��尡 head�� �ȴ�.
		// �ι�° ���(head) -> ù��° ��� -> NULL
	// ����° ���� head(=�ι�° ���)�� ����Ű�� �ϰ�
	// ����° ��尡 head�� �ȴ�.
		// ����° ���(head) -> �ι�° ��� -> ù��° ��� -> NULL
/*
		if (head == NULL)
		{
			head = newNode;
			head->next = NULL;
		}
		else
		{
			newNode->next = head;
		}
		head = newNode;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////










///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��ũ�� ����Ʈ : malloc���� ����� ����Ʈ //
// 2. ���� ����� �߰��� ��ũ�� ����Ʈ

///////////////////
// DLinkedList.h //
///////////////////
#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct struct_node
{
	LData data;
	struct struct_node* next;
} Node;

typedef struct _linkedList
{
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
} LinkedList;


typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif

///////////////////
// DLinkedList.c //
///////////////////
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}


void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////