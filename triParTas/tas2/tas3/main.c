#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t t1,t2;
int n1 = 50000,n2 = 100000,n3 = 150000,n4 = 200000,n5 = 250000;

int printMenuAndGetUserChoice(){
	system("clear");
	printf("\t\tMenu\n\n");
	printf("\t1 - Tri Bulle\n");
	printf("\t2 - Tri Bulle Optimal\n");
	printf("\t3 - Tri Gnome\n");
	printf("\t4 - Tri Base\n");
	printf("\t5 - Tri Rapide\n");
	printf("\t6 - Tri Tas\n");
	printf("\t0 - Quitter\n");
	int choice;
	do{
		printf("[0-6] : ");
		scanf("%d",&choice);
	}while(choice <0 || choice >6);
}
int main() 
{ 

	int* tab1 = (int)malloc(n1 * sizeof(int));
	int* tab2 = (int)malloc(n2 * sizeof(int));
	int* tab3 = (int)malloc(n3 * sizeof(int));
	int* tab4 = (int)malloc(n4 * sizeof(int));
	int* tab5 = (int)malloc(n5 * sizeof(int));



	int k;
	while(1){
		int userChoice = printMenuAndGetUserChoice();
		switch(userChoice) {
			case 0 : exit(0); break;
			case 1 :
					printf("\n\n***************** TRI BULLE *****************\n");
					for(k=1;k<6;k++){
						printf("---- %i ----\n",k);
						
						switch(k){
						    case 1 : tab1 = remplir(tab1,n1);
							     t1 = clock();
							     TriBulle(tab1,n1);	
							     break;
						    case 2 : tab2 = remplir(tab2,n2);
							     t1 = clock();
							     TriBulle(tab2,n2);
							     break;
						    case 3 : tab3 = remplir(tab3,n3);
				                             t1 = clock();
							     TriBulle(tab3,n3);
							     break;
						    case 4 : tab4 = remplir(tab4,n4);
							     t1 = clock();
							     TriBulle(tab4,n4);
							     break;
						    case 5 : tab5 = remplir(tab5,n5);
							     t1 = clock();
							     TriBulle(tab5,n5);
							     break;
						   }

						t2 = clock();
						printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));
					}
					/************************* END TRI BULLE ***************/
				break;

			case 2 : 

				printf("\n\n***************** TRI BULLE OPT *****************\n");
				for(k=1;k<6;k++){
					printf("---- %i ----\n",k);
					
					switch(k){
					    case 1 : tab1 = remplir(tab1,n1);
						     t1 = clock();
						     TriBulleOpt(tab1,n1);	
						     break;
					    case 2 : tab2 = remplir(tab2,n2);
						     t1 = clock();
						     TriBulleOpt(tab2,n2);
						     break;
					    case 3 : tab3 = remplir(tab3,n3);
			                             t1 = clock();
						     TriBulleOpt(tab3,n3);
						     break;
					    case 4 : tab4 = remplir(tab4,n4);
						     t1 = clock();
						     TriBulleOpt(tab4,n4);
						     break;
					    case 5 : tab5 = remplir(tab5,n5);
						     t1 = clock();
						     TriBulleOpt(tab5,n5);
						     break;
					   }

					t2 = clock();
					printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));
				}

				/************************* END TRI BULLE OPT ***************/
					break;

			case 3 : 

					printf("\n\n***************** TRI GNOME *****************\n");
				for(k=1;k<6;k++){
					printf("---- %i ----\n",k);
					
					switch(k){
					    case 1 : tab1 = remplir(tab1,n1);
						     t1 = clock();
						     triGnome(tab1,n1);	
						     break;
					    case 2 : tab2 = remplir(tab2,n2);
						     t1 = clock();
						     triGnome(tab2,n2);
						     break;
					    case 3 : tab3 = remplir(tab3,n3);
			                             t1 = clock();
						     triGnome(tab3,n3);
						     break;
					    case 4 : tab4 = remplir(tab4,n4);
						     t1 = clock();
						     triGnome(tab4,n4);
						     break;
					    case 5 : tab5 = remplir(tab5,n5);
						     t1 = clock();
						     triGnome(tab5,n5);
						     break;
					   }

					t2 = clock();
					printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));
				
				}

				/************************* END TRI BULLE OPT ***************/

				break;

			case 4 : 
					printf("\n\n***************** TRI BASE *****************\n");
					for(k=1;k<6;k++){
						printf("---- %i ----\n",k);
						
						switch(k){
						    case 1 : tab1 = remplir(tab1,n1);
							     t1 = clock();
							     triBase(tab1,n1);	
							     break;
						    case 2 : tab2 = remplir(tab2,n2);
							     t1 = clock();
							     triBase(tab2,n2);
							     break;
						    case 3 : tab3 = remplir(tab3,n3);
				                             t1 = clock();
							     triBase(tab3,n3);
							     break;
						    case 4 : tab4 = remplir(tab4,n4);
							     t1 = clock();
							     triBase(tab4,n4);
							     break;
						    case 5 : tab5 = remplir(tab5,n5);
							     t1 = clock();
							     triBase(tab5,n5);
							     break;
						   }

						t2 = clock();
						printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));

			
		
		}
		/************************* END TRI BAS ***************/
			break;

			case 5 : 
				printf("\n\n***************** TRI RAPIDE *****************\n");
				for(k=1;k<6;k++){
					printf("---- %i ----\n",k);
					
					switch(k){
					    case 1 : tab1 = remplir(tab1,n1);
						     t1 = clock();
						     triRapide(tab1,0,n1);	
						     break;
					    case 2 : tab2 = remplir(tab2,n2);
						     t1 = clock();
						     triRapide(tab2,0,n2);
						     break;
					    case 3 : tab3 = remplir(tab3,n3);
			                             t1 = clock();
						     triRapide(tab3,0,n3);
						     break;
					    case 4 : tab4 = remplir(tab4,n4);
						     t1 = clock();
						     triRapide(tab4,0,n4);
						     break;
					    case 5 : tab5 = remplir(tab5,n5);
						     t1 = clock();
						     triRapide(tab5,0,n5);
						     break;
					   }

					t2 = clock();
					printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));

			
		
		}
		/************************* END TRI RAPIDE ***************/

			break;

			case 6 : 

			printf("\n\n***************** TRI PAR TAS *****************\n");
				for(k=1;k<6;k++){
					printf("---- %i ----\n",k);
					
					switch(k){
					    case 1 : tab1 = remplir(tab1,n1);
						     t1 = clock();
						     triTas(tab1,n1);	
						     break;
					    case 2 : tab2 = remplir(tab2,n2);
						     t1 = clock();
						     triTas(tab2,n2);
						     break;
					    case 3 : tab3 = remplir(tab3,n3);
			                             t1 = clock();
						     triTas(tab3,n3);
						     break;
					    case 4 : tab4 = remplir(tab4,n4);
						     t1 = clock();
						     triTas(tab4,n4);
						     break;
					    case 5 : tab5 = remplir(tab5,n5);
						     t1 = clock();
						     triTas(tab5,n5);
						     break;
					   }

					t2 = clock();
					printf("tab[%d] = %f,\n",getSizeByIndicator(k),((double)(t2-t1)/CLOCKS_PER_SEC ));

					
				
				}
		/************************* END TRI PAR TAS ***************/

		break;
		}// end main switch
		printf("Press ENTER key to Continue\n");  
		getchar();
		int c = getchar();
	}

	printf("\n");
	return 0; 
} 

