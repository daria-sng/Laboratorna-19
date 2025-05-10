#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N1 4
#define N2 5

void inputs (double array[], int N);
void calculation (double array[], int N, double function1(double), double function2 (double), double *p1, double *p2);

int main(){
    system("chcp 65001");
    double a[N1], b[N2], A, B, C, D, gamma;
    inputs(a, N1);
    inputs(b, N2);

    calculation(a, N1, sin, tan, &A, &B);
    calculation(b, N2, cos, sin, &D, &C);

    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("D = %lf\n", D);
    printf("C = %lf\n", C);

    if(sin(D)+sin(C)>0){
        gamma = (A+B)/(sin(D)+sin(C));
        printf("Результат гамми: %lf\n", gamma);
    }
    else{
        printf("Увага! Знаменник sin(D)+sin(C)=0, спробуйте інші значення!");
    }
    return 0;
}

void inputs (double array[], int N){
    int i;
    printf("Введіть значення елементів у масив (Розміри - 4, 5): ");
    for(i=0; i<N; i+=1){
        scanf("%lf", &array[i]);
    }
}

void calculation (double array[], int N, double function1(double), double function2 (double), double *p1, double *p2){
    double s = 0;
    double p = 1;
    *p1 = 0;
    *p2 = 0;
    int i;
    for(i=0; i<N; i+=1){
        s+=array[i];
        p*=array[i];
    }
    for(i=0; i<N; i+=1){
        if(array[i]<=0){
            *p1+=array[i]*function1(array[i]);
        }
        else{
            *p2+=array[i]*function2(array[i]);
        }
    }
    *p1 *=s;
    *p2 *=p;
}