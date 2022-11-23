#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "priorityListFunc.c"
#include "queue_functions.c"

int areAllCashiersFree(int* cashier, int n);

int main()
{
	srand(20);
	printf("This is a VIP bank realization program.\n\n");
	int validation, probOfNormal, probOfVIP, amountOfNormalCashiers, amountOfVIPCashiers,
        serveTimeOfNormal, serveTimeOfVIP, dayLength, currentTime = 0, situation = 0;
	/*while(situation != 1 && situation != 2)
    {
		printf("Please select a situation you want to simulate (1 or 2).\n");
		scanf("%d", &situation);
	}*/

	FILE* fin = fopen("duom.txt", "r");
    validation = fscanf(fin, "%d%d%d%d%d%d%d", &probOfNormal, &probOfVIP, &amountOfNormalCashiers,
                        &amountOfVIPCashiers, &serveTimeOfNormal, &serveTimeOfVIP, &dayLength);
    fclose(fin);
    if(validation != 7)
    {
        printf("Something wrong with the data in the input file!\n");
        exit(1);
    }


		PriorityQueue* pQueue;
		CreateEmptyQueue(&pQueue);

		int cashierAmount = amountOfNormalCashiers + amountOfVIPCashiers;
		int cashierWorkTime = 0, cashierOvertime = 0, normalWaitingTime = 0, VIPWaitingTime = 0;
		int* cashier = malloc(cashierAmount * sizeof(int));

		for(int i = 0; i < cashierAmount; ++i)
			cashier[i] = 0;

		while(currentTime++ < dayLength || !IsEmpty(pQueue) || !areAllCashiersFree(cashier, cashierAmount))
        {
			int randForNormal = rand() % 100, randForVIP = rand() % 100;
			if(currentTime < dayLength)
            {
				if(randForNormal >= 100 - probOfNormal)
					Insert(&pQueue, serveTimeOfNormal, 0);
				if(randForVIP >= 100 - probOfVIP)
					Insert(&pQueue, serveTimeOfVIP, 1);
			}
			for(int i = 0; i < cashierAmount; ++i)
			{
				if(cashier[i] == 0 && !IsEmpty(pQueue))
				{
					cashier[i] = pQueue->head->data;
					Remove(&pQueue);
				}
			}
			for(int i = 0; i < cashierAmount; ++i)
            {
				if(cashier[i] > 0)
				{
					cashierWorkTime++;
					cashier[i]--;
					if(currentTime > dayLength)
						cashierOvertime++;
				}
			}

			Node* temp = (Node*)malloc(sizeof(Node));
			temp = pQueue->head;
			while(temp != NULL)
			{
				if(temp->priority == 1)
					VIPWaitingTime++;
				else
					normalWaitingTime++;

				temp = temp->next;
			}
		}
		printf("\nSimulation successful. Here are the results:\n");
		printf("Work time of cashiers: %d\nOvertime of cashiers: %d", cashierWorkTime, cashierOvertime);
                //\nNormal cashier waiting time: %d\nVIP cashier waiting time: %d

        fin = fopen("duom.txt", "r");
        validation = 0;
        validation = fscanf(fin, "%d%d%d%d%d%d%d", &probOfNormal, &probOfVIP, &amountOfNormalCashiers,
                        &amountOfVIPCashiers, &serveTimeOfNormal, &serveTimeOfVIP, &dayLength);
        //printf("%d %d %d %d %d %d %d", probOfNormal, probOfVIP, amountOfNormalCashiers, amountOfVIPCashiers, serveTimeOfNormal, serveTimeOfVIP, dayLength);
        fclose(fin);
    if(validation != 7)
    {
        printf("Something wrong with the data in the input file!\n");
        exit(1);
    }

		struct Queue* normalQueue = createQueue(), * VIPQueue = createQueue();
		int error = 0;
		cashierWorkTime = 0, cashierOvertime = 0, normalWaitingTime = 0, VIPWaitingTime = 0, currentTime = 0;
		int* VIPCashiers = (int*)malloc(sizeof(int) * amountOfVIPCashiers);

		for(int i = 0; i < amountOfVIPCashiers; ++i)
			VIPCashiers[i] = 0;

		int* normalCashiers = (int*)malloc(amountOfNormalCashiers * sizeof(int));
		for(int i = 0; i < amountOfNormalCashiers; ++i)
			normalCashiers[i] = 0;

		while(currentTime++ < dayLength || !isEmpty(normalQueue) || !isEmpty(VIPQueue) || !areAllCashiersFree(normalCashiers, amountOfNormalCashiers)
                || !areAllCashiersFree(VIPCashiers, amountOfVIPCashiers))
        {
			int randForNormal = rand() % 100, randForVIP = rand() % 100;
			if(currentTime < dayLength)
            {
				if(randForNormal >= 100 - probOfNormal)
					enQueue(normalQueue, serveTimeOfNormal, &error);
				if(randForVIP >= 100 - probOfVIP)
					enQueue(VIPQueue, serveTimeOfVIP, &error);
			}
			for(int i = 0; i < amountOfNormalCashiers; ++i)
			{
				if(normalCashiers[i] == 0 && !isEmpty(normalQueue))
				{
					normalCashiers[i] = normalQueue->front->data;
					deQueue(normalQueue);
				}
			}
			for(int i = 0; i < amountOfVIPCashiers; ++i)
			{
				if(VIPCashiers[i] == 0 && !isEmpty(VIPQueue))
				{
					VIPCashiers[i] = VIPQueue->front->data;
					deQueue(VIPQueue);
				}
			}
			for(int i = 0; i < amountOfVIPCashiers; ++i)
			{
				if(VIPCashiers[i] > 0)
				{
					cashierWorkTime++;
					VIPCashiers[i]--;
					if(currentTime > dayLength)
						cashierOvertime++;
				}
			}
			for(int i = 0; i < amountOfNormalCashiers; ++i)
			{
				if(normalCashiers[i] > 0)
				{
					cashierWorkTime++;
					normalCashiers[i]--;
					if(currentTime > dayLength)
						cashierOvertime++;
				}
			}


			struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
			temp = VIPQueue->front;
			while(temp != NULL)
            {
				VIPWaitingTime++;
				temp = temp->next;
			}

			temp = normalQueue;
			while(temp != NULL)
			{
				normalWaitingTime++;
				temp = temp->next;
			}
		}
		printf("\nSimulation successful. Here are the results:\n");
		printf("Work time of cashiers: %d\nOvertime of cashiers: %d", cashierWorkTime, cashierOvertime);

	return 0;
}

int areAllCashiersFree(int* cashier, int n)
{
	for(int i = 0; i < n-1; ++i)
    {
		if(cashier[i] != 0)
			return 0;
	}
	return 1;
}
