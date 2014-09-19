#include "af_conv.h"
#include <stdio.h>
#include <arrayfire.h>
#include <af/utils.h>

using namespace af;

int main()
{
    try {
        int device = 0; // free version only support 0
        af::deviceset(device);
        af::info();


        float a[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        float b[] = { 2, 1,2,1};

        array A(2,2,2, a, afHost);
        array B(2,2, b, afHost);
	gfor(array i, 10000){
		convolve(A,B);
	}
        array C = convolve(A,B);
        print(A);
        print(B);
        print(C);

    } catch (af::exception& e) {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }
	return 0;
}
