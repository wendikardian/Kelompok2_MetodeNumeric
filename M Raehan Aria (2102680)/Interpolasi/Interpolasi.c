// Muhamad Raehan Aria Pratama
// 2102680
// Pilkom A 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, i, j;
    double x[100], y[100], p, q;

    // Untuk menginput banyaknya nilai x dan y
    printf("Masukkan banyaknya nilai (x, y): ");
    scanf("%d", &n);

    // Untuk memasukan nilai-nilai x dan y
    printf("Masukkan nilai (x, y):\n");
    for (i = 0; i < n; i++){
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Menginput nilai interpolasi yang ingin dicari
    printf("Masukkan nilai x yang ingin dicari nilai y-nya: ");
    scanf("%lf", &p);

    q = 0;
    for (i = 0; i < n; i++){
        double interp = y[i];
        for (j = 0; j < n; j++){
            if (i != j){
                interp = interp * (p - x[j]) / (x[i] - x[j]); // Rumus interpolasi Langrange
            }
        }
        q = q + interp;
    }

    printf("Nilai y untuk x = %lf adalah %lf\n", p, q);

    return 0;
}
