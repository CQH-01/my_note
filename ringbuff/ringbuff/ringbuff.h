#ifndef __RINGBUFF_H__
#define __RINGBUFF_H__

#include "stdint.h"

#define RINGBUFF_SUCCESS 1
#define RINGBUFF_FAIL 0


typedef struct ringbuff
{
    uint16_t tail;
    uint16_t head;
    const uint16_t lenght;
     uint8_t * const buff_addr;
}RINGBUFF_STRUCT;

typedef RINGBUFF_STRUCT RINGBUFF;

#define RINGBUFF_DEF(name, size) \
        static uint8_t name##_ringbuff[size];       /* 环形缓冲内存 */\
        static RINGBUFF_STRUCT name =               /* 环形结构体 */\
        {                                                          \
            .tail = 0,                              /* 尾部 */\
            .head = 0,                              /* 头部 */\
            .lenght = size,                         /* 长度 */\
            .buff_addr = name##_ringbuff            /* 内存地址 */\
        };                                                     


uint8_t Ringbuff_PutByte(RINGBUFF *ring, uint8_t byte);
uint8_t Ringbuff_PushBte(RINGBUFF *ring, uint8_t *byte);
uint16_t Ringbuff_Push(RINGBUFF *ring, uint8_t buff[], uint16_t size);
void Ringbuff_ClearAll(RINGBUFF *ring);
void Ringbuff_Clear(RINGBUFF *ring, uint16_t lenght);
uint8_t Ringbuff_ReadByte(RINGBUFF *ring, uint16_t pos);

static inline uint16_t Ringbuff_GetLenght(RINGBUFF *ring)
{
    uint16_t head = ring->head;
    uint16_t tail = ring->tail;
    return (head <= tail) ? (tail - head) : (ring->lenght - head + tail);
}

#endif
