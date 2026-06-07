#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>

using namespace std;
using namespace chrono;

int main()
{
    const int SIZE = 100000000;

    vector<long long> data(SIZE, 1);

    long long sequential_sum = 0;

    auto start_seq = high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++)
    {
        sequential_sum += data[i];
    }

    auto end_seq = high_resolution_clock::now();

    double seq_time =
        duration<double>(end_seq - start_seq).count();

    long long parallel_sum = 0;

    auto start_par = high_resolution_clock::now();

#pragma omp parallel for reduction(+ : parallel_sum)
    for (int i = 0; i < SIZE; i++)
    {
        parallel_sum += data[i];
    }

    auto end_par = high_resolution_clock::now();

    double par_time =
        duration<double>(end_par - start_par).count();

    cout << "Sequential Sum : "
         << sequential_sum << endl;

    cout << "Parallel Sum   : "
         << parallel_sum << endl;

    cout << "Sequential Time : "
         << seq_time << " sec" << endl;

    cout << "Parallel Time   : "
         << par_time << " sec" << endl;

    cout << "Speedup : "
         << seq_time / par_time << "x" << endl;

    return 0;
}