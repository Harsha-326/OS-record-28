#include <stdio.h>

int main() {
    int n, i, j;
    
    // Prompt user for the number of processes
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    
    int pid[20], at[20], bt[20], ct[20], wt[20], tat[20], temp;
    float avg_wt = 0, avg_tat = 0;
    
    // Accept arrival time and burst time for each process
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter AT and BT for process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("BT: ");
        scanf("%d", &bt[i]);
    }
    
    // Sort processes based on Arrival Time (FCFS chronological ordering)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap Arrival Time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                
                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                // Swap Process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    
    // Calculate Completion Time (CT)
    for (i = 0; i < n; i++) {
        if (i == 0) {
            ct[i] = at[i] + bt[i];
        } else {
            if (ct[i - 1] < at[i]) {
                ct[i] = at[i] + bt[i]; // CPU sits idle if a gap exists
            } else {
                ct[i] = ct[i - 1] + bt[i];
            }
        }
    }
    
    // Calculate Turn Around Time (TAT) and Waiting Time (WT)
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    
    // Compute averages
    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;
    
    // Display results in a formatted table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    // Print averages
    printf("\nAverage tat = %.2f ms", avg_tat);
    printf("\nAverage wt = %.2f ms\n", avg_wt);
    
    return 0;
}
