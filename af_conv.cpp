#include "af_conv.cpp"
#include <stdio.h>
#include <arrayfire.h>
#include <af/utils.h>

using namespace af;

void func()
{
    try {
        int device = 0; // free version only support 0
        af::deviceset(device);
        af::info();


        float a[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        float b[] = { 1, 1};

        array A(3,3, a, afHost);
        array B(1,2, b, afHost);

        array C = convolve(A,B);
        print(A);
        print(B);
        print(C);

    } catch (af::exception& e) {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }

}
