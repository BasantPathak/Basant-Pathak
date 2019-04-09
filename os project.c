#include<conio.h>
#include<stdio.h>

int main()
{
  printf("\t\t******************Scheduling Algorithm*******************\n\n\n\n");
  long int no,i=0,j=0;
  printf(" Please enter the  Number of Processess : ");
  scanf("%ld",&no ); 
  double priorty[no];
  double bursttime[no];
  double arrivaltime[no],waitingTime[no],turnaroundTime[no];
  double  process[no], temp, completionTime[no];
  double min,sum=0,sum2=0,wait_final, turnaround_final, wait_avg, turnaround_avg;
  for(i=0;i<no;i++)
  {
    printf("\n Please Enter Burst Time of Processs [%d] : ", i+1 );
    scanf("%lf", &bursttime[i]);
    printf("Please Enter Arrival Time of Process [%d] : ", i+1 );
    scanf("%lf", &arrivaltime[i] );
    process[i]=i+1;
  }

  printf("\n\n\t\t\t -------------- Entered Values are --------------\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<no;i++)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],arrivaltime[i],bursttime[i]);
  }
    printf("\t\t\t---------------------------------------\n");


  printf("\n\n\t\t\t-------- Sorting Processes according to arrivaltime --------\n");

  for(i=0;i<no;i++)
  {
    for(j=0;j<no;j++)
    {
      if(arrivaltime[i]<arrivaltime[j])
      {
        
        temp = bursttime[j];
        bursttime[j] = bursttime[i];
        bursttime [i] = temp;
	
	      temp = process[j];
        process[j] = process[i];
        process[i] = temp;

	      temp = arrivaltime[j];
        arrivaltime[j] = arrivaltime[i];
        arrivaltime[i] = temp;
      
      }
    }
  }
  printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<no;i++)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],arrivaltime[i],bursttime[i]);
  }
    printf("\t\t\t---------------------------------------\n");


/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/


  long int k = 1;
  double b_time = 0;
  for(j=0;j<no;j++)
  {
    b_time = b_time + bursttime[j];
    min = bursttime[k];

    for(i=k;i<no;i++)
    {
      if((b_time >= arrivaltime[i])&&(bursttime[i]<min))
      {
        temp = bursttime[k];
        bursttime[k] = bursttime[i];
        bursttime[i] = temp;

        temp = arrivaltime[k];
        arrivaltime[k] = arrivaltime[i];
        arrivaltime[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }
    k++;
  }
  waitingTime[0] = 0;
  for(i=1;i<no;i++)
  {
    sum += bursttime[i-1];
    waitingTime[i] = sum - arrivaltime[i];
    wait_final += waitingTime[i]; 
  }
  wait_avg = wait_final/no;
  for(i=0;i<no;i++)
  {
    sum2 += bursttime[i];
    turnaroundTime[i] = sum2 - arrivaltime[i];
    turnaround_final += turnaroundTime[i];
  }
  turnaround_avg=turnaround_final/no;
printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  for(i=0;i<no;i++)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],arrivaltime[i],bursttime[i],waitingTime[i],turnaroundTime[i]);
  }
    printf("\t\t\t-----------------------------------------------------------------------------\n");



  /*Now we have to prioritize the processes according to the formulae
      priority = 1+ Waiting time / Estimated run time
  */
 
  
  completionTime[0] = bursttime[0];
  for(i=1;i<no;i++)
  {
    completionTime[i] = completionTime[i-1] + bursttime[i];
  }

  for(i=0;i<no;i++)
  {
    priorty[i] = 1+waitingTime[i]/completionTime[i];
    printf("%lf\n",priorty[i]);
  }


  printf("\n\n\t\t\t -------------- Final Values are --------------\n\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[0],arrivaltime[0],bursttime[0],waitingTime[0],turnaroundTime[0]);
  for(i=no-1;i>0;i--)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],arrivaltime[i],bursttime[i],waitingTime[i],turnaroundTime[i]);
  }
    printf("\t\t\t-----------------------------------------------------------------------------\n");

  printf("\n\n\n\t\t\tAverage Turn Around Time : %lf",turnaround_avg);
  printf("\n\t\t\tAverage Waiting Time     : %lf\n\n",wait_avg);
	
  getch();
  return 0;
}
