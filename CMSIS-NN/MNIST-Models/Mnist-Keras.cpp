#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "arm_math.h"
#include "arm_nnfunctions.h"

#include "boards.h"
#include "nrf_delay.h"
#include "SEGGER_RTT.h"
#include "nrf.h"
#include "nrf_drv_timer.h"
#include "bsp.h"
#include "app_error.h"
#include "app_timer.h"
#include "nrf_drv_clock.h"

#include "keras-dnn.h"

#include "mnist-images.h"
// image size  28 * 28 = 784
# define IMAGE_SIZE  784 


const nrf_drv_timer_t TIMER_SLEEP = NRF_DRV_TIMER_INSTANCE(0);


void single_shot_timer_handler(nrf_timer_event_t event_type, void * p_context)
{
    __WFE();
    __SEV();
    __WFE();
     nrf_drv_timer_task_address_get(&TIMER_SLEEP, NRF_TIMER_TASK_STOP);
     nrf_drv_timer_disable(&TIMER_SLEEP);
}



int main(void)
{
  printf("CMSIS-NN MNIST Evulation started!\n");
  //variables to save timer ticks
  uint32_t start = 0;
  uint32_t stop = 0 ;
  uint32_t elapsed;

  //Variables fro the event handler ( in order to go to sleep)
  uint32_t time_ms = 1; //Time(in miliseconds) between consecutive compare events.
  uint32_t time_ticks;
  uint32_t err_code = NRF_SUCCESS;

  nrf_drv_timer_config_t timer_cfg = NRF_DRV_TIMER_DEFAULT_CONFIG;
  err_code = nrf_drv_timer_init(&TIMER_SLEEP, &timer_cfg, single_shot_timer_handler);
  APP_ERROR_CHECK(err_code);

  time_ticks = nrf_drv_timer_ms_to_ticks(&TIMER_SLEEP, time_ms);

    nrf_drv_timer_extended_compare(
        &TIMER_SLEEP, NRF_TIMER_CC_CHANNEL0, time_ticks, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);
  nrf_drv_timer_enable(&TIMER_SLEEP);
  __SEV();   // clear signal event
  // wait for event 
  __WFE(); // Since internal event flag is set, this clears it without sleeping
  // wait for event
  __WFE(); // This should actually sleep until the next event.
  //

  // enable DWT
  CoreDebug->DEMCR |= 0x01000000;

  // Reset cycle counter
  DWT->CYCCNT = 0;

  // enable cycle counter
  DWT->CTRL |= 0x1;

  //timer snapshot 
  start = DWT->CYCCNT;

  uint8_t x = run_nn(MNIST_IMG[0]);
  printf("\n Real label: %d , predict: %u \n", MNIST_LABELS[0], x);

  //timer snapshot
  stop = DWT->CYCCNT;
  elapsed = stop-start;
  printf("cycles in ms = %lu\n",  ( elapsed / (SystemCoreClock/1000) ) );

  nrf_drv_timer_disable(&TIMER_SLEEP);


  __SEV();   // clear signal event
  // wait for event 
  __WFE(); // Since internal event flag is set, this clears it without sleeping
  // wait for event
  __WFE(); // This should actually sleep until the next event.


  return 0;
}


