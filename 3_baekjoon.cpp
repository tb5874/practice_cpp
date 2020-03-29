///////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1002
// �� 2��, ��ġ�� ���� ��
// 1. ��� �������� �Է¹޴´�.
// 2. 6�� �� �Է¹޴´�.
// 3-1. �ٷ� ��� ����ϱ�.
// 3-2. �ٷ� ��¾��ϰ� �������� ���Ƽ� ����ϱ�.
// 3-3. ���� �غ��ϱ� 3-1, 3-2 �Ѵ� �ȴ�.

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
        // sqrt�� pow�Լ��� �ð��� �� ����.
        // ���������� ������ ���� �� �ʿ�� ����.
        if (r1 > r2) temp = r2, r2 = r1, r1 = temp;
        // abs�Լ��� ������� �ʱ� ���� ��������

        distance_big_radius = r2 * r2;
        distance_radius_sum = (r1 + r2) * (r1 + r2);
        distance_radius_minus = (r2 - r1) * (r2 - r1);

        // ���� 0 : ������ Ǯ�� ���� ū ���� �������� �����Ѵ�.
        // ���� 1 : �� �� ������ �Ÿ��� ū ���� ���������� Ŭ��
            // �� �� ������ �Ÿ��� �� ���� �������� �պ��� ũ�� ���� ����
            // �� �� ������ �Ÿ��� �� ���� �������� �հ� ������ ���� 1��
            // �ƴ϶�� 2��
        // ���� 2 : �� �� ������ �Ÿ��� ū ���� �������� ������
            // ���� 2��
        // ���� 3 : �� �� ������ �Ÿ��� 0���� Ŭ��
            // �� �� ������ �Ÿ��� �������� ������ ������ ���� ����
            // �� �� ������ �Ÿ��� �������� ���� ������ ���� 1��
            // �ƴ϶�� 2��
        // ���� 4 : ���������� �� �� ������ �Ÿ��� 0�϶�
            // �� ���� �������� ���ٸ� ���� -1��
        // ���� 5 : �� ���� ���� 0���� ó���Ѵ�.
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
        // sqrt�� pow�Լ��� �ð��� �� ����.
        // ���������� ������ ���� �� �ʿ�� ����.
        if (r1 > r2) temp = r2, r2 = r1, r1 = temp;
        // abs�Լ��� ������� �ʱ� ���� ��������

        distance_big_radius = r2 * r2;
        distance_radius_sum = (r1 + r2) * (r1 + r2);
        distance_radius_minus = (r2 - r1) * (r2 - r1);

        // ���� 0 : ������ Ǯ�� ���� ū ���� �������� �����Ѵ�.
        // ���� 1 : �� �� ������ �Ÿ��� ū ���� ���������� Ŭ��
            // �� �� ������ �Ÿ��� �� ���� �������� �պ��� ũ�� ���� ����
            // �� �� ������ �Ÿ��� �� ���� �������� �հ� ������ ���� 1��
            // �ƴ϶�� 2��
        // ���� 2 : �� �� ������ �Ÿ��� ū ���� �������� ������
            // ���� 2��
        // ���� 3 : (�Ϲ������� �� �� ������ �Ÿ��� ū ���� ���������� ������) �� �� ������ �Ÿ��� 0���� Ŭ��
            // �� �� ������ �Ÿ��� �������� ������ ������ ���� ����
            // �� �� ������ �Ÿ��� �������� ���� ������ ���� 1��
            // �ƴ϶�� 2��
        // ���� 4 : �Ϲ������� �� �� ������ �Ÿ��� 0�϶�
            // �� ���� �������� ���ٸ� ���� -1��
        // ���� 5 : �� ���� ���� 0���� ó���Ѵ�.
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
// 1003 (���� ���α׷���, dynamic programming)
// �Ǻ���ġ ������ 1,1 �κ��� ���۵ȴ�.

// �õ� 1 (�ð��ʰ�)
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

        // �ð� ���� ����
        time_check_start = clock();

        ///////////////////////////////////////////////
        fibonacci(input_fibo);
        printf("%d %d\n", count_zero, count_one);
        count_one = 0;
        count_zero = 0;
        ///////////////////////////////////////////////

        // �ð� ���� ��
        time_check_end = clock();
        // �ð� ���� ��� ���
        printf("time check : %d\n", time_check_end - time_check_start);
    }

    return 0;
}

// �õ� 2 (���� ���α׷���, dynamic programming)
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
        // fibo(5) if���� else�� ������.
        // else ������ if���� �ƹ��͵� ���ϰ� �ȴ�.
        // memo[5] = fibo(4)+fibo(3)
            // fibo(4) if���� else�� ������.
            // else ������ if���� �ƹ��͵� ���ϰ� �ȴ�.
            // memo[4] = fibo(3)+fibo(2)�� �ȴ�.
                // fibo(3) if���� else�� ������.
                // else ������ if���� �ƹ��͵� ���ϰ� �ȴ�.
                // memo[3] = fibo(2)+fibo(1)�� �ȴ�.
                    // fibo(2) if���� else�� ������.
                    // else ������ if���� �ƹ��͵� ���ϰ� �ȴ�.
                    // memo[2] = fibo(1)+fibo(0)�� �ȴ�.
                        // fibo(1) if���� memo[1] = 1 �ȴ�.
                        // fibo(0) if���� memo[0] = 1 �ȴ�.
                // fibo(2) = memo[2] = 2 ��ȯ
                // fibo(1) = if�� ���ؼ� memo[1] = 1 ��ȯ
            // fibo(3) = memo[3] = 3 ��ȯ
            // fibo(2) = if�� ���ؼ� memo[2] = 2 ��ȯ
        // fibo(4) = memo[4] = 5 ��ȯ
        // fibo(3) = if�� ���ؼ� memo[3] = 3 ��ȯ
    // fibo(5) = memo[5] = 8 ��ȯ

    // fibo(0) = fibo( ) + fibo(0) = fibo(1) 0��, fibo(0) 1�� = 1
    // fibo(1) = fibo(1) + fibo( ) = fibo(1) 1��, fibo(0) 0�� = 1
    // fibo(2) = fibo(1) + fibo(0) = fibo(1) 1��, fibo(0) 1�� = 2
    // fibo(3) = fibo(2) + fibo(1) = fibo(1) 2��, fibo(0) 1�� = 3
    // fibo(4) = fibo(3) + fibo(2) = fibo(1) 3��, fibo(0) 2�� = 5
    // fibo(5) = fibo(4) + fibo(3) = fibo(1) 5��, fibo(0) 3�� = 8
    // fibo(6) = fibo(5) + fibo(4) = fibo(1) 8��, fibo(0) 5�� = 13
    // �м��ϸ� �Ʒ��� ����.
    // fibo(0), fibo(1)�� �����ϰ�
    // -1��° fibo�� 1�� ����
    // -2��° fibo�� 0�� ����
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










