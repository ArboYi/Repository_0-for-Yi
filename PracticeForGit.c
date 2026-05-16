#include <stdio.h>

void merge_arrays(const int *a, int na, const int *b, int nb, int *c)
{
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < na) {
        c[k++] = a[i++];
    }

    while (j < nb) {
        c[k++] = b[j++];
    }
}

int main(void)
{
    int a[8];
    int b[6];
    int c[14];

    for (int i = 0; i < 8; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 0;
        }
    }

    for (int i = 0; i < 6; i++) {
        if (scanf("%d", &b[i]) != 1) {
            return 0;
        }
    }

    merge_arrays(a, 8, b, 6, c);

    for (int i = 0; i < 14; i++) {
        printf("%d", c[i]);
        if (i < 13) {
            putchar(' ');
        }
    }

    return 0;
}
