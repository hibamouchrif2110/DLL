#include "main.h"
#include "pile.h"
#include "pile_ptr.h"

#include <string>

using namespace std;


bool correspondant(char ouvrant, char fermant)
{
    return ((ouvrant == '{' && fermant == '}') ||
            (ouvrant == '(' && fermant == ')') ||
            (ouvrant == '[' && fermant == ']'));
}


// =====================================================
// Validation avec la pile par pointeurs
// =====================================================

DLL_EXPORT bool verifierExpression(const char* expression)
{
    pile<char> p;

    string expr = expression;

    for (char c : expr)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            p.empiler(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (p.est_vide())
                return false;

            char ouvrant = p.depiler();

            if (!correspondant(ouvrant, c))
                return false;
        }
    }

    return p.est_vide();
}


// =====================================================
// Validation avec la pile par tableau
// =====================================================

DLL_EXPORT bool verifierExpressionTableau(const char* expression)
{
    Pile<char> p;

    string expr = expression;

    for (char c : expr)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            p.empiler(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (p.est_vide())
                return false;

            char ouvrant = p.depiler();

            if (!correspondant(ouvrant, c))
                return false;
        }
    }

    return p.est_vide();
}


// =====================================================
// DllMain
// =====================================================

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            break;

        case DLL_PROCESS_DETACH:
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    }

    return TRUE;
}
