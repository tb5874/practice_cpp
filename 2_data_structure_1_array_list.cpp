/*
목차
// 1. 정수를 array 리스트에 넣어보기 //
// 2. 구조체의 주소값을 array 리스트에 넣어보기 //
// 3. 정수와 주소 모두 담을수 있는 array 리스트를 하나의 파일로 직접 구현해보기 //
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1. 정수를 array 리스트에 넣어보기 //
// ArrayList.h와 ArrayList.c를 헤더파일에 넣고
// 소스파일에 ListMain.c를 넣고 컴파일한다.

////////////////
// ListMain.c //
////////////////
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	// ArrayList.h 안에 직접 만든 List가 정의되어있다.
	// 앞으로 사용되는 ListInit, LInsert 등은 전부 직접 만든것이다.

	// List를 이용해 list를 선언한다.
	List list;
	ListInit(&list); // 리스트를 초기화한다.

	// 5개의 데이터 저장
	// 순서대로 인덱스 0번부터 저장된다.
	// 원하는 위치에 데이터를 삽입하려면 새로 함수를 짜야한다.
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	printf("현재 데이터의 수: %d \n", LCount(&list));

	int data;
	// list의 첫 번째 데이터 조회해서 data에 담는다.
	// 첫번째 조회는 뭔가 특별하니까 LFirst로 호출한다.
	if (LFirst(&list, &data))
	{
		// 첫번째 데이터 출력
		printf("%d ", data);

		// 두번째 부터는 LNext로 호출한다.
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 다시 list의 첫 번째 데이터 조회해서 data에 담는다.
	// 첫번째 조회는 뭔가 특별하니까 LFirst로 호출한다.
	if (LFirst(&list, &data))
	{
		// 첫번째 데이터 탐색, 22를 찾으면 지운다.
		if (data == 22)
			LRemove(&list);

		// 두번째 부터는 LNext로 호출한다.
		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}


	// 재확인
	printf("현재 데이터의 수: %d \n", LCount(&list));
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
// 리스트의 헤더파일

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ARRAY_LIST_H__ 
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

#define LIST_LEN	100 // 배열 공간 100개 고정


// typedef int를 바꾸면 배열에 담기는 데이터의 성질이 변한다.
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
typedef ArrayList List;를 나중에
typedef LinkedList List;로 수정할 수 있다.
그러려면 아래처럼 LinkedList를 만들어야된다.
typedef struct __LinkedList
{
	코드 내용
	코드 내용
	코드 내용
} LinkedList;
이런식으로 코드를 재활용 할 수 있다.
*/

// 아래 함수는 ArrayList.c 에서 구현한다.
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
	plist->numOfData = 0; // 리스트에 저장된 데이터의 수를 0개로 초기화
	plist->curPosition = -1; // 배열의 인덱스를 -1로 초기화
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	// 초기화가 되었으므로 0번째 인덱스에 값을 넣는다.
	plist->arr[plist->numOfData] = data;
	// 인덱스의 카운트를 올린다.
	plist->numOfData++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
	{
		return FALSE;
	}

	// LFirst는 매번 첫번째 인덱스를 가리켜야한다.
	plist->curPosition = 0;
	// 첫번째 인덱스의 값을 pdata에 넣는다.
	*pdata = plist->arr[0];
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	// LNext는 반드시 LFirst 이후에 호출되도록 코드를 짜야한다.
	// numOfData는 배열에 담긴 데이터의 수 이다.
	// 예를들어 10개 들어있으면
	// 인덱스는 0부터 시작해서 9로 끝나므로
	// 10-1해야 마지막 인덱스다.
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

	// 삭제될 값을 임시로 저장함
	LData rdata = plist->arr[remove_index];

	// 값이 삭제되었으므로 뒤의 인덱스를 1씩 옮김
	for (int i = remove_index; i < list_size - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	plist->numOfData--; // 전체 항목 수 조정
	plist->curPosition--;
	// 1 2 3 에서 3을 삭제한 자리에 4가 들어갔으면
	// 다시 호출시 4를 봐야하므로 인덱스를 1칸 당긴다.

	// 혹시 몰라서 삭제한 값은 리턴시킨다.
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
// 2. 구조체의 주소값을 array 리스트에 넣어보기 //

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
	// 새로운 주소를 위한 선언
	Point* ppos;
	// 검색을 위한 선언
	Point compPos;

	ListInit(&list);

	/*** 4개의 데이터 저장 ***/
	// malloc을 반복하는 이유는
	// 기존에 만들어진 배열에
	// 매번 새로운 주소를 만들어서 할당해야 하기 때문이다.
	// malloc을 지워보면 쉽게 이해가 가능하다.
	// 지우게 된다면 마지막에 추가된 3,2로 전부 똑같아진다.
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

	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** xpos가 2인 모든 데이터 삭제 ***/
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

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}

