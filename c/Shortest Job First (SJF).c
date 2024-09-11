#include <stdio.h>

struct Process {
    int pid;        // Process ID
    int burst_time; // Burst Time
    int arrival_time; // Arrival Time
    int waiting_time; // Waiting Time
    int turn_around_time; // Turnaround Time
};

void sort_by_arrival(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].arrival_time > proc[j].arrival_time) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void sort_by_burst(struct Process proc[], int n, int start) {
    struct Process temp;
    for (int i = start; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].burst_time > proc[j].burst_time) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void calculate_waiting_time(struct Process proc[], int n) {
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
    }
}

void calculate_turnaround_time(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

int main() {
    int n;
    struct Process proc[30];

    // Input the number of processes
    printf("Enter the total number of processes (maximum 30): ");
    scanf("%d", &n);

    // Input burst time and arrival time for each process
    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("P[%d]\n", proc[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst_time);
    }

    // Sort processes by arrival time
    sort_by_arrival(proc, n);

    // Sort processes by burst time starting from the first arrived process
    sort_by_burst(proc, n, 0);

    // Calculate waiting time and turnaround time for each process
    calculate_waiting_time(proc, n);
    calculate_turnaround_time(proc, n);

    // Display process details
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t%d", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].waiting_time, proc[i].turn_around_time);
    }

    // Calculate and display average waiting time and turnaround time
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waiting_time;
        total_tat += proc[i].turn_around_time;
    }

    printf("\n\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);

    return 0;
}
