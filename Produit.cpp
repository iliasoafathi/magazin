#include "Produit.hpp"
#include <sstream>

// Classe Produit 
Produit::Produit(const string& nom, int quantite, int code) : nom(nom), quantite(quantite), code(code) {}

void Produit::afficher() const {
    cout << "Nom: " << nom << ", Quantité: " << quantite << ", Code: " << code << endl;
}

void Produit::saisir() {
    cout << "Nom: "; cin >> nom;
    cout << "Quantité: "; cin >> quantite;
    cout << "Code: "; cin >> code;
}

int Produit::getCode() const { return code; }

bool Produit::operator==(const Produit& autre) const { return code == autre.code; }

bool Produit::operator<(const Produit& autre) const { return quantite < autre.quantite; }

// Classe ProduitElectro
ProduitElectro::ProduitElectro(const string& nom, int quantite, int code, int garantie, int voltage)
    : Produit(nom, quantite, code), garantie(garantie), voltage(voltage) {}

void ProduitElectro::afficher() const {
    Produit::afficher();
    cout << "Garantie: " << garantie << " mois, Voltage: " << voltage << "V" << endl;
}

void ProduitElectro::saisir() {
    Produit::saisir();
    cout << "Garantie (mois): "; cin >> garantie;
    cout << "Voltage (V): "; cin >> voltage;
}

string ProduitElectro::toString() const {
    ostringstream oss;
    oss << "Electro," << nom << "," << quantite << "," << code << "," << garantie << "," << voltage;
    return oss.str();
}

// Classe ProduitLaitier
ProduitLaitier::ProduitLaitier(const string& nom, int quantite, int code, const string& dateLimite, int temperature)
    : Produit(nom, quantite, code), dateLimite(dateLimite), temperature(temperature) {}

void ProduitLaitier::afficher() const {
    Produit::afficher();
    cout << "Date limite: " << dateLimite << ", Température: " << temperature << "°C" << endl;
}

void ProduitLaitier::saisir() {
    Produit::saisir();
    cout << "Date limite: "; cin >> dateLimite;
    cout << "Température (°C): "; cin >> temperature;
}

string ProduitLaitier::toString() const {
    ostringstream oss;
    oss << "Laitier," << nom << "," << quantite << "," << code << "," << dateLimite << "," << temperature;
    return oss.str();
}

// Classe ProduitMobilier
ProduitMobilier::ProduitMobilier(const string& nom, int quantite, int code, double volume, double poids)
    : Produit(nom, quantite, code), volume(volume), poids(poids) {}

void ProduitMobilier::afficher() const {
    Produit::afficher();
    cout << "Volume: " << volume << " m³, Poids: " << poids << " kg" << endl;
}

void ProduitMobilier::saisir() {
    Produit::saisir();
    cout << "Volume (m³): "; cin >> volume;
    cout << "Poids (kg): "; cin >> poids;
}

string ProduitMobilier::toString() const {
    ostringstream oss;
    oss << "Mobilier," << nom << "," << quantite << "," << code << "," << volume << "," << poids;
    return oss.str();
}

// Classe ProduitTextile
ProduitTextile::ProduitTextile(const string& nom, int quantite, int code, const string& taille, const string& couleur)
    : Produit(nom, quantite, code), taille(taille), couleur(couleur) {}

void ProduitTextile::afficher() const {
    Produit::afficher();
    cout << "Taille: " << taille << ", Couleur: " << couleur << endl;
}

void ProduitTextile::saisir() {
    Produit::saisir();
    cout << "Taille: "; cin >> taille;
    cout << "Couleur: "; cin >> couleur;
}

string ProduitTextile::toString() const {
    ostringstream oss;
    oss << "Textile," << nom << "," << quantite << "," << code << "," << taille << "," << couleur;
    return oss.str();
}

// Classe ProduitEnfant
ProduitEnfant::ProduitEnfant(const string& nom, int quantite, int code, int ageLimite, const string& typeDeJouet)
    : Produit(nom, quantite, code), ageLimite(ageLimite), typeDeJouet(typeDeJouet) {}

void ProduitEnfant::afficher() const {
    Produit::afficher();
    cout << "Age limite: " << ageLimite << " ans, Type de jouet: " << typeDeJouet << endl;
}

void ProduitEnfant::saisir() {
    Produit::saisir();
    cout << "Age limite (ans): "; cin >> ageLimite;
    cout << "Type de jouet: "; cin >> typeDeJouet;
}

string ProduitEnfant::toString() const {
    ostringstream oss;
    oss << "Enfant," << nom << "," << quantite << "," << code << "," << ageLimite << "," << typeDeJouet;
    return oss.str();
}
