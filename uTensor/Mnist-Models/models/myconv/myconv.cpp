/* Auto-generated by utensor cli */
#include "uTensor.h"
#include "params_myconv.hpp"
#include "myconv.hpp"


Myconv::Myconv () :
op_DepthwiseSeparableConvOperator_000({ 1, 1 }, VALID, 32, { 1, 1 }, TFLM::TfLiteFusedActivation::kTfLiteActRelu)
, op_DequantizeOperator_001()
, op_Conv2dOperator_002({ 1, 1, 1, 1 }, VALID)
, op_ReshapeOperator_003({ 1, 800 })
, op_FullyConnectedOperator_004(TFLM::TfLiteFusedActivation::kTfLiteActNone)
, op_ReLUOperator_005()
, op_QuantizeOperator_006()
, op_MaxPoolOperator_007({ 2, 2 }, { 1, 2, 2, 1 }, VALID)
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
  Tensor t_input_1_int80 = new RamTensor({ 1, 28, 28, 1 }, i8);
    int32_t t_input_1_int80_zp = -128;
    float t_input_1_int80_scale = 0.003921569;
    PerTensorQuantizationParams t_input_1_int80_quant_params(t_input_1_int80_zp, t_input_1_int80_scale);
    t_input_1_int80->set_quantization_params(t_input_1_int80_quant_params);


  op_QuantizeOperator_006
    .set_inputs({
        { TflmSymQuantOps::QuantizeOperator<int8_t, float>::input, inputs[input_0].tensor() },
    })
    .set_outputs({
        { TflmSymQuantOps::QuantizeOperator<int8_t, float>::output, t_input_1_int80}
    })
    .eval();

  Tensor t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0 = new RomTensor({ 1, 3, 3, 32 }, i8, data_StatefulPartitionedCall_sequential_conv2d_Conv2D_ReadVariableOp_0);
    int32_t arr_t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_zp[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_scale[32] = { 0.00136815, 0.0013616548, 0.0025338444, 0.0042619207, 0.004248933, 0.0023117592, 0.0016247355, 0.0039672577, 0.0018790809, 0.0027441615, 0.005318181, 0.004486177, 0.0014340489, 0.004185101, 0.0058060475, 0.004708506, 0.0041835676, 0.0048946836, 0.0046950565, 0.004691366, 0.005376735, 0.005073283, 0.0037877338, 0.0045462837, 0.0061844764, 0.0030307057, 0.0016689106, 0.001136848, 0.0015340614, 0.0022016135, 0.0022410469, 0.004883179 };
    PerChannelQuantizationParams t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_quant_params(arr_t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_zp, arr_t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_scale);
    t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialconv2dConv2D_bias0 = new RomTensor({ 32 }, i32, data_StatefulPartitionedCall_sequential_conv2d_Conv2D_bias_0);
    int32_t arr_t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_zp[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_scale[32] = { 5.3652943e-06, 5.339823e-06, 9.936645e-06, 1.6713415e-05, 1.6662483e-05, 9.065723e-06, 6.3715124e-06, 1.5557875e-05, 7.3689453e-06, 1.0761419e-05, 2.0855614e-05, 1.7592853e-05, 5.6237213e-06, 1.6412161e-05, 2.2768814e-05, 1.846473e-05, 1.6406148e-05, 1.9194838e-05, 1.8411987e-05, 1.8397515e-05, 2.1085236e-05, 1.9895228e-05, 1.4853859e-05, 1.7828565e-05, 2.425285e-05, 1.1885121e-05, 6.544748e-06, 4.4582275e-06, 6.0159273e-06, 8.633779e-06, 8.78842e-06, 1.9149722e-05 };
    PerChannelQuantizationParams t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_quant_params(arr_t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_zp, arr_t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_scale);
    t_StatefulPartitionedCallsequentialconv2dConv2D_bias0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2dConv2D_bias0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialconv2dRelu0 = new RamTensor({ 1, 26, 26, 32 }, i8);
    int32_t t_StatefulPartitionedCallsequentialconv2dRelu0_zp = -128;
    float t_StatefulPartitionedCallsequentialconv2dRelu0_scale = 0.005575029;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialconv2dRelu0_quant_params(t_StatefulPartitionedCallsequentialconv2dRelu0_zp, t_StatefulPartitionedCallsequentialconv2dRelu0_scale);
    t_StatefulPartitionedCallsequentialconv2dRelu0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2dRelu0_quant_params);


  op_DepthwiseSeparableConvOperator_000
    .set_inputs({
        { TflmSymQuantOps::DepthwiseSeparableConvOperator<int8_t>::in, t_input_1_int80 },
        { TflmSymQuantOps::DepthwiseSeparableConvOperator<int8_t>::filter, t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0 },
        { TflmSymQuantOps::DepthwiseSeparableConvOperator<int8_t>::bias, t_StatefulPartitionedCallsequentialconv2dConv2D_bias0 },
    })
    .set_outputs({
        { TflmSymQuantOps::DepthwiseSeparableConvOperator<int8_t>::out, t_StatefulPartitionedCallsequentialconv2dRelu0}
    })
    .eval();

  t_StatefulPartitionedCallsequentialconv2dConv2D_bias0.free();

  t_input_1_int80.free();

  t_StatefulPartitionedCallsequentialconv2dConv2DReadVariableOp0.free();

  Tensor t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0 = new RamTensor({ 1, 13, 13, 32 }, i8);
    int32_t t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_zp = -128;
    float t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_scale = 0.005575029;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_quant_params(t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_zp, t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_scale);
    t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0->set_quantization_params(t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0_quant_params);


  op_MaxPoolOperator_007
    .set_inputs({
        { ReferenceOperators::MaxPoolOperator<int8_t>::in, t_StatefulPartitionedCallsequentialconv2dRelu0 },
    })
    .set_outputs({
        { ReferenceOperators::MaxPoolOperator<int8_t>::out, t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0}
    })
    .eval();

  t_StatefulPartitionedCallsequentialconv2dRelu0.free();

  Tensor t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0 = new RomTensor({ 32, 3, 3, 32 }, i8, data_StatefulPartitionedCall_sequential_conv2d_1_Conv2D_ReadVariableOp_0);
    int32_t arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_zp[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_scale[32] = { 0.005357639, 0.009262461, 0.004650231, 0.004800232, 0.005624249, 0.0038144977, 0.00466869, 0.004172589, 0.0062290635, 0.004250798, 0.0041327267, 0.0037532402, 0.004291947, 0.004927211, 0.005907468, 0.004557369, 0.00577684, 0.0043311277, 0.006236778, 0.00454792, 0.0058724396, 0.0040623364, 0.004295211, 0.0035144654, 0.0034830193, 0.0057619736, 0.00480481, 0.004898728, 0.00763018, 0.005579055, 0.0072211633, 0.004572018 };
    PerChannelQuantizationParams t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_quant_params(arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_zp, arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_scale);
    t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0 = new RomTensor({ 32 }, i32, data_StatefulPartitionedCall_sequential_conv2d_1_Conv2D_bias_0);
    int32_t arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_zp[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    float arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_scale[32] = { 2.9868994e-05, 5.163849e-05, 2.5925174e-05, 2.6761434e-05, 3.1355354e-05, 2.1265936e-05, 2.6028081e-05, 2.3262306e-05, 3.472721e-05, 2.3698323e-05, 2.3040071e-05, 2.0924424e-05, 2.392773e-05, 2.7469345e-05, 3.2934306e-05, 2.5407464e-05, 3.220605e-05, 2.4146164e-05, 3.477022e-05, 2.5354788e-05, 3.2739023e-05, 2.2647644e-05, 2.3945926e-05, 1.9593248e-05, 1.9417934e-05, 3.212317e-05, 2.6786956e-05, 2.731055e-05, 4.2538475e-05, 3.1103395e-05, 4.0258197e-05, 2.5489135e-05 };
    PerChannelQuantizationParams t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_quant_params(arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_zp, arr_t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_scale);
    t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialconv2d_1Relu0 = new RamTensor({ 1, 11, 11, 32 }, i8);
    int32_t t_StatefulPartitionedCallsequentialconv2d_1Relu0_zp = -128;
    float t_StatefulPartitionedCallsequentialconv2d_1Relu0_scale = 0.030304328;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialconv2d_1Relu0_quant_params(t_StatefulPartitionedCallsequentialconv2d_1Relu0_zp, t_StatefulPartitionedCallsequentialconv2d_1Relu0_scale);
    t_StatefulPartitionedCallsequentialconv2d_1Relu0->set_quantization_params(t_StatefulPartitionedCallsequentialconv2d_1Relu0_quant_params);


  op_Conv2dOperator_002
    .set_inputs({
        { ReferenceOperators::Conv2dOperator<int8_t>::in, t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0 },
        { ReferenceOperators::Conv2dOperator<int8_t>::filter, t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0 },
    })
    .set_outputs({
        { ReferenceOperators::Conv2dOperator<int8_t>::out, t_StatefulPartitionedCallsequentialconv2d_1Relu0}
    })
    .eval();

  t_StatefulPartitionedCallsequentialmax_pooling2dMaxPool0.free();

  t_StatefulPartitionedCallsequentialconv2d_1Conv2D_bias0.free();

  t_StatefulPartitionedCallsequentialconv2d_1Conv2DReadVariableOp0.free();

  Tensor t_3_CONV_2DReLU0 = new RamTensor({ 1, 11, 11, 32 }, i8);
    int32_t t_3_CONV_2DReLU0_zp = -128;
    float t_3_CONV_2DReLU0_scale = 0.030304328;
    PerTensorQuantizationParams t_3_CONV_2DReLU0_quant_params(t_3_CONV_2DReLU0_zp, t_3_CONV_2DReLU0_scale);
    t_3_CONV_2DReLU0->set_quantization_params(t_3_CONV_2DReLU0_quant_params);


  op_ReLUOperator_005
    .set_inputs({
        { ReferenceOperators::ReLUOperator<int8_t>::in, t_StatefulPartitionedCallsequentialconv2d_1Relu0 },
    })
    .set_outputs({
        { ReferenceOperators::ReLUOperator<int8_t>::out, t_3_CONV_2DReLU0}
    })
    .eval();

  t_StatefulPartitionedCallsequentialconv2d_1Relu0.free();

  Tensor t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0 = new RamTensor({ 1, 5, 5, 32 }, i8);
    int32_t t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_zp = -128;
    float t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_scale = 0.030304328;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_quant_params(t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_zp, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_scale);
    t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0->set_quantization_params(t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0_quant_params);


  op_MaxPoolOperator_007
    .set_inputs({
        { ReferenceOperators::MaxPoolOperator<int8_t>::in, t_3_CONV_2DReLU0 },
    })
    .set_outputs({
        { ReferenceOperators::MaxPoolOperator<int8_t>::out, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0}
    })
    .eval();

  t_3_CONV_2DReLU0.free();

  Tensor t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00 = new RamTensor({ 1, 800 }, i8);
    int32_t t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_zp = -128;
    float t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_scale = 0.030304328;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_quant_params(t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_zp, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_scale);
    t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00->set_quantization_params(t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00_quant_params);


  op_ReshapeOperator_003
    .set_inputs({
        { ReferenceOperators::ReshapeOperator<int8_t>::input, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0 },
    })
    .set_outputs({
        { ReferenceOperators::ReshapeOperator<int8_t>::output, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00}
    })
    .eval();

  t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool0.free();

  Tensor t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0 = new RomTensor({ 800, 10 }, i8, data_StatefulPartitionedCall_sequential_dense_MatMul_ReadVariableOp_transpose_0);
    int32_t t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_zp = 0;
    float t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_scale = 0.008123899;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_quant_params(t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_zp, t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_scale);
    t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0->set_quantization_params(t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0_quant_params);


  Tensor t_StatefulPartitionedCallsequentialdenseMatMul_bias0 = new RomTensor({ 10 }, i32, data_StatefulPartitionedCall_sequential_dense_MatMul_bias_0);
    int32_t t_StatefulPartitionedCallsequentialdenseMatMul_bias0_zp = 0;
    float t_StatefulPartitionedCallsequentialdenseMatMul_bias0_scale = 0.0002461893;
    PerTensorQuantizationParams t_StatefulPartitionedCallsequentialdenseMatMul_bias0_quant_params(t_StatefulPartitionedCallsequentialdenseMatMul_bias0_zp, t_StatefulPartitionedCallsequentialdenseMatMul_bias0_scale);
    t_StatefulPartitionedCallsequentialdenseMatMul_bias0->set_quantization_params(t_StatefulPartitionedCallsequentialdenseMatMul_bias0_quant_params);


  Tensor t_Identity_int80 = new RamTensor({ 1, 10 }, i8);
    int32_t t_Identity_int80_zp = 38;
    float t_Identity_int80_scale = 0.2529582;
    PerTensorQuantizationParams t_Identity_int80_quant_params(t_Identity_int80_zp, t_Identity_int80_scale);
    t_Identity_int80->set_quantization_params(t_Identity_int80_quant_params);


  op_FullyConnectedOperator_004
    .set_inputs({
        { TflmSymQuantOps::FullyConnectedOperator<int8_t>::input, t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00 },
        { TflmSymQuantOps::FullyConnectedOperator<int8_t>::filter, t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0 },
        { TflmSymQuantOps::FullyConnectedOperator<int8_t>::bias, t_StatefulPartitionedCallsequentialdenseMatMul_bias0 },
    })
    .set_outputs({
        { TflmSymQuantOps::FullyConnectedOperator<int8_t>::output, t_Identity_int80}
    })
    .eval();

  t_StatefulPartitionedCallsequentialdenseMatMul_bias0.free();

  t_StatefulPartitionedCallsequentialdenseMatMulReadVariableOptranspose0.free();

  t_StatefulPartitionedCallsequentialmax_pooling2d_1MaxPool_0_Reshape00.free();

  op_DequantizeOperator_001
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