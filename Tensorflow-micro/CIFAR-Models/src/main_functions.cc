/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "main_functions.h"

#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "constants.h"
#include "model.h"
#include "output_handler.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"

#include "cifar_input.h"

#include <zephyr.h>

// Globals, used for compatibility with Arduino-style sketches.
namespace
{
tflite::ErrorReporter *error_reporter = nullptr;
const tflite::Model *model = nullptr;
tflite::MicroInterpreter *interpreter = nullptr;
TfLiteTensor *input = nullptr;
TfLiteTensor *output = nullptr;
int inference_count = 0;

float  image_data[3072] = IMG_DATA;


extern "C" const int cifar10_tflite_len;

// Create an area of memory to use for input, output, and intermediate arrays.
// Minimum arena size, at the time of writing. After allocating tensors
// you can retrieve this value by invoking interpreter.arena_used_bytes().
const int kModelArenaSize = 2512;
// Extra headroom for model + alignment + future interpreter changes.
const int kExtraArenaSize =   model_len + 16 + 10600 ;
const int kTensorArenaSize =  kModelArenaSize + kExtraArenaSize;

alignas(16) static uint8_t tensor_arena[kTensorArenaSize];
} // namespace

// The name of this function is important for Arduino compatibility.
void setup()
{
	outputInit();


	// Set up logging. Google style is to avoid globals or statics because of
	// lifetime uncertainty, but since this has a trivial destructor it's okay.
	// NOLINTNEXTLINE(runtime-global-variables)

	static tflite::MicroErrorReporter micro_error_reporter;
	error_reporter = &micro_error_reporter;

	// Map the model into a usable data structure. This doesn't involve any
	// copying or parsing, it's a very lightweight operation.
	model = tflite::GetModel(model_tflite);

	if (model->version() != TFLITE_SCHEMA_VERSION) {
		TF_LITE_REPORT_ERROR(
			error_reporter,
			"Model provided is schema version %d not equal "
			"to supported version %d.",
			model->version(), TFLITE_SCHEMA_VERSION);
	}

	// This pulls in all the operation implementations we need.
	// NOLINTNEXTLINE(runtime-global-variables)
	static tflite::AllOpsResolver resolver;

	// Build an interpreter to run the model with.
	static tflite::MicroInterpreter static_interpreter(model, resolver,
							   tensor_arena,
							   kTensorArenaSize,
							   error_reporter);
	interpreter = &static_interpreter;

	// Allocate memory from the tensor_arena for the model's tensors.
	TfLiteStatus allocate_status = interpreter->AllocateTensors();

	if (allocate_status != kTfLiteOk) {
		TF_LITE_REPORT_ERROR(error_reporter,
				     "AllocateTensors() failed");
	}
	TF_LITE_REPORT_ERROR(error_reporter,"size : %d",interpreter->arena_used_bytes());

	// Obtain pointers to the model's input and output tensors.
	input = interpreter->input(0);
	output = interpreter->output(0);



	// Keep track of how many inferences we have performed.
	inference_count = 0;
}

// The name of this function is important for Arduino compatibility.
void loop()
{

		k_sleep(K_SECONDS(0.1)); 
			//****** DEFINE TIMESTAMPS ******
		s64_t time_stamp;
		s64_t milliseconds_spent;

		/********** capture initial time stamp ********/
		time_stamp = k_uptime_get();

		for (int d = 0; d < 3072; ++d) {input->data.f[d] = image_data[d]/255;}
		
		TfLiteStatus invoke_status = interpreter->Invoke();

		if (invoke_status != kTfLiteOk) {
			TF_LITE_REPORT_ERROR(error_reporter,
						"Invoke failed.");
		}

		float max_score = output->data.f[0];
		float guess = 0;

		for (int category_index = 1; category_index < 10;category_index++) 
		{
			float category_score = output->data.f[category_index];
			if (category_score > max_score) {
				max_score = category_score;
				guess = category_index;
			}
		}
		

		// Output the results. A custom HandleOutput function can be implemented
		// for each supported hardware target.
		int test_y = 9;
		HandleOutput(error_reporter, guess,test_y);


		// ************ GET TIMESTAMP***********
		milliseconds_spent = k_uptime_delta(&time_stamp);
		TF_LITE_REPORT_ERROR( error_reporter, "Time exec = %d",milliseconds_spent);


}
  