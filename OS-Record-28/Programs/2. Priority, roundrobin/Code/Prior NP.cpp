#include <stdio.h>

int main() {
    int n, i, j;
    
    // Prompt user for the number of processes
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    
    int pid[n], bt[n], priority[n], wt[n], tat[n];
    float awt = 0, atat = 0;
    
    // Accept burst time and priority for each process
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter BT and Priority for P%d: ", i + 1);
        scanf("%d %d", &bt[i], &priority[i]);
    }
    
    // Sort processes by priority in ascending order (lower number = higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                // Swap priority
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                
                // Swap burst time
                int temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;
                
                // Swap process ID
                int temp_pid = pid[i];
                pid[i] = pid[j];
                pid[j] = temp_pid;
            }
        }
    }
    
    // Waiting time for the first process is 0
    wt[0] = 0;
    
    // Calculate waiting time for each subsequent process
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    
    // Calculate turn around time and accumulate averages
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    
    // Compute final averages
    awt = awt / n;
    atat = atat / n;
    
    // Display results in a formatted tabular layout
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], priority[i], wt[i], tat[i]);
    }
    
    // Print average metrics
    printf("\nAvg wt = %.2f", awt);
    printf("\nAvg tat = %.2f\n", atat);
    
    return 0;
}
