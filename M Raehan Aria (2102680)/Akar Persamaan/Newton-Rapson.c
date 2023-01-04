// Muhamad Raehan Aria Pratama
// 2102680
// Pilkom A 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
    // Ubah fungsi f(x) di sini
    return x * x * x - 3 * x - 20;
}

double f_turunan(double x){
    // Ubah turunan fungsi f(x) di sini
    return (3 * x * x) - 3;
}

int main(){
    double x = 5;          // Nilai awal x
    double epsilon = 1e-9; // Toleransi error
    int max_iter = 100;    // Maksimum iterasi
    int iter;              // Iterasi saat ini

    // Hitung akar persamaan dengan metode Newton-Rapson
    for (iter = 0; iter < max_iter; iter++){
        double x_prev = x;
        x = x - f(x) / f_turunan(x);
        if (fabs(x - x_prev) < epsilon){
            // Jika error sudah dibawah toleransi, keluar dari loop/program akan berhenti
            break;
        }
    }

    // Cetak hasil perhitungan
    // Menampilkan nilai akar yang ditemukan
    printf("Akar persamaan adalah: %f\n", x);

    // Menampilkan iterasi ke berapa saat akar ditemukan
    printf("Ditemukan setelah %d iterasi.\n", iter + 1);

    return 0;
}
