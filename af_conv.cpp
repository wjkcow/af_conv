#include "af_conv.h"
#include <stdio.h>
#include <arrayfire.h>
#include <af/utils.h>

using namespace af;
// int main(){
// 	af::deviceset(0);
// 	af::info();


//     img.image_base = new float[50];
//     ker.kernel_base = new float[2];

//     memset(img.image_base, 0, 50);
//     memset(ker.kernel_base, 0, 2);
//     float * result = new float[1000];

// }
int af_conv(float *img, float * kernel, int img_x, int img_y, int img_s,
    int ker_x, int ker_y, int ker_s, int ch, float *result){

    try {
        int device = 0; // free version only support 0
        af::deviceset(device);
        af::info();
        array Img(img_x, img_y, ch, img_s, img, afHost);
        array Ker(ker_x, ker_y, ch, ker_s, kernel, afHost);
        array Result = constant(0, img_x - ker_x + 1, img_y - ker_y + 1, ker_s, img_s);

        gfor(array i, img_s * ker_s){
            for(int c = 0; c < ch; ++c){
              int img_stack_n = i.elements() / ker_s;
              int ker_stack_n = i.elements() % img_s;
              array c_pic = convolve(Img(span, span, c, img_stack_n), Ker(span, span, c, ker_stack_n));
              Result(span, span, ker_stack_n, img_stack_n) += c_pic(seq(img_x - ker_x + 1),
					seq(img_y - ker_y + 1));
            }
        }
        Result.host<float>(result);

    } catch (af::exception& e) {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }
	return 0;

}
