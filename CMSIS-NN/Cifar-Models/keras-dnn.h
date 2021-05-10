#include "keras-weights.h"
#include "keras-parameters.h"
uint8_t run_nn(q7_t* input_data);

static q7_t conv2d_2_wt[CONV2D_2_IN_CH*CONV2D_2_KER_DIM*CONV2D_2_KER_DIM*CONV2D_2_OUT_CH] = CONV2D_2_WT;
static q7_t conv2d_2_bias[CONV2D_2_OUT_CH] = CONV2D_2_BIAS;
static q7_t conv2d_3_wt[CONV2D_3_IN_CH*CONV2D_3_KER_DIM*CONV2D_3_KER_DIM*CONV2D_3_OUT_CH] = CONV2D_3_WT;
static q7_t conv2d_3_bias[CONV2D_3_OUT_CH] = CONV2D_3_BIAS;
static q7_t dense_1_wt[DENSE_1_DIM *DENSE_1_OUT] = DENSE_1_WT;
static q7_t dense_1_bias[DENSE_1_OUT] = DENSE_1_BIAS;

static q7_t conv_buffer_out[28800];
static q15_t conv_buffer_in[7200];
static q7_t pool_out[7200];
static q15_t dense_buffer[1152];
static q7_t y_out[10];

uint8_t run_nn(q7_t* input_data) {
  arm_convolve_HWC_q7_RGB(input_data, CONV2D_2_IN_DIM, CONV2D_2_IN_CH, conv2d_2_wt, CONV2D_2_OUT_CH, CONV2D_2_KER_DIM, CONV2D_2_PAD, CONV2D_2_STRIDE, conv2d_2_bias, CONV2D_2_BIAS_LSHIFT, CONV2D_2_OUT_RSHIFT, conv_buffer_out, CONV2D_2_OUT_DIM, conv_buffer_in, NULL);
  arm_relu_q7(conv_buffer_out, CONV2D_2_OUT_DIM*CONV2D_2_OUT_DIM*CONV2D_2_OUT_CH);
  arm_maxpool_q7_HWC(conv_buffer_out, MAX_POOLING2D_2_IN_DIM, MAX_POOLING2D_2_IN_CH, MAX_POOLING2D_2_KER_DIM, MAX_POOLING2D_2_PAD, MAX_POOLING2D_2_STRIDE, MAX_POOLING2D_2_OUT_DIM, NULL,  pool_out);

  arm_convolve_HWC_q7_fast(pool_out, CONV2D_3_IN_DIM, CONV2D_3_IN_CH, conv2d_3_wt, CONV2D_3_OUT_CH, CONV2D_3_KER_DIM, CONV2D_3_PAD, CONV2D_3_STRIDE, conv2d_3_bias, CONV2D_3_BIAS_LSHIFT, CONV2D_3_OUT_RSHIFT, conv_buffer_out, CONV2D_3_OUT_DIM, conv_buffer_in, NULL);
  arm_relu_q7(pool_out, CONV2D_3_OUT_DIM*CONV2D_3_OUT_DIM*CONV2D_3_OUT_CH);
  arm_maxpool_q7_HWC(conv_buffer_out, MAX_POOLING2D_3_IN_DIM, MAX_POOLING2D_3_IN_CH, MAX_POOLING2D_3_KER_DIM, MAX_POOLING2D_3_PAD, MAX_POOLING2D_3_STRIDE, MAX_POOLING2D_3_OUT_DIM, NULL,  pool_out);

  arm_fully_connected_q7_opt(pool_out,dense_1_wt, DENSE_1_DIM, DENSE_1_OUT, DENSE_1_BIAS_LSHIFT, DENSE_1_OUT_RSHIFT, dense_1_bias, y_out, dense_buffer ) ;
  arm_softmax_q7(y_out, 10, y_out); 
  uint32_t index[1];
  q7_t result[1];
  uint32_t blockSize = sizeof(y_out);
  arm_max_q7(y_out, blockSize, result, index);
  return index[0];
}