#pragma once
#include <utility>
#include <vector>
#include<cmath>

/**
 * @brief Classe que representa uma Árvore Binária de Busca (BST).
 *
 * Armazena elementos em ordem, permitindo operações eficientes de busca,
 * inserção e remoção.
 *
 * @tparam T Tipo dos elementos armazenados na árvore.
 */
template <class T>
class AVL {
 private:
  /**
   * @brief Estrutura interna que representa um nó da árvore.
   */
  struct TreeNode {
    T data;           ///< Valor armazenado no nó.
    TreeNode* left;   ///< Ponteiro para o filho à esquerda.
    TreeNode* right;  ///< Ponteiro para o filho à direita.
    int height;  ///< Altura do nó na árvore. Usada para balanceamento da AVL.

    /**
     * @brief Construtor que inicializa o nó com um valor.
     *
     * @param value Valor a ser armazenado no nó.
     */
    TreeNode(const T& value);

    /**
     * @brief Destrutor do nó, libera recursivamente seus filhos.
     */
    ~TreeNode();

    /**
     * @brief Retorna o nó com o maior valor da subárvore.
     *
     * @return Ponteiro para o nó com o valor máximo.
     */
    TreeNode* max();

    /**
     * @brief Retorna o nó com o menor valor da subárvore.
     *
     * @return Ponteiro para o nó com o valor mínimo.
     */
    TreeNode* min();
  };

  /**
   * @brief Retorna a altura de um nó da árvore.
   *
   * @param node Ponteiro para o nó.
   * @return Altura do nó se não for nulo, ou -1 caso seja nullptr.
   */
  int height(TreeNode* node) const;

  /**
   * @brief Atualiza o balanceamento da árvore AVL a partir de um nó.
   *
   * Recalcula a altura do nó, verifica o fator de balanceamento
   * e realiza rotações simples ou duplas conforme necessário para
   * manter as propriedades da AVL.
   *
   * @param node Referência para o ponteiro do nó a ser balanceado.
   */
  void balance(TreeNode*& node);

  /**
   * @brief Insere um valor na árvore recursivamente.
   *
   * @param node Ponteiro de referência para o nó atual.
   * @param value Valor a ser inserido.
   * @return `true` se a inserção foi bem-sucedida, `false` se o valor já
   * existia.
   */
  bool insert(TreeNode*& node, const T& value);

  /**
   * @brief Remove um valor da árvore recursivamente.
   *
   * @param node Ponteiro de referência para o nó atual.
   * @param value Valor a ser removido.
   * @return `true` se a remoção foi bem-sucedida, `false` se o valor não foi
   * encontrado.
   */
  bool remove(TreeNode*& node, const T& value);

  /**
   * @brief Verifica se a árvore contém um valor específico.
   *
   * @param node Ponteiro para o nó atual.
   * @param value Valor a ser buscado.
   * @return `true` se o valor estiver na árvore, `false` caso contrário.
   */
  bool contain(const TreeNode* const node, const T& value) const;

  /**
   * @brief Executa a travessia in-order recursiva.
   *
   * Visita a subárvore esquerda, depois o nó atual e em seguida a subárvore
   * direita. Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void in_order(const TreeNode* const node, std::vector<T>& result) const;

  /**
   * @brief Executa a travessia pre-order recursiva.
   *
   * Visita o nó atual, em seguida a subárvore esquerda e depois a direita.
   * Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void pre_order(const TreeNode* const node, std::vector<T>& result) const;

  /**
   * @brief Executa a travessia post-order recursiva.
   *
   * Visita a subárvore esquerda, depois a direita e por último o nó atual.
   * Os valores visitados são armazenados em `result`.
   *
   * @param node Ponteiro para o nó atual.
   * @param result Vetor onde os valores visitados serão armazenados.
   */
  void post_order(const TreeNode* const node, std::vector<T>& result) const;

 public:
  /**
   * @brief Construtor da árvore (inicialmente vazia).
   */
  AVL();

  /**
   * @brief Destrutor da árvore, libera todos os nós.
   */
  ~AVL();

  /**
   * @brief Insere um novo valor na árvore.
   *
   * @param value Valor a ser inserido.
   * @return `true` se inserido com sucesso, `false` se o valor já existia.
   */
  bool insert(const T& value);

  /**
   * @brief Remove um valor da árvore.
   *
   * @param value Valor a ser removido.
   * @return `true` se o valor foi removido, `false` se não estava presente.
   */
  bool remove(const T& value);

