#include <stdio.h>
#include "../include/avalam.h"
#include <stdlib.h>
#include "topologie.h"
#include <string.h>

octet bonusJ,bonusR;//Bonus & Malus (jaune)
    octet malusJ,malusR;//Bonus & Malus (rouge)
    octet origin,dest;//Origine & Destination
    T_Position p; //Position des pions
	T_ListeCoups l; 
	int menu(), rep, monchoix;
	int i;
	T_Score a;

	int test, num;
	char nom [50];

//Prototype de fonctions utilisées ci-dessous
void Jouer(int argc, char nom [50]);
void Aff(); //Affichage du plateau independant
void CreaJS(int argc, char nom [50]); //MAJ du fichier js (oups.js)

int main(int argc,char **argv) {

if (argc == 1)
	printf("\n        Utilisation de Coups.js (par défaut");
else if (argc==2){
	printf("\n        Utilisation de %s", argv[1]);
	num = argc;
	strcpy(nom, argv[1]);


}


	printf0("Création de la position initiale ...\n"); 
	p = getPositionInitiale();
	
	printf0("Récupération des coups légaux de la position initiale ...\n"); 
 	l = getCoupsLegaux(p);

	printf("\n\n   Ceci est un programme d'exemple pour le livrable 1\n");
	printf("   Depuis la position initiale du jeu, il y a %d coups possibles\n", l.nb);

	printf("   Depuis la position initiale du jeu, le trait est aux %ss\n", COLNAME(p.trait));

			//////////////////////ModifJSON//////////////////////////////////
				
								CreaJS(argc, nom);

			/////////////////////////////////////////////////////////////////

printf("\n\n\n	***Bienvenu dans le merveilleux jeu d'Avalam Evolution*** (LINUX (x86) uniquement)    \n");

 //Affichage du menu 
 

 //Traitement de la reponse de la l'utilisateur
do {
	rep=menu();
	switch (rep) {
    case 1 : 
			Jouer(argc, argv[1]);
             break;
    case 2 :
			printf("Voici le plateau actuel :\n\n");
			Aff();
             break;
    case 3 : 
		system(" gnome-terminal -- bash -c \"./ScriptAff.sh\" ");//METTRE L'URL QUE VOUS AVEZ QUAND VOUS LANCEZ LE FICHIER
		 printf ("\033[34;01m\n\n      *************Cliquez sur le terminal puis selectionnez 1************\033[00m\n");
			 break;
    case 4 :  /// SECTION REGLE
			
             break;
    case 5 : printf("\n FIN !!!\n\n");
			monchoix=5;
             break;

    default : printf("\n Cas imprevu !!!\n\n");
}

}while (monchoix!=5); //On arrete quand l'utilisateur choisi l'option 5

return 1;

}


int menu(){
int choix;  //Permet de saisir la reponse de l'utilisateur

printf("\n\n   Veuillez choisir une des options suivantes s'il vous plaît...:(\n");

 printf("\n	   1-  Jouer (duo)");
 printf("\n	   2-  Affichage du plateau");
 printf("\n	   3-  Afficher la partie graphique du plateau ");
 printf("\n	   4-  Règles du jeu (officiel)\n");
 printf("\n	   5-  Quitter\n");
 printf("\n	    Votre choix : "); 
 scanf("%d",&choix);
 getchar();
return choix;

}

void Aff(){
	afficherPosition(p);
	return;
}

