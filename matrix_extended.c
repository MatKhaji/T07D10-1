#include <stdio.h>
#include <stdlib.h>

void static_alloc(int n, int m) {
    int matrix[100][100];
    int max_elements[100];
    int min_elements[100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        int max = matrix[i][0];
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] > max) max = matrix[i][j];
            printf("%d ", matrix[i][j]);
        }
        max_elements[i] = max;
    }
    for (int j = 0; j < m; ++j) {
        int min = matrix[0][j];
        for (int i = 1; i < n; ++i) {
            if (matrix[i][j] < min) min = matrix[i][j];
            printf("%d ", matrix[i][j]);
        }
        min_elements[j] = min;
    }
}

void dynamic_alloc(int n, int m) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void dynamic_alloc_with_realloc(int n, int m) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void dynamic_alloc_with_calloc(int n, int m) {
    int** matrix = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int*)calloc(m, sizeof(int));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int choice;
    printf("Выберите тип выделения памяти:\n");
    printf("1. Статическое выделение\n");
    printf("2. Динамическое выделение с помощью malloc\n");
    printf("3. Динамическое выделение с помощью realloc\n");
    printf("4. Динамическое выделение с помощью calloc\n");
    scanf("%d", &choice);
    int n, m;

    scanf("%d %d", &n, &m);
    switch (choice) {
        case 1:
            static_alloc(n, m);
            break;
        case 2:
            dynamic_alloc(n, m);
            break;
        case 3:
            dynamic_alloc_with_realloc(n, m);
            break;
        case 4:
            dynamic_alloc_with_calloc(n, m);
            break;
        default:
            printf("n/a");
    }
    return 0;
}
