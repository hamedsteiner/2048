#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// All rights reserved by SeyedHamed RahmaniKhezri

void intro()/*rabete graphiki*/
{
	int i, j;
	for (j = 0; j < 2; j++)
	{
		for (i = 0; i < 25; i++)
		{
			printf("***");
			if (i == 24)
				printf("\n");
		}
	}
	printf("   ***   2048:the game   produced by hamed rahmani  enjoy the game!  ***\n");
	for (j = 0; j < 2; j++)
	{
		for (i = 0; i < 25; i++)
		{
			printf("***");
			if (i == 24)
				printf("\n");
		}
	}
}

void drawnewtable(int array[][4])/* printing newtable in restart in pause */
{
	int i, j;
	printf("			            score=0\n");
	printf("			_________________________________\n\n");
	for (i = 0; i < 4; i++)
	{
		printf("			");
		for (j = 0; j < 4; j++)
		{
			if (array[i][j]>0)
			{

				printf("|%4d	", array[i][j]);
			}
			else
				printf("|    	");
			if (j == 3)
			{
				printf("|\n");
				printf("			_________________________________\n\n");

			}
		}
	}
}

int max(int array[][4])/*finding the greatest number as we consider 2048 */
{
	int i,j;
	int max = array[0][0];
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			max = max>array[i][j] ? max : array[i][j];
		}
	}
	return max;
}

int checkzero(int array[][4])/*tedade sefaro bar migardone*/
{
	int i, j, s = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			if (array[i][j] == 0)
				s++;
		}
	return s;
}

int endgame(int array[][4])/* NO MOVEMENT CIRCUMSTANCE */
{
	int i, j, s = 0;
	for (i = 0; i < 4; i++)
	{
	for (j = 0; j < 3; j++)
			if (array[i][j] == array[i][j + 1])
				s++;
	}
	for (j = 0; j <= 3; j++)
	for (i = 0; i < 3; i++)
		{
			if (array[i][j] == array[i + 1][j])
				s++;
		}
	return s;
}

void randmaker(int array[][4])
{
	int c,num;
	int i, j, count = 0, secondcount = 0;
	c = rand() % 3;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		if (array[i][j] == 0)
			count++;
	}
	num = (rand() % count) + 1;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		if (array[i][j] == 0)
		{
			secondcount++;
			if (num == secondcount)
			{
				if (c == 1 || c == 2)
					array[i][j] = 2;
				else
					array[i][j] = 4;
			}
		}
	}
}

int shiftright(int array[][4])/* tabee right ke AZ RAST AMAL MIKONAD*/
{
	int score = 0;
	int i, j, t;
	for (i = 0; i < 4; i++)
	for (t = 0; t < 4; t++)
	for (j = 3; j>0; j--)
		if (array[i][j] == 0)
			{
			array[i][j] = array[i][j - 1];
			array[i][j - 1] = 0;
			}	
		for (i = 0; i < 4; i++)
	for (j = 3; j>0; j--)
	{
		if (array[i][j] == array[i][j - 1])
		{
			array[i][j] += array[i][j - 1];
			score += array[i][j];
			array[i][j - 1] = 0;
		}
	}
	for (i = 0; i < 4; i++)
	for (t = 0; t < 4; t++)
	for (j = 3; j>0; j--)
		if (array[i][j] == 0)
			{
			array[i][j] = array[i][j - 1];
			array[i][j - 1] = 0;
			}
	return score;
}

int shiftleft(int array[][4])/* tabee left ke AZ CHAP AMAL MIKONAD*/
{
	int score = 0;
	int i, j, t;
	for (i = 0; i < 4; i++)
	for (t = 0; t < 4; t++)
	for (j = 0; j<3; j++)
	if (array[i][j] == 0)
	{
		array[i][j] = array[i][j + 1];
		array[i][j + 1] = 0;
	}
	for (i = 0; i < 4; i++)
	for (j = 0; j<3; j++)
	{
		if (array[i][j] == array[i][j+1])
		{
			array[i][j] += array[i][j+1];
			score += array[i][j];
			array[i][j+1] = 0;
		}
	}
	for (i = 0; i < 4; i++)
	for (t = 0; t < 4; t++)
	for (j = 0; j<3; j++)
	if (array[i][j] == 0)
	{
		array[i][j] = array[i][j + 1];
		array[i][j + 1] = 0;
	}
	return score;
}

