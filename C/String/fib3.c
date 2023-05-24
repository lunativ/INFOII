#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fibonacciTerm(int n)
{
   int a=0, b=1, c;
   for(int i=1; i<n; i++)
   {
     c = a+b;
     a = b;
     b = c;
   }
   return a;
}

int main(int argc, char *argv[])
{
   int term, result,i;
  // system("clear");
  
  if (argc < 2)
  {
   printf("Ingrese el termino requerido de la serie de Fibonacci: ");
   scanf("%d", &term);
  }
  else{
	  term = atoi(argv[1]);
  }
	clock_t begin = clock();
	for(i = 0; i<10000;i++)
	   result = fibonacciTerm(term);
	clock_t end = clock();
	double time_spent = (double)(end - begin); //in microseconds
   printf("El termino requerido es: %d\n", result);
   printf("El tiempo de computo fue: %f\n", time_spent);

   return 0;
}