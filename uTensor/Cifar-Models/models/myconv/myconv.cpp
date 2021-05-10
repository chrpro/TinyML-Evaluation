/* Auto-generated by utensor cli */
#include "uTensor.h"
#include "params_myconv.hpp"
#include "myconv.hpp"


Myconv::Myconv () :
op_QuantizeOperator_000()
, op_FullyConnectedOperator_001(TFLM::TfLiteFusedActivation::kTfLiteActNone)
, op_ReLUOperator_002()
, op_MaxPoolOperator_003({ 2, 2 }, { 1, 2, 2, 1 }, VALID)
, op_ReshapeOperator_004({ 1, 576 })
, op_Conv2dOperator_005({ 1, 1, 1, 1 }, VALID)
, op_DequantizeOperator_006()
{
  Context::get_default_context()->set_ram_data_allocator(&ram_allocator);
  Context::get_default_context()->set_metadata_allocator(&metadata_allocator);
  // TODO: moving ROMTensor declarations here
}

void Myconv::compute()
{
  // update context in case there are multiple models being run
  Context::get_default_context()->set_ram_data_allocator(&ram_allocator);
  Context::get_default_context()->set_metadata_allocator(&metadata_allocator);
  // start rendering local snippets
  Tensor t_input_1_int80 = new RamTensor({ 1, 32, 32, 3 }, i8);
    int32_t t_input_1_int80_zp = -128;
    float t_input_1_int80_scale = 0.003921569;
    PerTensorQuantizationParams t_input_1_int80_quant_params(t_input_1_int80_zp, t_input_1_int80_scale);
    t_input_1_int80->set_quantization_params(t_input_1_int80_quant_params);


  op_QuantizeOperator_000
    .set_inputs({
        { TflmSymQuantOps::QuantizeOperator<int8_t, float>::input, inputs[input_0].tensor() },
    })
    .set_outputs({
        { TflmSymQuantOps::QuantizeOperator<int8_t, float>::output, t_input_1_int80}
    })
    .eval();

  Tensor t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0 = new RomTensor({ 16, 3, 3, 3 }, i8, data_StatefulPartitionedCall_sequential_conv2d_Conv2D_ReadVariableOp_0);
    int32_t arr_t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_zp[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_scale[16] = { 0.0015036869, 0.0014956356, 0.0014535798, 0.001383201, 0.0013538942, 0.0014658115, 0.0013952658, 0.0013506651, 0.0012956059, 0.0014101366, 0.0013051761, 0.0014522014, 0.0015481816, 0.0015304622, 0.0015260074, 0.0015871952 };
    PerChannelQuantizationParams t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_quant_params(arr_t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_zp, arr_t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_scale);
    t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialconv2dConv2D_bias0 = new RomTensor({ 16 }, i32, data_StatefulPartitionedCall_sequential_conv2d_Conv2D_bias_0);
    int32_t arr_t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_zp[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_scale[16] = { 5.8968117e-06, 5.865238e-06, 5.700313e-06, 5.424318e-06, 5.3093895e-06, 5.7482807e-06, 5.471631e-06, 5.296726e-06, 5.0808076e-06, 5.529948e-06, 5.118338e-06, 5.694908e-06, 6.071301e-06, 6.001813e-06, 5.9843433e-06, 6.2242952e-06 };
    PerChannelQuantizationParams t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_quant_params(arr_t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_zp, arr_t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_scale);
    t_StatefulPartitionedCallsequentialconv2dConv2D_bias0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialconv2dRelu0 = new RamTensor({ 1, 30, 30, 16 }, i8);
    int32_t t_StatefulPartitionedCallsequentialconv2dRelu0_zp = -128;
    float t_StatefulPartitionedCallsequentialconv2dRelu0_scale = 0.004493453;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialconv2dRelu0_quant_params(t_StatefulPartitionedCallsequentialconv2dRelu0_zp, t_StatefulPartitionedCallsequentialconv2dRelu0_scale);
    t_StatefulPartitionedCallsequentialconv2dRelu0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2dRelu0_quant_params);


  op_Conv2dOperator_005
    .set_inputs({
        { ReferenceOperators::Conv2dOperator<int8_t>::in, t_input_1_int80 },
        { ReferenceOperators::Conv2dOperator<int8_t>::filter, t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0 },
    })
    .set_outputs({
        { ReferenceOperators::Conv2dOperator<int8_t>::out, t_StatefulPartitionedCallsequentialconv2dRelu0}
    })
    .eval();

  t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0.free();

  t_input_1_int80.free();

  t_StatefulPartitionedCallsequentialconv2dConv2D_bias0.free();

  Tensor t_1_CONV_2DReLU0 = new RamTensor({ 1, 30, 30, 16 }, i8);
    int32_t t_1_CONV_2DReLU0_zp = -128;
    float t_1_CONV_2DReLU0_scale = 0.004493453;
    PerTensorQuantizationParams t_1_CONV_2DReLU0_quant_params(t_1_CONV_2DReLU0_zp, t_1_CONV_2DReLU0_scale);
    t_1_CONV_2DReLU0->set_quantization_params(t_1_CONV_2DReLU0_quant_params);


  op_ReLUOperator_002
    .set_inputs({
        { ReferenceOperators::ReLUOperator<int8_t>::in, t_StatefulPartitionedCallsequentialconv2dRelu0 },
    })
    .set_outputs({
        { ReferenceOperators::ReLUOperator<int8_t>::out, t_1_CONV_2DReLU0}
    })
    .eval();

  t_StatefulPartitionedCallsequentialconv2dRelu0.free();

  Tensor t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0 = new RamTensor({ 1, 15, 15, 16 }, i8);
    int32_t t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_zp = -128;
    float t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_scale = 0.004493453;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_quant_params(t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_zp, t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_scale);
    t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0->set_quantization_params(t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_quant_params);


  op_MaxPoolOperator_003
    .set_inputs({
        { ReferenceOperators::MaxPoolOperator<int8_t>::in, t_1_CONV_2DReLU0 },
    })
    .set_outputs({
        { ReferenceOperators::MaxPoolOperator<int8_t>::out, t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0}
    })
    .eval();

  t_1_CONV_2DReLU0.free();

  Tensor t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0 = new RomTensor({ 16, 3, 3, 16 }, i8, data_StatefulPartitionedCall_sequential_conv2d_1_Conv2D_ReadVariableOp_0);
    int32_t arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_zp[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_scale[16] = { 0.0011658036, 0.0011165448, 0.0012007528, 0.0011854726, 0.0012360296, 0.0012074583, 0.0012068556, 0.0012981615, 0.0011716263, 0.0013064089, 0.0011657372, 0.0011820904, 0.0012233781, 0.0012269251, 0.0012538491, 0.001244765 };
    PerChannelQuantizationParams t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_quant_params(arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_zp, arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_scale);
    t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0 = new RomTensor({ 16 }, i32, data_StatefulPartitionedCall_sequential_conv2d_1_Conv2D_bias_0);
    int32_t arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_zp[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_scale[16] = { 5.238484e-06, 5.0171416e-06, 5.3955264e-06, 5.3268654e-06, 5.554041e-06, 5.4256575e-06, 5.422949e-06, 5.8332275e-06, 5.264648e-06, 5.870287e-06, 5.238185e-06, 5.311668e-06, 5.497192e-06, 5.51313e-06, 5.6341123e-06, 5.5932933e-06 };
    PerChannelQuantizationParams t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_quant_params(arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_zp, arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_scale);
    t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialconv2d_1Relu0 = new RamTensor({ 1, 13, 13, 16 }, i8);
    int32_t t_StatefulPartitionedCallsequentialconv2d_1Relu0_zp = -128;
    float t_StatefulPartitionedCallsequentialconv2d_1Relu0_scale = 0.00541981;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialconv2d_1Relu0_quant_params(t_StatefulPartitionedCallsequentialconv2d_1Relu0_zp, t_StatefulPartitionedCallsequentialconv2d_1Relu0_scale);
    t_StatefulPartitionedCallsequentialconv2d_1Relu0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2d_1Relu0_quant_params);


  op_Conv2dOperator_005
    .set_inputs({
        { ReferenceOperators::Conv2dOperator<int8_t>::in, t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0 },
        { ReferenceOperators::Conv2dOperator<int8_t>::filter, t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0 },
    })
    .set_outputs({
        { ReferenceOperators::Conv2dOperator<int8_t>::out, t_StatefulPartitionedCallsequentialconv2d_1Relu0}
    })
    .eval();

  t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0.free();

  t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0.free();

  t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0.free();

  Tensor t_3_CONV_2DReLU0 = new RamTensor({ 1, 13, 13, 16 }, i8);
    int32_t t_3_CONV_2DReLU0_zp = -128;
    float t_3_CONV_2DReLU0_scale = 0.00541981;
    PerTensorQuantizationParams t_3_CONV_2DReLU0_quant_params(t_3_CONV_2DReLU0_zp, t_3_CONV_2DReLU0_scale);
    t_3_CONV_2DReLU0->set_quantization_params(t_3_CONV_2DReLU0_quant_params);


  op_ReLUOperator_002
    .set_inputs({
        { ReferenceOperators::ReLUOperator<int8_t>::in, t_StatefulPartitionedCallsequentialconv2d_1Relu0 },
    })
    .set_outputs({
        { ReferenceOperators::ReLUOperator<int8_t>::out, t_3_CONV_2DReLU0}
    })
    .eval();

  t_StatefulPartitionedCallsequentialconv2d_1Relu0.free();

  Tensor t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0 = new RamTensor({ 1, 6, 6, 16 }, i8);
    int32_t t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_zp = -128;
    float t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_scale = 0.00541981;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_quant_params(t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_zp, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_scale);
    t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0->set_quantization_params(t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_quant_params);


  op_MaxPoolOperator_003
    .set_inputs({
        { ReferenceOperators::MaxPoolOperator<int8_t>::in, t_3_CONV_2DReLU0 },
    })
    .set_outputs({
        { ReferenceOperators::MaxPoolOperator<int8_t>::out, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0}
    })
    .eval();

  t_3_CONV_2DReLU0.free();

  Tensor t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00 = new RamTensor({ 1, 576 }, i8);
    int32_t t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_zp = -128;
    float t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_scale = 0.00541981;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_quant_params(t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_zp, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_scale);
    t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00->set_quantization_params(t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_quant_params);


  op_ReshapeOperator_004
    .set_inputs({
        { ReferenceOperators::ReshapeOperator<int8_t>::input, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0 },
    })
    .set_outputs({
        { ReferenceOperators::ReshapeOperator<int8_t>::output, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00}
    })
    .eval();

  t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0.free();

  Tensor t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0 = new RomTensor({ 576, 10 }, i8, data_StatefulPartitionedCall_sequential_dense_MatMul_ReadVariableOp_transpose_0);
    int32_t t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_zp = 0;
    float t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_scale = 0.0009943044;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_quant_params(t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_zp, t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_scale);
    t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0->set_quantization_params(t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialdenseMatMul_bias0 = new RomTensor({ 10 }, i32, data_StatefulPartitionedCall_sequential_dense_MatMul_bias_0);
    int32_t t_StatefulPartitionedCallsequentialdenseMatMul_bias0_zp = 0;
    float t_StatefulPartitionedCallsequentialdenseMatMul_bias0_scale = 5.3889407e-06;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialdenseMatMul_bias0_quant_params(t_StatefulPartitionedCallsequentialdenseMatMul_bias0_zp, t_StatefulPartitionedCallsequentialdenseMatMul_bias0_scale);
    t_StatefulPartitionedCallsequentialdenseMatMul_bias0->set_quantization_params(t_StatefulPartitionedCallsequentialdenseMatMul_bias0_quant_params);


  Tensor t_Identity_int80 = new RamTensor({ 1, 10 }, i8);
    int32_t t_Identity_int80_zp = 7;
    float t_Identity_int80_scale = 0.017865459;
    PerTensorQuantizationParams t_Identity_int80_quant_params(t_Identity_int80_zp, t_Identity_int80_scale);
    t_Identity_int80->set_quantization_params(t_Identity_int80_quant_params);


  op_FullyConnectedOperator_001
    .set_inputs({
        { TflmSymQuantOps::FullyConnectedOperator<int8_t>::input, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00 },
        { TflmSymQuantOps::FullyConnectedOperator<int8_t>::filter, t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0 },
        { TflmSymQuantOps::FullyConnectedOperator<int8_t>::bias, t_StatefulPartitionedCallsequentialdenseMatMul_bias0 },
    })
    .set_outputs({
        { TflmSymQuantOps::FullyConnectedOperator<int8_t>::output, t_Identity_int80}
    })
    .eval();

  t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0.free();

  t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00.free();

  t_StatefulPartitionedCallsequentialdenseMatMul_bias0.free();

  op_DequantizeOperator_006
    .set_inputs({
        { TflmSymQuantOps::DequantizeOperator<float, int8_t>::a, t_Identity_int80 },
    })
    .set_outputs({
        { TflmSymQuantOps::DequantizeOperator<float, int8_t>::b, outputs[output_0].tensor()}
    })
    .eval();

  t_Identity_int80.free();
  // end of rendering local snippets
}