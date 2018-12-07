#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int m;

void remplissage(int *tas, int *liste){
	int i;
	int j = 1; tas[0] = 0;
	int pere, k;
	for(i = 0; i<m; i++){
		tas[j] = liste[i];
		k = j;
		pere = j/2;
		while(pere > 0 && tas[pere] > tas[k]){
			permut(&tas[pere], &tas[k]);
			k = pere;
			pere = k/2;
		}
		j++;
	}
	/*for(i = 9; i<20; i++){
		tas[i] = 0;
	}*/
}
void afficher(int *array, int n){
	int i;
	for(i = 1; i < n; i++){
		printf("T[%d] = %d\n", i, array[i]);
	}

}
void permut(int *val1, int *val2){
	int x;
	x = *val1;
	*val1 = *val2;
	*val2 = x;
}
void tri_Par_Tas(int *tas, int *resultat, int n){
	int i = 1;
	int j;
	while(n > 0){
		resultat[i] = tas[1];
		supprimerMin(tas, n);
		tas[n-1] = 0;
		n--;
		printf("affichage apres suppression du min num %d\n", i);
		afficher(tas, n);
		i++;
	}
}
void supprimerMin(int *tas, int n){
	int i = 1;
	tas[i] = tas[n-1];
	int g = i*2, d = (i*2)+1;
	int suivant;
	while((tas[g] != 0 && tas[i] > tas[g]) || (tas[d] != 0 && tas[i] > tas[d])){
		int *min;
		if(tas[g] > tas[d]){
			 min = &tas[d];
			 suivant = d;
		}else{
			 min = &tas[g];
			 suivant = g;
		}
		printf("min = %d\n", *min);
		permut(&tas[i], min);
		i = suivant;
		g = i*2; d = (i*2)+1;
	}
}


int main(){
    int i;
    printf("Donnez la taille du tas");
    scanf("%d",&m);
	int liste[m-1];
	int tas[m];
	int tasFinale[m];

	//REMPLISSAGE DE LA LISTE
	for(i=0;i<m-1;i++){
        liste[i] = rand()%20; 
	}

	//INITIALISER LE TAS FINAL A 0
	for(i = 0; i<m; i++){
		tasFinale[i] = 0;
	}

	printf("remplissage du tas a partir de la liste\n");
	remplissage(tas, liste);
	//affichage du tas initial
	afficher(tas, m);
	printf("tri par tas en cours...\n");
	tri_Par_Tas(tas, tasFinale, m);
	printf("Affichage finale : \n");
	afficher(tasFinale, m);
}


