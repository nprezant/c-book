#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Exercise 3-1. Our binary search makes two tests inside the loop, when
 * one would suffice (at the price of more tests outside.) Write a version
 * with only one test inside the loop and measure the difference in run-time.
 *
 * Results:
 * Using `perf stat -d -r 10 ./3-01_binsearch.out <type>`
 * Repeat: 10 times
 * Extra details
 *
 * kr:
 *   - 3 branches in while loop
 *   - 168.83 msec
 *   - 444.66 million cycles
 *   - 71.4 million branches
 *   - 2.6 million branch misses
 *   - 225 million L1-dcache-loads
 *
 * np:
 *   - 2 branches in while loop
 *   - 184.45 msec
 *   - 484.46 million cycles
 *   - 57.9 million branches
 *   - 3.8 million branch misses
 *   - 204 million L1-dcache-loads
 *
 * I was originally surprised that the 2-branch option was slower than the
 * 3-branch option. However, I think it makes sense. The 3-branch binary
 * search is faster because of its early exit: it checks each time if the
 * midpoint is the target value, and exits if it is. Whereas, the 2-branch
 * option requires that the binary search converge on a single point before
 * returning.
 *
 * This rationale is supported by the `perf stat` details. We can see that
 * the 3-branch option has 40 million less cpu cycles than the 2-branch
 * option.
 */

#define VECSIZE 8
#define DEFAULT_PERF_VEC_SIZE 1000000

int binsearch_kr(int x, int v[], int n);
int binsearch(int x, int v[], int n);

void general_test()
{
    int v[VECSIZE] = { 0, 1, 2, 3, 4, 5, 6, 7 };

    printf("Testing binsearch\n");
    printf("Found %d at index %d\n", 0, binsearch(0, v, VECSIZE));
    printf("Found %d at index %d\n", 1, binsearch(1, v, VECSIZE));
    printf("Found %d at index %d\n", 2, binsearch(2, v, VECSIZE));
    printf("Found %d at index %d\n", 3, binsearch(3, v, VECSIZE));
    printf("Found %d at index %d\n", 4, binsearch(4, v, VECSIZE));
    printf("Found %d at index %d\n", 5, binsearch(5, v, VECSIZE));
    printf("Found %d at index %d\n", 6, binsearch(6, v, VECSIZE));
    printf("Found %d at index %d\n", 7, binsearch(7, v, VECSIZE));

    printf("Cannot find %d (should be -1): %d\n", -1, binsearch(-1, v, VECSIZE));
    printf("Cannot find %d (should be -1): %d\n", 8, binsearch(8, v, VECSIZE));
    printf("Cannot find %d (should be -1): %d\n", 9, binsearch(9, v, VECSIZE));

    printf("\n");
    printf("Testing binsearch_kr\n");
    printf("Found %d at index %d\n", 0, binsearch_kr(0, v, VECSIZE));
    printf("Found %d at index %d\n", 1, binsearch_kr(1, v, VECSIZE));
    printf("Found %d at index %d\n", 2, binsearch_kr(2, v, VECSIZE));
    printf("Found %d at index %d\n", 3, binsearch_kr(3, v, VECSIZE));
    printf("Found %d at index %d\n", 4, binsearch_kr(4, v, VECSIZE));
    printf("Found %d at index %d\n", 5, binsearch_kr(5, v, VECSIZE));
    printf("Found %d at index %d\n", 6, binsearch_kr(6, v, VECSIZE));
    printf("Found %d at index %d\n", 7, binsearch_kr(7, v, VECSIZE));

    printf("Cannot find %d (should be -1): %d\n", -1, binsearch_kr(-1, v, VECSIZE));
    printf("Cannot find %d (should be -1): %d\n", 8, binsearch_kr(8, v, VECSIZE));
    printf("Cannot find %d (should be -1): %d\n", 9, binsearch_kr(9, v, VECSIZE));
}

void initvec(int v[], int start, int count)
{
    int i;
    for (i = 0; i < count; ++i)
        v[i] = start++;
}

void performance_test_kr(int vec_size)
{
    int x;
    int v[vec_size];
    initvec(v, 0, vec_size);
    for (x = 0; x < vec_size; ++x) {
        binsearch_kr(x, v, vec_size);
    }
}

void performance_test_np(int vec_size)
{
    int x;
    int v[vec_size];
    initvec(v, 0, vec_size);
    for (x = 0; x < vec_size; ++x) {
        binsearch(x, v, vec_size);
    }
}

int main(int argc, char** argv)
{
    int vec_size;

    /* First arg is file name. */
    if (argc == 1) {
        general_test();
    }

    /* If we have more inputs, they should be for the performance tests */
    else if (argc > 1) {
        /* Read performance vector size (or use default) */
        if (argc < 3)
            vec_size = DEFAULT_PERF_VEC_SIZE;
        else
            vec_size = atoi(argv[2]);

        /* Choose and perform test */
        if (strcmp(argv[1], "kr") == 0) {
            performance_test_kr(vec_size);
        }
        else if (strcmp(argv[1], "np") == 0) {
            performance_test_np(vec_size);
        }
        else {
            printf("Command not recognized. Expected \"kr\" or \"np\". Got \"%s\"\n", argv[1]);
        }
    }
}

int binsearch_kr(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;

    /* helpful print statements in the loop
    printf("[%2d, %2d], mid=%2d\n", low, high, mid);
    printf("\t-->[%2d, %2d]\n", low, high);
    */

    /* Keep looking until we find it */
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    mid = (low + high) / 2;
    if (v[mid] == x)
        return mid;
    return -1; /* no match */
}
