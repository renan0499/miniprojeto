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

int rand_number(int, int);
void print_status(int, int, int);
void print_menu(void);


int main()
{
  char choose;
  int level = 1;
  int score = 0;
  int plays = 0;
  int max = 0;
  int min = 0;

	puts(MSG_WELCOME);
  print_menu();
  scanf("%c", &choose);
  
  switch (choose)
  {
    case 'q':
      print_status(level, score, plays);
      puts(MSG_BYE);
      break;
    case 'p':
      puts(MSG_SORT);
      rand_number(min, max);
      break;
    case 's':
      print_status(level, score, plays);
      break;
    default:
      puts(MSG_UNKNOWN);
      break;
  }
}
/* generate four random integers between min and max */
int rand_number(int min, int max)
{
  min = 0;
  max = 10;
  int contagem = 4;
  int i = 0;
  int num[4];
  int n1, n2, n3, n4;
  int n[4];
  int ordenado;

  srand(time(0));

  for (; i < contagem; i++)
  {
    num[i] = (rand() % (max - min + 1)) + min;
    printf ("%d ", num[i]);
  } 
  while(ordenado == 0) 
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
  }
  scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
  if (n[4] == n[i+1])
  {
    puts(MSG_WELL);
  }
  else
  {
    puts(MSG_WRONG);
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