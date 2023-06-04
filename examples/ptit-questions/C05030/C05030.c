#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

// 1
// 3 3
// 222
// 201
// 122

// 1
// 3 3
// 000
// 201
// 002

typedef struct
{
    uint32_t count_of_1;
    uint32_t count_of_2;
} matrix_statistic_t;

char matrix[1000][1000];
matrix_statistic_t row_statistic[1000];
matrix_statistic_t col_statistic[1000];

uint64_t solve(uint16_t m, uint16_t n);

void analysis(uint16_t m, uint16_t n);

int main()
{
    uint16_t t;
    scanf("%hd", &t);

    while (t--)
    {
        char row[1000];

        uint16_t n, m;
        scanf("%hd %hd", &n, &m);

        for (uint16_t i = 0; i < n; i++)
        {
            scanf("%s", row);
            for (uint16_t j = 0; j < m; j++)
                matrix[i][j] = row[j];
        }

        uint64_t result = solve(m, n);

        printf("%lld\n", result);
    }

    system("pause");
    return 0;
}

uint64_t solve(uint16_t m, uint16_t n)
{
    uint64_t result = 0;

    analysis(m, n);

    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                result += (uint64_t)(row_statistic[i].count_of_2 * col_statistic[j].count_of_2);
                // printf("%lld\t", (uint64_t)(row_statistic[i].count_of_2 * col_statistic[j].count_of_2));
            }
            else if (matrix[i][j] == '2')
            {
                result += (uint64_t)(row_statistic[i].count_of_1 * col_statistic[j].count_of_1);
                // printf("%lld\t", (uint64_t)(row_statistic[i].count_of_1 * col_statistic[j].count_of_1));
            }
        }
        printf("\n");
    }

    return result;
}

void analysis(uint16_t m, uint16_t n)
{
    // row analysis
    for (uint16_t i = 0; i < n; i++)
    {
        // set default values
        row_statistic[i].count_of_1 = 0;
        row_statistic[i].count_of_2 = 0;

        for (uint16_t j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
                row_statistic[i].count_of_1++;
            else if (matrix[i][j] == '2')
                row_statistic[i].count_of_2++;
        }
    }
    // for (uint16_t i = 0; i < n; i++)
    // {
    //     printf("%hd-%hd\t", row_statistic[i].count_of_1, row_statistic[i].count_of_2);
    // }
    // printf("\n");

    // col analysis
    for (uint16_t j = 0; j < m; j++)
    {
        // set default values
        col_statistic[j].count_of_1 = 0;
        col_statistic[j].count_of_2 = 0;

        for (uint16_t i = 0; i < n; i++)
        {
            if (matrix[i][j] == '1')
                col_statistic[j].count_of_1++;
            else if (matrix[i][j] == '2')
                col_statistic[j].count_of_2++;
        }
    }

    // for (uint16_t i = 0; i < n; i++)
    // {
    //     printf("%hd-%hd\t", col_statistic[i].count_of_1, col_statistic[i].count_of_2);
    // }
    // printf("\n");
}