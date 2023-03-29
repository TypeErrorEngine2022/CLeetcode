#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    int key;
    int val;
} ht_item;

typedef struct {
    int index;
    int hasNext;
} HashTableIterator;

typedef struct {
    ht_item** items;
    int capacity;
    int size;
    HashTableIterator* iter;
} HashTableForInt;

HashTableIterator* createHashTableIterator() {
    HashTableIterator* iter = (HashTableIterator*)malloc(sizeof(HashTableIterator));
    iter -> index = -1;
    iter -> hasNext = 0;
    return iter;
}

ht_item* createHashItem(int key, int val) {
    ht_item* item = (ht_item*)malloc(2 * sizeof(ht_item));
    item -> key = key;
    item -> val = val;
    return item;
}

HashTableForInt* createHashTableForInt(int capacity) {
    HashTableForInt* table = (HashTableForInt*)malloc(sizeof(HashTableForInt));
    table -> items = (ht_item**)malloc(capacity * sizeof(ht_item*));
    memset(table -> items, 0, capacity * sizeof(ht_item*));
    table -> size = 0;
    table -> capacity = capacity;
    table -> iter = createHashTableIterator();
    return table;
}

void closeHashTableForInt(HashTableForInt* table) {
    for (int i = 0; i < table -> capacity; i++) {
        if (table -> items[i] == NULL) continue;
        free(table -> items[i]);
    }
    free(table -> items);
    free(table -> iter);
    free(table);
}

// quadratic probing
unsigned int hashInt(int key, int failureCt, int capacity) {
    int index = (key + (int)pow(failureCt, 2.0)) % capacity;
    return (index < 0)? -1 * index: index;
}

int isFullForHashTable(HashTableForInt* table) {
    return table -> size == table -> capacity;
}

int getCount(HashTableForInt* table) {
    return table -> size;
}

void insertForIntHashTable(HashTableForInt* table, int key, int val) {
    ht_item* item = createHashItem(key, val);
    int failureCt = 0;
    while (1) {
        if (failureCt > table -> capacity - 1) {
            //printf("not enough space to store\n");
            break;
        }
        int index = hashInt(key, failureCt, table -> capacity);
        ht_item* cur = table -> items[index];
        if (cur == NULL) {
            // does not exist
            if (isFullForHashTable(table)) {
                //printf("Hash table is full\n");
                free(item);
                return;
            }
            //printf("insert successfully at %d\n", index);
            table -> items[index] = item;
            table -> size += 1;
            break;
        }
        else if (cur -> key == key) {
            cur -> val = val; // update val if key exist
            break;
        }
        //printf("need to rehash\n");
        failureCt++;
    }
    return;
}

int getForIntHashTable(HashTableForInt* table, int key) {
    int failureCt = 0;
    while (1) {
        if (failureCt > table -> capacity - 1) {
            //printf("does not contain element with key %d\n", key);
            return 0;
        }
        int index = hashInt(key, failureCt, table -> capacity);
        ht_item* cur = table -> items[index];
        if (cur == NULL) {
            // does not exist
            //printf("does not contain element with key %d\n", key);
            return 0;
        }
        else if (cur -> key == key) {
            return cur -> val;
        }
        failureCt++;
    }
    return 0;
}

void deleteForIntHashTable(HashTableForInt* table, int key) {
    int failureCt = 0;
    while (1) {
        if (failureCt > table -> capacity - 1) {
            //printf("does not contain element with key %d\n", key);
            break;
        }
        int index = hashInt(key, failureCt, table -> capacity);
        ht_item* cur = table -> items[index];
        if (cur == NULL) {
            // does not exist
            //printf("does not contain element with key %d\n", key);
            return;
        }
        else if (cur -> key == key) {
            free(cur);
            cur = NULL;
            table -> items[index] = NULL;
            table -> size -= 1;
            return;
        }
        failureCt++;
    }
    return; 
}

void printHashTableForInt(HashTableForInt* table) {
    printf("Hash Table: ");
    for (int i = 0; i < table -> capacity; i++)
    {
        if (table -> items[i] == NULL) continue;
        printf("(Index: %d, Key:%d, Val:%d) ", i, table -> items[i] -> key, table -> items[i] -> val);
    } 
    printf("\n");
    return;
}

// will update iter index to index of next available element
int hasNextForIntHashTable(HashTableForInt* table) {
    HashTableIterator* iter = table -> iter;
    int hasNext = 0;
    for (int i = iter -> index + 1; i < table -> capacity; i++) {
        if (table -> items[i] == NULL) 
            continue;

        iter -> index = i; // next available element
        hasNext = 1;
        break;
    } 
    return hasNext;
}

ht_item* nextElement(HashTableForInt* table) {
    return table -> items[table -> iter -> index];
}

