#include <iostream>
using namespace std;

struct Case
{
   
    int lig, col;
    Case* suivant;
};

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

int lenghListeRec(Case* tete)
{
    if (tete == NULL)
    {
        cout << " Liste Vide " << endl;
        return 0;
    }
   
    
      else  return 1 + lenghListeRec(tete->suivant);
            

}
    

int  main()
{
    int taille = 8;
    Case* tete = NULL;
    Case* result = initListCaseVideIter(tete, taille);
    afficheExempleIter(result, taille);
    cout << endl;
    cout << " #########################" << endl;
    cout << endl;
    Case* result1 = initListCaseVideRec(taille, 0, 0);
    afficheExempleRec(result1, taille);
    
    int result2 = lenghListeRec(result1);
    cout << endl;
    cout << "La liste contient : " << result2 << " Cases " << endl;
    return 0;
}
