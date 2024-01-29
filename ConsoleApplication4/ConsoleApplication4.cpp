// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 400
#define mostrar 5

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando arreglos en paralelo... \n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }
    int pedazos = chunk;

 #pragma omp parallel for \
 shared(a, b, c, pedazos) private(i) \
 schedule (static, pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    std::cout << "\n\nImprimiendo los primeros " << mostrar << " valores del arreglo a: \n" << std::endl;
    imprimeArreglo(a);
    std::cout << "\n\nImprimiendo los primeros " << mostrar << " valores del arreglo b: \n" << std::endl;
    imprimeArreglo(b);
    std::cout << "\n\nImprimiendo los primeros " << mostrar << " valores del arreglo c: \n" << std::endl;
    imprimeArreglo(c);

}

    void imprimeArreglo(float* d)
    {
        for (int x = 0; x < mostrar; x++)
            std::cout << d[x] << " - ";
        std::cout << std::endl;
    }



