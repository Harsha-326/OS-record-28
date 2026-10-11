
#include<stdio.h>
#include<stdlib.h>

void show(int frame[], int f) {
    printf("[");
    for (int i = 0; i < f; i++) {
        if (frame[i] == -1) printf(" -");
        else printf(" %d", frame[i]);
    }
    printf(" ]");
}

void lru(int pages[], int n, int f) {
    int frame[f], last[f], faults = 0;
    for (int i = 0; i < f; i++) { frame[i] = -1; last[i] = 0; }

    printf("\nLRU RESULT\n");
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i]) pos = j;

        if (pos != -1) {
            last[pos] = i;               // update recency on hit
        } else {
            int victim = 0;
            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) { victim = j; break; }
                if (last[j] < last[victim]) victim = j;
            }
            frame[victim] = pages[i];
            last[victim] = i;
            faults++;
        }
        printf("Page %d: ", pages[i]);
        show(frame, f);
        printf(pos != -1 ? " Hit\n" : " Fault\n");
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

    lru(pages, n, f);

    return 0;
}

