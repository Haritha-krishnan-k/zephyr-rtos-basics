#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

#define GPIO_NODE DT_NODELABEL(gpio0)
#define LED1 2
#define LED2 3
#define LED3 4

const struct device *gpio_dev;

void main(void)
{

printk("3 LED BLINK START");

gpio_dev = DEVICE_DT_GET(GPIO_NODE);

if(!device_is_ready(gpio_dev))
{
printk("GPIO not ready");
return ;
}

gpio_pin_configure(gpio_dev , LED1 , GPIO_OUTPUT);
gpio_pin_configure(gpio_dev , LED2 , GPIO_OUTPUT);
gpio_pin_configure(gpio_dev,  LED3 , GPIO_OUTPUT);

while(1)

{

gpio_pin_set(gpio_dev , LED1 , 1);
gpio_pin_set(gpio_dev , LED2 , 1);
gpio_pin_set(gpio_dev , LED3 , 1);

k_msleep(500);

gpio_pin_set(gpio_dev, LED1 ,0);
gpio_pin_set(gpio_dev, LED2 ,0);
gpio_pin_set(gpio_dev, LED3 ,0);

k_msleep(500);

}

}
