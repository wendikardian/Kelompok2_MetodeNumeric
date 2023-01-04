// Muhamad Raehan Aria Pratama
// 2102680
// Pilkom A 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fungsi yang akan diintegrasikan
double f(double x)
{
    return x * x;
}

int main()
{
    double a, b, h, integral;
    int n, i;

    // Batasan integral
    // Batas bawah
    a = 0.0;
    // Batas Atas
    b = 3.0;

    // Jumlah interval
    n = 10;

    // Jarak antara titik-titik pembagian
    h = (b - a) / n;

    // Hitung integral dengan metode trapezoidal
    integral = (f(a) + f(b)) / 2.0;
    // Melakukan perulangan sebanyak n atau jumlah interval
    for (i = 1; i < n; i++)
    {
        // Menambahkan nilai perkiraan sampai perulangan berhenti
        integral += f(a + i * h);
    }

    // mengalikan nilai perkiraan dari jarak antara titik-titik pembagian
    integral = integral * h;

    // Menampilkan hasil integral
    printf("Hasil integral: %f\n", integral);

    return 0;
}
