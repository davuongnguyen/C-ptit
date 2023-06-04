#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void solve();

int main()
{
    uint8_t t = 0;
    scanf("%hhu", &t);
    while (t--)
    {
        solve();
    }

    system("pause");
    return 0;
}

void solve()
{
    uint8_t m = 0;
    scanf("%hhd", &m);

    char arr[10][11];

    for (size_t i = 0; i < m; i++)
    {
        scanf("%s", arr[i]);
    }

    for (uint8_t i = 0; i < m - 1; i++)
    {
        for (uint8_t j = i + 1; j < m; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                char tmp[11];
                strcpy(tmp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], tmp);
            }
        }
    }

    for (uint8_t i = 0; i < m; i++)
    {
        printf("%s", arr[i]);
    }
    printf("\n");
}