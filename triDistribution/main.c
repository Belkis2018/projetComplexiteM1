#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// tri par distribution
int cle(int x,int y)
{
	return ( (x%(int)pow(10,y+1)) / pow(10,y));	
}
// procedure permuter
void permuter(int *x,int *y)
{
	int z;
	z=*x;
	*x=*y;
	*y=z;
}
//procedure triAux
void triAux(int *t,int n, int i)
{
	int j = 0;
	while(j<n-1)
	{
		if(cle(t[j],i) <= cle(t[j+1],i) )j++;
		else
		{
			permuter(&t[j],&t[j+1]);
			j--;
			if(j < 0 ) j++;
		}
	}
}
/* meilleur cas n
pire cas n^2*/
//procedure triBase
void triBase(int *t, int n, int k)
{
	int i=0;
	for(i=0;i<=k;i++)
	{
		triAux(t,n,i);
	}
}
/* meilleur cas k*n
pire cas k*n^2*/
int main(int argc, char *argv[]) {
	
	int i,j,n;
	clock_t t1,t2;
	float diff;
	// declaration du tableau de valeurs d n 
	int val[6];
	val[0] = 500;
	val[1] = 700;
	val[2] = 1000;
	val[3] = 2000;
	val[4] = 3000;
	val[5] = 4000;
	// cette boucle pour parcourir le tableau d n
	// le tri à bulle
	printf("TRI BASE \n");
	
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
		triBase(a,5,4);
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
		triBase(t,n,4);
		t2= clock();
		diff = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri base pour n = %d => temps = %f \n",n,diff);

	}
	printf("\t pire cas : tableau non trié (methode rand) \n");
	for (i=0;i<6;i++)
	{
		n = val[i];
		int *t = (int *)malloc(n*sizeof(int));
		//remplissage du tableau
		for(j=0;j<n;j++)
		{
			t[j] = rand() % n;
		}

		t1 = clock();
		triBase(t,n,4);
		t2= clock();
		diff = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri base pour n = %d => temps = %f \n",n,diff);

	}
}
