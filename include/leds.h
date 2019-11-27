/*
* Leds interface for tamboSound
*/

#ifndef __LEDS_H__
#define __LEDS_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "driver/gpio.h"


#define LED_PIN         GPIO_NUM_2

#define SHORT_PULSE     200
#define LONG_PULSE      500

esp_err_t init_leds();

void blink_connected();

void blink_disconnected();

void blink_connected_task();

void blink_disconnected_task();

#endif // __LEDS_H__