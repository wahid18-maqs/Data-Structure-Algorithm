#include<stdio.h>

int main() 
{
    int n, bt[30], wait_t[30], turn_ar_t[30];
    int av_wt_t = 0, av_turn_ar_t = 0, i, j;

    // Input the number of processes
    printf("Please enter the total number of processes (maximum 30): ");
    scanf("%d", &n); 

    // Input burst time for each process
    printf("\nEnter the Burst Time for each process:\n");
    for(i = 0; i < n; i++) 
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate waiting time for each process
    wait_t[0] = 0;  // First process has 0 waiting time
    for(i = 1; i < n; i++) 
    {
        wait_t[i] = 0;
        for(j = 0; j < i; j++)
            wait_t[i] += bt[j];  // Accumulate burst time of previous processes
    }

    // Display process details and calculate average waiting and turnaround time
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i = 0; i < n; i++) 
    {
        turn_ar_t[i] = bt[i] + wait_t[i];  // Calculate turnaround time
        av_wt_t += wait_t[i];  // Accumulate total waiting time
        av_turn_ar_t += turn_ar_t[i];  // Accumulate total turnaround time
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wait_t[i], turn_ar_t[i]);
    }

    // Calculate and display the average waiting time and turnaround time
    av_wt_t /= n;
    av_turn_ar_t /= n;

    printf("\n\nAverage Waiting Time: %d", av_wt_t);
    printf("\nAverage Turnaround Time: %d", av_turn_ar_t);

    return 0;
}
