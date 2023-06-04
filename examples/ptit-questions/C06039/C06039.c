#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define min(i, j) ((i < j) ? i : j)

char permutation[50][51];   // Mảng lưu hoán vị của chuỗi ban đầu
int mark[50] = {0};         // Đánh dấu số lần xuất hiện của các giá trị đã nhập ánh xạ với mảng các hoán vị của chuỗi ban đầu.
int len = 0;                // Độ dài của chuỗi.

/**
 * @brief Giải pháp của chương trình. Nó có nhiệm vụ in ra và trả về số bước ngắn nhất để chuyển đổi.
 * @param t Số lượng test
 * @return -1: Không thể chuyển đổi
 * @return >=0: Số bước tối thiểu để chuyển các chuỗi
 */
int solve(uint8_t t);

/**
 * @brief Tạo các hoán vị của chuỗi
 * @param source Chuỗi nguồn
 */
void generator_permutation(char source[]);

/**
 * @brief Kiểm tra xem chuỗi hiện tại có thuộc danh sách các hoán vị của chuỗi ban đầu hay không.
 *        Nếu nó nằm trong danh sách đó, tăng giá trị tương ứng của nó trong mảng mark.
 * @param s Chuỗi cần kiểm tra
 * @return true: Chuỗi kiểm tra thuộc danh sách các hoán vị chuỗi ban đầu.
 * @return false: Chuỗi kiểm tra không thuộc danh sách các hoán vị chuỗi ban đầu.
 */
bool isCheck(char s[]);

/**
 * @brief Tìm đường ngắn nhất để chuyển đổi các chuỗi thành một chuỗi giống nhau.
 * @return 
 */
int find_min_way();

int main()
{
    uint8_t t;
    scanf("%hhd", &t);

    solve(t);

    system("pause");
    return 0;
}

int solve(uint8_t t)
{
    char str[51];
    mark[0] = 1;

    // Nhận test đầu tiên và tạo các hoán vị của nó.
    scanf("%s", str);
    generator_permutation(str);
    t--;

    // Nhận các test tiếp theo và kiểm tra xem nó có phải hoán vị của test đầu tiên không.
    while (t--)
    {
        scanf("%s", str);
        if (!isCheck(str))
        {
            printf("-1");
            return -1;
        }
    }

    int result = find_min_way();

    printf("%d", result);
    return result;
}

void generator_permutation(char source[])
{
    int i = 0;
    len = strlen(source);

    // Sao chép và lưu trữ giá trị của chuỗi source tới phần tử đầu tiên của mảng.
    strcpy(permutation[i++], source);

    // Tạo các hoán vị của chuỗi source.
    while (i < len)
    {
        char first_char = source[0];

        // Giảm index các tất cả phần tử có index từ 1 của chuỗi source đi một đơn vị
        for (int j = 0; j < len - 1; j++)
        {
            source[j] = source[j + 1];
        }

        // Đổi vị trí phần tử đầu xuống cuối của chuỗi
        source[len - 1] = first_char;

        // Sao chép chuỗi đã hoán vị vào các phần tử tiếp theo của mảng.
        strcpy(permutation[i++], source);
    }
}

bool isCheck(char s[])
{
    for (int i = 0; i < len; i++)
    {
        if (strcmp(s, permutation[i]) == 0)
        {
            mark[i]++; // Đánh dấu đã xuất hiện tại vị trí i.
            return true;
        }
    }

    return false;
}

int find_min_way()
{
    int result = INT_MAX;
    // Tìm số bước xoay ngắn nhất.
    for (int i = 0; i < len; i++)
    {
        if (mark[i] != 0)
        {
            int res = 0;

            for (int j = 0; j < i; j++)
            {
                res += mark[j] * (i - j);
            }

            for (int j = i + 1; j < len; j++)
            {
                res += mark[j] * (len - (j - i));
            }

            result = min(res, result);
        }
    }
    return result;
}