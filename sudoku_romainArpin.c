#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 9

typedef enum {
    HORIZ,
    VERT
}Sens;

typedef enum {
    VRAI,
    FAUX
}Bool;



/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/
// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls
// ici on va utiliser un tableau . La fonction retournera 1 si ça s’est bien passé, sinon elle retournera 0//

void generer(int grid[SIZE][SIZE])
{

    // Générer des nombres aléatoires pour la grille
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num = rand() % 9 + 1;
            grid[i][j] = num;
            
        }
    }

    int enleverNombre = 30; //30 nombres doivent être supprimés

    while (enleverNombre > 0) {
        int row = rand() % 9; //choisir une ligne au hasard
        int col = rand() % 9; //choisir une colone au hasard
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            enleverNombre--;
        }
    }
  

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    
}

   

// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/ Merci ;)


/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/

void saisir(int grid[SIZE][SIZE], int i, int j, int v ){
    int count = 0;
    int y = 0;
    //continuer tant qu'il y a des 0 sur la grille//
    
    for (count = 0; count < 81; count++){
        printf("Saisir les indices i et j et la valeur v  placer a (i,j) : \n");

        printf("Saisir i : \n");
        scanf("%d", &i);
        
        printf("Saisir j : \n");
        scanf("%d", &j);


        printf("Saisir v : \n");
        scanf("%d", &v);


        if (i < 0 || i > 9 || j < 0 || j > 9 || v < 0 || v > 9) {
            printf("Valeur non valide \n");
            y++;
        }
            
        if (grid[i][j] != 0) {
            printf("Case non disponible \n");
            y++;
        }
        
        if (grid[i][j] == v) {
            printf("Valeur deja presente \n");
            y++;
        }
         // afficher la grille remplis si il n'y a pas d'erreur//
        if(y == 0 ) {
            printf("Valeur validee \n");
            // remplir la grille //
            grid[i][j] = v;
            // afficher la grille //
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++)
                    printf("%d ", grid[i][j]);
                printf("\n");
            }
        }
        
        
        y -3;
        
    // Quand la grille est remplie, on affiche le message suivant : "Grille remplie"//
    // code fait comme je pouvait boucle while pas trouver //
        if (count == 81) {
            printf("Grille remplie \n");
        }

    }
}

    

    



/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/
int verifierLigneColonne(int grid[SIZE][SIZE], int HORIZ, int VERT, int num)
{
    // Vérifier la ligne
    for (int i = 0; i < SIZE; i++)
        if (grid[VERT][i] == num){
            return 1;
            }
        else{
            printf("Erreur sur la ligne (horizontale)");
            return 0;
        }

    // Vérifier la colonne
    for (int i = 0; i < SIZE; i++)
        if (grid[i][HORIZ] == num){
            return 1;
            }
        else {
            printf("Erreur sur la colonne");
            return 0;
            }
}

/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

int verifierRegion(int grid[SIZE][SIZE], int k, int l, int num)
{
    // Vérifier la région
    // pour calculer la regions on divise par 3 et on multiplie par 3 parce que la grille est de 9x9 est cela revient a faire 3x3//
    int carréAvecHorizon = ( HORIZ / 3) * 3;
    int carréAvecVert = ( VERT / 3) * 3;
    for (int k = carréAvecHorizon; k < carréAvecHorizon + 3; k++) {
        for (int l = carréAvecVert; l < carréAvecVert + 3; l++) {
            if (grid[k][l] == num){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}



//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon

int verifierGrille(int grid[SIZE][SIZE])
{
    // Vérifier la grille
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}


//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)




int main(){
     int i, j, k, v;

    // generer et afficher la grille avec des nombres aleatoireq //

    int grid[SIZE][SIZE];

    
    // Afficher la grille de Sudoku générée
    printf("\n Grille de Sudoku generee aleatoirement :\n");

    // Générer une grille de Sudoku
    generer(grid);
    saisir(grid, i, j, v);
    


    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


   
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 
    
  



    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

