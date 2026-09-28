#include <iostream>
using namespace std;
template <typename T>
class noeud{
public:
    T val;
    noeud<T>*suiv;
    noeud():suiv(nullptr){};

};
template <typename T>
class pile{
private:
    noeud<T>*sommet;
public:
    pile():sommet(nullptr){};
    void empiler(T elem);
    T depiler();
    int est_vide();

};
template <typename T>
int pile<T>:: est_vide(){
    return !this->sommet;

}
template <typename T>
void pile<T>::empiler(T elem){
   noeud<T>*nv= new noeud<T>;
   nv->val=elem;
   nv->suiv=sommet;
   this->sommet= nv;

}
template <typename T>
T pile<T>::depiler()
{
    if (est_vide())
    {
        throw runtime_error("Pile vide");
    }

    noeud<T>* tmp = this->sommet;

    this->sommet = this->sommet->suiv;

    T res = tmp->val;

    delete tmp;

    return res;
}
