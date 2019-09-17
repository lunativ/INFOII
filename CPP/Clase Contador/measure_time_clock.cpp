#include <time.h>
#include <stdio.h>
#include <math.h>

int main () {
   clock_t start_t, end_t, total_t;
   int i;
   float a=0.5;

   start_t = clock();
   printf("Starting of the program, start_t = %ld\n", start_t);

     printf("Going to scan a big loop, start_t = %ld\n", start_t);

   for(i=0; i< 400000000; i++) {
	   a = sinf(a);
   }
   end_t = clock();

   printf("End of the big loop, end_t = %ld\n", end_t);

   total_t = (double)(end_t - start_t);// / CLOCKS_PER_SEC;
   printf("Total time taken by CPU: %f\n", (float) total_t / CLOCKS_PER_SEC );
   printf("Exiting of the program...\n");

   return(0);
}
