#ifndef MAIN_H
#define MAIN_H

#include <windows.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

DLL_EXPORT bool verifierExpression(const char* expression);
DLL_EXPORT bool verifierExpressionTableau(const char* expression);

#ifdef __cplusplus
}
#endif

#endif
