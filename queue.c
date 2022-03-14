#include "queue.h"
#include <stdlib.h>
#include <string.h>


uint32_t create_message_queue(message_queue_t *queue,
                              size_t length,
                              size_t msg_size)
{
    *queue = (message_queue_t) calloc(1, sizeof(queue_t));
    (*queue)->item_num = length;
    (*queue)->msg_size = msg_size;
    (*queue)->item = NULL;

    return 0;
}

uint32_t put_message_queue(message_queue_t *queue,
                           void *msg,
                           uint32_t timeout_ms)
{
    queue_item_t *new_queue_item = calloc(1, sizeof(queue_item_t));

    new_queue_item->msg = msg;
    new_queue_item->next = (*queue)->item;

    (*queue)->item = new_queue_item;

    return 0;
}

uint32_t get_message_queue(message_queue_t *queue,
                           void *msg,
                           uint32_t timeout_ms)
{
    queue_item_t *cur, *prev;

    if ((*queue)->item == NULL) {
        return 0;
    }

    cur = (*queue)->item;

    if (cur->next == NULL) {
        (*queue)->item = NULL;
    }

    prev = cur;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    memcpy(msg, cur->msg, (*queue)->msg_size);
    prev->next = NULL;

    free(cur);

    return 0;
}
