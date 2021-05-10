#include <stdio.h>

#include <cmath>

#include "models/myconv/myconv.hpp"  //gernerated model file"
#include "uTensor.h"
#include "mbed.h"

#include "cifar_input.h"



using namespace uTensor;

int argmax(const Tensor &logits) {
  uint32_t num_elems = logits->num_elems();
  float max_value = static_cast<float>(logits(0));
  int max_index = 0;
  for (int i = 1; i < num_elems; ++i) {
    float value = static_cast<float>(logits(i));
    if (value >= max_value) {
      max_value = value;
      max_index = i;
    }
  }
  return max_index;
}

static Myconv model;


Timer t;

int main(void) {
  

  printf("\n -------uTensor Evaluation-------\n");


  ThisThread::sleep_for(0.1);

  t.reset();
  t.start();


  Tensor input_image = new RomTensor({3, 32, 32}, u8, arr_input_image);

  Tensor logits = new RamTensor({1, 10}, flt);

  model.set_inputs({{Myconv::input_0, input_image}})
      .set_outputs({{Myconv::output_0, logits}})
      .eval();

  int max_index = argmax(logits);


  t.stop();
  printf("Inference time: %d ms\n", t.read_ms());
  printf("pred label: %d\r\n", max_index);
  ThisThread::sleep_for(100);


  printf("\n -------end-------\n");


  return 0;
}
