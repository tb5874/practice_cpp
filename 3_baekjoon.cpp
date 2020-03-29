///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1002
// 원 2개, 겹치는 점의 수
// 1. 몇번 수행할지 입력받는다.
// 2. 6개 값 입력받는다.
// 3-1. 바로 결과 출력하기.
// 3-2. 바로 출력안하고 마지막에 몰아서 출력하기.
// 3-3. 실험 해보니까 3-1, 3-2 둘다 된다.

#include <stdio.h>
int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        int x1, y1, r1, x2, y2, r2, tmp, c;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int D = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (r1 > r2) tmp = r2, r2 = r1, r1 = tmp;

        if (D > r2* r2)
            if (D > (r1 + r2)* (r1 + r2)) c = 0;
            else if (D == (r1 + r2) * (r1 + r2)) c = 1;
            else c = 2;
        else if (D == r2 * r2) c = 2;
        else if (D > 0)
            if (D < (r2 - r1) * (r2 - r1)) c = 0;
            else if (D == (r2 - r1) * (r2 - r1)) c = 1;
            else c = 2;
        else if (r1 == r2) c = -1;
        else c = 0;

        printf("%d\n", c);
    }
}

// 1002 (3-1)
#include <stdio.h>
int main(void)
{
    int x1, y1, r1;
    int x2, y2, r2;

    int distance_center = 0;
    int distance_radius_sum = 0;
    int distance_radius_minus = 0;
    int distance_big_radius = 0;

    int count_input = 0;
    scanf("%d", &count_input);
    int cross_point_count;

    int temp;
    while (count_input--)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        distance_center = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        // sqrt와 pow함수는 시간만 더 쓴다.
        // 수학적으로 완전한 답을 낼 필요는 없다.
        if (r1 > r2) temp = r2, r2 = r1, r1 = temp;
        // abs함수를 사용하지 않기 위해 내림차순

        distance_big_radius = r2 * r2;
        distance_radius_sum = (r1 + r2) * (r1 + r2);
        distance_radius_minus = (r2 - r1) * (r2 - r1);

        // 조건 0 : 문제를 풀기 위해 큰 원을 기준으로 생각한다.
        // 조건 1 : 두 원 사이의 거리가 큰 원의 반지름보다 클때
            // 두 원 사이의 거리가 두 원의 반지름의 합보다 크면 교점 없음
            // 두 원 사이의 거리가 두 원의 반지름의 합과 같으면 교점 1개
            // 아니라면 2개
        // 조건 2 : 두 원 사이의 거리가 큰 원의 반지름과 같을때
            // 교점 2개
        // 조건 3 : 두 원 사이의 거리가 0보다 클때
            // 두 원 사이의 거리가 반지름의 차보다 작으면 교점 없음
            // 두 원 사이의 거리가 반지름의 차와 같으면 교점 1개
            // 아니라면 2개
        // 조건 4 : 묵시적으로 두 원 사이의 거리가 0일때
            // 두 원의 반지름이 같다면 교점 -1개
        // 조건 5 : 이 외의 경우는 0으로 처리한다.
        if (distance_center > distance_big_radius)
            if (distance_center > distance_radius_sum) cross_point_count = 0;
            else if (distance_center == distance_radius_sum) cross_point_count = 1;
            else cross_point_count = 2;
        else if (distance_center == distance_big_radius) cross_point_count = 2;
        else if (distance_center > 0)
            if (distance_center < distance_radius_minus) cross_point_count = 0;
            else if (distance_center == distance_radius_minus) cross_point_count = 1;
            else cross_point_count = 2;
        else if (r1 == r2) cross_point_count = -1;
        else cross_point_count = 0;

        printf("%d\n", cross_point_count);
    }

}

