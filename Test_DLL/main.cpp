#include <iostream>
#include <windows.h>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;


// Fonction pour la pile par pointeurs
typedef bool (*VerifierExpression)(const char*);

// Fonction pour la pile par tableau
typedef bool (*VerifierExpressionTableau)(const char*);


int main()
{
    cout << "=== Test de la DLL ===" << endl;


    // =====================================================
    // 1. Charger la DLL
    // =====================================================

    HINSTANCE dll = LoadLibrary("pile_generique_DLL.dll");

    if (dll == NULL)
    {
        cout << "Erreur : impossible de charger la DLL." << endl;
        return 1;
    }

    cout << "DLL chargee avec succes !" << endl;


    // =====================================================
    // 2. Recuperer la fonction pour la pile pointeur
    // =====================================================

    VerifierExpression verifier =
        (VerifierExpression)GetProcAddress(
            dll,
            "verifierExpression"
        );

    if (verifier == NULL)
    {
        cout << "Erreur : fonction verifierExpression introuvable."
             << endl;

        FreeLibrary(dll);
        return 1;
    }


    // =====================================================
    // 3. Recuperer la fonction pour la pile tableau
    // =====================================================

    VerifierExpressionTableau verifierTableau =
        (VerifierExpressionTableau)GetProcAddress(
            dll,
            "verifierExpressionTableau"
        );

    if (verifierTableau == NULL)
    {
        cout << "Erreur : fonction verifierExpressionTableau "
             << "introuvable." << endl;

        FreeLibrary(dll);
        return 1;
    }

    cout << "Fonctions trouvees !" << endl;


    // =====================================================
    // 4. Demander l'expression
    // =====================================================

    string expression;

    cout << endl;
    cout << "Entrer une expression : ";
    cin >> expression;


    // =====================================================
    // 5. Test avec la pile par pointeurs
    // =====================================================

    auto debutPointeur = high_resolution_clock::now();

    bool resultatPointeur =
        verifier(expression.c_str());

    auto finPointeur = high_resolution_clock::now();


    duration<double, milli> tempsPointeur =
        finPointeur - debutPointeur;


    // =====================================================
    // 6. Test avec la pile par tableau
    // =====================================================

    auto debutTableau = high_resolution_clock::now();

    bool resultatTableau =
        verifierTableau(expression.c_str());

    auto finTableau = high_resolution_clock::now();


    duration<double, milli> tempsTableau =
        finTableau - debutTableau;


    // =====================================================
    // 7. Affichage des resultats
    // =====================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "       RESULTATS DE LA VALIDATION" << endl;
    cout << "========================================" << endl;


    cout << endl;
    cout << "Pile par pointeurs :" << endl;

    if (resultatPointeur)
        cout << "Expression valide !" << endl;
    else
        cout << "Expression invalide !" << endl;

    cout << "Temps d'execution : "
         << tempsPointeur.count()
         << " ms" << endl;


    cout << endl;
    cout << "Pile par tableau :" << endl;

    if (resultatTableau)
        cout << "Expression valide !" << endl;
    else
        cout << "Expression invalide !" << endl;

    cout << "Temps d'execution : "
         << tempsTableau.count()
         << " ms" << endl;


    // =====================================================
    // 8. Fermer la DLL
    // =====================================================

    FreeLibrary(dll);

    return 0;
}
