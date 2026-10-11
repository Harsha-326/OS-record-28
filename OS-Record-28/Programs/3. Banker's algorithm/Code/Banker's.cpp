#include <stdio.h> 

  int main() 
{     
	int n, m; 
    int alloc[10][10], max[10][10], need[10][10]; 
    int avail[10], finish[10] = {0}, safe[10]; 
    int i, j, count = 0; 
    printf("        BANKER'S ALGORITHM\n"); 
    printf("Enter Number of Processes : "); 
    scanf("%d", &n); 
    printf("Enter Number of Resource Types : "); 
    scanf("%d", &m); 
    printf("\nEnter Allocation Matrix:\n"); 

    for(i = 0; i < n; i++) 
    { 
        printf("P%d : ", i); 
        for(j = 0; j < m; j++) 
            scanf("%d", &alloc[i][j]); 
    } 

    printf("\nEnter Maximum Matrix:\n"); 
    for(i = 0; i < n; i++) 
    {
        printf("P%d : ", i); 
        for(j = 0; j < m; j++) 
            scanf("%d", &max[i][j]); 
    } 
    printf("\nEnter Available Resources : "); 
    for(j = 0; j < m; j++) 
        scanf("%d", &avail[j]); 
    for(i = 0; i < n; i++) 
    { 
        for(j = 0; j < m; j++) 
        { 
            need[i][j] = max[i][j] - alloc[i][j]; 
        } 
    } 

    while(count < n) 
    { 
        int found = 0; 
        for(i = 0; i < n; i++) 
        { 
        int flag = 1; 
            if(finish[i] == 0) 
                for(j = 0; j < m; j++) 
        		{ 
                    if(need[i][j] > avail[j]) 
                    { 
                    	flag = 0; 
                        break; 
                    } 
                } 
                if(flag) 
                { 
                    for(j = 0; j < m; j++) {					
                    avail[j] += alloc[i][j]; 
                    safe[count++] = i; 
                    finish[i] = 1; 
                    found = 1; 
                	} 
           	 	} 
        	}
        if(found == 0) {
            break; }
    } 
    printf("Need Matrix\n"); 
    
    for(i = 0; i < n; i++) 
    { 
        printf("P%d : ", i); 
        for(j = 0; j < m; j++) 
            printf("%d ", need[i][j]); 
        printf("\n"); 
    } 
    if(count == n) 
    { 
        printf("System is in SAFE State.\n"); 
printf("Safe Sequence : "); 

for(i = 0; i < n; i++) 
 { 
            printf("P%d", safe[i]); 
            if(i != n - 1) 
                printf(" -> "); 
        } 
        printf("\n"); 
    } 
    else 
    { 
        printf("System is NOT in SAFE State.\n"); 
    } 
    return 0; 
} 
