#include<iostream>
#include<conio.h>
using namespace std; 
int main()
 
{
 
  cout<<"\t\t\t----------------------- Scheduling -----------------------\n\n\n\n";
 
  long int n,i=0,j=0;
 
  cout<<"Enter Number of Processes : ";
 
  cin>>n;
 
  double priority[n],avg_waiting,avg_turnaround,burstTime[n],arrivalTime[n],waitingTime[n],turnaroundTime[n], process[n], temp, completionTime[n],min,sum=0,sum2=0,wait_final, turnaround_final, wait_avg, turnaround_avg;
 
  for(i=0;i<n;i++)
 
  {
 
    cout<<"\nEnter Burst Time for Process "<<i+1<<": ";
 
    cin>>burstTime[i];
 
    cout<<"Enter Arrival Time for Process "<< i+1<<": " ;
 
    cin>>arrivalTime[i];
 
    process[i]=i+1;
 
  }
 
 
  cout<<"\n\n\t\t\t -------------- Entered Values are --------------\n\n";
 
  cout<<"\t\t\t---------------------------------------\n";
 
  cout<<"\t\t\t| Process | Arrival Time | Burst Time |\n";
 
  cout<<"\t\t\t---------------------------------------\n";
 
  for(i=0;i<n;i++)
 
  {
 
    cout<<"\t\t\t   "<<process[i]<<"     |        "<< arrivalTime[i] <<"     |    "<< burstTime[i] <<"      |\n";
 
  }
 
    cout<<"\t\t\t---------------------------------------\n";
 
 
 
  cout<<"\n\n\t\t\t-------- Sorting Processes according to Arrivaltime --------\n";
 
 
  for(i=0;i<n;i++)
 
  {
 
    for(j=0;j<n;j++)
 
    {
 
      if(arrivalTime[i]<arrivalTime[j])
 
      {
 
        
 
        temp = burstTime[j];
 
        burstTime[j] = burstTime[i];
 
        burstTime [i] = temp;
 
 
     temp = process[j];
 
        process[j] = process[i];
 
        process[i] = temp;
 
 
     temp = arrivalTime[j];
 
        arrivalTime[j] = arrivalTime[i];
 
        arrivalTime[i] = temp;
 
      
 
      }
 
    }
 
  }
 
  cout<<"\n\n\t\t\t -------------- Now Values are --------------\n\n";
 
 cout<<"\t\t\t---------------------------------------\n";
 
  cout<<"\t\t\t| Process | Arrival Time | Burst Time |\n";
 
  cout<<"\t\t\t---------------------------------------\n";
 
  for(i=0;i<n;i++)
 
  {
 
    cout<<"\t\t\t   "<<process[i]<<"     |        "<< arrivalTime[i] <<"     |    "<< burstTime[i] <<"      |\n";
 
  }
 
    cout<<"\t\t\t---------------------------------------\n";
 
 
 
 
 
  long int k = 1;
 
  double b_time = 0;
 
  for(j=0;j<n;j++)
 
  {
 
    b_time = b_time + burstTime[j];
 
    min = burstTime[k];
 
 
    for(i=k;i<n;i++)
 
    {
 
      if((b_time >= arrivalTime[i])&&(burstTime[i]<min))
 
      {
 
        temp = burstTime[k];
 
        burstTime[k] = burstTime[i];
 
        burstTime[i] = temp;
 
 
        temp = arrivalTime[k];
 
        arrivalTime[k] = arrivalTime[i];
 
        arrivalTime[i] = temp;
 
 
        temp = process[k];
 
        process[k] = process[i];
 
        process[i] = temp;
 
      }
 
    }
 
    k++;
 
  }
 
  waitingTime[0] = 0;
 
  for(i=1;i<n;i++)
 
  {
 
    sum += burstTime[i-1];
 
    waitingTime[i] = sum - arrivalTime[i];
 
    wait_final += waitingTime[i];
 
  }
 
  wait_avg = wait_final/n;
 
  for(i=0;i<n;i++)
 
  {
 
    sum2 += burstTime[i];
 
    turnaroundTime[i] = sum2 - arrivalTime[i];
 
    turnaround_final += turnaroundTime[i]; 
 
  }
 
  turnaround_avg=turnaround_final/n;
 
  cout<<"\n\n\t\t\t -------------- Now Values are --------------\n\n";
 
  cout<<"\t\t\t-----------------------------------------------------------------------------\n";
 
  cout<<"\t\t\t| Process | Arrival Time | Burst Time | Waiting Time | Turn Around Time |\n";
 
  cout<<"\t\t\t-----------------------------------------------------------------------------\n";
 
  for(i=0;i<n;i++)
 
  {
 	cout<<"\t\t\t   "<<process[i]<<"     |        "<<arrivalTime[i] <<"     |        "<< burstTime[i]<<"     |    "<< waitingTime[i]<<"     |    "<< turnaroundTime[i]<<"      |\n";
 
  }
 
    cout<<"\t\t\t-----------------------------------------------------------------------------\n";

 
 
 
  
 
  completionTime[0] = burstTime[0];
 
  for(i=1;i<n;i++)
 
  {
 
    completionTime[i] = completionTime[i-1] + burstTime[i];
 
  }
 
 
  for(i=0;i<n;i++)
 
  {
 
    priority[i] = 1+waitingTime[i]/completionTime[i];
 
    cout<<"\t\t\t\t"<<"Priority "<<i+1<<": "<<priority[i]<<"\n";
 
  }
 
 
 
  cout<<"\n\n\t\t\t -------------- Final Values are --------------\n\n";
 
  cout<<"\t\t\t-----------------------------------------------------------------------------\n";
 
  cout<<"\t\t\t| Process | Arrival Time | Burst Time | Waiting Time | Turn Around Time |\n";
 
  cout<<"\t\t\t-----------------------------------------------------------------------------\n";
  cout<<"\t\t\t   "<<process[0]<<"     |        "<<arrivalTime[0] <<"     |        "<< burstTime[0]<<"     |    "<< waitingTime[0]<<"     |    "<< turnaroundTime[0]<<"      |\n";
  
 
  for(i=n-1;i>0;i--)
 
  {
  	
 	cout<<"\t\t\t   "<<process[i]<<"     |        "<<arrivalTime[i] <<"     |        "<< burstTime[i]<<"     |    "<< waitingTime[i]<<"     |    "<< turnaroundTime[i]<<"      |\n";
 
  }
 
    printf("\t\t\t-----------------------------------------------------------------------------\n");
 
 
  cout<<"\n\n\n\t\t\tAverage Turn Around Time :"<<turnaround_avg;
 
  cout<<"\n\t\t\tAverage Waiting Time : "<<wait_avg;
 
 
  getch();
 
  return 0;
 
}
