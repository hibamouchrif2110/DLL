#ifndef PILE_H
#define PILE_H

#define MAX_ELEM 100

#include <iostream>

using namespace std;

template <typename T>
class Pile
{
private:
    T tab[MAX_ELEM];
    int sommet;

public:
    Pile() : sommet(-1) {}

    void empiler(T elem);
    T depiler();
    int est_saturee();
    int est_vide();
    T top();
};


template <typename T>
T Pile<T>::top()
{
    return tab[sommet];
}


template <typename T>
int Pile<T>::est_saturee()
{
    if (sommet == MAX_ELEM - 1)
        return 1;

    return 0;
}


template <typename T>
int Pile<T>::est_vide()
{
    if (sommet == -1)
        return 1;

    return 0;
}


template <typename T>
void Pile<T>::empiler(T elem)
{
    if (est_saturee())
    {
        cout << "Pile saturee" << endl;
        return;
    }

    tab[++sommet] = elem;
}


template <typename T>
T Pile<T>::depiler()
{
    if (est_vide())
    {
        cout << "Pile vide" << endl;
        return T();
    }

    T temp = tab[sommet];

    sommet--;

    return temp;
}

#endif