int shiftup(int array[][4])
{
	int score = 0;
	int i, j, t;
	for (j = 0; j<4; j++)
	for (t = 0; t < 4; t++)
	for (i = 0; i<3; i++)
	if (array[i][j] == 0)
	{
		array[i][j] = array[i + 1][j];
		array[i + 1][j] = 0;
	}
	for (i = 0; i<3; i++)
	for (j = 0; j<4; j++)
	{
		if (array[i][j] == array[i + 1][j])
		{
			array[i][j] += array[i +1][j];
			score += array[i][j];
			array[i +1 ][j] = 0;
		}
	}
	for (j = 0; j<4; j++)
	for (t = 0; t < 4; t++)
	for (i = 0; i<3; i++)
	if (array[i][j] == 0)
	{
		array[i][j] = array[i + 1][j];
		array[i + 1][j] = 0;
	}
	return score;
}

int shiftdown(int array[][4])
{
	int score = 0;
	int i, j, t;
	for (j = 0; j<4; j++)
	for (t = 0; t < 4; t++)
	for (i = 3; i>0; i--)
	if (array[i][j] == 0)
	{
		array[i][j] = array[i - 1][j];
		array[i - 1][j] = 0;
	}
	for (i = 3; i>0; i--)
	for (j = 0; j<4; j++)
	{
		if (array[i][j] == array[i - 1][j])
		{
			array[i][j] += array[i - 1][j];
			array[i - 1][j] = 0;
			score += array[i][j];

		}
	}
	for (j = 0; j<4; j++)
	for (t = 0; t < 4; t++)
	for (i = 3; i>0; i--)
	if (array[i][j] == 0)
	{
		array[i][j] = array[i - 1][j];
		array[i - 1][j] = 0;
	}
	return score;
}

