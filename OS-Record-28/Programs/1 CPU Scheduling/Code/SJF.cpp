#include <stdio.h>

int main() {
    int n, i, j;
    
    // Prompt user for the number of processes
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    
    int pid[n], bt[n], wt[n], tat[n];
    float avg_wt = 0, avg_tat = 0;
    
    // Initialize process IDs and accept burst times
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter BT for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    // Sort processes by burst time in ascending order (SJF selection logic)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                // Swap corresponding process ID
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
    
    // Calculate turn around time and sum up metrics
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    
    // Compute averages
    avg_wt = (float)avg_wt / n;
    avg_tat = (float)avg_tat / n;
    
    // Display results in a formatted tabular layout
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }
    
    // Print average metrics
    printf("\nAverage waiting time = %.2f", avg_wt);
    printf("\nAverage turn around time = %.2f\n", avg_tat);
    
    return 0;
}
