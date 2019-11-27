#include "leds.h"


esp_err_t init_leds()
{
    return gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

}

void blink_connected()
{
    xTaskCreate(&blink_connected_task, "blink_connected_task", 1024, NULL, 2, NULL);

}

void blink_disconnected()
{
    xTaskCreate(&blink_disconnected_task, "blink_disconnected_task", 1024, NULL, 2, NULL);

}

void blink_connected_task()
{
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);

    gpio_set_level(LED_PIN, 1);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);

    gpio_set_level(LED_PIN, 1);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);

    vTaskDelete(NULL);
}

void blink_disconnected_task()
{
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);

    gpio_set_level(LED_PIN, 1);
    vTaskDelay(LONG_PULSE / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(LONG_PULSE / portTICK_PERIOD_MS);

    gpio_set_level(LED_PIN, 1);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(SHORT_PULSE / portTICK_PERIOD_MS);

    vTaskDelete(NULL);
}