int main()           /*start of program*/
{
	srand(time(NULL));
	int copy[4][4];
	char command[10];
	int score = 0;
	int array[4][4] = { 0 };
	int x, i, a, b, j, check, pausecommand;
	intro();/*graphic function!*/
	printf("\n\n\t\t\t\t menu\n\n	  *__|__*  welcome to the  of 2048:hamed rahmani Edition *__|__* \n\n\n\t***type the according number as you wish***\n\n  \t  )1 commencing\n \t  )2 terminate\n \t ");
	while (true)/*while asli ke bar asase maghadire avalie dar menu ejra ya payan miabad */
	{
		a = rand() % 4;
		b = rand() % 4;
		i = rand() % 4;
		j = rand() % 4;
		array[i][j] = 2;
		if (a == i && j == b)/* checking whether the randomz would fill each other or not */
			array[(a + 1) % 4][(b + 1) % 4] = 2;
		else array[a][b] = 2;
		scanf("%d", &x);
		if (x == 2)/*terminate*/
			return 0;
		else if (x == 1)/*beginning of the game from menu*/
		{
			printf("			            score=0\n");/*printing first table*/
			printf("			_________________________________\n\n");
			for (i = 0; i < 4; i++)
			{
				printf("			");
				for (j = 0; j < 4; j++)
				{
					if (array[i][j]>0)
					{

						printf("|%4d	", array[i][j]);
					}
					else
						printf("|    	");
					if (j == 3)
					{
						printf("|\n");
						printf("			_________________________________\n\n");

					}
				}
			}

			while ((max(array) < 2048) || (endgame != 0 && checkzero != 0))/* sharte aval va 2vom payane bazi*/
			{
				check = 0;
				for (i = 0; i < 4; i++)
				for (j = 0; j < 4; j++)
					copy[i][j] = array[i][j];/*gereftane ye copy az araye baraye chek kardane halate khas*/
				scanf("%s", command);/*dastoor giri baraye harakate bazi*/
				if (strncmp(command, "up", 3) == 0)
				{
					score += shiftup(array);
				}

				else	if (strncmp(command, "right", 6) == 0)
				{
					score += shiftright(array);
				}

				else if (strncmp(command, "left", 5) == 0)
				{
					score += shiftleft(array);
				}

				else if (strncmp(command, "down", 5) == 0)
				{
					score += shiftdown(array);
				}

				else	if (strncmp(command, "exit", 5) == 0)
				{
					printf("     YOU HAVE TERMINATED THE GAME \n VISIT US LATER\n");
					return 0;
				}

				else	if (strncmp(command, "pause", 6) == 0)
				{
					while (true)/* a while for pause to end or continue*/
					{
						printf("\n\n		 ****PAUSE****		\n");
						printf(" \t\t1)EXIT GAME \n\t\t2)RESTART THE GAME \n\t\t3)RESUME	\n");
						scanf("%d", &pausecommand);
						if (pausecommand == 2)/* restart */
						{
							printf("		   you have choosen to start new game  \n\n\n \t\ttype the according commands as you wish\n\n\n\n ");
							check = 1;
							score = 0;
							for (i = 0; i < 4; i++)
							{
								for (j = 0; j < 4; j++)
									array[i][j] = 0;
							}
							a = rand() % 4;
							b = rand() % 4;
							i = rand() % 4;
							j = rand() % 4;
							array[i][j] = 2;
							if (a == i && j == b)
								array[(a + 1) % 4][(b + 1) % 4] = 2;
							else array[a][b] = 2;
							drawnewtable(array);
							break;
						}
						else if (pausecommand == 1)/* exit */
						{
							printf(" *__|__*you have choosen to completely exit the game \n");
							return 0;
						}
						else if (pausecommand == 3)/* continue the game as it was */
						{
							printf("enter a command to move your game\n");
								break;
						}
						else/* wrong command */
						{
							printf("wrong.........try again from first\n enter commands\n\n");
							continue;
						}
					}

				}

				else/*invalid comand for table */
				{
					printf("	 ***** you have give invalid command. try typing a new command*****  \n\n");
					continue;
				}

				if (check == 1)/* if the player intends to start a new game.....rand maker wont work for a round*/
					continue;

				else
				{
					for (i = 0; i < 4; i++)
					for (j = 0; j < 4; j++)
					if (copy[i][j] == array[i][j])/*checking if the numbers have made any changes or not */
						continue;
					else{
						randmaker(array);
						printf("\n\n");
						printf("\n\n	\t\tscore:%d\n\n", score);

						printf("			_________________________________\n\n");
						for (i = 0; i < 4; i++)
						{
							printf("			");
							for (j = 0; j < 4; j++)
							{
								if (array[i][j]>0)
								{

									printf("|%4d	", array[i][j]);
								}
								else
									printf("|    	");
								if (j == 3)
								{
									printf("|\n");
									printf("			_________________________________\n\n");

								}
							}
						}
					}
				}/*end of else*/
			}/*end of second while*/
		}/* end of x==1*/
		if (max(array) == 2048)/* WINNING CONDITION*/
		{
			printf("\n\tCONGRATS	YOU WIN\n\n\n\n");
			printf("\n\n\t\t\t\t menu\n\n	  *__|__*  welcome to the  of 2048:hamed rahmani Edition *__|__* \n\n\n\t***type the according number as you wish***\n\n  \t  )1 commencing\n \t  )2 terminate\n \t ");
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
					array[i][j] = 0;
			}
			continue;
		}
		else/* LOSING CONDITION*/
		{
			printf(" YOU LOSE\n\n\n\n ");
			printf("\n\n\t\t\t\t menu\n\n	  *__|__*  welcome to the  of 2048:hamed rahmani Edition *__|__* \n\n\n\t***type the according number as you wish***\n\n  \t  )1 commencing\n \t  )2 terminate\n \t ");
			continue;
		}
		}/*end of while true*/
		return 0;
	}




