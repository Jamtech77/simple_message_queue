#ifndef _QUEUE_H
#define _QUEUE_H

#include "stdint.h"

typedef struct queue_item
{
    void *msg;
    struct queue_item *next;
} queue_item_t;

typedef struct queue
{
    uint32_t item_num;
    uint32_t msg_size;
    queue_item_t *item;
} queue_t;

typedef queue_t*    message_queue_t;


uint32_t create_message_queue(message_queue_t *queue, size_t length,
                              size_t msg_size);

uint32_t put_message_queue(message_queue_t *queue, void *msg,
                           uint32_t timeout_ms);

uint32_t get_message_queue(message_queue_t *queue, void *msg,
                           uint32_t timeout_ms);

#endif /* _QUEUE_H */