void Jouer (int argc, char nom [50]) {
	//Pt bonus/malus ////////////// DEBUT (ne pas toucher !!!)

system("clear");
			
			do{
				printf("\033[33;01m\n\n Joueur : 1 (jaune) **BONUS** \n\n Veuillez placer votre bonus à la place d'un pion jaune disponible : \033[00m");
				scanf("%hhd", &p.evolution.bonusJ);

				if(p.evolution.bonusJ<0 || p.evolution.bonusJ>47 || p.evolution.bonusJ == 0 || p.evolution.bonusJ == 4 || p.evolution.bonusJ == 9 || p.evolution.bonusJ == 16 || p.evolution.bonusJ == 25 || p.evolution.bonusJ == 35 || p.evolution.bonusJ == 2 || p.evolution.bonusJ == 7 || p.evolution.bonusJ == 14 || p.evolution.bonusJ == 33 || p.evolution.bonusJ == 40 || p.evolution.bonusJ == 45 || p.evolution.bonusJ == 12 || p.evolution.bonusJ == 22 || p.evolution.bonusJ == 31 || p.evolution.bonusJ == 38 || p.evolution.bonusJ == 43 || p.evolution.bonusJ == 47 || p.evolution.bonusJ == 20 || p.evolution.bonusJ == 29 || p.evolution.bonusJ == 36 || p.evolution.bonusJ == 11 || p.evolution.bonusJ == 18 || p.evolution.bonusJ == 27 )
					
					printf("\033[34;01m\n\nSaisie incorrect monsieur JAUNE, veuillez placer votre bonus à la place d'un pion jaune disponible...\033[00m\n\n");
				}while (p.evolution.bonusJ<0 || p.evolution.bonusJ>47 || p.evolution.bonusJ == 0 || p.evolution.bonusJ == 4 || p.evolution.bonusJ == 9 || p.evolution.bonusJ == 16 || p.evolution.bonusJ == 25 || p.evolution.bonusJ == 35 || p.evolution.bonusJ == 2 || p.evolution.bonusJ == 7 || p.evolution.bonusJ == 14 || p.evolution.bonusJ == 33 || p.evolution.bonusJ == 40 || p.evolution.bonusJ == 45 || p.evolution.bonusJ == 12 || p.evolution.bonusJ == 22 || p.evolution.bonusJ == 31 || p.evolution.bonusJ == 38 || p.evolution.bonusJ == 43 || p.evolution.bonusJ == 47 || p.evolution.bonusJ == 20 || p.evolution.bonusJ == 29 || p.evolution.bonusJ == 36 || p.evolution.bonusJ == 11 || p.evolution.bonusJ == 18 || p.evolution.bonusJ == 27 );

system("clear");

			do{
				printf("\033[31;01m\n\n Joueur : 2 (rouge) **BONUS** \n\n Veuillez placer votre bonus à la place d'un pion rouge disponible et différent des pions précédemment utilisés pour les autres bonus/malus : \033[00m");
				scanf("%hhd", &p.evolution.bonusR);

				if(p.evolution.bonusR<0 || p.evolution.bonusR>47 || p.evolution.bonusR == p.evolution.bonusJ || p.evolution.bonusR == 19 || p.evolution.bonusR == 1 || p.evolution.bonusR == 5 || p.evolution.bonusR == 10 || p.evolution.bonusR == 17 || p.evolution.bonusR == 26 || p.evolution.bonusR == 3 || p.evolution.bonusR == 8 || p.evolution.bonusR == 15 || p.evolution.bonusR == 24 || p.evolution.bonusR == 34 || p.evolution.bonusR == 41 || p.evolution.bonusR == 6 || p.evolution.bonusR == 13 || p.evolution.bonusR == 23 || p.evolution.bonusR == 32 || p.evolution.bonusR == 39 || p.evolution.bonusR == 44 || p.evolution.bonusR == 21 || p.evolution.bonusR == 30 || p.evolution.bonusR == 37 || p.evolution.bonusR == 42 || p.evolution.bonusR == 46 || p.evolution.bonusR == 28 )
					
					printf("\033[34;01m\n\nSaisie incorrect monsieur ROUGE, veuillez placer votre bonus à la place d'un pion rouge disponible, \ndifférent des pions précédemment utilisés pour les autres bonus/malus...\033[00m\n\n");
			
			}while (p.evolution.bonusR<0 || p.evolution.bonusR>47 || p.evolution.bonusR == p.evolution.bonusJ || p.evolution.bonusR == 19 || p.evolution.bonusR == 1 || p.evolution.bonusR == 5 || p.evolution.bonusR == 10 || p.evolution.bonusR == 17 || p.evolution.bonusR == 26 || p.evolution.bonusR == 3 || p.evolution.bonusR == 8 || p.evolution.bonusR == 15 || p.evolution.bonusR == 24 || p.evolution.bonusR == 34 || p.evolution.bonusR == 41 || p.evolution.bonusR == 6 || p.evolution.bonusR == 13 || p.evolution.bonusR == 23 || p.evolution.bonusR == 32 || p.evolution.bonusR == 39 || p.evolution.bonusR == 44 || p.evolution.bonusR == 21 || p.evolution.bonusR == 30 || p.evolution.bonusR == 37 || p.evolution.bonusR == 42 || p.evolution.bonusR == 46 || p.evolution.bonusR == 28 );			
			
system("clear");
			
			do{
				printf("\033[31;01m\n\n Joueur : 2 (rouge) **MALUS** \n\n Veuillez placer votre malus à la place d'un pion rouge disponible et différent des pions précédemment utilisés pour les autres bonus/malus : \033[00m");
				scanf("%hhd", &p.evolution.malusR);

				if (p.evolution.malusR<0 || p.evolution.malusR>47 || p.evolution.malusR == p.evolution.bonusJ || p.evolution.malusR == p.evolution.bonusR || p.evolution.malusR == 19 || p.evolution.malusR == 1 || p.evolution.malusR == 5 || p.evolution.malusR == 10 || p.evolution.malusR == 17 || p.evolution.malusR == 26 || p.evolution.malusR == 3 || p.evolution.malusR == 8 || p.evolution.malusR == 15 || p.evolution.malusR == 24 || p.evolution.malusR == 34 || p.evolution.malusR == 41 || p.evolution.malusR == 6 || p.evolution.malusR == 13 || p.evolution.malusR == 23 || p.evolution.malusR == 32 || p.evolution.malusR == 39 || p.evolution.malusR == 44 || p.evolution.malusR == 21 || p.evolution.malusR == 30 || p.evolution.malusR == 37 || p.evolution.malusR == 42 || p.evolution.malusR == 46 || p.evolution.malusR == 28 )
					
					printf("\033[34;01m\n\nSaisie incorrect monsieur ROUGE, veuillez placer votre malus à la place d'un pion rouge disponible, \ndifférent des pions précédemment utilisés pour les autres bonus/malus...\033[00m\n\n");
			
			}while (p.evolution.malusR<0 || p.evolution.malusR>47 || p.evolution.malusR == p.evolution.bonusJ || p.evolution.malusR == p.evolution.bonusR || p.evolution.malusR == 19 || p.evolution.malusR == 1 || p.evolution.malusR == 5 || p.evolution.malusR == 10 || p.evolution.malusR == 17 || p.evolution.malusR == 26 || p.evolution.malusR == 3 || p.evolution.malusR == 8 || p.evolution.malusR == 15 || p.evolution.malusR == 24 || p.evolution.malusR == 34 || p.evolution.malusR == 41 || p.evolution.malusR == 6 || p.evolution.malusR == 13 || p.evolution.malusR == 23 || p.evolution.malusR == 32 || p.evolution.malusR == 39 || p.evolution.malusR == 44 || p.evolution.malusR == 21 || p.evolution.malusR == 30 || p.evolution.malusR == 37 || p.evolution.malusR == 42 || p.evolution.malusR == 46 || p.evolution.malusR == 28 );
			
system("clear");
			
			do{
				printf("\033[33;01m\n\n Joueur : 1 (jaune) **MALUS** \n\n Veuillez placer votre malus à la place d'un pion jaune disponible et différent des pions précédemment utilisés pour les autres bonus/malus : \033[00m");
				scanf("%hhd", &p.evolution.malusJ);

				if (p.evolution.malusJ<0 || p.evolution.malusJ>47 || p.evolution.malusJ == p.evolution.bonusJ || p.evolution.malusJ == p.evolution.bonusR || p.evolution.malusJ == p.evolution.malusR || p.evolution.malusJ == 0 || p.evolution.malusJ == 4 || p.evolution.malusJ == 9 || p.evolution.malusJ == 16 || p.evolution.malusJ == 25 || p.evolution.malusJ == 35 || p.evolution.malusJ == 2 || p.evolution.malusJ == 7 || p.evolution.malusJ == 14 || p.evolution.malusJ == 33 || p.evolution.malusJ == 40 || p.evolution.malusJ == 45 || p.evolution.malusJ == 12 || p.evolution.malusJ == 22 || p.evolution.malusJ == 31 || p.evolution.malusJ == 38 || p.evolution.malusJ == 43 || p.evolution.malusJ == 47 || p.evolution.malusJ == 20 || p.evolution.malusJ == 29 || p.evolution.malusJ == 36 || p.evolution.malusJ == 11 || p.evolution.malusJ == 18 || p.evolution.malusJ == 27 )
					
					printf("\033[34;01m\n\nSaisie incorrect monsieur JAUNE, veuillez placer votre malus à la place d'un pion jaune disponible, \ndifférent des pions précédemment utilisés pour les autres bonus/malus...\033[00m\n\n");
			
			}while (p.evolution.malusJ<0 || p.evolution.malusJ>47 || p.evolution.malusJ == p.evolution.bonusJ || p.evolution.malusJ == p.evolution.bonusR || p.evolution.malusJ == p.evolution.malusR || p.evolution.malusJ == 0 || p.evolution.malusJ == 4 || p.evolution.malusJ == 9 || p.evolution.malusJ == 16 || p.evolution.malusJ == 25 || p.evolution.malusJ == 35 || p.evolution.malusJ == 2 || p.evolution.malusJ == 7 || p.evolution.malusJ == 14 || p.evolution.malusJ == 33 || p.evolution.malusJ == 40 || p.evolution.malusJ == 45 || p.evolution.malusJ == 12 || p.evolution.malusJ == 22 || p.evolution.malusJ == 31 || p.evolution.malusJ == 38 || p.evolution.malusJ == 43 || p.evolution.malusJ == 47 || p.evolution.malusJ == 20 || p.evolution.malusJ == 29 || p.evolution.malusJ == 36 || p.evolution.malusJ == 11 || p.evolution.malusJ == 18 || p.evolution.malusJ == 27 );	
			//////////////////////ModifJSON//////////////////////////////////
				
								CreaJS(argc, nom);

			/////////////////////////////////////////////////////////////////

	printf("\n1)\n");
	afficherPosition(p);//Positions avant changements

		do {
system("clear");
			do{
			
				l=getCoupsLegaux(p);
				l = getCoupsLegaux(p);
				printf("\033[33;01m\n\n-> Joueur JAUNE\033[00m\n");

				printf("\033[33;01m\nPion d'origine : \033[00m");
				scanf("%hhd",&origin);//rapel

				printf("\033[33;01m\nDestination du pion : \033[00m");
				scanf("%hhd",&dest);//rapel

				printf("\n\n---> From %hhd to %hhd", origin, dest);

			}while (estValide(p, origin, dest) ==FAUX);	

			p=jouerCoup(p, origin, dest);
				getCoupsLegaux(p);
				l = getCoupsLegaux(p);

	//////////////////////ModifJSON//////////////////////////////////
		
								CreaJS(argc, nom);

	/////////////////////////////////////////////////////////////////
				
				//afficherPosition(p); //////UTILSER GRAPHIQUE
				evaluerScore(p);
				printf("\n");
				a=evaluerScore(p);
				afficherScore(a);

				l = getCoupsLegaux(p);
				printf("\n\n il reste %d coups legaux (FIN SI 0)\n\n", l.nb);
					test=l.nb;
system("clear");	
			do{
				printf("\033[31;01m\n\n-> Joueur ROUGE\033[00m\n");

				printf("\033[31;01m\nPion d'origine : \033[00m");
					scanf("%hhd",&origin);//rapel

				printf("\033[31;01m\nDestination du pion : \033[00m");
					scanf("%hhd",&dest);//rapel

				printf("\n\n---> From %hhd to %hhd", origin, dest);
				} while(estValide(p,origin,dest)==FAUX);
					
				p=jouerCoup(p, origin, dest);
					getCoupsLegaux(p);
					l = getCoupsLegaux(p);
	//////////////////////ModifJSON//////////////////////////////////
		
								CreaJS(argc, nom);

	/////////////////////////////////////////////////////////////////

				//afficherPosition(p);/////////// Utiliser graphique
				printf("\n");
				a=evaluerScore(p);
				afficherScore(a);
				l = getCoupsLegaux(p);
				
				test=l.nb;
					printf("\n\n il reste %d coups legaux (FIN SI 0)\n\n", l.nb);
			l = getCoupsLegaux(p);
			} while (test!=0);

	//////////////////////ModifJSON//////////////////////////////////
		
								CreaJS(argc, nom);

	/////////////////////////////////////////////////////////////////

			printf("\n"); //FIN DE LA PARTIE

	///////////////Decompte des pts

	printf("\nFIN !!!! :))))\n\n");

	if (a.nbJ>a.nbR)
		printf("\033[34;01m Joueur 1 (JAUNE) remporte cette partie, BRAVO !\n\n Merci d'avoir jouer à cette partie d'Avalam evolution !\n\n SUUU X Avalam (Oya)\n\n Equipe de SUUU : \n-> Younes Boughriet\n-> Valentin Noël\n-> Adelyza Desumeur\n-> Angel Verhaeghe \033[00m\n\n");
else 
	if (a.nbR>a.nbJ)
		printf("\033[34;01m Joueur 2 (ROUGE) remporte cette partie, BRAVO !\n\n Merci d'avoir jouer à cette partie d'Avalam evolution !\n\n SUUU X Avalam (Oya)\n\n Equipe de SUUU : \n-> Younes Boughriet\n-> Valentin Noël\n-> Adelyza Desumeur\n-> Angel Verhaeghe \033[00m\n\n");
else 
		if (a.nbJ=a.nbR){

			if (a.nbJ5>a.nbR5)
				printf("\033[34;01m Egalité mais Joueur 1 (JAUNE) remporte cette partie grâce à son nombre de tour jaune, BRAVO !\n\n Merci d'avoir jouer à cette partie d'Avalam evolution !\n\n SUUU X Avalam (Oya)\n\n Equipe de SUUU : \n-> Younes Boughriet\n-> Valentin Noël\n-> Adelyza Desumeur\n-> Angel Verhaeghe \033[00m\n\n");
		else 
			if (a.nbJ5<a.nbR5)
				printf("\033[34;01m Egalité mais Joueur 2 (ROUGE) remporte cette partie grâce à son nombre de tour rouge, BRAVO !\n\n Merci d'avoir jouer à cette partie d'Avalam evolution !\n\n SUUU X Avalam (Oya)\n\n Equipe de SUUU : \n-> Younes Boughriet\n-> Valentin Noël\n-> Adelyza Desumeur\n-> Angel Verhaeghe \033[00m\n\n");
		else 
				printf("\033[34;01m Egalité parfaite entre Joueur 1 (JAUNE) et Joueur 2 (ROUGE), BRAVO (lol) !\n\n Merci d'avoir jouer à cette partie d'Avalam evolution !\n\n SUUU X Avalam (Oya)\n\n Equipe de SUUU : \n-> Younes Boughriet\n-> Valentin Noël\n-> Adelyza Desumeur\n-> Angel Verhaeghe \033[00m\n\n");

		}
	
	
/////////Fonction utilisée ci-dessus pour créer et modifier le fichier JS


}

