// Heap

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int max(int a, int b) {
    return (a >= b)? a:b;
}

int fillCups(int* amount, int amountSize){
    qsort(amount, amountSize, sizeof(int), cmpfunc);
    int time = 0;
    while (1) {
        if (amount[2] == 0)
            break;
        
        amount[2]--; // here amount[2] must >= 1, can -= 1
        amount[1]--; // even though arr = [0, 0, 2] the time is still += 1 for single cup
        time++;
        qsort(amount, amountSize, sizeof(int), cmpfunc);
    }
    return time;
}