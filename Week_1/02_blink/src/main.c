#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define SLEEP_TIME_MS 500

int main(void)
{
    int count =0;

    while(1)
    {
        printk("LED ON (%d)\n",count++);
        k_msleep(SLEEP_TIME_MS);

        printk("LED OFF (%D)\n",count++);
        k_msleep(SLEEP_TIME_MS);
    }

    return 0;
}