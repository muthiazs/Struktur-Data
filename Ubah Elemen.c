#include <stdio.h>

void ubahElemen(int tabel[], int n, int i, int Y)
{
    tabel[i] = Y;
}

int main()
{
    int tabel[] = {1, 2, 3, 4, 5};
    int n = sizeof(tabel) / sizeof(tabel[0]);
    int i = 2;
    int Y = 10;

    ubahElemen(tabel, n, i, Y);

    for (int j = 0; j < n; j++)
    {
        printf("%d ", tabel[j]);
    }
    printf("\n");

    return 0;
}

