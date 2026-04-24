#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

void main(void)
{
printk("hello world from Zephyr");
printk("Board:%s\n",CONFIG_BOARD);

}