// 변경사항 없음 //
/////////////////
// ArrayList.c //
/////////////////
#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	plist->numOfData = 0; // 리스트에 저장된 데이터의 수를 0개로 초기화
	plist->curPosition = -1; // 배열의 인덱스를 -1로 초기화
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	// 초기화가 되었으므로 0번째 인덱스에 값을 넣는다.
	plist->arr[plist->numOfData] = data;
	// 인덱스의 카운트를 올린다.
	plist->numOfData++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
	{
		return FALSE;
	}

	// LFirst는 매번 첫번째 인덱스를 가리켜야한다.
	plist->curPosition = 0;
	// 첫번째 인덱스의 값을 pdata에 넣는다.
	*pdata = plist->arr[0];
	return TRUE;
}
int LNext(List* plist, LData* pdata)
{
	// LNext는 반드시 LFirst 이후에 호출되도록 코드를 짜야한다.
	// numOfData는 배열에 담긴 데이터의 수 이다.
	// 예를들어 10개 들어있으면
	// 인덱스는 0부터 시작해서 9로 끝나므로
	// 10-1해야 마지막 인덱스다.
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

	// 삭제될 값을 임시로 저장함
	LData rdata = plist->arr[remove_index];

	// 값이 삭제되었으므로 뒤의 인덱스를 1씩 옮김
	for (int i = remove_index; i < list_size - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	plist->numOfData--; // 전체 항목 수 조정
	plist->curPosition--;
	// 1 2 3 에서 3을 삭제한 자리에 4가 들어갔으면
	// 다시 호출시 4를 봐야하므로 인덱스를 1칸 당긴다.

	// 혹시 몰라서 삭제한 값은 리턴시킨다.
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}


// 변경사항 있음 //
/////////////////
// ArrayList.h //
/////////////////
// 리스트의 헤더파일

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ARRAY_LIST_H__ 
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

#define LIST_LEN	100 // 배열 공간 100개 고정

	////////////////////////// 1번에서 수정된 부분 /////////////////////////////
	// LData를 바꾸면 배열에 담기는 데이터의 성질이 변한다.
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
	typedef ArrayList List;를 나중에
	typedef LinkedList List;로 수정할 수 있다.
	그러려면 아래처럼 LinkedList를 만들어야된다.
	typedef struct __LinkedList
	{
		코드 내용
		코드 내용
		코드 내용
	} LinkedList;
	이런식으로 코드를 재활용 할 수 있다.
	*/

	// 아래 함수는 ArrayList.c 에서 구현한다.
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

// 새로운 파일 //
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

	// Point 변수의 xpos, ypos 값 설정
	void SetPointPos(Point* ppos, int xpos, int ypos);

	// Point 변수의 xpos, ypos 정보 출력 
	void ShowPointPos(Point* ppos);

	// 두 Point 변수의 비교
	int PointComp(Point* pos1, Point* pos2);

#endif

#ifdef __cplusplus
}
#endif

// 새로운 파일 //
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
// 3. 정수와 주소 모두 담을수 있는 array 리스트를 하나의 파일로 직접 구현해보기 //
#include <stdio.h>
#include <stdlib.h>

