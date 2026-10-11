#include<stdio.h>
#include<stdlib.h>

void print(int frame[], int f) {
    printf("[");
    for (int i = 0; i < f; i++) {
        if (frame[i] == -1) printf(" -");
        else printf(" %d", frame[i]);
    }
    printf(" ]");
}

void fifo(int pages[], int n, int f) {
    int frame[f], next = 0, faults = 0;
    for (int i = 0; i < f; i++) frame[i] = -1;

    printf("\nFIFO RESULT\n");
    for (int i = 0; i < n; i++) {
        int hit = 0;
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i]) hit = 1;

        if (!hit) {
            frame[next] = pages[i];
            next = (next + 1) % f;
            faults++;
        }
        printf("Page %d: ", pages[i]);
        print(frame, f);
        printf(hit ? " Hit\n" : " Fault\n");
    }
    printf("Total Page Faults: %d\n", faults);
}
int main() {
    int n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter reference string (%d pages):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    fifo(pages, n, f);

    return 0;
}
