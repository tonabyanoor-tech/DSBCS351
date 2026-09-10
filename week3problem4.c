//Factorial//
#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Factorial = %d", factorial(n));

    return 0;
}

//Fibonacci//
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        printf("%d ", fibonacci(i));

    return 0;
}

//GCD//
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    printf("GCD = %d", gcd(a, b));

    return 0;
}

//Sum of Digits//
#include <stdio.h>

int sum(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sum(n / 10);
}

int main() {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Sum of digits = %d", sum(n));

    return 0;
}