#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

char permutation[20][61]; // Mảng lưu hoán vị của chuỗi ban đầu
int len = 0;              // Độ dài của chuỗi.

/**
 * @brief Tạo các hoán vị của chuỗi
 * @param source Chuỗi nguồn
 */
void generator_permutation(char source[]);

/**
 * @brief Nhân 2 số nguyên lớn dưới dạng mảng ký tự
 * @param num1 Số nguyên thứ nhất
 * @param num2 Hệ số nhân
 * @param result Kết quả nhân
 */
void multiply_big_ints(char num1[], char num2[], char result[]);

/**
 * @brief Xóa các số 0 ở đầu
 * @param num Số cần thực hiện
 * @param length Số lượng các số 0 có thể xóa.
 */
void remove_leading_zeros(char num[], int length);

/**
 * @brief Kiểm tra xem chuỗi hiện tại có thuộc danh sách các hoán vị của chuỗi ban đầu hay không.
 * @param num Chuỗi cần kiểm tra
 * @return true: Chuỗi kiểm tra thuộc danh sách các hoán vị chuỗi ban đầu.
 * @return false: Chuỗi kiểm tra không thuộc danh sách các hoán vị chuỗi ban đầu.
 */
bool is_check(char num[]);

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        char input[61];
        scanf("%s", input);

        generator_permutation(input);

        bool check;

        for (int i = 1; i <= len; i++)
        {
            check = false;
            char multiplier[3];
            char result[65];

            // chuyển đổi số sang chuỗi.
            sprintf(multiplier, "%d", i);

            // Nhân 2 số và kiểm tra kết quả xem có hợp lệ hay không.
            multiply_big_ints(input, multiplier, result);
            remove_leading_zeros(result, strlen(result) - len);

            printf("%s x %s = %s\n", input, multiplier, result);

            check = is_check(result);

            if (!check)
                break;
        }

        if (check)
            printf("YES\n");
        else
            printf("NO\n");
    }

    system("pause");
    return 0;
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

    // Restore source
    strcpy(source, permutation[0]);

    // Show the permutation
    for (i = 0; i < len; i++)
    {
        printf("%s ", permutation[i]);
    }
    printf("\n");
}

void multiply_big_ints(char num1[], char num2[], char result[])
{
    // Khai báo một biến để lưu chiều dài của kết quả
    int temp_length = strlen(num1) + strlen(num2);
    // Khởi tạo một mảng để lưu kết quả tạm thời
    int temp[temp_length];
    // Gán giá trị 0 cho tất cả các phần tử của mảng
    memset(temp, 0, sizeof(temp));

    // Duyệt qua hai chuỗi từ cuối về đầu
    for (int i = strlen(num1) - 1; i >= 0; i--)
    {
        for (int j = strlen(num2) - 1; j >= 0; j--)
        {
            // Lấy từng cặp chữ số tương ứng trong hai chuỗi
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            // Nhân chúng lại và cộng vào mảng tạm thời
            temp[i + j + 1] += digit1 * digit2;
        }
    }

    // Duyệt qua mảng tạm thời từ cuối về đầu
    for (int i = temp_length - 1; i > 0; i--)
    {
        // Chia lấy dư mỗi phần tử cho 10 và gán vào chuỗi kết quả
        result[i] = (char)(temp[i] % 10 + '0');
        // Chia lấy nguyên mỗi phần tử cho 10 và cộng vào phần tử trước đó
        temp[i - 1] += temp[i] / 10;
    }

    // Gán phần tử đầu tiên của mảng tạm thời vào chuỗi kết quả
    result[0] = (char)(temp[0] + '0');

    // Kết thúc chuỗi kết quả bằng ký tự '\0'
    result[temp_length] = '\0';
}

void remove_leading_zeros(char num[], int length)
{
    // Tìm số lượng chữ số 0 cần cắt
    int i = 0;
    while (num[i] == '0' && i < length)
    {
        i++;
    }

    // Dịch các ký tự từ vị trí đó sang trái
    int j = 0;
    while (i < (int)strlen(num))
    {
        num[j] = num[i];
        i++;
        j++;
    }

    // Kết thúc chuỗi bằng ký tự '\0'
    num[j] = '\0';
}

bool is_check(char num[])
{
    // So sánh kết quả với danh sách các hoán vị.
    for (int j = 0; j < len; j++)
    {
        if (strcmp(num, permutation[j]) == 0)
        {
            return true;
        }
    }

    return false;
}