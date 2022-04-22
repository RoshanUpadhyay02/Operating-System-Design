#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data,process,priority;
    struct node *next;
}*head;

void insert(int a,int value, int p)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->process = a;
    newnode->priority = p;

    if(head  == NULL || head->priority >= p)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while(temp->next != NULL && temp->next->priority <= p)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void wt_tt(int n)
{
    int waiting_time[n],turnaround_time[n],avg_wt=0,avg_tt=0;
    waiting_time[0] = 0;
    struct node *temp = head;
    int i = 1;
    while(temp != NULL && i<=n)
    {
        waiting_time[i] = waiting_time[i-1] + temp->data;
        i++;
        temp = temp->next;
    }

    i=0;
    struct node *temp1 = head;
    while(temp1 != NULL)
    {
        turnaround_time[i] = waiting_time[i] + temp1->data;
        i++;
        temp1 = temp1->next;
    }

    i=0;
    struct node *temp2 = head;
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while(temp2 != NULL)
    {
        printf("P%d\t    %d\t\t    %d\t\t    %d\t\t    %d",temp2->process,temp2->priority,temp2->data,waiting_time[i],turnaround_time[i]);
        printf("\n");
        avg_wt += waiting_time[i];
        avg_tt += turnaround_time[i];
        temp2 = temp2->next;
        i++;
    }
    printf("\n Average Watiing time = %d",avg_wt/n);
    printf("\n Average Turnaround time = %d\n\n",avg_tt/n);
}


int main()
{
    int n,i;
    printf("Enter the no. of processes: ");
    scanf("%d",&n);
    int x,y;

    printf("Enter the burst time and priority: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        insert(i+1,x,y);
    }

    wt_tt(n);

    return 0;
}