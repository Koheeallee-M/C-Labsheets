#include <stdio.h>
#include <math.h>

#define MAX_TERMS 100

double factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double sin(double x, int terms) {
    double result = 0.0;
    int sign = 1;

    for (int i = 1; i <= terms; i++) {
        result += sign * pow(x, 2 * i - 1) / (double)factorial(2 * i - 1);
        sign = -sign;
    }

    return result;
}

double cos(double x, int terms) {
    double result = 1.0;
    int sign = -1;

    for (int i = 1; i <= terms; i++) {
        result += sign * pow(x, 2 * i) / (double)factorial(2 * i);
        sign = -sign;
    }

    return result;
}

int main() {
    double x, result_sin, result_cos;
    int terms;

    printf("Enter the value of x in radians: ");
    scanf("%lf", &x);

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    result_sin = sin(x, terms);
    result_cos = cos(x, terms);

    printf("sin(%.2f) = %.6f\n", x, result_sin);
    printf("cos(%.2f) = %.6f\n", x, result_cos);

    return 0;
}
