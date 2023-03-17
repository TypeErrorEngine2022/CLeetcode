#include "Heap.h"
#include <stdio.h>

void testInsert() {
    Heap* heap = createMaxHeap(5);
    for (int i = 5; i >= 1; i--) {
        insert(heap, i);
    }
    print(heap);
}

int main() {
    testInsert();
}