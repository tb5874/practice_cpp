///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
����Ʈ
�ߺ��� �� �̶� ���ʴ�� �����Ѵ�.
���԰� ���Ű� �Ͼ ��� �������� ���� ������ �޶�����.
���԰� ���Ŵ� ���� �Ͼ�Ƿ� ����Ʈ�� �����Ͱ� ����� ������ �������� ���Ѵٰ� ���� �ȴ�.

���� ����Ʈ : array�� ����� ����Ʈ
				ó�� ���鶧 �迭�� x���� �Ҵ��ϰ� �����ϱ� ������ x�� �̻� �߰��ϱ� �����.
				������ ���԰� ���ſ� ���ؼ� �ִ� n���� �׸� �̵��� �߻��Ͽ� ���� �� �ִ�.
				�ε����� �� �� �ִٸ� �ٷ� ������ ������ �����ϴ�.
					������� 8��°�� �Է��� ������ �ε����� 3�̸� �ε��� 3���� �ٷ� ������ �����ϴ�.
				������ Ž���� ���ؼ� �ִ� n���� ������ �߻�

��ũ�� ����Ʈ : malloc�� �޸𸮸� �Ҵ��ؼ� ����� ����Ʈ
				�Ź� �޸𸮸� �Ҵ��ϱ� ������ �ӵ��� ���� �� �ִ�.
				�������� ���԰� ���ſ� �׸��̵��� �߻����� �ʴ´�.
				�ε����� ��� �ݵ�� head�κ��� ���°���� ī��Ʈ�� �ؾ��Ѵ�.
					������� 8��°�� �Է��� ������ ���� �ִ°� �˾Ƶ� 8��° �Է��� ������ �ٷ� ���� �� ����� ����.
					�ݵ�� head���� ���󰡼� ���������� 8��° ��ġ���� �̵��ؾ��Ѵ�.
				������ Ž���� ���ؼ� �ִ� n���� ������ �߻��Ѵ�.
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////










///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� ����Ʈ : array�� ����� ����Ʈ //
// 1. ������ ���� ����Ʈ�� �־�� //
// ArrayList.h�� ArrayList.c�� ������Ͽ� �ְ�
// �ҽ����Ͽ� ListMain.c�� �ְ� �������Ѵ�.

////////////////
// ListMain.c //
////////////////
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	// ArrayList.h �ȿ� ���� ���� List�� ���ǵǾ��ִ�.
	// ������ ���Ǵ� ListInit, LInsert ���� ���� ���� ������̴�.

	// List�� �̿��� list�� �����Ѵ�.
	List list;
	ListInit(&list); // ����Ʈ�� �ʱ�ȭ�Ѵ�.

	// 5���� ������ ����
	// ������� �ε��� 0������ ����ȴ�.
	// ���ϴ� ��ġ�� �����͸� �����Ϸ��� ���� �Լ��� ¥���Ѵ�.
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	printf("���� �������� ��: %d \n", LCount(&list));

	int data;
	// list�� ù ��° ������ ��ȸ�ؼ� data�� ��´�.
	// ù��° ��ȸ�� ���� Ư���ϴϱ� LFirst�� ȣ���Ѵ�.
	if (LFirst(&list, &data))
	{
		// ù��° ������ ���
		printf("%d ", data);

		// �ι�° ���ʹ� LNext�� ȣ���Ѵ�.
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// �ٽ� list�� ù ��° ������ ��ȸ�ؼ� data�� ��´�.
	// ù��° ��ȸ�� ���� Ư���ϴϱ� LFirst�� ȣ���Ѵ�.
	if (LFirst(&list, &data))
	{
		// ù��° ������ Ž��, 22�� ã���� �����.
		if (data == 22)
			LRemove(&list);

		// �ι�° ���ʹ� LNext�� ȣ���Ѵ�.
		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}


	// ��Ȯ��
	printf("���� �������� ��: %d \n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");


	return 0;
}


/////////////////
// ArrayList.h //
/////////////////
// ����Ʈ�� �������

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ARRAY_LIST_H__ 
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

#define LIST_LEN	100 // �迭 ���� 100�� ����


// typedef int�� �ٲٸ� �迭�� ���� �������� ������ ���Ѵ�.
typedef int LData;
//typedef Point* LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;
/*
typedef ArrayList List;�� ���߿�
typedef LinkedList List;�� ������ �� �ִ�.
�׷����� �Ʒ�ó�� LinkedList�� �����ߵȴ�.
typedef struct __LinkedList
{
	�ڵ� ����
	�ڵ� ����
	�ڵ� ����
} LinkedList;
�̷������� �ڵ带 ��Ȱ�� �� �� �ִ�.
*/

// �Ʒ� �Լ��� ArrayList.c ���� �����Ѵ�.
void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

#endif

#ifdef __cplusplus
}
#endif



/////////////////
// ArrayList.c //
/////////////////
#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	plist->numOfData = 0; // ����Ʈ�� ����� �������� ���� 0���� �ʱ�ȭ
	plist->curPosition = -1; // �迭�� �ε����� -1�� �ʱ�ȭ
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	// �ʱ�ȭ�� �Ǿ����Ƿ� 0��° �ε����� ���� �ִ´�.
	plist->arr[plist->numOfData] = data;
	// �ε����� ī��Ʈ�� �ø���.
	plist->numOfData++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
	{
		return FALSE;
	}

	// LFirst�� �Ź� ù��° �ε����� �����Ѿ��Ѵ�.
	plist->curPosition = 0;
	// ù��° �ε����� ���� pdata�� �ִ´�.
	*pdata = plist->arr[0];
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	// LNext�� �ݵ�� LFirst ���Ŀ� ȣ��ǵ��� �ڵ带 ¥���Ѵ�.
	// numOfData�� �迭�� ��� �������� �� �̴�.
	// ������� 10�� ���������
	// �ε����� 0���� �����ؼ� 9�� �����Ƿ�
	// 10-1�ؾ� ������ �ε�����.
	if (plist->curPosition >= plist->numOfData - 1)
		return FALSE;

	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;

}