  /**
   * @brief Verifica se um valor está presente na árvore.
   *
   * @param value Valor a ser verificado.
   * @return `true` se presente, `false` caso contrário.
   */
  bool contain(const T& value) const;

  /**
   * @brief Retorna os valores da árvore em ordem (in-order).
   *
   * Visita a subárvore esquerda, o nó atual e a subárvore direita.
   *
   * @return Vetor com os valores em ordem.
   */
  std::vector<T> in_order() const;

  /**
   * @brief Retorna os valores da árvore em pré-ordem (pre-order).
   *
   * Visita o nó atual, depois a subárvore esquerda e depois a direita.
   *
   * @return Vetor com os valores em pré-ordem.
   */
  std::vector<T> pre_order() const;

  /**
   * @brief Retorna os valores da árvore em pós-ordem (post-order).
   *
   * Visita a subárvore esquerda, depois a direita e por fim o nó atual.
   *
   * @return Vetor com os valores em pós-ordem.
   */
  std::vector<T> post_order() const;

  /**
   * @brief Verifica se a árvore está balanceada (propriedade da AVL).
   *
   * @return `true` se todos os nós estão balanceados, `false` caso contrário.
   */
  bool is_balanced() const { return is_balanced(root).first; }

  /**
   * @brief Verifica recursivamente se a subárvore está balanceada e retorna sua
   * altura.
   *
   * @param node Nó atual.
   * @return Par (está_balanceada, altura).
   */
  std::pair<bool, int> is_balanced(TreeNode* node) const {
    if (!node) return {true, -1};

    auto left = is_balanced(node->left);
    auto right = is_balanced(node->right);

    bool balanced =
        left.first && right.first && std::abs(left.second - right.second) <= 1;
    int node_height = 1 + std::max(left.second, right.second);

    return {balanced, node_height};
  }

 private:
  TreeNode* root;  ///< Ponteiro para a raiz da árvore.
};

template <class T>
int AVL<T>::height(TreeNode* node) const { //a altura de um nó é a quantidade de arestas no caminho mais longo até a folha 
  return node ? node->height : -1;
}

template <class T>
void AVL<T>::balance(TreeNode*& node) { //calcula o FB = altura da esquerda - altura da direita, tem q ser [-1, 0, 1]
    if (!node) return;

    int balance_factor = height(node->left) - height(node->right);

    if (balance_factor > 1) { 
        if (height(node->left->left) >= height(node->left->right)) {
            TreeNode* L = node->left;
            node->left = L->right;
            L->right = node;
            node = L;
        } else {
            TreeNode* L = node->left;
            TreeNode* LR = L->right;
            L->right = LR->left;
            LR->left = L;
            node->left = LR->right;
            LR->right = node;
            node = LR;
        }
    } else if (balance_factor < -1) {
        if (height(node->right->right) >= height(node->right->left)) {
            TreeNode* R = node->right;
            node->right = R->left;
            R->left = node;
            node = R;
        } else {
            TreeNode* R = node->right;
            TreeNode* RL = R->left;
            R->left = RL->right;
            RL->right = R;
            node->right = RL->left;
            RL->left = node;
            node = RL;
        }
    }
    
   //atualizar a altura 
    node->height = 1 + std::max(height(node->left), height(node->right));
}



template <class T>
AVL<T>::TreeNode::TreeNode(const T& value) : data (value), left(nullptr), right(nullptr), height(0){} //sempre que inserimos um novo valor, altura 0 pq ele nao tem filho 
  


template <class T>
AVL<T>::TreeNode::~TreeNode() { //se o filho tiver outros filhos, o destrutor daquele filho erá chamado automaticamente. Garante que toda a árvore seja deletada
  delete left;
  delete right;
}

template <class T>
typename AVL<T>::TreeNode* AVL<T>::TreeNode::max() { //encontra o nó com o valor maior em uma subárvore, o maior sempre a direita 
 TreeNode* current = this;
 while (current ->right != nullptr){
  current = current->right;
 }
 return current;
} 

template <class T>
typename AVL<T>::TreeNode* AVL<T>::TreeNode::min() { //encontra o  valor menor na subárvore, menor sempre a esquerda 
  TreeNode* current = this;
  while (current ->left!=nullptr){
    current = current->left;
  }
  return current;
}

template <class T>
AVL<T>::AVL() : root(nullptr){} //inicializa a raiz da árvore como vazia, sem nó

template <class T>
AVL<T>::~AVL() { //limpa toda a árvore 
  delete root; 
}

template <class T>
bool AVL<T>::insert(const T& value) {
  return insert(root, value);
}

template <class T>
bool AVL<T>::remove(const T& value) {
 return remove(root, value);
}

