/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

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

#include "output_handler.h"

#include <zephyr.h>
#include <sys/printk.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <drivers/pwm.h>

#include <sys/__assert.h>

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

#define PWM_LED0_NODE	DT_ALIAS(pwm_led0)
#define FLAGS_OR_ZERO(node)                                                    \
	COND_CODE_1(DT_PHA_HAS_CELL(node, pwms, flags), (DT_PWMS_FLAGS(node)), \
		    (0))

#define PWM_LABEL DT_PWMS_LABEL(PWM_LED0_NODE)
#define PWM_CHANNEL DT_PWMS_CHANNEL(PWM_LED0_NODE)
#define PWM_FLAGS FLAGS_OR_ZERO(PWM_LED0_NODE)

#define MIN_PERIOD_USEC (USEC_PER_SEC / 64U)

struct device *pwm;
static u32_t period;
static u32_t new_period;

void outputInit()
{
	pwm = device_get_binding(PWM_LABEL);
	if (!pwm) {
		printk("Error: didn't find %s device\n", PWM_LABEL);
		return;
	}

 	period = MIN_PERIOD_USEC;
}

void HandleOutput(tflite::ErrorReporter* error_reporter, int prediction, int label) {
  TF_LITE_REPORT_ERROR(error_reporter, "Model estimates [%d] label [%d]\n", prediction, label);
}