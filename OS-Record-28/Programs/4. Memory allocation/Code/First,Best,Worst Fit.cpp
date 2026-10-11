#include <stdio.h>

void firstFit(int b[], int nb, int p[], int np) {
    int bc[nb], alloc[np];
    for (int j = 0; j < nb; j++) bc[j] = b[j];
    for (int i = 0; i < np; i++) alloc[i] = -1;

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (bc[j] >= p[i]) {
                alloc[i] = j;
                bc[j] -= p[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT\n");
    printf("P_No\tP_Size\tBlock_No\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t%d\t", i + 1, p[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int b[], int nb, int p[], int np) {
    int bc[nb], alloc[np];
    for (int j = 0; j < nb; j++) bc[j] = b[j];
    for (int i = 0; i < np; i++) alloc[i] = -1;

    for (int i = 0; i < np; i++) {
        int best = -1;
        for (int j = 0; j < nb; j++) {
            if (bc[j] >= p[i]) {
                if (best == -1 || bc[j] < bc[best])
                    best = j;
            }
        }
        if (best != -1) {
            alloc[i] = best;
            bc[best] -= p[i];
        }
    }

    printf("\nBEST FIT\n");
    printf("P_No\tP_Size\tBlock_No\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t%d\t", i + 1, p[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int b[], int nb, int p[], int np) {
    int bc[nb], alloc[np];
    for (int j = 0; j < nb; j++) bc[j] = b[j];
    for (int i = 0; i < np; i++) alloc[i] = -1;

    for (int i = 0; i < np; i++) {
        int worst = -1;
        for (int j = 0; j < nb; j++) {
            if (bc[j] >= p[i]) {
                if (worst == -1 || bc[j] > bc[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            alloc[i] = worst;
            bc[worst] -= p[i];
        }
    }

    printf("\nWORST FIT\n");
    printf("P_No\tP_Size\tBlock_No\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t%d\t", i + 1, p[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int nb, np;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    int b[nb];
    printf("Enter size of %d blocks:\n", nb);
    for (int i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);
    int p[np];
    printf("Enter size of %d processes:\n", np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &p[i]);
    }

    firstFit(b, nb, p, np);
    bestFit(b, nb, p, np);
    worstFit(b, nb, p, np);
    return 0;
}
