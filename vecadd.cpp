#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>
#include <omp.h>

// function to add elements of two vectors
void add (int n, float *x, float *y)
{
    for (int i = 0; i < n; i++)
        y[i] = x[i] + y[i];
}

int main ()
{
    //int N = 1 << 23; // 8 million elements
    int N = 1 << 20; // 8 million elements

    std::cout << "Doing vector addition of " << N << " elements.\n";

    float *x = new float[N];
    float *y = new float[N];

    for (int i = 0; i < N; i++)
    {
        x[i] 1.0f;
        y[i] = 2.0f;
    }

    std::cout << std::fixed << std::setprecision(5);
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();
    add(N, x, y);
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "Elapsed time is: " << elapsed.count() " sec. or " << elapsed.count()*1000 << " ms\n";

    // check for error - all values should be 3.0f
    float maxerror = 0.0f;
    for (int i = 0; i < N; i++)
    {
        maxerror = fmax(maxerror, fabs(y[i] - 3.0f));
    }

    std::cout << "Max error: " << maxerror << std::endl;

    delete [] x;
    delete [] y;

    return 0;
}