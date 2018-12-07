#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// tri rapide
// procedure permuter
void permuter(int *x,int *y)
{
	int z;
	z=*x;
	*x=*y;
	*y=z;
}
// fonction partitionner
int partitionner(int *t,int d, int f)
{
	int i,j,x;
	int pivot = t[d];
	i=d;
	j=f;
	while(i<=j)
	{
		while( (t[i] <= pivot) && (i<=j) ) i++;
		while( (t[j] > pivot) && (i<=j) ) j--;
		if(i<=j) permuter(&t[i],&t[j]);
	}
	permuter(&t[d],&t[j]);
	return j;
}
//procedure triRapide
void triRapide(int *t, int p, int r)
{
	int q;
	if(p < r)
	{
		q = partitionner(t,p,r);
		triRapide(t,p,q);
		triRapide(t,q+1,r);
	}
}
// si le tab est trie a l'envers alors j = 0 donc 1er appel 0 itera et 2eme appel ydir n-1 ite
// => pire cas t(n-1) + n => n^2
// meilleur cas si max au milieu donc 1er appel n/2 ite et 2eme n/2 
// => 2 t(n/2) + n => n log n 
int main(int argc, char *argv[]) {
	int i,j,n;
	clock_t t1,t2;
	float diff;
	srand(time(NULL));
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
	printf("TRI RAPIDE \n");
	
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
		triRapide(t,0,4);
		printf("\n apres tri \n");
		for(j=0;j<5;j++)
		{
			printf("%d \t",t[j]);
		}
		printf("\n \n");
	
	printf("\t pire cas : tableau trié \n");
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
		triRapide(t,0,n-1);
		t2= clock();
		diff = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri rapide pour n = %d => temps = %f \n",n,diff);

	}
	printf("\t meilleur cas : tableau non trié (methode rand) \n");
	
	val[0] = 50;
	val[1] = 70;
	val[2] = 100;
	val[3] = 150;
	val[4] = 200;
	val[5] = 250;
	
	for (i=0;i<6;i++)
	{
		n = val[i];
		int *t = (int *)malloc(n*sizeof(int));
		//remplissage du tableau
		for(j=0;j<n;j++)
		{
			t[j] = rand();
		}

	/*	for(j=0;j<n;j++)
		{
			printf("%d \t",t[j]);
		}
		*/
		t1 = clock();
		triRapide(t,0,n-1);
		t2= clock();
		diff = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri rapide pour n = %d => temps = %f \n",n,diff);
		/*printf("\n apres tri \n");
		for(j=0;j<n;j++)
		{
			printf("%d \t",t[j]);
		}
		printf("\n autre val d n \n");*/

	}


		
}
