/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void calculate_prefix_sum(int *sequence, int *prefix_sum, int N) {
    prefix_sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + sequence[i - 1];
    }
}


void handle_queries(int *prefix_sum, int Q, int queries[][2]) {
    for (int i = 0; i < Q; i++) {
        int L = queries[i][0];
        int R = queries[i][1];
        int range_sum = prefix_sum[R] - prefix_sum[L - 1];
        printf("%d\n", range_sum);
    }
}

int main() {
    int N, Q;
    

    scanf("%d", &N);
    

    int *sequence = (int *)malloc(N * sizeof(int));
    int *prefix_sum = (int *)malloc((N + 1) * sizeof(int));
    

    for (int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
    }
    

    calculate_prefix_sum(sequence, prefix_sum, N);
    

    scanf("%d", &Q);
    

    int queries[Q][2];
    

    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &queries[i][0], &queries[i][1]);
    }
    
    handle_queries(prefix_sum, Q, queries);
    
    free(sequence);
    free(prefix_sum);
    
    return 0;
}
