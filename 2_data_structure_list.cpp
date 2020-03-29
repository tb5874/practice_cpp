///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
리스트
중복된 값 이라도 차례대로 저장한다.
삽입과 제거가 일어난 경우 데이터의 삽입 순서와 달라진다.
삽입과 제거는 자주 일어나므로 리스트는 데이터가 저장된 순서를 유지하지 못한다고 봐도 된다.

순차 리스트 : array로 만드는 리스트
				처음 만들때 배열을 x개로 할당하고 시작하기 때문에 x개 이상 추가하기 힘들다.
				데이터 삽입과 제거에 대해서 최대 n번의 항목 이동이 발생하여 느릴 수 있다.
				인덱스를 알 수 있다면 바로 데이터 접근이 가능하다.
					예를들어 8번째로 입력한 공간의 인덱스가 3이면 인덱스 3으로 바로 접근이 가능하다.
				데이터 탐색에 대해서 최대 n번의 접근이 발생

링크드 리스트 : malloc등 메모리를 할당해서 만드는 리스트
				매번 메모리를 할당하기 때문에 속도가 느릴 수 있다.
				데이터의 삽입과 제거에 항목이동이 발생하지 않는다.
				인덱스가 없어서 반드시 head로부터 몇번째인지 카운트를 해야한다.
					예를들어 8번째로 입력한 공간에 값이 있는걸 알아도 8번째 입력한 공간에 바로 접근 할 방법이 없다.
					반드시 head부터 따라가서 마지막에서 8번째 위치까지 이동해야한다.
				데이터 탐색에 대해서 최대 n번의 접근이 발생한다.
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////










///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 순차 리스트 : array로 만드는 리스트 //
// 1. 정수를 순차 리스트에 넣어보기 //
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
// 순차 리스트 : array로 만드는 리스트 //
// 2. 구조체의 주소값을 순차 리스트에 넣어보기 //

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
///////////////////////////////////////////////////////////////////////////////////////////////////////////










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
// 2. 정렬 기능이 추가된 링크드 리스트의 ADT와 구현
///////////////////////////////////////////////////////////////////////////////////////////////////////////