void CreaJS(int argc, char nom[50]){

	if (argc==1){
				FILE* fichier = NULL;
    			
    			fichier = fopen("Coups.js", "w");
				fprintf(fichier, "traiterJson({\n");
				fprintf(fichier, "\"trait\":%d,\n", p.trait);

				fprintf(fichier, "\"scoreJ\":%d,\n", a.nbJ); 
				fprintf(fichier, "\"scoreJ5\":%d,\n", a.nbJ5);
				fprintf(fichier, "\"scoreR\":%d,\n", a.nbR);
				fprintf(fichier, "\"scoreR5\":%d,\n", a.nbR5);
				fprintf(fichier, "\"bonusJ\":%hhd,\n", p.evolution.bonusJ);
				fprintf(fichier, "\"malusJ\":%hhd,\n", p.evolution.malusJ);
				fprintf(fichier, "\"bonusR\":%hhd,\n", p.evolution.bonusR);
				fprintf(fichier, "\"malusR\":%hhd,\n", p.evolution.malusR);
				fprintf(fichier, "\"cols\":[\n");
				
				for (i=0; i<=47; i++){
					fprintf(fichier, "	{\"nb\":%hhd, \"couleur\":%hhd},\n", p.cols[i].nb, p.cols[i].couleur);
				}

				fprintf(fichier, "]\n");
				fprintf(fichier, "});");
				fclose(fichier);
	}
	else if (argc==2){
			FILE* fichier = NULL;
    			
    			fichier = fopen(nom, "w");
				fprintf(fichier, "traiterJson({\n");
				fprintf(fichier, "\"trait\":%d,\n", p.trait);

				fprintf(fichier, "\"scoreJ\":%d,\n", a.nbJ); 
				fprintf(fichier, "\"scoreJ5\":%d,\n", a.nbJ5);
				fprintf(fichier, "\"scoreR\":%d,\n", a.nbR);
				fprintf(fichier, "\"scoreR5\":%d,\n", a.nbR5);
				fprintf(fichier, "\"bonusJ\":%hhd,\n", p.evolution.bonusJ);
				fprintf(fichier, "\"malusJ\":%hhd,\n", p.evolution.malusJ);
				fprintf(fichier, "\"bonusR\":%hhd,\n", p.evolution.bonusR);
				fprintf(fichier, "\"malusR\":%hhd,\n", p.evolution.malusR);
				fprintf(fichier, "\"cols\":[\n");

				for (i = 0; i <= 47; i++)
				{
					fprintf(fichier, "	{\"nb\":%hhd, \"couleur\":%hhd},\n", p.cols[i].nb, p.cols[i].couleur);
				}

				fprintf(fichier, "]\n");
				fprintf(fichier, "});");
				fclose(fichier);
	}
}

