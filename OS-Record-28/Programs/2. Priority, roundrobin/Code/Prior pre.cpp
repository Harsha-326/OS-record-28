#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    
    // Prompt user for the number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int pid[n], at[n], bt[n], rbt[n], priority[n], iscomp[n];
    int ct[n], tat[n], wt[n];
    
    // Accept AT, BT, and Priority for each process
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nEnter Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        
        rbt[i] = bt[i]; // Remaining burst time
        iscomp[i] = 0;  // Completion status flag
    }
    
    // Scheduling loop using preemptive priority logic
    while (completed < n) {
        int idx = -1;
        int highest_prior = 9999;
        
        for (i = 0; i < n; i++) {
            if (at[i] <= time && iscomp[i] == 0) {
                if (priority[i] < highest_prior) {
                    highest_prior = priority[i];
                    idx = i;
                } else if (priority[i] == highest_prior) {
                    if (at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }
        
        if (idx != -1) {
            rbt[idx]--;
            time++;
            
            if (rbt[idx] == 0) {
                ct[idx] = time;
                iscomp[idx] = 1;
                completed++;
            }
        } else {
            time++; // CPU sits idle if no process has arrived yet
        }
    }
    
    // Calculate Turn Around Time and Waiting Time
    float totalwt = 0, totaltat = 0;
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        
        totalwt += wt[i];
        totaltat += tat[i];
    }
    
    // Compute averages
    float avgwt = totalwt / n;
    float avgtat = totaltat / n;
    
    // Display results in a formatted table
    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", pid[i], at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }
    
    // Print averages
    printf("\nAvg wt = %.2f", avgwt);
    printf("\nAvg tat = %.2f\n", avgtat);
    
    return 0;
}
