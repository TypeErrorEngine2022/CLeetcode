#include "HashTableForInt.h"

int main() {
    HashTableForInt* table = createHashTableForInt(10);
    insertForIntHashTable(table, 10, 1);
    insertForIntHashTable(table, 2, 3);
    insertForIntHashTable(table, 10, 2);
    insertForIntHashTable(table, 22, 3);
    insertForIntHashTable(table, 20, 4);
    insertForIntHashTable(table, 30, 4);
	insesdsdjnjnsd
    printHashTableForInt(table);
    deleteForIntHashTable(table, 30);
    printHashTableForInt(table);
    while (hasNextForIntHashTable(table)) {
        ht_item* item = nextElement(table);
        printf("(Key: %d, Val: %d) ", item -> key, item -> val);
    }
    printf("\n");
    insertForIntHashTable(table, 9, 3);
    printHashTableForInt(table);
    closeHashTableForInt(table);
    return 0;
}
