#include "HashTableForInt.h"
#include "ArrayList.h"

typedef struct {
	HashTableForInt* hashTable;
	ArrayList* queue;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
	LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
	obj -> hashTable = createHashTableForInt(capacity);
	obj -> queue = createArrayList(capacity);
	return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
	int res = getForIntHashTable(obj -> hashTable, key); 
	obj -> queue
}

void lRUCachePut(LRUCache* obj, int key, int value) {

}

void lRUCacheFree(LRUCache* obj) {

}
