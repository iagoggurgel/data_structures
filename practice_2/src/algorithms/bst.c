#include "alg.h"

struct Node 
{

    int data;
    struct Node * left;
    struct Node * right;

} typedef Node;

Node * createNode(int);
Node * insert(Node *, int );
Node * search(Node *, int);
Node * generateBST(int);
void destroyBST(Node *);
void testBST();

/*
    Função para alocar um nó da árvore
*/
Node * createNode(int data) 
{
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*
    Função para inicializar ou inserir um nó na árvore de forma ordenada
*/
Node * insert(Node * root, int data) 
{
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

/*
    Função para buscar um nó na árvore
*/
Node * search(Node * root, int key) 
{
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

/*
    Desaloca completamente uma árvore
*/
void destroyBST(Node * root) 
{
    if (root != NULL) {
        destroyBST(root->left);
        destroyBST(root->right);
    }
    free(root);
}


/*
    Função para gerar uma árvore pseudo-aleatória
*/
Node * generateBST(int n)
{
    Node * root = insert(NULL, rand());

    for (int i = 0; i < n; i++)
    {
        insert(root, rand());
    }

    return root;
}

void testBST()
{

    Node * root;

    FILE * fp = fopen("results/bst.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < TESTCASES; i++)
    {
        int numberOfInputs = (((GROWTHRATE * i) + 1) % 1048576);

        root = generateBST(numberOfInputs);

        startClock();
        search(root, rand());
        endClock();

        diffTime(fp, numberOfInputs);

        destroyBST(root);
        
    }

    fclose(fp);
}

int main()
{
    testBST();
}