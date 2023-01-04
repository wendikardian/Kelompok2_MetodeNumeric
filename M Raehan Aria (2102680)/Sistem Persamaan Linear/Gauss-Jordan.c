// Muhamad Raehan Aria Pratama
// 2102680
// Pilkom A 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100

int main(){
    int n;
    double a[MAX_N][MAX_N + 1]; // matriks augmented

    // Membaca sistem persamaan linear
    printf("Masukkan jumlah variabel: ");
    scanf("%d", &n);
    printf("Masukkan koefisien-koefisien dari sistem persamaan linear:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%lf", &a[i][j]);

    // Mencari solusi dengan metode Gauss-Jordan
    for (int i = 0; i < n; i++)
    {
        // Mencari pivot
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(a[j][i]) > fabs(a[pivot][i]))
                pivot = j;

        // Menukar baris-baris jika diperlukan
        if (pivot != i)
        {
            for (int j = 0; j <= n; j++)
            {
                double temp = a[i][j];
                a[i][j] = a[pivot][j];
                a[pivot][j] = temp;
            }
        }

        // Menghilangkan elemen-elemen di bawah pivot
        for (int j = i + 1; j < n; j++)
        {
            double f = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++)
                a[j][k] -= f * a[i][k];
        }
    }

    // Menghitung solusi sistem persamaan linear
    double x[MAX_N]; // solusi sistem persamaan linear
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    // Menampilkan solusi sistem persamaan linear
    printf("Solusi sistem persamaan linear:\n");
    for (int i = 0; i < n; i++)
        printf("x[%d] = %lf\n", i, x[i]);

    return 0;
}
