///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 링크드 리스트 : malloc으로 만드는 리스트 //
// 1. 링크드 리스트 구현해보기
#include <stdio.h>
#include <stdlib.h>

// _node라는 이름의 구조체를 별칭 Node로 선언한다.
// struct _node* next; 는 '자기참조 구조체'라고 한다.
// 자신과 같은 구조체의 주소를 저장할 수 있다.
typedef struct _node
{
	int data;
	struct _node* next;
} Node;

int main(void)
{

	// Node 구조체 3개를 미리 선언한다.
	Node* head = NULL;
	Node* newNode = NULL;
	Node* tail = NULL;

	int readData;
	while (1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);

		if (readData < 1)
		{
			break;
		}

		// 매번 새롭게 노드를 생성
		newNode = (Node*)malloc(sizeof(Node));
		// 값 입력
		newNode->data = readData;
		// 새로 만들어진 노드의 자기참조 구조체는 항상 다음으로 NULL을 가리킨다.
		newNode->next = NULL;

		if (head == NULL)
		{
			// 1. 첫번째 만들어진 Node는 head에 넣는다.
			// head = 첫번째 Node.
			// 첫번째 Node의 next 는 NULL.
			head = newNode;
		}
		else
		{
			tail->next = newNode;
			// 3. 첫번째 만들어진 Node는 현재 tail이고 next로 두번째 만들어진 노드를 가리키게 한다.
				// head = 첫번째 Node.
				// tail = 첫번째 Node.
				// 첫번째 Node의 next = 두번째 노드
				// 두번째 Node의 next 는 NULL.
			// 5. 두번째 만들어진 Node는 현재 tail이고 next로 세번째 만들어진 노드를 가리키게 한다.
				// head = 첫번째 Node.
				// tail = 두번째 Node.
				// 첫번째 Node의 next = 두번째 노드
				// 두번째 Node의 next = 세번째 노드
				// 세번째 Node의 next 는 NULL.
		}

		tail = newNode;
		// 2. 첫번째 만들어졌으니까 1개밖에 없어서 tail과 head가 같다.
			// head = 첫번째 Node.
			// tail = 첫번째 Node.
			// 첫번째 Node의 next 는 NULL.
		// 4. 두번째 만들어진 Node는 tail이 된다.
			// head = 첫번째 Node.
			// tail = 두번째 Node.
			// 첫번째 Node의 next = 두번째 노드
			// 두번째 Node의 next 는 NULL.
		// 6. 세번째 만들어진 Node는 tail이 된다.
			// head = 첫번째 Node.
			// tail = 세번째 Node.
			// 첫번째 Node의 next = 두번째 노드
			// 두번째 Node의 next = 세번째 노드
			// 세번째 Node의 next 는 NULL.
	}
	printf("\n");


	/**** 입력 받은 데이터의 출력과정 ****/
	Node* cur = NULL;
	printf("입력 받은 데이터의 전체출력! \n");

	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		cur = head;
		printf("%d  ", cur->data);   // 첫 번째 데이터 출력

		while (cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리의 해제과정 ****/
	if (head == NULL)
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);    // 첫 번째 노드의 삭제

		while (delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}

	return 0;
}

// 위 코드는 First In First Out 으로 출력하지만 ( head가 가장 첫번째 저장한 값, tail에 나중의 값을 저장 )
// 대부분의 링크드 리스트는 Last In First Out을 구현한다. ( head가 가장 마지막에 저장한 값, head에 나중의 값을 저장, tail이라는 변수 필요없음 )
// Last In First Out 으로 출력하려면 아래와 같이 수정한다.
	// 즉 첫번째 노드는 head이고 next는 NULL이며
	// 두번째 노드는 head(=첫번째 노드)를 가르키게 하고
	// 두번째 노드가 head가 된다.
		// 두번째 노드(head) -> 첫번째 노드 -> NULL
	// 세번째 노드는 head(=두번째 노드)를 가르키게 하고
	// 세번째 노드가 head가 된다.
		// 세번째 노드(head) -> 두번째 노드 -> 첫번째 노드 -> NULL
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
// 링크드 리스트 : malloc으로 만드는 리스트 //
// 2. 정렬 기능이 추가된 링크드 리스트

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