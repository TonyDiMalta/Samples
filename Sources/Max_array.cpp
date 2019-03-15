void maxArray(double* x, double* y)
{
    for (int i = 0; i < 65536; i++)
    {
        if (y[i] > x[i]) x[i] = y[i];
    }
}

// Compile with -O3 -march=native to see autovectorization
#ifdef __GNUC__ //gcc specific
    typedef double __attribute__((aligned(64))) aligned_double;
#elif _MSC_VER //vc++ specific
    typedef double __declspec(align(64)) aligned_double;
#endif

void maxArray2(aligned_double* __restrict x, aligned_double* __restrict y)
{
    for (int i = 0; i < 65536; ++i)
    {
        x[i] = ((y[i] > x[i]) ? y[i] : x[i]);
    }
}
