#include <iostream>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numbers>
#include <vector>

const int N = 4e6;
const int M = 6e5;
const auto PI = acos(-1.0);
std::complex<double> A[N], B[N];



void FFT(std::complex<double>* A, int n, int op)
{
    if (n == 1)
    {
        return;
    }
    const int mid = n/2;
    std::complex<double> *A1 = new std::complex<double>[mid];
    std::complex<double> *A2 = new std::complex<double>[mid];
    for (int i = 0; i < n / 2; i++)
    {
        A1[i] = A[i * 2];
        A2[i] = A[i * 2 + 1];
    }
    FFT(A1, mid, op);
    FFT(A2, mid, op);
    std::complex<double> w1({cos(2 * PI / n), sin(2 * PI / n) * op});
    std::complex<double> wk({1, 0});
    for (int i = 0; i < n / 2; i++)
    {
        A[i] = A1[i] + A2[i] * wk;
        A[i + n / 2] = A1[i] - A2[i] * wk;
        wk = wk * w1;
    }
    delete[] A1;
    delete[] A2;
}

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n-1; ++i)
    {
        double x;
        scanf("%lf", &x);
        A[i].real(x);
    }
    for (int i = 0; i <= m-1; ++i)
    {
        double x;
        scanf("%lf", &x);
        B[i].real(x);
    }
    for (m = n + m - 1, n = 1; n <= m; n <<= 1)
        ;
    FFT(A, n, 1);
    FFT(B, n, 1);
    for (int i = 0; i < n; i++)
    {
        A[i] = A[i] * B[i];
    }
    FFT(A, n, -1);
    for (int i = 0; i <= m-1; i++)
    {
        printf("%d ", (int)((A[i].real()) / n + 0.5));
    }
}
