// Muhamad Raehan Aria Pratama
// 2102680
// Pilkom A 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fungsi yang akan dijadikan persamaan
double f(double x)
{
    // fungsi f(x) yang akan dipakai
    return x * x - 2;
}

int main()
{
    double a, b, c;
    int iterasi = 0;
    double toleransi = 1e-9;

    // Batas-batas interval
    a = 1.0;
    b = 2.0;

    // Iterasi sampai mencapai toleransi yang ditentukan
    while (fabs(a - b) > toleransi)
    {
        c = (a + b) / 2;

        // Jika f(c) = 0 maka akarnya adalah c
        if (f(c) == 0.0)
            break;
        // interval B diganti dengan interval baru
        else if (f(c) * f(a) < 0)
            b = c;
        // interval A diganti dengan interval baru
        else
            a = c;

        // Iterasi terus berlanjut
        iterasi++;
    }

    // Menampilkan nilai akar yang ditemukan
    printf("Akar terletak di x = %lf\n", c);

    // Menampilkan iterasi ke berapa saat akar ditemukan
    printf("Ditemukan dalam %d iterasi\n", iterasi);

    return 0;
}
