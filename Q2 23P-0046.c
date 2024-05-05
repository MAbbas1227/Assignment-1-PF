#include <stdio.h>
int collatzSequenceLength(long long n) {
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        length++;
    }
    return length;
}
void longestCollatzSequence(long long N) {
    long long longestStart = 0;
    int maxLength = 0;
    
    for (long long i = 2; i < N; i++) {
        int length = collatzSequenceLength(i);
        if (length > maxLength) {
            maxLength = length;
            longestStart = i;
        }
    }
    
    printf("Number with the longest Collatz sequence under %lld is %lld, a length of %d.\n", N, longestStart, maxLength);
}

int main() {
    long long N;
    printf("Enter the upper limit N: ");
    scanf("%lld", &N);

    longestCollatzSequence(N);
    
    return 0;
}
