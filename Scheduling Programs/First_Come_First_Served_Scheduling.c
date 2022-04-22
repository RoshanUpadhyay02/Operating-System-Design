#include <stdio.h>

int main()
{
    int n,i;
    printf("Enter the no. of processes: ");
    scanf("%d",&n);
    int burst_time[n], waiting_time[n], turnaround_time[n],avg_wt=0,avg_tt=0;

    printf("Enter the burst time: ");
    for(i=0;i<n;i++)
        scanf("%d",&burst_time[i]);

    waiting_time[0] = 0;
    for(i=1;i<n;i++)
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];

    for(i=0;i<n;i++)
        turnaround_time[i] = waiting_time[i] + burst_time[i];

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t    %d\t\t    %d\t\t    %d",i,burst_time[i],waiting_time[i],turnaround_time[i]);
        printf("\n");
        avg_wt += waiting_time[i];
        avg_tt += turnaround_time[i];
    }


    printf("\n Average Watiing time = %d",avg_wt/n);
    printf("\n Average Turnaround time = %d\n\n",avg_tt/n);

    return 0;
}