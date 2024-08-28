#include "alg.h"

struct BinaryNode 
{

    int data;
    struct BinaryNode * left;
    struct BinaryNode * right;

} typedef BinaryNode;

BinaryNode * create(int);
BinaryNode * insert(BinaryNode *, int);
BinaryNode * search(BinaryNode *, int);
void destroyBTree(BinaryNode *);
BinaryNode * generateBTree(int);
void testBTree();

/*
    Função para alocar um nó da árvore binária
*/
BinaryNode * create(int data) 
{
    BinaryNode * newNode = (BinaryNode *) malloc(sizeof(BinaryNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*
    Função para inserir um nó na árvore binária
*/
BinaryNode * insert(BinaryNode * root, int data) 
{

    if (root == NULL) {
        return create(data);
    }
    if (root->left == NULL) {
        root->left = create(data);
    } else if (root->right == NULL) {
        root->right = create(data);
    } else {
        if (rand() % 2) {
            insert(root->left, data);
        } else {
            insert(root->right, data);
        }
    }

    return root;
}

/*
    Função para buscar um nó na árvore binária
*/
BinaryNode * search(BinaryNode * root, int key) 
{
    if (root == NULL || root->data == key) {
        return root;
    }

    BinaryNode * found = search(root->left, key);
    if (found == NULL) {
        found = search(root->right, key);
    }

    return found;
}

/*
    Desalocar completamente a árvore binária
*/
void destroyBTree(BinaryNode * root) 
{
    if (root != NULL) {
        destroyBTree(root->left);
        destroyBTree(root->right);
    }
    free(root);
}

/*
    Função para gerar uma árvore pseudo-aleatória
*/
BinaryNode * generateBTree(int n)
{
    BinaryNode * root = insert(NULL, rand());

    for (int i = 0; i < n; i++)
    {
        insert(root, rand());
    }

    return root;
}

void testBTree()
{

    BinaryNode * root;

    FILE * fp = fopen("results/btree.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < (TESTCASES >> 1); i++)
    {
        int numberOfInputs = ((((GROWTHRATE >> 1) * i) + 1) % 262144);

        root = generateBTree(numberOfInputs);

        startClock();
        search(root, rand());
        endClock();

        diffTime(fp, numberOfInputs);

        destroyBTree(root);
        
    }

    fclose(fp);
}

int main()
{
    testBTree();
}