#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/**
 * @brief Giải quyết bài toán đặt ra
 * @param str Chuỗi đầu vào.
 */
void solve(char str[]);

/**
 * @brief Tìm phần tử có thứ tự từ điển là lớn nhất
 * @param str Chuỗi tìm
 * @param start Nơi bắt đầu tìm
 * @param end Nơi kết thúc tìm
 * @param index_final con trỏ vị trí cuối cùng phần tử lớn nhất được tìm thấy
 * @return Phần tử có thứ tự từ điển lớn nhất.
 */
char find_max(char str[], int start, int end, int *index_final);

/**
 * @brief In ra các phần tử muốn in tồn tại trong chuỗi
 * @param str Chuỗi nguồn
 * @param a Các phần tử cần in
 * @param start Vị trí bắt đầu
 * @param end Vị trí kết thúc
 */
void print_results(char str[], char a, int start, int end);

int main()
{
    char input[100001];
    scanf("%s", input);

    solve(input);
    // print_results(input, 'b', 0, strlen(input));

    system("pause");
    return 0;
}

void solve(char str[])
{
    char a;
    int index_start = 0;
    int index_final = 0;

    while (index_start < (int)strlen(str))
    {
        a = find_max(str, index_start, strlen(str), &index_final);
        
        print_results(str, a, index_start, ++index_final);

        index_start = index_final;
    }
    printf("\n");
}

char find_max(char str[], int start, int end, int *index_final)
{
    char max = str[start];

    for (int i = start + 1; i < end; i++)
    {
        if (max <= str[i])
        {
            max = str[i];
            *index_final = i;
        }
    }

    return max;
}

void print_results(char str[], char a, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (str[i] == a)
        {
            printf("%c", str[i]);
        }
    }
}