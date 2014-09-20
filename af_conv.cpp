#include "af_conv.h"
#include <stdio.h>
#include <arrayfire.h>
#include <af/utils.h>

using namespace af;


int af_conv(float *img, float * kernel, int img_x, int img_y, int img_s,
    int ker_x, int ker_y, int ker_s, int ch, float *result){

    try {
        int device = 0; // free version only support 0
        af::deviceset(device);
        af::info();
        array img(img_x, img_y, ch, img_s, img, afHost);
        array ker(ker_x, ker_y, ch, ker_s, kernel, afHost);
        array result = constant(0, img_x - ker_x + 1, img_y - ker_y + 1, ker_s, img_s);

        gfor(array i, img_s * ker_s){
            for(int c = 0; c < ch; ++c){
                result(span, span, i / ker_s, i / img_s) += convolve(img(span, span, c, i / ker_s), ker(span, span, c, i % img_s))(seq(img_x - ker_x + 1),
                    seq(img_y - ker_y + 1));
            }
        }

    } catch (af::exception& e) {
        fprintf(stderr, "%s\n", e.what());
        throw;
    }

}