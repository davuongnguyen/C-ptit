#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int **input_data(int *n);
void check_numbers(int **test_cases, int *n);
char isPrime(int x);
char fullCheck(int x);

int main()
{
    int n = 0;
    int **test_cases = input_data(&n);

    check_numbers(test_cases, &n);

    free(test_cases);
    system("pause");
    return 0;
}

int **input_data(int *n)
{
    printf("Please enter number of test cases: ");
    scanf("%d", n);

    int **array = calloc((*n), sizeof(int *));

    for (int i = 0; i < *n; i++)
    {
        array[i] = calloc(2, sizeof(int));

        printf("Case %d: ", i);
        scanf("%d %d", &array[i][0], &array[i][1]);
    }

    printf("------------------------------------\n");

    return array;
}

void check_numbers(int **test_cases, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        int count = 0;
        for (int j = test_cases[i][0]; j <= test_cases[i][1]; j++)
        {   
            if(fullCheck(j) == TRUE && isPrime(j) == TRUE)
                count++;
        }
        printf("Result case %d: %d\n", i, count);
    }
}

char isPrime(int x)
{
    if (x < 2)
        return FALSE;

    int break_number = sqrt(x);
    for (int i = 2; i <= break_number; i++)
    {
        if (x % i == 0)
            return FALSE;
    }

    return TRUE;
}

char isMiniPrime(int x)
{
    if (x != 2 && x !=3 && x != 5 && x != 7)
        return FALSE;

    return TRUE;
}

char fullCheck(int x)
{
    int sum = 0;
    int temp = 0;

    while(x)
    {
        temp = x % 10;
        if (isMiniPrime(temp) == FALSE)
        {
            return FALSE;
        }

        sum += temp;
        x /= 10;
    }

    if (sum != 23 && isMiniPrime(sum) == FALSE)
    {
        return FALSE;
    }

    return TRUE;
}