// 1002 (3-2)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x1, y1, r1;
    int x2, y2, r2;

    int distance_center = 0;
    int distance_radius_sum = 0;
    int distance_radius_minus = 0;
    int distance_big_radius = 0;

    int count_input = 0;
    int count_print = 0;
    scanf("%d", &count_input);
    int* cross_point_count;
    cross_point_count = (int*)malloc(sizeof(int) * count_input);

    int temp;
    while (count_print < count_input)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        distance_center = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        // sqrt와 pow함수는 시간만 더 쓴다.
        // 수학적으로 완전한 답을 낼 필요는 없다.
        if (r1 > r2) temp = r2, r2 = r1, r1 = temp;
        // abs함수를 사용하지 않기 위해 내림차순

        distance_big_radius = r2 * r2;
        distance_radius_sum = (r1 + r2) * (r1 + r2);
        distance_radius_minus = (r2 - r1) * (r2 - r1);

        // 조건 0 : 문제를 풀기 위해 큰 원을 기준으로 생각한다.
        // 조건 1 : 두 원 사이의 거리가 큰 원의 반지름보다 클때
            // 두 원 사이의 거리가 두 원의 반지름의 합보다 크면 교점 없음
            // 두 원 사이의 거리가 두 원의 반지름의 합과 같으면 교점 1개
            // 아니라면 2개
        // 조건 2 : 두 원 사이의 거리가 큰 원의 반지름과 같을때
            // 교점 2개
        // 조건 3 : (암묵적으로 두 원 사이의 거리가 큰 원의 반지름보다 작으며) 두 원 사이의 거리가 0보다 클때
            // 두 원 사이의 거리가 반지름의 차보다 작으면 교점 없음
            // 두 원 사이의 거리가 반지름의 차와 같으면 교점 1개
            // 아니라면 2개
        // 조건 4 : 암묵적으로 두 원 사이의 거리가 0일때
            // 두 원의 반지름이 같다면 교점 -1개
        // 조건 5 : 이 외의 경우는 0으로 처리한다.
        if (distance_center > distance_big_radius)
            if (distance_center > distance_radius_sum) cross_point_count[count_print] = 0;
            else if (distance_center == distance_radius_sum) cross_point_count[count_print] = 1;
            else cross_point_count[count_print] = 2;
        else if (distance_center == distance_big_radius) cross_point_count[count_print] = 2;
        else if (distance_center > 0)
            if (distance_center < distance_radius_minus) cross_point_count[count_print] = 0;
            else if (distance_center == distance_radius_minus) cross_point_count[count_print] = 1;
            else cross_point_count[count_print] = 2;
        else if (r1 == r2) cross_point_count[count_print] = -1;
        else cross_point_count[count_print] = 0;

        count_print++;
    }

    count_print = 0;
    while (count_print < count_input)
    {
        printf("%d\n", cross_point_count[count_print]);
        count_print++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
















///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1003 (동적 프로그래밍, dynamic programming)
// 피보나치 수열은 1,1 로부터 시작된다.

// 시도 1 (시간초과)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_one = 0;
int count_zero = 0;

int fibonacci(int n)
{
    if (n == 0)
    {
        count_zero++;
        return 0;
    }
    else if (n == 1)
    {
        count_one++;
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    clock_t time_check_start, time_check_end;

    int input_count = 0;
    int input_fibo = 0;
    scanf("%d", &input_count);
    while (input_count--)
    {
        scanf("%d", &input_fibo);

        // 시간 측정 시작
        time_check_start = clock();

        ///////////////////////////////////////////////
        fibonacci(input_fibo);
        printf("%d %d\n", count_zero, count_one);
        count_one = 0;
        count_zero = 0;
        ///////////////////////////////////////////////

        // 시간 측정 끝
        time_check_end = clock();
        // 시간 측정 결과 출력
        printf("time check : %d\n", time_check_end - time_check_start);
    }

    return 0;
}

// 시도 2 (동적 프로그래밍, dynamic programming)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int memo[41] = { 1,1, };

int fibonacci(int n)
{
    if (n <= 1)
    {
        return memo[n];
    }
    else
    {
        if (memo[n] > 0) return memo[n];
    }

    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

    // fibo(5)
        // fibo(5) if에서 else로 빠진다.
        // else 내부의 if에서 아무것도 안하게 된다.
        // memo[5] = fibo(4)+fibo(3)
            // fibo(4) if에서 else로 빠진다.
            // else 내부의 if에서 아무것도 안하게 된다.
            // memo[4] = fibo(3)+fibo(2)가 된다.
                // fibo(3) if에서 else로 빠진다.
                // else 내부의 if에서 아무것도 안하게 된다.
                // memo[3] = fibo(2)+fibo(1)가 된다.
                    // fibo(2) if에서 else로 빠진다.
                    // else 내부의 if에서 아무것도 안하게 된다.
                    // memo[2] = fibo(1)+fibo(0)가 된다.
                        // fibo(1) if에서 memo[1] = 1 된다.
                        // fibo(0) if에서 memo[0] = 1 된다.
                // fibo(2) = memo[2] = 2 반환
                // fibo(1) = if에 의해서 memo[1] = 1 반환
            // fibo(3) = memo[3] = 3 반환
            // fibo(2) = if에 의해서 memo[2] = 2 반환
        // fibo(4) = memo[4] = 5 반환
        // fibo(3) = if에 의해서 memo[3] = 3 반환
    // fibo(5) = memo[5] = 8 반환

    // fibo(0) = fibo( ) + fibo(0) = fibo(1) 0개, fibo(0) 1개 = 1
    // fibo(1) = fibo(1) + fibo( ) = fibo(1) 1개, fibo(0) 0개 = 1
    // fibo(2) = fibo(1) + fibo(0) = fibo(1) 1개, fibo(0) 1개 = 2
    // fibo(3) = fibo(2) + fibo(1) = fibo(1) 2개, fibo(0) 1개 = 3
    // fibo(4) = fibo(3) + fibo(2) = fibo(1) 3개, fibo(0) 2개 = 5
    // fibo(5) = fibo(4) + fibo(3) = fibo(1) 5개, fibo(0) 3개 = 8
    // fibo(6) = fibo(5) + fibo(4) = fibo(1) 8개, fibo(0) 5개 = 13
    // 분석하면 아래와 같다.
    // fibo(0), fibo(1)을 제외하고
    // -1번째 fibo는 1의 개수
    // -2번째 fibo는 0의 개수
}

int main()
{
    int T; //testCase
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int temp;
        scanf("%d", &temp);

        if (temp == 0) printf("1 0\n");
        else if (temp == 1) printf("0 1\n");
        else
        {
            fibonacci(temp);
            printf("%d %d\n", memo[temp - 2], memo[temp - 1]);
        }
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////










