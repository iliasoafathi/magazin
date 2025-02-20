#ifndef Stock_hpp
#define Stock_hpp

#include "Produit.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Stock {
private:
    vector<Produit*> produits;

public:
    ~Stock();
    void ajouterProduit(Produit* produit);
    void supprimerProduit(int code);
    Produit* rechercherProduit(int code) const;
    void afficherStock() const;
    void trierProduits();
    void sauvegarder(const string& nomFichier) const;
    void reinitialiser();
    void afficherStatistiques() const;
};

#endif
