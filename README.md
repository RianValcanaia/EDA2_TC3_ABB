<div align="center" id="topo">

<img src="https://media.giphy.com/media/iIqmM5tTjmpOB9mpbn/giphy.gif" width="200px" alt="Gif animado"/>

# <code><strong> Implementação de Árvore Binária de Busca </strong></code>

<em>Trabalho da disciplina de Estrutura de Dados focado na implementação de uma Árvore Binária de Busca (ABB) com diversas funcionalidades.</em>

[![C++ Usage](https://img.shields.io/badge/C++-100%25-blue?style=for-the-badge&logo=c%2B%2B)]()
[![Status](https://img.shields.io/badge/Status-Concluído-green?style=for-the-badge)]()
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Visite%20meu%20perfil-blue?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/rian-carlos-valcanaia-b2b487168/)

</div>


## Índice

- [📌 Objetivos](#-objetivos)
- [📥 Entradas do sistema](#-entradas-do-sistema)
- [🧱 Estruturas de Dados](#-estruturas-de-dados)
- [🧰 Funcionalidades](#-funcionalidades)
- [📊 Exemplo de Execução](#-exemplo-de-execução)
- [📂 Como executar](#-como-executar)
- [👨‍🏫 Envolvidos](#-envolvidos)
- [📅 Curso](#-curso)
- [📄 Código-fonte](#-código-fonte)

## 📌 Objetivos
O objetivo deste trabalho é desenvolver um programa em C++ para gerenciar uma Árvore Binária de Busca (ABB), implementando as seguintes funcionalidades:
* Criar uma ABB com operações de inserção, remoção e busca de elementos.
* Listar todos os elementos da árvore utilizando travessias em pré-ordem, em-ordem (ordenada) e pós-ordem.
* Analisar a árvore para extrair informações detalhadas, como:
  * Verificar se a árvore está vazia.
  * Calcular o tamanho (número de nós) e a altura (profundidade).
  * Determinar a largura da árvore em cada nível.
  * Verificar se a árvore é cheia ou completa.

[⬆ Voltar ao topo](#topo)

## 📥 Entradas do sistema
O programa é interativo e controlado por um menu no terminal:
* O usuário seleciona uma das opções do menu digitando um número (de 1 a 6).
* Para operações de inserção, remoção ou busca, o sistema solicita ao usuário que digite um valor numérico de ponto flutuante.

[⬆ Voltar ao topo](#topo)

## 🧱 Estruturas de Dados
As principais estruturas utilizadas para construir a árvore são `Dado` (para armazenar o valor) e `No` (para compor a árvore).

### 🔸 'Arvore'
```cpp
struct Arvore{
    struct Dado{ ... };
    struct No{ ... };

    No *raiz;

    // Contrutor
    Arvore() : raiz(nullptr) {}
    // Destrutor
    ~Arvore(){ ... }

    // Métodos
    No *buscaNodo(float valor){ ... }
    bool inserirNodo(float valor){ ... }
    int removerNodo(float valor){ ... }
    void preOrdem(){ ... }
    void emOrdem(){ ... }
    void posOrdem(){ ... }
    int altura(){ ... }
    bool vazia(){ ... }
    int qtNos(){ ... }
    void larguraPorNivel(){ ... }
    bool cheia(){ ... }
    bool completa() { ... }
    private:
        void destruir(No *nodo){ ... }
        void preOrdemRec(No *nodo){ ... }
        void emOrdemRec(No *nodo){ ... }
        void posOrdemRec(No *nodo){ ... }
        bool cheiaRec(No* no) { ... }
};
```

### 🔸 `Dado`
```cpp
struct Dado{
    float valor;
    //construtor
    Dado(float v) : valor(v) {}

    Dado() : valor(0) {}
};
```

### 🔸 `No`
```cpp
struct No {
    Dado info;
    No *pai;
    No *esq;
    No *dir;

    // Contrutor 
    No(float valor) : info(valor), pai(nullptr), esq(nullptr), dir(nullptr) {}

    // Destrutor
    ~No(){}

    // Métodos
    void print(){ ... }
    int altura(){ ... }
    int qtFilhos(){ ... }
};
```

[⬆ Voltar ao topo](#topo)

## 🧰 Funcionalidades

### 🔹 Funções Principais (Métodos da classe `Arvore`)
* `inserirNodo()`: Insere um novo elemento na árvore, mantendo a propriedade da ABB.
* `removerNodo()`: Remove um elemento específico da árvore, reorganizando os nós conforme necessário.
* `buscaNodo()`: Procura por um elemento na árvore e retorna um ponteiro para ele se encontrado.
* `preOrdem()`, `emOrdem()`, `posOrdem()`: Percorrem e exibem os nós da árvore nas respectivas ordens.
* `altura()`: Calcula a altura da árvore (o caminho mais longo da raiz até uma folha).
* `vazia()`: Verifica se a árvore não possui nenhum nó.
* `qtNos()`: Retorna a quantidade total de nós na árvore.
* `larguraPorNivel()`: Exibe a quantidade de nós em cada nível da árvore.
* `cheia()`: Verifica se a árvore é uma árvore cheia (todos os nós têm 0 ou 2 filhos).
* `completa()`: Verifica se a árvore é uma árvore completa.

### 🔸 Funções Secundárias
* `limpa_tela()`: Limpa a tela do console (compatível com Windows e Linux).
* `limpa_buffer()`: Limpa o buffer de entrada para evitar erros de leitura.
* `entrada()`: Valida a entrada do usuário para garantir que esteja dentro de um intervalo esperado.

[⬆ Voltar ao topo](#topo)

## 📊 Exemplo de Execução
1. Ao iniciar, o programa exibe um menu com 6 opções: Inserir, Remover, Buscar, Listar, Informações e Sair.
2. O usuário seleciona `1` para inserir e digita um valor, como `50`. O sistema confirma a inserção.
3. O usuário repete o passo 2 para inserir outros valores, como `30`, `70`, `20`, `40`.
4. Ao selecionar a opção `4`, o sistema exibe as listagens:
   * **Pré-ordem**: 50, 30, 20, 40, 70
   * **Em-ordem**: 20, 30, 40, 50, 70
   * **Pós-ordem**: 20, 40, 30, 70, 50
5. Ao selecionar a opção `5`, o sistema exibe informações como altura, quantidade de nós e se a árvore é cheia ou completa.
6. O processo continua até que o usuário selecione a opção `6` para encerrar o programa.

[⬆ Voltar ao topo](#topo)

## 📂 Como executar
Para compilar e executar o programa, utilize um compilador C++ como o g++. Abra o terminal no diretório do arquivo e execute o seguinte comando:
```bash
g++ trabalho.cpp -o trabalho && ./trabalho
```

[⬆ Voltar ao topo](#topo)

## 👨‍🏫 Envolvidos
* **Professor**: André Tavares da Silva
* **Estudantes**:
  * [Rian Valcanaia](https://github.com/RianValcanaia)

[⬆ Voltar ao topo](#topo)

## 📅 Curso

* **Universidade**: Universidade do Estado de Santa Catarina (UDESC)
* **Disciplina**: Estrutura de Dados 2
* **Semestre**: 4º

[⬆ Voltar ao topo](#topo)

## 📄 Código-fonte

🔗 [https://github.com/RianValcanaia/EDA2_TC3_ABB](https://github.com/RianValcanaia/EDA2_TC3_ABB)

[⬆ Voltar ao topo](#topo)
