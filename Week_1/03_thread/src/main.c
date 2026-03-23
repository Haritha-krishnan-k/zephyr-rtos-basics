#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define STACK_SIZE 1024
#define PRIORITY 5

K_THREAD_STACK_DEFINE(stack1,STACK_SIZE);
K_THREAD_STACK_DEFINE(stack2,STACK_SIZE);

struct k_thread thread1_data;
struct k_thread thread2_data;

void thread1(void *p1 , void *p3)
{
    while(1)
    {
        printk("Thread 1 running\n");
        k_sleep(K_MSEC(500));
    }
}

void thread2(void *p1 , void *p2 , void *p3)
{
    while(1)
    {
        printk("thread 2 running\n");
        k_sleep(K_MSEC(1000));
    }
}

void main(void)
{
    printk("starting threads \n");

    k_thread_create(&thread1_data,stack1,STACK_SIZE,thread1,NULL,NULL,NULL,PRIORITY,0,K_NO_WATT);
    k_thread_create(&thread2_data,stack2,STACK_SIZE,thread2,NULL,NULL,NULL,PRIORITY,0,K_NO_WAIT);
}