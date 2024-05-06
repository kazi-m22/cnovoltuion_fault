#include "cpp_float.h"


//float cpp_float (const float * x1, const float * w1) {
//	float  temp;
//
//	temp = 0.0;
//
//	for(int i = 0; i<4; i++) {
//		temp = temp + x1[i] * y1[i];
//	}
//	return temp;
//}

//float cpp_float(float x[4], float y[4]) {
//#pragma HLS pipeline II=1
//    float sum = 0.0, temp;
//    for (int i = 0; i < 4; ++i) {
//#pragma HLS pipeline II=1
//#pragma HLS bind_op  variable=temp op=fmul impl=fabric
//        temp =  x[i] * y[i];
//#pragma HLS bind_op  variable=sum op=fadd impl=fabric
//        sum = sum + temp;
//    }
//    return sum;
//}

void cpp_float(float x[1024], float y[1024]) {

	float temp1, temp2, temp3, temp4, add;
	float weights[4] = {1.2, 2.3, 4.5, 7.8};


    for (int i = 0; i < 1024; i++){

    	float sum = 0.0;
    	for (int j = 0; j < 4; j++) {
#pragma HLS bind_op  variable=add op=fmul impl=fabric
    		add = weights[j] *  x[i+j];
#pragma HLS bind_op  variable=sum op=fadd impl=fabric
    		sum = sum + add;
    	}
    	y[i] = sum;

    }
}


//data_t cpp_float(data_t x1, data_t x2, data_t x3, data_t x4) {
//
////	data_t offset = position * factor;
////	data_t s = sin(angle + offset);
////	data_t c = cos(angle - offset);
//
//	data_t w1 = 0.057;
//	data_t w2 = 0.135;
//	data_t w3 = 0.345;
//	data_t w4 = 1.246;
//
//	data_t mul1, mul2, mul3, mul4, output;
//
//#pragma HLS bind_op  variable=mul1 op=fmul impl=fabric
//#pragma HLS bind_op  variable=mul2 op=fmul impl=fabric
//#pragma HLS bind_op  variable=mul3 op=fmul impl=fabric
//#pragma HLS bind_op  variable=mul4 op=fmul impl=fabric
//
//	mul1 = w1*x1;
//	mul2 = w2*x2;
//	mul3 = w3*x3;
//	mul4 = w4*x4;
//
//#pragma HLS bind_op  variable=output op=fadd impl=fabric
//	output =  mul1 + mul2 + mul3 + mul4;
//
//	return output;
//}
