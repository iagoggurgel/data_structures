#include "alg.h"

#define TABLE_SIZE 131072

/*
    Estrutura do item de uma tabela de dispersão

    Tamanho: INT + INT + POINTER = 16

*/
struct HashItem 
{

    int key;
    int value;
    struct HashItem * next;

} typedef HashItem;


/*
    Estrutura do item de uma tabela de dispersão

    Tamanho: TABLE[131072] * POINTER * HASHITEM = 1048576 * 16 = 16777216 = 16MB

*/
struct HashTable 
{

    struct HashItem * table[TABLE_SIZE];

} typedef HashTable;


int hashFunction(int);
HashItem * createHashItem(int, int);
HashTable * createHashTable();
void insertHashTable(HashTable * , int, int);
int searchHashTable(HashTable * , int);
void destroyHashTable(HashTable *);
void destroyHashItem(HashItem *);
void testHashTable();
HashTable * generateHashTable(int);

/*
    Função de hash baseada no módulo da chave pelo tamanho da tabela.
*/
int hashFunction(int key) 
{
    return key % TABLE_SIZE;
}

/*
    Função para alocar um HashItem
*/
HashItem * createHashItem(int key, int value) 
{
    HashItem * newItem = (HashItem *) malloc(sizeof(HashItem));
    newItem->key = key;
    newItem->value = value;
    newItem->next = NULL;
    return newItem;
}

/*
    Função para inicializar uma tabela de dispersão.
*/
HashTable * createHashTable() 
{
    HashTable * hashTable = (HashTable *) malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

/*
    Função para inserir um HashItem na tabela de dispersão.
*/
void insertHashTable(HashTable * hashTable, int key, int value) 
{
    int hashIndex = hashFunction(key);
    HashItem * newItem = createHashItem(key, value);

    if (hashTable->table[hashIndex] == NULL) {
        hashTable->table[hashIndex] = newItem;
    } else {
        HashItem * temp = hashTable->table[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

/*
    Função para buscar um HashItem na tabela de dispersão.
*/
int searchHashTable(HashTable * hashTable, int key) 
{
    int hashIndex = hashFunction(key);
    HashItem * temp = hashTable->table[hashIndex];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }

    return -1;
}

/*
    Função para desalocar uma tabela de dispersão de forma completa.
*/
void destroyHashTable(HashTable * hashTable) 
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable->table[i] != NULL)
        {
            destroyHashItem(hashTable->table[i]);
        }
    }
    
    free(hashTable);
}

/*
    Função para desalocar completamente um HashItem.
*/
void destroyHashItem(HashItem * hashItem) 
{
    if (hashItem == NULL) 
    {
        return;
    } 
    else 
    {
        HashItem * temp = hashItem;
        HashItem* last = hashItem;
        while (temp->next != NULL) {
            temp = temp->next;
            free(last);
            last = temp;
        }
        free(last);
    }
}

void testHashTable()
{

    HashTable * hashTable;

    FILE * fp = fopen("results/hashTable.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < TESTCASES; i++)
    {
        int numberOfInputs = (((GROWTHRATE * i) + 1) % 1048576);

        hashTable = generateHashTable(numberOfInputs);

        startClock();
        searchHashTable(hashTable, rand());
        endClock();

        diffTime(fp, numberOfInputs);

        destroyHashTable(hashTable);
        
    }

    fclose(fp);
}

HashTable * generateHashTable(int n)
{
    HashTable * hashTable = createHashTable();

    for (int i = 0; i < n; i++)
    {
        insertHashTable(hashTable, rand(), rand());
    }
    
    return hashTable;
}

int main()
{
    testHashTable();
}