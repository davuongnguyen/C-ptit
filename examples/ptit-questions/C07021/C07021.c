#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[100];
    float a, b, c, sum;
} student_t;

/**
 * @brief Đổi giá trị của 2 đối tượng cho nhau
 * @param i Đối tượng thứ nhất
 * @param j Đối tượng thứ hai
 */
void swap(student_t *i, student_t *j);

/**
 * @brief Thêm đối tượng mới vào mảng.
 * @param sv Mảng để thêm vào.
 * @param stt Số thứ tự thêm vào.
 */
void add(student_t sv[], int *stt);

/**
 * @brief Cập nhật giá trị mới cho đối tượng trong mảng.
 * @param sv Mảng để cập nhật.
 * @param id Mã sinh viên của đối tượng muốn sửa.
 */
void update(student_t sv[], int id);

/**
 * @brief Sắp xếp lại mảng theo tổng điểm
 * @param sv Mảng cần sắp xếp
 * @param length Độ dài của mảng
 */
void sort(student_t sv[], int length);

/**
 * @brief In ra màn hình console các giá trị của mảng.
 * @param sv Mảng chứa dữ liệu
 * @param length Độ dài của mảng
 */
void display(student_t sv[], int length);


int main()
{
    int n, k;
    student_t sv[100];
    int stt = 0;
    while (1)
    {
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            scanf("%d", &k);
            for (int i = 0; i < k; i++)
                add(sv, &stt);
            printf("%d\n", k);
            break;
        case 2:
            scanf("%d", &k);
            update(sv, k);
            printf("%d\n", k);
            break;
        case 3:
            goto OPTION_3;
            break;
        default:
            printf("Unknown option");
            break;
        }
    }

OPTION_3:
    sort(sv, stt);
    display(sv, stt);

    system("pause");
    return 0;
}

void swap(student_t *i, student_t *j)
{
    student_t temp = *i;
    *i = *j;
    *j = temp;
}

void add(student_t sv[], int *stt)
{
    // Gán ID = Số thứ tự + 1
    sv[*stt].id = *stt + 1;

    // Nhập thông tin tên và điểm số
    scanf("\n%[^\n]s", sv[*stt].name);      // %[^\n]s: Đọc các ký tự cho đến khi gặp ký tự xuống dòng (\n)
    scanf("%f %f %f", &sv[*stt].a, &sv[*stt].b, &sv[*stt].c);

    // Tính toán và gán tổng
    sv[*stt].sum = sv[*stt].a + sv[*stt].b + sv[*stt].c;

    // Cập nhật số thứ tự
    *stt++;
}

void update(student_t sv[], int id)
{
    int index = id - 1;             // Vì vị trí trong mảng của đối tượng bé hơn id một đơn vị.

    scanf("\n%[^\n]s", sv[index].name);
    scanf("%f %f %f", &sv[index].a, &sv[index].b, &sv[index].c);
    sv[index].sum = sv[index].a + sv[index].b + sv[index].c;
}

void sort(student_t sv[], int stt)
{
    for (int i = 0; i < stt - 1; i++)
        for (int j = i + 1; j < stt; j++)
            if (sv[j].sum < sv[i].sum)
                swap(&sv[i], &sv[j]);
}

void display(student_t sv[], int stt)
{
    for (int i = 0; i < stt; i++)
        printf("%d %s %.1f %.1f %.1f\n", sv[i].id, sv[i].name, sv[i].a, sv[i].b, sv[i].c);
}