#include <stdio.h>
#include <stdlib.h>

void clook(int req[], int n, int head, int direction) {
    // direction: 1 = towards higher values, 0 = towards lower values
    int left[n], right[n], li = 0, ri = 0;
    for (int i = 0; i < n; i++) {
        if (req[i] < head) left[li++] = req[i];
        else right[ri++] = req[i];
    }

    // sort left and right (simple bubble sort)
    for (int i = 0; i < li - 1; i++)
        for (int j = 0; j < li - i - 1; j++)
            if (left[j] > left[j + 1]) {
                int t = left[j]; left[j] = left[j + 1]; left[j + 1] = t;
            }
    for (int i = 0; i < ri - 1; i++)
        for (int j = 0; j < ri - i - 1; j++)
            if (right[j] > right[j + 1]) {
                int t = right[j]; right[j] = right[j + 1]; right[j + 1] = t;
            }

    int total = 0;
    printf("\nCLOOK RESULT\n");
    printf("Seek Sequence: %d", head);

    if (direction == 1) {
        for (int i = 0; i < ri; i++) {
            total += abs(right[i] - head);
            head = right[i];
            printf(" -> %d", head);
        }
        // jump to the smallest request and continue upward (no reversal)
        for (int i = 0; i < li; i++) {
            total += abs(left[i] - head);
            head = left[i];
            printf(" -> %d", head);
        }
    } else {
        for (int i = li - 1; i >= 0; i--) {
            total += abs(left[i] - head);
            head = left[i];
            printf(" -> %d", head);
        }
        // jump to the largest request and continue downward (no reversal)
        for (int i = ri - 1; i >= 0; i--) {
            total += abs(right[i] - head);
            head = right[i];
            printf(" -> %d", head);
        }
    }
    printf("\nTotal Seek Time: %d\n", total);
}

int main() {
    int n, head, direction;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter %d requests:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 = towards higher, 0 = towards lower): ");
    scanf("%d", &direction);

    clook(req, n, head, direction);

    return 0;
}
