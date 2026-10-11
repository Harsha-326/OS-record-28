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

void optimal(int pages[], int n, int f) {
    int frame[f], faults = 0;
    for (int i = 0; i < f; i++) frame[i] = -1;

    printf("\nOPTIMAL RESULT\n");
    for (int i = 0; i < n; i++) {
        int hit = 0;
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i]) hit = 1;

        if (!hit) {
            int victim = 0, farthest = -1;
            for (int j = 0; j < f; j++) {
                if (frame[j] == -1) { victim = j; break; }
                int k;
                for (k = i + 1; k < n; k++)      
                    if (pages[k] == frame[j]) break;
                if (k > farthest) { farthest = k; victim = j; } 
            }
            frame[victim] = pages[i];
            faults++;
        }
        printf("Page %d: ", pages[i]);
        show(frame, f);
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
    optimal(pages, n, f);

    return 0;
}
