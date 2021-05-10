
#include <stdio.h>

#include <cmath>

#include "models/myconv/myconv.hpp"  //gernerated model file"
#include "uTensor.h"
#include "mbed.h"

#include "input_image.h"  //contains the first sample taken from the MNIST test set


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

  printf("\n -------uTensor - MNIST Evaluation -------\n");

  t.reset();
  t.start();
  // create the input/output tensor
  Tensor input_image = new RomTensor({1, 28, 28, 1}, flt, arr_input_image);
  
  Tensor logits = new RamTensor({1, 10}, flt);

  model.set_inputs({{Myconv::input_0, input_image}})
      .set_outputs({{Myconv::output_0, logits}})
      .eval();


  int max_index = argmax(logits);


  t.stop();
  printf("Inference time: %d s\n", t.read_ms());
  printf("pred label: %d\r\n", max_index);

  printf("\n -------end-------\n");


return 0;
}
