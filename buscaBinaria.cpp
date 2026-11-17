#include <iostream>
using namespace std;

struct NoArvore{
    int data;
    NoArvore* esquerda;
    NoArvore* direita;

};

NoArvore* inserirBST(NoArvore *&raiz, int chave){
    if (raiz == NULL)
    {
        NoArvore *novoNo = new NoArvore;
        novoNo -> data = chave;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;

        raiz = novoNo;
        return raiz;
    }
    if(chave > raiz -> data){
        raiz -> direita = inserirBST(raiz -> direita, chave);
    }
    if(chave < raiz -> data){
        raiz -> esquerda = inserirBST(raiz -> esquerda, chave);
    }
    return raiz;
}

NoArvore* buscarBST(NoArvore *&raiz, int chave){
    if(raiz == NULL){
        return NULL;
    }
    if (raiz -> data == chave){
        return  raiz;
    }
    if(chave > raiz -> data){
        return buscarBST(raiz -> direita, chave);
    }
    return buscarBST(raiz -> esquerda, chave);
}


int main(){

    NoArvore* raiz = NULL;

    inserirBST(raiz, 10);
    inserirBST(raiz, 20);
    inserirBST(raiz, 30);
    inserirBST(raiz, 40);

    if (buscarBST(raiz, 50))
    {
        cout << "encontrado\n";
    }else{
        cout << "Não encontrado\n";
    }

    if (buscarBST(raiz, 20))
    {
        cout << "encontrado\n";
    }else{
        cout << "Não encontrado\n";
    }
}