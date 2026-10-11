#include <stdio.h>
#include <stdlib.h>

void fcfs(int req[], int n, int head) {
    int total = 0;
    printf("\nFCFS RESULT\n");
    printf("Seek Sequence: %d", head);

    for (int i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }
    printf("\nTotal Seek Time: %d\n", total);
}

int main() {
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter %d requests:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    fcfs(req, n, head);

    return 0;
}


