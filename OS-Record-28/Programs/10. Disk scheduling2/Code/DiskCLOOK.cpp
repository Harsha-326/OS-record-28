#include <stdio.h>
#include <stdlib.h>

void cscan(int req[], int n, int head, int disk_size, int direction) {
    int arr[n + 1];
    for (int i = 0; i < n; i++) arr[i] = req[i];
    arr[n] = head;
    int total_n = n + 1;

    for (int i = 0; i < total_n - 1; i++) {
        for (int j = 0; j < total_n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int index;
    for (index = 0; index < total_n; index++) {
        if (arr[index] == head) break;
    }

    int total = 0;
    int cur = head;

    printf("\nCSCAN RESULT\n");
    printf("Seek Sequence: %d", head);

    if (direction == 1) {
        for (int i = index + 1; i < total_n; i++) {
            total += abs(arr[i] - cur);
            cur = arr[i];
            printf(" -> %d", cur);
        }
        total += abs((disk_size - 1) - cur);
        cur = disk_size - 1;
        printf(" -> %d", cur);

        // wrap to the start (no reversal) then continue upward
        total += abs(0 - cur);
        cur = 0;
        printf(" -> %d", cur);

        for (int i = 0; i < index; i++) {
            total += abs(arr[i] - cur);
            cur = arr[i];
            printf(" -> %d", cur);
        }
    } else {
        for (int i = index - 1; i >= 0; i--) {
            total += abs(arr[i] - cur);
            cur = arr[i];
            printf(" -> %d", cur);
        }
        total += abs(0 - cur);
        cur = 0;
        printf(" -> %d", cur);

        // wrap to the end (no reversal) then continue downward
        total += abs((disk_size - 1) - cur);
        cur = disk_size - 1;
        printf(" -> %d", cur);

        for (int i = total_n - 1; i > index; i--) {
            total += abs(arr[i] - cur);
            cur = arr[i];
            printf(" -> %d", cur);
        }
    }

    printf("\nTotal Seek Time: %d\n", total);
}

int main() {
    int n, head, disk_size, direction;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter %d requests:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (1 for forward, 0 for back): ");
    scanf("%d", &direction);

    cscan(req, n, head, disk_size, direction);

    return 0;
}
