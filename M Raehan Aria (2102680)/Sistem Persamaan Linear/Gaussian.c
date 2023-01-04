// Muhamad Raehan Aria Pratama
// 2102680
// Pilkom A 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// jumlah variabel
#define N 3 

// jumlah persamaan
#define M 3 

// Fungsi untuk mencari nilai pivot
int pivot(double a[M][N], int k){
    int i, p = k;
    double t = fabs(a[k][k]);
    for (i = k + 1; i < M; i++){
        if (fabs(a[i][k]) > t){
            p = i;
            t = fabs(a[i][k]);
        }
    }
    return p;
}

// Fungsi untuk melakukan eliminasi Gauss
void gauss(double a[M][N], double x[N]){
    int i, j, k, p;
    double t;

    for (k = 0; k < N - 1; k++){
        // Mencari nilai pivot
        p = pivot(a, k);
        // Menukar baris jika diperlukan
        if (p != k){
            for (j = k; j < N; j++){
                t = a[k][j];
                a[k][j] = a[p][j];
                a[p][j] = t;
            }

            t = x[k];
            x[k] = x[p];
            x[p] = t;
        }
        // Melakukan eliminasi Gauss
        for (i = k + 1; i < M; i++){
            t = a[i][k] / a[k][k];
            x[i] -= t * x[k];
            for (j = k + 1; j < N; j++){
                a[i][j] -= t * a[k][j];
            }
        }
    }
}

int main(){
    double a[M][N] = {
        {3, -2, 1},
        {2, 3, -2},
        {1, -1, 2}
    };

    double x[N] = {4, 3, -1};

    gauss(a, x);

    // Mencetak hasilnya
    printf("Hasilnya adalah:\n");
    for (int i = 0; i < N; i++){
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    return 0;
}
