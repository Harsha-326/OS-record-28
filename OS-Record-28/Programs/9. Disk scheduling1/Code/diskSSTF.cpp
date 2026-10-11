#include <stdio.h>
#include <stdlib.h>

void sstf(int req[], int n, int head) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int total = 0;
    int cur = head;

    printf("\nSSTF RESULT\n");
    printf("Seek Sequence: %d", cur);

    for (int count = 0; count < n; count++) {
        int closest = -1;
        int min_dist = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int dist = abs(req[i] - cur);
                if (min_dist == -1 || dist < min_dist) {
                    min_dist = dist;
                    closest = i;
                }
            }
        }

        visited[closest] = 1;
        total += min_dist;
        cur = req[closest];
        printf(" -> %d", cur);
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

    sstf(req, n, head);

    return 0;
}
