/*
����
// 1. ������ array ����Ʈ�� �־�� //
// 2. ����ü�� �ּҰ��� array ����Ʈ�� �־�� //
// 3. ������ �ּ� ��� ������ �ִ� array ����Ʈ�� �ϳ��� ���Ϸ� ���� �����غ��� //
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1. ������ array ����Ʈ�� �־�� //
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2. ����ü�� �ּҰ��� array ����Ʈ�� �־�� //

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

// ���ο� ���� //
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

// ���ο� ���� //
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3. ������ �ּ� ��� ������ �ִ� array ����Ʈ�� �ϳ��� ���Ϸ� ���� �����غ��� //
#include <stdio.h>
#include <stdlib.h>

// array data type ����  //
#define Data_Type_Int
//#define Data_Type_User
// array data type ����  //

#define LIST_LEN	100

////////////////////
#ifdef Data_Type_Int
	typedef int List_Data_Type;
#endif
///////////////////

////////////////////
#ifdef Data_Type_User
	typedef struct struct_Point
	{
		int xpos;
		int ypos;
	};
	typedef struct_Point* List_Data_Type;

	// int a = 4 ó�� �ٷ� �Ҵ� �Ұ��ϴϱ� �Լ��� �����.
	void SetPointPos(struct_Point* ppos, int xpos, int ypos)
	{
		ppos->xpos = xpos;
		ppos->ypos = ypos;
	}
	// printf("%d", a); ó�� ���� �� �����ϱ� �Լ��� �����. 
	void ShowPointPos(struct_Point* ppos)
	{
		printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
	}
#endif
////////////////////


//////////////////// �������� �ʰ� ���� ��ų �Լ� //////////////////////////////
typedef struct struct_ArrayList
{
	List_Data_Type arr[LIST_LEN];
	int Number_Of_Data = 0;		// ���� ����Ʈ�� ����� �������� �� = 0��
	int List_Cursor = 0;		// ���� ����Ʈ�� Ŀ�� = �ε��� 0
};

void List_Init(struct_ArrayList* plist)
{
	plist->Number_Of_Data = 0;
	plist->List_Cursor = 0;
}

void List_Cursor_Init(struct_ArrayList* plist)
{
	plist->List_Cursor = 0;	// Ŀ���� �ε��� 0���� �ű��.
}

int List_Count(struct_ArrayList* plist)
{
	return plist->Number_Of_Data;
}

void List_Insert(struct_ArrayList* plist, List_Data_Type data)
{
	if (plist->Number_Of_Data >= LIST_LEN)
	{
		puts("����Ʈ ���� ������ �ʰ��Ͽ� ������ �Ұ����մϴ�.");
		return;
	}
	printf("�����͸� �߰��մϴ�.\n");
	plist->arr[plist->Number_Of_Data] = data;
	plist->Number_Of_Data++;
}

int List_Get(struct_ArrayList* plist, List_Data_Type* pdata)
{
	if (plist->List_Cursor > plist->Number_Of_Data - 1)
	{
		return 0; // ���̻� ����Ʈ�� �ڷᰡ ������ 0 ����
	}
	else
	{
		*pdata = plist->arr[plist->List_Cursor];
		return 1; // �ڷᰡ ������ 1 ����
	}

}

void List_Remove(struct_ArrayList* plist)
{
	for (int i = plist->List_Cursor; i < plist->Number_Of_Data; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}
	plist->Number_Of_Data--;
}
//////////////////// �������� �ʰ� ���� ��ų �Լ� //////////////////////////////




// �����Ϳ� ���� ��� ������ �ٸ��Ƿ� ��¿ �� ���� �ٱ���� �Լ��� �������Ѵ�.
void List_Search_Function(struct_ArrayList* plist)
{
	if (plist->Number_Of_Data == 0)
	{
		printf("���� ����Ʈ�� �ƹ��͵� �����ϴ�.\n");
		return;
	}
	else
	{
		printf("����Ʈ�� ��ȸ�մϴ�.\n");
		List_Cursor_Init(plist);
		List_Data_Type data;
		while (List_Get(plist, &data))
		{
			///////////////////
#ifdef Data_Type_Int
			printf("%d ", data);
#endif
			///////////////////

			////////////////////
#ifdef Data_Type_User
			ShowPointPos(data);
#endif
			////////////////////
			plist->List_Cursor++;
		}
	}
}

// �����Ϳ� ���� ���� ���ϴ� ����� �޶����Ƿ� ��¿ �� ���� �ٱ���� �Լ��� �������Ѵ�.
void List_Remove_Function(struct_ArrayList* plist, List_Data_Type match_value)
{
	if (plist->Number_Of_Data == 0)
	{
		printf("����Ʈ�� �ƹ��͵� ���� ���� �� �����ϴ�.\n");
	}
	else
	{
		List_Cursor_Init(plist);
		List_Data_Type data;
		while (List_Get(plist, &data))
		{
			////////////////////
#ifdef Data_Type_Int
			if (data == match_value)
			{
				printf("::%d:: �����մϴ�.\n", match_value);
				List_Remove(plist);
			}
			else
			{
				plist->List_Cursor++;
			}
#endif
			////////////////////

			////////////////////
#ifdef Data_Type_User
			if (data->xpos == match_value->xpos && data->ypos == match_value->ypos)
			{
				printf("::%d %d:: �����մϴ�.\n", match_value->xpos, match_value->ypos);
				List_Remove(plist);
				free(data);
			}
			else
			{
				plist->List_Cursor++;
			}
#endif
			////////////////////
		}
	}
}

int main(void)
{
	///////////////////
#ifdef Data_Type_Int
	struct_ArrayList Int_List;
	List_Init(&Int_List);

	List_Insert(&Int_List, 11);
	List_Insert(&Int_List, 11);
	List_Insert(&Int_List, 22);
	List_Insert(&Int_List, 22);
	List_Insert(&Int_List, 33);
	printf("\n");

	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 22);
	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 11);
	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Insert(&Int_List, 55);
	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 33);
	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 55);
	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 22);
	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Insert(&Int_List, 33);
	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Insert(&Int_List, 55);
	printf("���� �������� ���� : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");
#endif
	///////////////////

	///////////////////
#ifdef Data_Type_User
	struct_ArrayList Point_List;
	List_Init(&Point_List);

	struct_Point* ppos;

	ppos = (struct_Point*)malloc(sizeof(struct_Point));
	SetPointPos(ppos, 1, 1);
	List_Insert(&Point_List, ppos);
	ppos = (struct_Point*)malloc(sizeof(struct_Point));
	SetPointPos(ppos, 1, 1);
	List_Insert(&Point_List, ppos);
	ppos = (struct_Point*)malloc(sizeof(struct_Point));
	SetPointPos(ppos, 1, 3);
	List_Insert(&Point_List, ppos);
	ppos = (struct_Point*)malloc(sizeof(struct_Point));
	SetPointPos(ppos, 1, 4);
	List_Insert(&Point_List, ppos);
	printf("���� �������� ���� : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	struct_Point remove_ppos;
	remove_ppos.xpos = 1;
	remove_ppos.ypos = 4;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("���� �������� ���� : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	remove_ppos.xpos = 1;
	remove_ppos.ypos = 2;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("���� �������� ���� : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	remove_ppos.xpos = 1;
	remove_ppos.ypos = 3;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("���� �������� ���� : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	remove_ppos.xpos = 1;
	remove_ppos.ypos = 1;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("���� �������� ���� : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	remove_ppos.xpos = 1;
	remove_ppos.ypos = 1;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("���� �������� ���� : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	ppos = (struct_Point*)malloc(sizeof(struct_Point));
	SetPointPos(ppos, 1, 5);
	List_Insert(&Point_List, ppos);
	printf("���� �������� ���� : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

#endif
	////////////////////

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////