#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
      char *x[20];
      int i,n=0;
      void reorder(int n,char *x[]);
      system("clear");
      printf("Ingrese nro de cadenas: ");
      scanf("%d",&n);
      printf("\n");
     
	for(i=0;i<n;i++)
	 {
		printf("Ingrese la cadena %d : ",i+1);
	   x[i]=(char *)malloc(20*sizeof(char));
	   scanf("%s",x[i]);
	 }
	reorder(n,&x);
	printf("\nLista ordenada:  \n");
	for(i=0;i<n;i++)
   {
	  printf("%d %s\n",i+1,x[i]);
   }
			  
}
void reorder2(int n,char *x[])
{
	int i,j;
	char t[20];
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
		if(strcmp(x[i],x[j])>0)
		  {
			strcpy(t,x[j]);
			strcpy(x[j],x[i]);
			strcpy(x[i],t);
		  }
	return;
}

void reorder(int n,char * x[])
{
	int i,j;
	char *t;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
		if(strcmp(x[i],x[j])>0)
		  {
			t=x[j];
			x[j] = x[i];
			x[i]=t;
		  }
	return;
}