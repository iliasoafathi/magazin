#include <iostream>
#include "Stock.hpp"

using namespace std;

//menu
void afficherMenu() {
    cout << "\n=== Menu ===\n";
    cout << "1. Afficher les produits\n";
    cout << "2. Ajouter un produit\n";
    cout << "3. Supprimer un produit\n";
    cout << "4. Rechercher un produit par code\n";
    cout << "5. Trier les produits par quantité\n";
    cout << "6. Sauvegarder les produits\n";
    cout << "7. Réinitialiser la base de données\n";
    cout << "8. Afficher les statistiques\n";
    cout << "0. Quitter\n";
}

int main() {
    Stock stock;
    int choix;

    do {
        afficherMenu();
        cout << "Votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                stock.afficherStock();
                break;
            }
            case 2: {
                int type;
                cout << "Quel type de produit ? (1 = Electro, 2 = Laitier, 3 = Mobilier, 4 = Textile, 5 = Enfant): ";
                cin >> type;

                Produit* produit = nullptr;

                switch (type) {
                    case 1:
                        produit = new ProduitElectro("", 0, 0, 0, 0);
                        break;
                    case 2:
                        produit = new ProduitLaitier("", 0, 0, "", 0);
                        break;
                    case 3:
                        produit = new ProduitMobilier("", 0, 0, 0.0, 0.0);
                        break;
                    case 4:
                        produit = new ProduitTextile("", 0, 0, "", "");
                        break;
                    case 5:
                        produit = new ProduitEnfant("", 0, 0, 0, "");
                        break;
                    default:
                        cout << "Type invalide.\n";
                        continue;
                }

                produit->saisir(); // pour saisir les attributs
                stock.ajouterProduit(produit);
                break;
            }
            case 3: {
                int code;
                cout << "Entrez le code du produit à supprimer: ";
                cin >> code;
                stock.supprimerProduit(code);
                break;
            }
            case 4: {
                int code;
                cout << "Entrez le code du produit à rechercher: ";
                cin >> code;
                Produit* produitTrouve = stock.rechercherProduit(code);
                if (produitTrouve) {
                    cout << "Produit trouvé :\n";
                    produitTrouve->afficher();
                } else {
                    cout << "Aucun produit trouvé avec ce code.\n";
                }
                break;
            }
            case 5: {
                stock.trierProduits(); // Trier les produits par quantité (<)
                cout << "Produits triés par quantité.\n";
                break;
            }
            case 6: {
                string fichier;
                cout << "Entrez le nom du fichier pour la sauvegarde: ";
                cin >> fichier;
                stock.sauvegarder(fichier);
                break;
            }
            case 7: {
                stock.reinitialiser(); // Réinitialiseer la base de données
                cout << "Base de données réinitialisée.\n";
                break;
            }
            case 8: {
                stock.afficherStatistiques(); // Afficher les statistiques des produits
                break;
            }
            case 0: {
                cout << "Au revoir !\n";
                break;
            }
            default: {
                cout << "Choix invalide, veuillez réessayer.\n";
                break;
            }
        }
    } while (choix != 0);

    return 0;
}
