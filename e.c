/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    long long int n, i;
    long double e = 1.0L;
    long long int factorial = 1;

    scanf("%lld", &n);

    for (i = 1; i <= n; i++) {
        factorial *= i; 
        e += 1.0L / factorial;
    }

    printf("%1.8Lf\n", e);
    return 0;
}