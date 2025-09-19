#include <iostream>
#include <random>
#include <math.h>
using namespace std;

struct Case
{
   
    int lig, col;
    Case* suivant;
};
struct coord {
    int x;
    int y;
};
//1
Case* initListCaseVideIter(Case* tete, int taille)
{
    tete = NULL;
    for (int i = taille -1 ; i >=0 ; i--)
    {
        for (int j = taille - 1; j >= 0; j--)
        {
            Case* newNode = new Case;
            newNode->lig = i;
            newNode->col = j;
            newNode->suivant = tete;
            tete = newNode;
        }
    }
    return tete;
}
//2
Case* initListCaseVideRec(int taille, int i = 0, int j = 0)
{
    if (i >= taille)
    {
        return nullptr;
    }
   
    Case* newNode = new Case;
    newNode->col = j;
    newNode->lig = i;
    int next_j = j + 1;
    int next_i = i;
    if (next_j >= taille)
    {
        next_j = 0;
        next_i = i + 1;
    }
    newNode->suivant = initListCaseVideRec(taille, next_i, next_j);
    return newNode;
}


//teste recursive
void afficheExempleRec(Case* tete, int taille, int compteur = 0)
{
    if (tete == NULL)
    {
        cout << " Liste vide " << endl;
    }
    else
    {
        cout << "( " << tete->lig << " - " << tete->col << " )";
        compteur++;
        if (compteur % taille == 0)
        {
            cout << endl;
        }
        afficheExempleRec(tete->suivant, taille, compteur++);
    }
}

//teste iter
void afficheExempleIter(Case* tete, int taille)
{
    if (tete == NULL)
    {
        cout << "Liste vide" << endl;
    }
    else
    {
        Case* temp = tete;
        int compteur = 0;
                while (temp != NULL)
                {
                    cout << "( " << temp->lig<< " - " << temp->col <<" )";
                    compteur++;
                    if (compteur % taille == 0) {
                        cout << endl;
                    }
                     
                    temp = temp->suivant;
                }
        cout << endl;
    }
}
//3
int lenghListeRec(Case* tete)
{
    if (tete == NULL)
    {
        cout << " Liste Vide " << endl;
        return 0;
    }
    
    
    else  return 1 + lenghListeRec(tete->suivant);
}
//4 via pointeur

void rechercheAlea(Case* tete, int taille, int* i, int* j)
{
    if (tete == NULL)
    {
        cout << " Liste Vide " << endl;
        *i = -1;
        *j = -1;
        return;
    }
    else
    {
        
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<>dist(0, taille-1);
        *i = dist(gen);
        *j = dist(gen);
    }
}
//4 via structure
coord AleaRecherche(Case* tete, int taille)
{
    coord Z;
    if (tete == NULL)
    {
        cout << " Liste Vide " << endl;
        Z.x = -1;
        Z.y = -1;
        return Z;
    }
    else
    {
        
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<>dist(0, taille-1);
        Z.x = dist(gen);
        Z.y = dist(gen);
    }
        return Z;
    
}
//5
bool estPrise(int i, int j, int xDame, int yDame)
{
// L'emplacement est prenable si elle est libre
// Sinon elle  est prenable
  
        // Même ligne
        if (i == xDame && j != yDame) return true;
        
        // Même colonne
        if (j == yDame && i != xDame) return true;
        
        // Même diagonale
        if (abs(i - xDame) == abs(j - yDame) && (i != xDame || j != yDame)) {
            return true;
        }
        
        return false;
}
 
//6
void MAJ(Case* tete, int xDame, int yDame)
{
    if (tete == NULL)
    {
        cout << " Liste Vide " << endl;
        return;
    }
    Case* temp = tete;
    Case* prec = NULL;
    while (temp != NULL)
    {
       
        if (estPrise(temp->lig, temp->col, xDame, yDame))
        {
            prec->suivant = temp->suivant;
            delete temp;
            prec = temp;
            temp = temp->suivant;
        }
    }
   
    
}

bool ajouteDame(Case** tete, int i, int j)
{
    if (tete == NULL)
    {
        Case* newNode = new Case;
        newNode->lig = i;
        newNode->col = j;
        newNode->suivant = *tete;
        *tete = newNode;
    }
    Case* temp = *tete;
    while (temp != NULL)
    {
        if (estPrise(i, j, temp->lig, temp->col))
        {
            return false;
            
        }
        else
        {
            temp = temp->suivant;
            
        }
    }
    Case* newNode = new Case;
    newNode->lig = i;
    newNode->col = j;
    newNode->suivant = *tete;
    *tete = newNode;
    return true;
    
}

bool AJouteDame(Case** tete, Case* x)
{
    if (*tete == NULL)
    {
        x->suivant = *tete;
        *tete = x;
        return true;
    }
    else{
        
        if (estPrise(x->lig, x->col, (*tete)->lig, (*tete)->col))
        {
            return false;
        }
    }
         return AJouteDame(&(*tete)->suivant, x);
     
}




int  main()
{
    
    int i,j;
    int taille = 8;
    Case* tete = NULL;
    Case* result = initListCaseVideIter(tete, taille);
    afficheExempleIter(result, taille);
    
    cout << endl;
    cout << " #########################" << endl;
    cout << endl;
    Case* temp = tete;
    int maxEssai = 8;
    int nbrDame = 0;
    while (temp != NULL)
    {
        ajouteDame(&temp, temp->lig, temp->col);
        nbrDame++;
        temp = temp->suivant;
        if (nbrDame == maxEssai)
        {
            temp = temp->suivant;
        }
        else{
            cout << " Nombre de tour atteint " << endl;
        }
}
    
    Case* result1 = initListCaseVideRec(taille, 0, 0);
    afficheExempleRec(result1, taille);
    
    int result2 = lenghListeRec(result1);
    cout << endl;
    
    cout << "La liste contient : " << result2 << " Cases " << endl;
    cout << endl;
    
    rechercheAlea(result, taille, &i, &j);
    cout<< " Coordonnee Alea : " << "( " << i <<" - " << j << " )" << endl;
    cout << endl;
    
    coord coordonnees = AleaRecherche(result, taille);
    cout<< " Coordonnee Alea : " << "( " << coordonnees.x <<" - " << coordonnees.y << " )" << endl;
    
    
    
    
    
    
    return 0;
}
