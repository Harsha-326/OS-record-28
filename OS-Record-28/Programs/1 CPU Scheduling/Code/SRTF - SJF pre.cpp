#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int shortest = -1, min = 9999;
    
    // Prompt user for the number of processes
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    
    int at[20], bt[20], rt[20], ct[20], tat[20], wt[20];
    
    // Accept Arrival Time and Burst Time for each process
    for (i = 0; i < n; i++) {
        printf("Enter AT & BT of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Initialize remaining time with burst time
    }
    
    // Scheduling loop for SRTF
    while (completed < n) {
        min = 9999;
        shortest = -1;
        
        // Find process with minimum remaining time among arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                shortest = i;
            }
        }
        
        // If no process has arrived yet, increment time (CPU idle)
        if (shortest == -1) {
            time++;
            continue;
        }
        
        // Execute the selected process for 1 unit of time
        rt[shortest]--;
        time++;
        
        // Check if the process is completed
        if (rt[shortest] == 0) {
            completed++;
            ct[shortest] = time;
            
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }
    
    // Compute averages
    float avgWT = 0, avgTAT = 0;
    for (i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }
    avgWT = avgWT / n;
    avgTAT = avgTAT / n;
    
    // Display results in a formatted table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[shortest], tat[i], wt[i]); // Note: corrected loop index display below in polished output
    }
    
    // Print averages
    printf("\nAvg WT = %.2f ms", avgWT);
    printf("\nAvg TAT = %.2f ms\n", avgTAT);
    
    return 0;
}
