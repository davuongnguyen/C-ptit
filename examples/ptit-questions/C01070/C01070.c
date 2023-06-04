#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    uint8_t a;
    uint8_t b;
} rectangle_t;

void input_data(rectangle_t (*arr_r)[3]);
void check_square(rectangle_t (*arr_r)[3]);
void sort_rectangle(rectangle_t (*arr_r)[3]);

int main()
{
    rectangle_t arr_r[3];
    input_data(&arr_r);

    check_square(&arr_r);

    system("pause");
    return 0;
}

void input_data(rectangle_t (*arr_r)[3])
{
    printf("Please enter data (a, b)!\n");
	printf("Rectangle 1: ");
	scanf("%hhd %hhd", &arr_r[0]->a, &arr_r[0]->b);
    printf("Rectangle 2: ");
	scanf("%hhd %hhd", &arr_r[1]->a, &arr_r[1]->b);
    printf("Rectangle 3: ");
	scanf("%hhd %hhd", &arr_r[2]->a, &arr_r[2]->b);

    printf("\nData:\n");
	printf("%hhd - %hhd\n%hhd - %hhd\n%hhd - %hhd",
		   arr_r[0]->a, arr_r[0]->b, 
           arr_r[1]->a, arr_r[1]->b, 
           arr_r[2]->a, arr_r[2]->b);

	printf("\n--------------------------------\n\n\n");
}

void check_square(rectangle_t (*arr_r)[3])
{
    sort_rectangle(arr_r);

    // th1
    if (arr_r[0]->b == arr_r[1]->b && arr_r[1]->b == arr_r[2]->b)
    {
        if ((arr_r[0]->a + arr_r[1]->a + arr_r[2]->a) == arr_r[0]->b)
        {
            printf("YES - th1");
            return;
        }
        else
        {
            printf("NO - th1");
            return;
        }
    }

    // th2
    uint8_t temp = arr_r[2]->b - arr_r[2]->a;
    if (arr_r[0]->a == temp && arr_r[1]->a == temp)
    {
        if (arr_r[0]->b + arr_r[1]->b == arr_r[2]->b)
        {
            printf("YES - th2");
            return;
        }
    }
    if (arr_r[0]->a == temp && arr_r[1]->b == temp)    
    {
        if (arr_r[0]->b + arr_r[1]->a == arr_r[2]->b)
        {
            printf("YES - th2");
            return;
        }
    }
    if (arr_r[0]->b == temp && arr_r[1]->a == temp)
    {
        if (arr_r[0]->a + arr_r[1]->b == arr_r[2]->b)
        {
            printf("YES - th2");
            return;
        }
    }
    if (arr_r[0]->b == temp && arr_r[1]->b == temp)
    {
        if (arr_r[0]->a + arr_r[1]->a == arr_r[2]->b)
        {
            printf("YES - th2");
            return;
        }
    }
    
    printf("NO - th2");
}

void sort_rectangle(rectangle_t (*arr_r)[3])
{
    uint8_t temp = 0;
    rectangle_t r_temp = {0, 0};
    for (uint8_t i = 0; i < 3; i++) 
    {
        if (arr_r[i]->a > arr_r[i]->b)
        {
            temp = arr_r[i]->a;
            arr_r[i]->a = arr_r[i]->b;
            arr_r[i]->b = temp;
        }
    }

    for (uint8_t i = 0; i < 2; i++)
    {
        if (arr_r[i]->b > arr_r[i+1]->b)
        {
            r_temp = *arr_r[i];
            *arr_r[i] = *arr_r[i+1];
            *arr_r[i+1] = r_temp;
        }
    }
}