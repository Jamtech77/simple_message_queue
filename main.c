#include <stdio.h>
#include "queue.h"

message_queue_t queue_handle;

typedef struct myqueue {
    int val;
    char id[10];
} myqueue_t;

int main(void)
{
    puts("Hello World!");

    create_message_queue(&queue_handle, 10, sizeof(myqueue_t));

    printf("%d\n", queue_handle->msg_size);
    printf("%d\n", queue_handle->item_num);

    myqueue_t queue1;
    queue1.val = 100;
    myqueue_t queue2;
    queue2.val = 200;
    myqueue_t queue3;
    queue3.val = 300;
    myqueue_t queue4;
    queue4.val = 400;
    myqueue_t queue5;
    queue5.val = 500;

    put_message_queue(&queue_handle, &queue1, 0);
    put_message_queue(&queue_handle, &queue2, 0);
    put_message_queue(&queue_handle, &queue3, 0);

    /* Get item from queue */
    myqueue_t get_queue;

    get_message_queue(&queue_handle, &get_queue, 0);
    printf("get_queue.val = %d\n", get_queue.val);

    put_message_queue(&queue_handle, &queue4, 0);

    get_message_queue(&queue_handle, &get_queue, 0);
    printf("get_queue.val = %d\n", get_queue.val);

    get_message_queue(&queue_handle, &get_queue, 0);
    printf("get_queue.val = %d\n", get_queue.val);

    put_message_queue(&queue_handle, &queue5, 0);

    get_message_queue(&queue_handle, &get_queue, 0);
    printf("get_queue.val = %d\n", get_queue.val);

    get_message_queue(&queue_handle, &get_queue, 0);
    printf("get_queue.val = %d\n", get_queue.val);

    get_message_queue(&queue_handle, &get_queue, 0);
    printf("get_queue.val = %d\n", get_queue.val);

    return 0;
}
