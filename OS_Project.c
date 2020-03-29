//Program to calculate waiting time and turnaround time for each process in Priority Scheduling Algorithm.
//Date:March 28,2020.    Author:Ashish Yadav

#include<stdio.h>
#include<conio.h>
int main()

{
	
	int Process_no[20],BurstTime[20],WaitingTime[20],TurnaroundTime[20];
    int i,j,Arrival_Time[20],Priority[20],NumberofProcess,Total=0,flag,temp,Avg_WaitingTime,Avg_TurnaroundTime;
    
	printf("Enter the number of Processes:");
    scanf("%d",&NumberofProcess);
    
	for(i=0;i<NumberofProcess;i++)
    {
        printf("\nP[%d]\n",(i+1));
        printf("Enter Burst Time:");
        scanf("%d",&BurstTime[i]);
        printf("Enter Arrival Time:");
        scanf("%d",&Arrival_Time[i]);
        printf("Enter Priority:");
        scanf("%d",&Priority[i]);
        Process_no[i]=i+1;
    }
    
	for(i=0;i<NumberofProcess;i++)
    {
        flag=i;
        for(j=i+1;j<NumberofProcess;j++)
        {
            if(Priority[j]<Priority[flag])
            flag=j;
        }
        temp=Priority[i];
        Priority[i]=Priority[flag];
        Priority[flag]=temp;
        temp=BurstTime[i];
        BurstTime[i]=BurstTime[flag];
        BurstTime[flag]=temp;
        temp=Process_no[i];
        Process_no[i]=Process_no[flag];
        Process_no[flag]=temp;
    }
    
	WaitingTime[0]=0;  
    for(i=1;i<NumberofProcess;i++)
    {
        WaitingTime[i]=0;
        for(j=0;j<i;j++)
            WaitingTime[i]+=BurstTime[j];
        Total+=WaitingTime[i];
    }
    Avg_WaitingTime=Total/NumberofProcess;  
    Total=0;
    printf("____________________________________________________________________\n");
    printf("\nProcess\t      Burst Time      Waiting Time   TurnaroundTime");
    
	for(i=0;i<NumberofProcess;i++)
    {
        TurnaroundTime[i]=BurstTime[i]+WaitingTime[i];  
        Total+=TurnaroundTime[i];
        printf("\nProcess %d \t %d\t \t   %d\t\t%d",Process_no[i],BurstTime[i],WaitingTime[i],TurnaroundTime[i]);
    }
        printf("\n____________________________________________________________________");
    Avg_TurnaroundTime=Total/NumberofProcess;
    printf("\n\n\nAverage Waiting Time= %d",Avg_WaitingTime);
    printf("\nAverage TurnAroundTime= %d\n\n",Avg_TurnaroundTime);
   
    return 0;
}
