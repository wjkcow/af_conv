#ifndef CUDA_CONV_H
#define CUDA_CONV_H


int af_conv(float *img, float * kernel, int img_x, int img_y, int img_s,
	int ker_x, int ker_y, int ker_s, int ch, float *result);

#endif /* CUDA_CONV_H */