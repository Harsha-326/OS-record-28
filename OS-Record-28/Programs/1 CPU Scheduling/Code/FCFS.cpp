#include <stdio.h>

int main() {
    int n, i;
    
    // Prompt user for the number of processes
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n];
    float avg_wt = 0;
    float avg_tat = 0;
    
    // Accept burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter BT for process P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    // Waiting time for the first process is always 0
    wt[0] = 0;
    
    // Calculate waiting time for each subsequent process
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    
    // Calculate turn around time and sum up waiting and turn around times
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    
    // Compute averages
    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;
    
    // Display results in a formatted tabular layout
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    
    // Print average metrics
    printf("\nAverage waiting time = %.2f", avg_wt);
    printf("\nAverage turn around time = %.2f\n", avg_tat);
    
    return 0;
}
