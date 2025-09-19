#include <iostream>
using namespace std;

struct noeud
{
    int val;
    noeud* gauche;
    noeud* droite;
};

void affichePrefixe(noeud* racine)
{
    if (racine == NULL)
    {
        cout << "arbre vide " << endl;
        return;
    }
    else{
        cout << racine->val;
        affichePrefixe(racine->gauche);
        affichePrefixe(racine->droite);
    }
}

int main()
{
    noeud* racine = NULL;
    affichePrefixe(racine);
    return 0;
}