template <class T>
bool AVL<T>::contain(const T& value) const {
  return contain(root, value);
}

template <class T>
bool AVL<T>::insert(TreeNode*& node, const T& value) { //navega a árvore de forma recursiva, se o nó atual(node) for nulo, insere o novo valor aq(sendo menor para o esquerdo e o maior para a direita) se for igual retorna falso(não pode ter números iguais)
  if (!node){ //se o nó atual for nulo
    node = new TreeNode(value); //cria um novo nó com o valor 
    return true;

  }

  if (value==node->data){//se for o mesmo número 
    return false;
  }

  bool result = false; //se inseriu ou não
  if (value < node->data){ //se for menor, vai para a esquerda 
    result = insert(node->left, value);
    
  }else {
    result = insert(node->right, value); //se for maior vai para a direita 
  }

  if(result){
    node->height = 1 + std::max(height(node->left), height(node->right)); //atualiza a altura do nó 
    balance(node); //faz o balanceamento 
  }

  return result; //retorna o resultado sendo true ou false
}

template <class T>
bool AVL<T>::contain(const TreeNode* const node, const T& value) const { //navega a árvore para verificar se o valor existe 
   if(!node) return false; //árvore vazia 

   if (value == node->data) return true; //achou o valor 

   if(value < node->data){
    return contain(node->left, value); //busca a esquerda 

   }else {
    return contain(node->right, value); //busca a direita 
   }
}

template <class T>
bool AVL<T>::remove(TreeNode*& node, const T& value) { //navega pela árvore procurando o nó a ser removido
      if (!node) return false;  // não achou

    bool result = false;
    if (value < node->data) { //se for menor, busca na esquerda
        result = remove(node->left, value);
    } else if (value > node->data) { //se for maior, verifica na direita 
        result = remove(node->right, value);
    } else {  // achou!
        result = true;

        if (!node->left) { //caso tenha só filho a direita ou nenhum
            TreeNode* temp = node;
            node = node->right;
            temp->left = temp->right = nullptr;  // evita deletar subárvores
            delete temp;
        } else if (!node->right) {//caso só tenha filho na esquerda 
            TreeNode* temp = node;
            node = node->left;
            temp->left = temp->right = nullptr;
            delete temp;
        } else {  // dois filhos
            TreeNode* minRight = node->right->min();
            node->data = minRight->data;  // copia o valor do sucessor
            remove(node->right, minRight->data);  // remove o sucessor
        }
    }

    if (node) { //atualiza altura e balanceia 
        node->height = 1 + std::max(height(node->left), height(node->right));
        balance(node);
    }

    return result;
}

template <class T>
void AVL<T>::in_order(const TreeNode* const node,
                      std::vector<T>& result) const { //percorre a árvore e vai preenchendo o vetor result com os elementos em ordem crescente
    if (!node) return; //árvore vazia

    in_order(node->left, result); //percorre a esquerda
    result.push_back(node->data); //processa o nó
    in_order(node->right, result); //percorre a direita
   }

template <class T>
std::vector<T> AVL<T>::in_order() const {
  std::vector<T> result; //cria um vetor vazio para armazenar os elemnetos 
  in_order(root, result); //chama a função recursiva começando pela raiz 
  return result; //retornar o valor preenchido com os valores em ordem 
}

template <class T>
void AVL<T>::pre_order(const TreeNode* const node,
                       std::vector<T>& result) const { //percorre a árvore e vai armazenando os elementos no vetor result 
  if (!node) return; 

  result.push_back(node->data); //processa o nó atual
  pre_order(node->left, result);//percorre a subárvore da esquerda
  pre_order(node->right, result);//percorre a subárvore da direita 


  }

template <class T>
std::vector<T> AVL<T>::pre_order() const {
  std::vector<T> result; //cria um vetor vazio para armazenar os valores 
  pre_order(root, result);//chama a função recursiva a partir a partir da raiz
  return result; //retorna o vetor preenchido com os valores em pré-ordem 
}

template <class T>
void AVL<T>::post_order(const TreeNode* const node,
                        std::vector<T>& result) const {
  if(!node) return;

  post_order(node->left, result);//percorre a esquerda
  post_order(node->right, result);//percorre a direita 
  result.push_back(node->data);//processa o nó
                        }

template <class T>
std::vector<T> AVL<T>::post_order() const {
  std::vector<T> result;//cria um vetor vazio para armazenar os valores 
  post_order(root, result);//chama a função recursiva a partir da raiz 
  return result; //retorna o vetor preenchido com os valores em pos-ordem 
}
