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
/* Usar puts() para imprirmir strings constantes */

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
        /*Informação de nivel*/
          if (score <=10)
          {
            level = 1;
          }
          else if (10 < score && score <= 20)
          {
            level = 2;
          }
          else if (20 < score && score <= 30)
          {
            level = 3;
          }
          else if (30 < score && score <= 40)
          {
            level = 4;
          }
          else if (40 < score && score <= 50)
          {
            level = 5;
          }
          else
          {
            level = 6;
          }
          if (level == 6)
          {
            break;
          }
          puts(MSG_SORT);
          score = rand_number(min, max, score);
          plays++;
         break;
        case 's':
          print_status(level, score, plays);
          break;
        case 'm':
          print_menu();
          break;
        default:
          puts(MSG_UNKNOWN);
          break;
      }
      /*Game over*/
    if (plays == 29 || level == 6){
      puts(MSG_MAX);
      print_status(level, score, plays);
      puts(MSG_OVER);
      return 0;
    }
  }
}

/* generar 4 numeros aleatorios entre o maximo e o minimo */
int rand_number(int min, int max, int score)
{
  /* especificação de nivel */
  if (score <=10)
  {
    min = 0;
    max = 10;
  }
  else if (10 < score && score <= 20) 
  {
    min = 0;
    max = 30;
  }
  else if (20 < score && score <= 30)
  {
    min = 50;
    max = 30;
  }
  else if (30 < score && score <= 40)
  {
    min = 0;
    max = 100;
  }
  else if (40 < score && score <= 50)
  {
    min = 100;
    max = 200;
  }
  
  int contagem = 4;
  int i = 0;
  int num[4];
  int n1, n2, n3, n4;
  int score_sum = 0;
  int j;

  srand(time(0));
  /*Gera numemors para os niveis 1 e 2*/
  if ( 0 <= score && score <= 20)
  {
    for (i = 0; i < contagem; i++)
    {
      num[i] = (rand() % (max - min + 1)) + min;
      printf ("%d", num[i]);
      if (i != 3)
      {
        printf(", ");
      }
    } 
  }
  /*Gera numeros para o nivel 3*/
  else if ( 20 < score && score <= 30)
  {
    num[0] = -1 * ((rand() % (min - 0 + 1)));
    num[1] = (rand() % (max - 0 + 1));
    num[2] = -1 * ((rand() % (min - 0 + 1)));
    num[3] = (rand() % (max - 0 + 1));
    for (i = 0; i < contagem; i++)
    {
      printf ("%d", num[i]);
      if (i != 3)
      {
        printf(", ");
      }
    }
  }
  /*Gera numeros para os níveis 4 e 5*/
  else
  {
    for (i = 0; i < contagem; i++)
    {
      num[i] = -1 * ((rand() % (max - min + 1)) + min);
      printf ("%d", num[i]);
      if (i != 3)
      {
        printf(", ");
      }
    } 
  }
  printf("\n");
   /*Por os numeros gerados em ordem crescente*/
  for (i=0;i<4;i++){
    for (j=0;j<4;j++){
      if (num[j] > num[i]){
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
      }
    }
  }
  /*Verificação se o input foi certo ou errado*/
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


/* imprimir statuts do jogo */
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