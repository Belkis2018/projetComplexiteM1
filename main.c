#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// tri a bulle
// procedure permuter
void permuter(int *x,int *y)
{
	int z;
	z=*x;
	*x=*y;
	*y=z;
}
//procedure tri à bulle
void triBulle(int *t,int n)
{
	int chang = 0;
	int i;
	while(chang == 0)
	{
		chang = 1;
		for(i=0;i<n-1;i++)
		{
			if(t[i] > t[i+1])
			{
				permuter(&t[i],&t[i+1]);
				chang = 0;
			}
		}
	}
}
/* meilleur cas n
pire cas n^2*/
//prodecude tri à bulle optimal
void triBulleOPT(int *t,int n)
{
	int chang = 0;
	int i,m=n-1;
	while(chang == 0)
	{
		chang = 1;
		for(i=0;i<m;i++)
		{
			if(t[i] > t[i+1])
			{
				permuter(&t[i],&t[i+1]);
				chang = 0;
			}
		}
		m = m-1;
	}
}


int main(int argc, char *argv[]) {
	
	int i,j,n;
	clock_t t1,t2;
	float diff;
	// declaration du tableau de valeurs d n 
	int val[6];
	val[0] = 5000;
	val[1] = 7000;
	val[2] = 10000;
	val[3] = 15000;
	val[4] = 20000;
	val[5] = 25000;
	// cette boucle pour parcourir le tableau d n
	// le tri à bulle
	printf("TRI A BULLE \n");
	
	printf("\n EXEMPLE D'UN TRIE \n");
	int *t = (int *)malloc(5*sizeof(int));
		//remplissage du tableau
		for(j=0;j<5;j++)
		{
			t[j] = rand() % 100;
		}
		for(j=0;j<5;j++)
		{
			printf("%d \t",t[j]);
		}
		triBulle(t,5);
		printf("\n apres tri \n");
		for(j=0;j<5;j++)
		{
			printf("%d \t",t[j]);
		}
		printf("\n \n");
	
	printf("\t meilleur cas : tableau trié \n");
	for (i=0;i<6;i++)
	{
		n = val[i];
		int *t = (int *)malloc(n*sizeof(int));
		//remplissage du tableau
		for(j=0;j<n;j++)
		{
			t[j] = j;
		}

		t1 = clock();
		triBulle(t,n);
		t2= clock();
		diff = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri a bulle pour n = %d => temps = %f \n",n,diff);

	}
	printf("\t pire cas : tableau non trié (methode rand) \n");
	for (i=0;i<6;i++)
	{
		n = val[i];
		int *t = (int *)malloc(n*sizeof(int));
		//remplissage du tableau
		for(j=0;j<n;j++)
		{
			t[j] = rand();
		}

		t1 = clock();
		triBulle(t,n);
		t2= clock();
		diff = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri a bulle pour n = %d => temps = %f \n",n,diff);

	}
	// le tri à bulle optimal
		printf("******************************************************************************\n");
	printf("TRI A BULLE OPTIMAL\n");
	
	printf("\n EXEMPLE D'UN TRIE \n");
	int *a = (int *)malloc(5*sizeof(int));
		//remplissage du tableau
		for(j=0;j<5;j++)
		{
			a[j] = rand() % 100;
		}
		for(j=0;j<5;j++)
		{
			printf("%d \t",a[j]);
		}
		triBulleOPT(a,5);
		printf("\n apres tri \n");
		for(j=0;j<5;j++)
		{
			printf("%d \t",a[j]);
		}
		printf("\n \n");
	
	printf("\t meilleur cas : tableau trié \n");
	for (i=0;i<6;i++)
	{
		n = val[i];
		int *t = (int *)malloc(n*sizeof(int));
		//remplissage du tableau
		for(j=0;j<n;j++)
		{
			t[j] = j;
		}
		t1 = clock();
		triBulleOPT(t,n);
		t2= clock();
		diff = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri a bulle OPT pour n = %d => temps = %f \n",n,diff);
	
	}
	printf("\t pire cas : tableau non trié \n");
	for (i=0;i<6;i++)
	{
		n = val[i];
		int *t = (int *)malloc(n*sizeof(int));
		//remplissage du tableau
		for(j=0;j<n;j++)
		{
			t[j] = rand();
		}
		t1 = clock();
		triBulleOPT(t,n);
		t2= clock();
		diff = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri a bulle OPT pour n = %d => temps = %f \n",n,diff);
	
	}
	
}