// array data type 선택  //
#define Data_Type_Int
//#define Data_Type_User
// array data type 선택  //

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

	// int a = 4 처럼 바로 할당 불가하니까 함수를 만든다.
	void SetPointPos(struct_Point* ppos, int xpos, int ypos)
	{
		ppos->xpos = xpos;
		ppos->ypos = ypos;
	}
	// printf("%d", a); 처럼 읽을 수 없으니까 함수를 만든다. 
	void ShowPointPos(struct_Point* ppos)
	{
		printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
	}
#endif
////////////////////


//////////////////// 수정하지 않고 고정 시킬 함수 //////////////////////////////
typedef struct struct_ArrayList
{
	List_Data_Type arr[LIST_LEN];
	int Number_Of_Data = 0;		// 순차 리스트에 저장된 데이터의 수 = 0개
	int List_Cursor = 0;		// 순차 리스트의 커서 = 인덱스 0
};

void List_Init(struct_ArrayList* plist)
{
	plist->Number_Of_Data = 0;
	plist->List_Cursor = 0;
}

void List_Cursor_Init(struct_ArrayList* plist)
{
	plist->List_Cursor = 0;	// 커서를 인덱스 0으로 옮긴다.
}

int List_Count(struct_ArrayList* plist)
{
	return plist->Number_Of_Data;
}

void List_Insert(struct_ArrayList* plist, List_Data_Type data)
{
	if (plist->Number_Of_Data >= LIST_LEN)
	{
		puts("리스트 저장 공간을 초과하여 저장이 불가능합니다.");
		return;
	}
	printf("데이터를 추가합니다.\n");
	plist->arr[plist->Number_Of_Data] = data;
	plist->Number_Of_Data++;
}

int List_Get(struct_ArrayList* plist, List_Data_Type* pdata)
{
	if (plist->List_Cursor > plist->Number_Of_Data - 1)
	{
		return 0; // 더이상 리스트에 자료가 없으면 0 리턴
	}
	else
	{
		*pdata = plist->arr[plist->List_Cursor];
		return 1; // 자료가 있으면 1 리턴
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
//////////////////// 수정하지 않고 고정 시킬 함수 //////////////////////////////




// 데이터에 따라서 출력 형식이 다르므로 어쩔 수 없이 다기능의 함수를 만들어야한다.
void List_Search_Function(struct_ArrayList* plist)
{
	if (plist->Number_Of_Data == 0)
	{
		printf("현재 리스트에 아무것도 없습니다.\n");
		return;
	}
	else
	{
		printf("리스트를 조회합니다.\n");
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

// 데이터에 따라서 값을 비교하는 방식이 달라지므로 어쩔 수 없이 다기능의 함수를 만들어야한다.
void List_Remove_Function(struct_ArrayList* plist, List_Data_Type match_value)
{
	if (plist->Number_Of_Data == 0)
	{
		printf("리스트에 아무것도 없어 지울 수 없습니다.\n");
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
				printf("::%d:: 삭제합니다.\n", match_value);
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
				printf("::%d %d:: 삭제합니다.\n", match_value->xpos, match_value->ypos);
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

	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 22);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 11);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Insert(&Int_List, 55);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 33);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 55);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Remove_Function(&Int_List, 22);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Insert(&Int_List, 33);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
	List_Search_Function(&Int_List);
	printf("\n\n");

	List_Insert(&Int_List, 55);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Int_List));
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
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	struct_Point remove_ppos;
	remove_ppos.xpos = 1;
	remove_ppos.ypos = 4;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	remove_ppos.xpos = 1;
	remove_ppos.ypos = 2;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	remove_ppos.xpos = 1;
	remove_ppos.ypos = 3;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	remove_ppos.xpos = 1;
	remove_ppos.ypos = 1;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	remove_ppos.xpos = 1;
	remove_ppos.ypos = 1;
	List_Remove_Function(&Point_List, &remove_ppos);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

	ppos = (struct_Point*)malloc(sizeof(struct_Point));
	SetPointPos(ppos, 1, 5);
	List_Insert(&Point_List, ppos);
	printf("현재 데이터의 갯수 : %d \n", List_Count(&Point_List));
	List_Search_Function(&Point_List);
	printf("\n");

#endif
	////////////////////

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////