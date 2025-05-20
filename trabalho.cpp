#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Estrutura de dados
typedef struct dado{
    float valor;

    //construtor
    Dado(float v) valor = v;
}Dado;

typedef struct no {
    struct dado dado;
    struct no *pai;
    struct no *esq;
    struct no *dir;

    // Contrutor 
    No(float valor){
        dado.valor = valor 
        pai = nullptr;
        esq = nullptr;
        dir = nullptr;
    }

    // Destrutor
    ~No() delete dado;
}No;

typedef struct Arvore{
    struct no *raiz;

    // Contrutor
    Arvore() raiz = nullptr;
}Arvore;

// Funções Secundárias
void limpa_tela(){  // seq Ansi para limpar tela
    cout << "\033[2J\033[H";
}

void limpa_buffer() {  // limpa buffer de entrada
    cin.clear();               
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void entrada(int ini, int fim, int *opcao){  // verifica se a entrada esta dentro do intervalo
    int a;
    cout << "Digite uma opção: ";
    cin >> a;
    while (a < ini || a > fim){
        cout << "Digite nomamente, intervalo aceito [" << ini << ',' << fim << ']' << endl;
        cout << "Digite uma opção: ";
        cin >> a;
    }
    *opcao = a;
}

// Funções primárias
bool inserirNodo(No *novo, Arvore *arv){
    if(arv->raiz == nullptr) {
        arv->raiz = novo;
        return true;    
    }

    No *auxPai = nullptr;
    No *aux = arv->raiz;
    while(aux != nullptr){
        if(aux->dado->valor == novo->valor){
            cout << "Nodo com mesmo valor já adicionado. Aperte enter para voltar" << endl.
            cin.ignore();
            cin.get();
            return false;
        }
        auxPai = aux;
        if (novo->dado->valor > aux->dado->valor) aux = aux->dir;
        else aux = aux->esq;
    }

    if(aux != nullptr) return false;

    if(novo->dado->valor > auxPai->dado->valor) auxPai->dir = novo;
    else auxPai->esq = novo;

    novo->pai = auxPai;

    return true;
}

int removerNodo(float valor, Arvore *arv){
    No *auxPai = nullptr, *aux = arv->raiz, *subst, *paiSubst, *avante;

    while (aux != NULL && (valor != aux->dado->valor))
}

void buscarNodo(){
}

void listarNodos(){
}

void exibirInfos(){
}


int main(){
    bool continuar = true;
    int opcao;
    Arvore *arv = new Arvore();

    while(continuar){
        float valor;
        cout << "1 - Inserir nodo" << endl
             << "2 - Remover nodo" << endl
             << "3 - Buscar nodo"  << endl
             << "4 - Listar todos os nodos" << endl
             << "5 - Exibir informações" << endl
             << "6 - Sair"  << endl;

        entrada(1, 7, &opcao);
        switch(opcao){
            case 1:
                cout << "Digite o valor do dado a ser inserido: ";
                cin >> valor;
                No *nodo = new No(valor);
                
                if (inserirNodo(nodo, arv)) cout << "\u2714 Nodo inserido com sucesso.";
                else cout << "\u274C Erro ao inserir nodo na árvore. ";
            break;
            case 2:
                cout << "Digite o valor do nodo que deseja remover: " << endl;
                cin >> valor;

                int remove = removerNodo(valor, arv);
                if (remove == 1) cout << "\u2714 Nodo removido com suesso.";
                else if (remove == 2) cout << "\u274C Erro ao remover o nodo.";
                else cout << "\u274C Nodo não encontrado.";
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
                continuar = false;
            break;
        }
        cout << "Aperte enter para voltar.";
        cin.ignore();
        cin.get();
    }





}