LData LRemove(List* plist)
{
	int list_size = plist->numOfData;
	int remove_index = plist->curPosition;

	// ������ ���� �ӽ÷� ������
	LData rdata = plist->arr[remove_index];

	// ���� �����Ǿ����Ƿ� ���� �ε����� 1�� �ű�
	for (int i = remove_index; i < list_size - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	plist->numOfData--; // ��ü �׸� �� ����
	plist->curPosition--;
	// 1 2 3 ���� 3�� ������ �ڸ��� 4�� ������
	// �ٽ� ȣ��� 4�� �����ϹǷ� �ε����� 1ĭ ����.

	// Ȥ�� ���� ������ ���� ���Ͻ�Ų��.
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////










///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� ����Ʈ : array�� ����� ����Ʈ //
// 2. ����ü�� �ּҰ��� ���� ����Ʈ�� �־�� //

// ������� ���� //
/////////////////
// ArrayList.c //
/////////////////
#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	plist->numOfData = 0; // ����Ʈ�� ����� �������� ���� 0���� �ʱ�ȭ
	plist->curPosition = -1; // �迭�� �ε����� -1�� �ʱ�ȭ
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	// �ʱ�ȭ�� �Ǿ����Ƿ� 0��° �ε����� ���� �ִ´�.
	plist->arr[plist->numOfData] = data;
	// �ε����� ī��Ʈ�� �ø���.
	plist->numOfData++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
	{
		return FALSE;
	}

	// LFirst�� �Ź� ù��° �ε����� �����Ѿ��Ѵ�.
	plist->curPosition = 0;
	// ù��° �ε����� ���� pdata�� �ִ´�.
	*pdata = plist->arr[0];
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	// LNext�� �ݵ�� LFirst ���Ŀ� ȣ��ǵ��� �ڵ带 ¥���Ѵ�.
	// numOfData�� �迭�� ��� �������� �� �̴�.
	// ������� 10�� ���������
	// �ε����� 0���� �����ؼ� 9�� �����Ƿ�
	// 10-1�ؾ� ������ �ε�����.
	if (plist->curPosition >= plist->numOfData - 1)
		return FALSE;

	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;

}

LData LRemove(List* plist)
{
	int list_size = plist->numOfData;
	int remove_index = plist->curPosition;

	// ������ ���� �ӽ÷� ������
	LData rdata = plist->arr[remove_index];

	// ���� �����Ǿ����Ƿ� ���� �ε����� 1�� �ű�
	for (int i = remove_index; i < list_size - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	plist->numOfData--; // ��ü �׸� �� ����
	plist->curPosition--;
	// 1 2 3 ���� 3�� ������ �ڸ��� 4�� ������
	// �ٽ� ȣ��� 4�� �����ϹǷ� �ε����� 1ĭ ����.

	// Ȥ�� ���� ������ ���� ���Ͻ�Ų��.
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}


// ������� ���� //
/////////////////
// ArrayList.h //
/////////////////
// ����Ʈ�� �������

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ARRAY_LIST_H__ 
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

#define LIST_LEN	100 // �迭 ���� 100�� ����

	////////////////////////// 1������ ������ �κ� /////////////////////////////
	// LData�� �ٲٸ� �迭�� ���� �������� ������ ���Ѵ�.
	// typedef int LData;
	typedef Point* LData;
	////////////////////////////////////////////////////////////////////////////

	typedef struct __ArrayList
	{
		LData arr[LIST_LEN];
		int numOfData;
		int curPosition;
	} ArrayList;

	typedef ArrayList List;
	/*
	typedef ArrayList List;�� ���߿�
	typedef LinkedList List;�� ������ �� �ִ�.
	�׷����� �Ʒ�ó�� LinkedList�� �����ߵȴ�.
	typedef struct __LinkedList
	{
		�ڵ� ����
		�ڵ� ����
		�ڵ� ����
	} LinkedList;
	�̷������� �ڵ带 ��Ȱ�� �� �� �ִ�.
	*/

	// �Ʒ� �Լ��� ArrayList.c ���� �����Ѵ�.
	void ListInit(List* plist);
	void LInsert(List* plist, LData data);

	int LFirst(List* plist, LData* pdata);
	int LNext(List* plist, LData* pdata);

	LData LRemove(List* plist);
	int LCount(List* plist);

#endif

#ifdef __cplusplus
}
#endif

/////////////
// Point.h //
/////////////
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __POINT_H__
#define __POINT_H__

	typedef struct _point
	{
		int xpos;
		int ypos;
	} Point;

	// Point ������ xpos, ypos �� ����
	void SetPointPos(Point* ppos, int xpos, int ypos);

	// Point ������ xpos, ypos ���� ��� 
	void ShowPointPos(Point* ppos);

	// �� Point ������ ��
	int PointComp(Point* pos1, Point* pos2);

#endif

#ifdef __cplusplus
}
#endif

/////////////
// Point.c //
/////////////
#include <stdio.h>
#include "Point.h"

void SetPointPos(Point* ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point* ppos)
{
	printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
}

int PointComp(Point* pos1, Point* pos2)
{
	if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
		return 0;
	else if (pos1->xpos == pos2->xpos)
		return 1;
	else if (pos1->ypos == pos2->ypos)
		return 2;
	else
		return -1;
}

////////////////
// ListMain.c //
////////////////
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void)
{
	List list;
	// ���ο� �ּҸ� ���� ����
	Point* ppos;
	// �˻��� ���� ����
	Point compPos;

	ListInit(&list);

	/*** 4���� ������ ���� ***/
	// malloc�� �ݺ��ϴ� ������
	// ������ ������� �迭��
	// �Ź� ���ο� �ּҸ� ���� �Ҵ��ؾ� �ϱ� �����̴�.
	// malloc�� �������� ���� ���ذ� �����ϴ�.
	// ����� �ȴٸ� �������� �߰��� 3,2�� ���� �Ȱ�������.
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	/*** ����� �������� ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** xpos�� 2�� ��� ������ ���� ***/
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	/*** ���� �� ���� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////










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
// 2. ���� ����� �߰��� ��ũ�� ����Ʈ�� ADT�� ����
///////////////////////////////////////////////////////////////////////////////////////////////////////////