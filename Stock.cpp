#include "Stock.hpp"
#include <iostream>
#include <map>

Stock::~Stock() {
    for (Produit* produit : produits) {
        delete produit;
    }
}

void Stock::ajouterProduit(Produit* produit) {
    for (const auto& p : produits) {
        if (*p == *produit) { // opérateur ==
            cout << "Le produit existe déjà.\n";
            return;
        }
    }
    produits.push_back(produit);
    cout << "Produit ajouté.\n";
}

void Stock::supprimerProduit(int code) {
    auto it = find_if(produits.begin(), produits.end(), [code](Produit* p) {
        return p->getCode() == code;
    });
    if (it != produits.end()) {
        delete *it;
        produits.erase(it);
        cout << "Produit supprimé.\n";
    } else {
        cout << "Produit introuvable.\n";
    }
}

Produit* Stock::rechercherProduit(int code) const {
    auto it = find_if(produits.begin(), produits.end(), [code](Produit* p) {
        return p->getCode() == code;
    });
    return (it != produits.end()) ? *it : nullptr;
}

void Stock::afficherStock() const {
    if (produits.empty()) {
        cout << "Aucun produit en stock.\n";
        return;
    }
    for (const auto& produit : produits) {
        produit->afficher();
    }
}

void Stock::trierProduits() {
    sort(produits.begin(), produits.end(), [](Produit* a, Produit* b) {
        return *a < *b; // opérateur <
    });
    cout << "Produits triés par quantité.\n";
}

void Stock::sauvegarder(const string& FichierP) const {
    ofstream fichier(FichierP);
    if (!fichier) {
        cout << "Erreur lors de l'ouverture du fichier.\n";
        return;
    }
    for (const auto& produit : produits) {
        fichier << produit->toString() << endl;
    }
    fichier.close();
    cout << "les Données sont sauvegardées dans le fichier " << FichierP << ".\n";
}

void Stock::reinitialiser() {
    for (Produit* produit : produits) {
        delete produit;
    }
    produits.clear();
    cout << "Base de données réinitialisée.\n";
}

void Stock::afficherStatistiques() const {
    map<string, int> stats;
    for (const auto& produit : produits) {
        stats[typeid(*produit).name()]++;
    }
    cout << "Statistiques des produits :\n";
    for (const auto& [type, count] : stats) {
        cout << "Type " << type << ": " << count << " produit(s).\n";
    }
}
