#ifndef Produit_hpp
#define Produit_hpp

#include <string>
#include <iostream>
using namespace std;

class Produit {
protected:
    string nom;
    int quantite;
    int code;

public:
    Produit(const string& nom, int quantite, int code);
    virtual ~Produit() = default;

    virtual void afficher() const;
    virtual void saisir();
    virtual string toString() const = 0;

    int getCode() const;
    bool operator==(const Produit& autre) const;
    bool operator<(const Produit& autre) const;
};

// sous-classes
class ProduitElectro : public Produit {
    int garantie;
    int voltage;

public:
    ProduitElectro(const string& nom, int quantite, int code, int garantie, int voltage);
    void afficher() const override;
    void saisir() override;
    string toString() const override; 
};

class ProduitLaitier : public Produit {
    string dateLimite;
    int temperature;

public:
    ProduitLaitier(const string& nom, int quantite, int code, const string& dateLimite, int temperature);
    void afficher() const override;
    void saisir() override;
    string toString() const override;
};

class ProduitMobilier : public Produit {
    double volume;
    double poids;

public:
    ProduitMobilier(const string& nom, int quantite, int code, double volume, double poids);
    void afficher() const override;
    void saisir() override;
    string toString() const override;
};

class ProduitTextile : public Produit {
    string taille;
    string couleur;

public:
    ProduitTextile(const string& nom, int quantite, int code, const string& taille, const string& couleur);
    void afficher() const override;
    void saisir() override;
    string toString() const override;
};

class ProduitEnfant : public Produit {
    int ageLimite;
    string typeDeJouet;

public:
    ProduitEnfant(const string& nom, int quantite, int code, int ageLimite, const string& typeDeJouet);
    void afficher() const override;
    void saisir() override;
    string toString() const override;
};

#endif
