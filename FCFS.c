//FCFS Scheduling
//Sanchith B Anand
//1AT19IS088

#include <stdio.h>
#include <stdlib.h>

int MAX = 10;

int main()
{
	float p;
	int  b[MAX];
	char a[MAX];
	printf("=====FCFS Scheduling=====\n");
	
	//Input the number of processes
	printf("\n Number of Processes: ");
	scanf("%f",&p);
	for (int i = 0; i < p; i++)
	{
		printf("\n Name of the process (Eg: C, A) : ");
		scanf("%s",&a[i]);
		printf("\n Burst Time of the process (miliseconds) : ");
		scanf("%d",&b[i]);
		printf("\n ** Data Updated **");
	}

	//wait time calculation
	printf("\n ***Calculating Wait Time***");
	int temp = 0;
	int wt[MAX];
	wt[0]=0;
	for (int i = 1; i < p; i++)
	{
		wt[i]=b[i-1]+wt[i-1];
	}

	int sum1 = 0;
	float avg1;
	for (int i = 0; i < p; ++i)
	{
		sum1=sum1+wt[i];
	}
	avg1=sum1/p;


	//Total Turn Around Time calculation
	printf("\n ***Calculating Total Turn Around Time***");
	int tat[MAX];
	for (int i = 0; i < p; i++)
	{
		tat[i]=b[i]+wt[i];
	}

	int sum2 = 0;
	float avg2;
	for (int i = 0; i < p; ++i)
	{
		sum2=sum2+tat[i];
	}
	avg2=sum2/p;

	printf("\n \t Processes \t \t Burst Time \t \t Wait Time \t \t Turn Around Time");
	for (int i = 0; i < p; i++)
	{
		printf("\n \t \t %c \t \t \t %d \t \t \t %d \t \t \t %d",a[i],b[i],wt[i],tat[i]);
	}
	printf("\n --------------------------------------- ");
	printf("\n Average Waiting Time: %f ms",avg1);
	printf("\n Average Turn Around Time: %f ms",avg2);

}
