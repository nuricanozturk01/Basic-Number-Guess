#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define MAX_SIZE 100
#define HEALTH 7



void main()
{
	typedef enum Level { PRO, GOOD, STUPID } Level;
	Level level = STUPID;
	
	srand(time(0));

	int secretNumber = rand() % MAX_SIZE;
	int guess,choose;
	int health = HEALTH;


	printf("Key: %d\n", secretNumber);
	for (int i = 1; i < 2;)
	{
		printf("\n[+]Enter the number between 0-%d\n", MAX_SIZE);
		scanf_s("%d", &guess);
		if (guess < secretNumber)
		{
			printf("->Entered the number lower than secret key....\n");
			health--;
			printf("[-]Your health: %d\n", health);
		}
		else if (guess > secretNumber)
		{
			printf("->Entered the number bigger than secret key....\n");
			health--;
			printf("[-]Your health: %d\n", health);
		}
		else if(guess==secretNumber)
		{
			printf("[***] Congratulations\n");
			if (health == HEALTH)
				level = PRO;

			if (health<HEALTH && health!=0)
				level = GOOD;

			break;
		}
		if (health == 0)
		{
			printf("[->]SECRET KEY: %d\n", secretNumber);
			level = STUPID;
			break;
		}
		
	}
	switch (level)
	{
	case PRO:
		printf("[***] RESPECT: PROFESSIONAL!\n");
		break;
	case GOOD:
		printf("[**] RESPECT: GOOD\n");
		break;
	case STUPID:
		printf("[*] RESPECT: STUPID\n");
		break;
	default:
		break;
	}

	
}
