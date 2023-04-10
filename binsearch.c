#include <stdio.h>
#include <time.h>

// Your binsearch function here

int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 7;

    clock_t start, end;
    double cpu_time_used;
    int runs = 10000;
    int result;

    start = clock();
    for (int i = 0; i < runs; i++) {
        result = binsearch(x, v, n);
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / (CLOCKS_PER_SEC * runs);

    printf("Element found at index: %d\n", result);
    printf("Average time taken per run: %f seconds\n", cpu_time_used);

    return 0;
}

int binsearch( int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while ( low <= high ){
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid -1;
        else if (x > v[mid])
            low = mid +1;
        else 
            return mid;
    }
    return -1; /*no match*/
}
