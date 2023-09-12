#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main()
{
    stdio_init_all();

    if (cyw43_arch_init()) {
        return -1;
    }

    int i;
    int timer = 1000;
    while(true) {
        i = 1;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, i);
        sleep_ms(timer);
        printf("ON\n");
        i = 0;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, i);
        sleep_ms(timer);
        printf("OFF\n");
    }
    
    return 0;
}