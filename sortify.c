#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MSG_WELCOME "WELCOME TO SORTIFY!"
#define MSG_SORT "Sort the following numbers:"
#define MSG_SORT2 "Please sort the numbers"
#define MSG_WELL "Well done!"
#define MSG_WIN "Congratulations, you win!"
#define MSG_OVER "Game Over."
#define MSG_WRONG "Wrong answer."
#define MSG_MAX "You have reached the maximum number of moves."
#define MSG_BYE "Bye."
#define MSG_UNKNOWN "Unknown option."
/* Use puts() to print constant strings */

int rand_number(int, int, int);
void print_status(int, int, int);
void print_menu(void);


int main()
{
  char choose;
  int level = 1;
  int plays = 0;
  int score = 0;
  int max = 0;
  int min = 0;
  int loop = 0;
  int i;

	puts(MSG_WELCOME);
  print_menu();
  
  for (i = 1; i > 0;i++){
    scanf(" %c", &choose);
      switch (choose)
      {
        case 'q':
          print_status(level, score, plays);
          puts(MSG_BYE);
          return 0;
          break;
        case 'p':
          puts(MSG_SORT);
          score = rand_number(min, max, score);
          plays++;
          /*Level info*/
          if (score <=10)
          {
            level = 1;
          }
          else if (10 < score <= 20)
          {
            level = 2;
          }
          else if (20 < score <= 30)
          {
            level = 3;
          }
          else if (30 < score <= 40)
          {
            level = 4;
          }
            else if (40 < score)
          {
            level = 5;
          }
         break;
        case 's':
          print_status(level, score, plays);
          break;
        default:
          puts(MSG_UNKNOWN);
          break;
      }
      /*Game over*/
    if (plays == 10){
      puts(MSG_MAX);
      print_status(level, score, plays);
      puts(MSG_OVER);
      return 0;
    }
  }
}

/* generate four random integers between min and max */
int rand_number(int min, int max, int score)
{
  /* Level specifications */
  if (score <=10)
  {
    min = 0;
    max = 10;
  }
  else if (10 < score <= 20)
  {
    min = 0;
    max = 30;
  }
  else if (20 < score <= 30)
  {
    min = -50;
    max = 30;
  }
  else if (30 < score <= 40)
  {
    min = -100;
    max = 0;
  }
    else if (40 < score)
  {
    min = -200;
    max = -100;
  }
  
  int contagem = 4;
  int i = 0;
  int num[4];
  int n1, n2, n3, n4;
  int n[4];
  int ordenado;
  int score_sum = 0;
  int j;

  srand(time(0));

  for (i = 0; i < contagem; i++)
  {
    num[i] = (rand() % (max - min + 1)) + min;
    printf ("%d, ", num[i]);
  } 
  printf("\n");
  /*while(ordenado == 0) 
  {
    ordenado = 1;
    for (i=0;i<4;i++)
    {
      if (num[i] > num[i+1])
      {
        int aux;
        aux = num[i];
        num[i]= num[i + 1];
        num[i +1] = aux;
        ordenado = 0;
      }
    }
  }*/
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (num[j] > num[i]){
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
      }
    }
  }
  scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
  if (n1 == num[0] && n2 == num[1] && n3 == num[2] && n4 == num[3])
  {
    puts(MSG_WELL);
    score_sum = score + 5;
    return score_sum;
  }
  else
  {
    puts(MSG_WRONG);
    score_sum = score;
    return score_sum;
  }
    
  return 0;
}


/* print the game status */
void print_status(int level, int score, int plays)
{
	puts("+-----------------------------+");
	printf("| level:  %02d                  |\n", level);
	printf("| points: %02d                  |\n", score);
	printf("| plays:  %02d                  |\n", plays);
	puts("+-----------------------------+");
}

/* print the option menu */
void print_menu(void)
{
	puts("+-----------------------------+");
	puts("| SORTIFY                     |");
	puts("| p - next chalenge           |");
	puts("| q - quit                    |");
	puts("| m - print this information  |");
	puts("| s - show your status        |");
	puts("+-----------------------------+");
}