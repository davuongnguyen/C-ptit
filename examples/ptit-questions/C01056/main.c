#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int *input_data(int *n);
void check_numbers(int *test_cases, int *n);

int main()
{
    int n = 0;
    int *test_cases = input_data(&n);

    check_numbers(test_cases, &n);

    free(test_cases);
    system("pause");
    return 0;
}

int *input_data(int *n)
{
    printf("Please enter number of test cases: ");
    scanf("%d", n);

    int *array = calloc((*n), sizeof(int));

    for (int i = 0; i < *n; i++)
    {
        printf("Case %d: ", i);
        scanf("%d", &array[i]);
    }

    printf("------------------------------------\n");

    return array;
}

void check_numbers(int *test_cases, int *n)
{
    char result;
    int current, previous;

    for (int i = 0; i < *n; i++)
    {
        result = TRUE;
        current = 10;
        previous = 10;

        while (test_cases[i])
        {
            current = test_cases[i] % 10;

            if (current > previous)
            {
                result = FALSE;
                break;
            }
            else
                previous = current;

            test_cases[i] /= 10;
        }

        if (result == TRUE)
        {
            printf("Case %d: YES\n", i);
        }
        else
        {
            printf("Case %d: NO", i);
        }
        
    }
}