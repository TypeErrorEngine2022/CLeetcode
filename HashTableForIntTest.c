#include "HashTableForInt.h"

int main() {
    HashTableForInt* table = createHashTableForInt(10);
    insertForIntHashTable(table, 10, 1);
    insertForIntHashTable(table, 2, 3);
    insertForIntHashTable(table, 10, 2);
    insertForIntHashTable(table, 22, 3);
    insertForIntHashTable(table, 20, 4);
    insertForIntHashTable(table, 30, 4);
    printHashTableForInt(table);
    deleteForIntHashTable(table, 30);
    printHashTableForInt(table);
    HashTableIterator* iter = createHashTableIterator();
    for (int i = 0; i < 3; i++) {
        ht_item* item = nextElement(table, iter);
        printf("(Key: %d, Val: %d) ", item -> key, item -> val);
    }
    printf("\n");
    closeHashTableIterator(iter);
    closeHashTableForInt(table);
    return 0;
}