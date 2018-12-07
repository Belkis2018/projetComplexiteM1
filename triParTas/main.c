#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// tri par tas
void permuter(int a, int b, int *tas)
{
    int temp;
    temp = tas[a];
    tas[a] = tas[b];
    tas[b] = temp;
}

void afficher_tas(int n,int *tas)
{
    int i;
    for(i=0;i<n;i++){
        printf("tas[%d] = %d \n",i,tas[i]);
    }
}

void tamiser_tas(int *tas,int n)
{
    int i,k,j,temp;
    for(i=0;i<n/2;i++){
            k=2*i;
        if(tas[2*i+1] > tas[i]){ // fils gauche
            j= k+1;
            while( j>0 && ( tas[j] > tas[(j-1)/2] ) ){

                permuter(j,(j-1)/2,tas);
                j= (j-1)/2;
            }
        }
        if((tas[2*i+2] > tas[i]) && 2*i+2 < n){ // fils droit && cas taille pair
            j = k+2;
            while( j>0 && ( tas[j] > tas[(j-1)/2] ) ){
                permuter(j,(j-1)/2,tas);
                j= (j-1)/2;
            }
        }
    }
}

void tri_par_tas(int *tas,int len)
{
    int k=0,j;
    while(len > 1){
        permuter(len-1,0,tas);
        len--;
        j=0;
        while(2*j+1<len){
            k = 2*j;
            if(k+2 < len){
                if(tas[k+1] > tas[k+2]  &&  tas[j] < tas[k+1]){
                    permuter(k+1,j,tas);
                    j=k+1;
                }else
                 {
                     if(tas[j] < tas[k+2]){ // fils < pere
                        permuter(k+2,j,tas);
                        j=k+2;
                     }else break;
                 }
            }else
            {
                if(k+1 < len){
                    if(tas[j] < tas[k+1]){
                        permuter(k+1,j,tas);
                    }
                    else break;
                }else break;
            }
        }
    }
}


int main()
{
    int i,n,j;
    clock_t t1,t2;
    double diff;
    int val[6];
    int *tas;
	val[0] = 500000;
	val[1] = 700000;
	val[2] = 1000000;
	val[3] = 1500000;
	val[4] = 10000000;
	val[5] = 15000000;
	printf("TRI PAR TAS \n");

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
		tamiser_tas(a,5);
		tri_par_tas(a,5);
		printf("\n apres tri \n");
		for(j=0;j<5;j++)
		{
			printf("%d \t",a[j]);
		}
		printf("\n \n");

	printf("\t pire cas : tableau trié \n");
	for (i=0;i<6;i++)
	{
		n = val[i];
		tas = (int *)malloc(n*sizeof(int));
		//remplissage du tableau
		srand(time(NULL));
		for(j=0;j<n;j++)
		{
			tas[j] = j;
		}

		t1 = clock();
		tamiser_tas(tas,n);
		tri_par_tas(tas,n);
		t2= clock();
		diff = (double)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri par tas pour n = %d => temps = %f \n",n,diff);

	}


	printf("\t meilleur cas : tableau trié a l'envers' \n");
	for (i=0;i<6;i++)
	{
		n = val[i];
		tas = (int *)malloc(n*sizeof(int));
		//remplissage du tableau
		for(j=0;j<n;j++)
		{
			tas[j] = n-j;
		}
		t1 = clock();
		tamiser_tas(tas,n);
		tri_par_tas(tas,n);
		t2= clock();
		diff = (double)(t2-t1)/CLOCKS_PER_SEC;
		printf("\t \t \t tri par tas pour n = %d => temps = %f \n",n,diff);

	}






   /* printf("Donnez la taille du tas \n");
    scanf("%d",&n);*/
    /*int *tas= (int *) malloc(n*sizeof(int));;
    srand(time(NULL));
    for(i=0;i<n;i++){
        tas[i] = (rand()%100);
    }
    printf("Affichage du tableau brut\n");
    afficher_tas(n,tas);
    tamiser_tas(tas,n);
    printf("Affichage du tableau apres tamisage\n");
    afficher_tas(n,tas);
    printf("affichage apres TRI\n");
    tri_par_tas(tas,n);
    afficher_tas(n,tas);*/

    return 0;
}
