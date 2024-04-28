#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int *data = NULL;
    int n;
    int error = input(&data, &n);
    if (error) {
        printf("n/a");
        error++;
    } else {
        sort(data, n);
        output(data, n);
        free(data);
    }
    return error;
}

int input(int **a, int *n) {
    if (scanf("%d", n) != 1) return 1;
    if (*n <= 0) return 1;
    *a = malloc(*n * sizeof(int));
    for (int *p = *a; p - *a < *n; p++) {
        if (scanf("%d", p) != 1) {
            free(*a);
            return 1;
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", a[n - 1]);
}

void sort(int *a, int n) {
    for (int i = n; i > 1; i--)
        for (int j = 1; j < i; j++)
            if (a[j] < a[j - 1]) {
                int d = a[j];
                a[j] = a[j - 1];
                a[j - 1] = d;
            }
}