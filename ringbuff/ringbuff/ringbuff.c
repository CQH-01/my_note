#include "ringbuff.h"
#include "string.h"

/*  
 *  名称：放入字节
 *  描述：将数据放入缓存
 */
uint8_t Ringbuff_PutByte(RINGBUFF *ring, uint8_t byte)
{
    if((Ringbuff_GetLenght(ring) + 1) == ring->lenght) return RINGBUFF_FAIL;

    ring->buff_addr[ring->tail++] = byte;

    if(ring->tail == ring->lenght) ring->tail = 0;

    return RINGBUFF_SUCCESS;
}

/*  
 *  名称：取出字节
 *  描述：将缓存数据取出
 *  输入：ring：目标结构体，size：要提取字节数
 *  输出：buff：提取的字节
 *  返回：已提取字节数
 */
uint16_t Ringbuff_Push(RINGBUFF *ring, uint8_t buff[], uint16_t size)
{
    uint16_t lenght = Ringbuff_GetLenght(ring);

    if(size < lenght) lenght = size;

    if(ring->head < ring->tail){

        memcpy(buff, ring->buff_addr + ring->head, lenght);
    }else{

        uint16_t pos = ring->lenght - ring->head;

        memcpy(buff, ring->buff_addr + ring->head, pos);
        memcpy(buff + pos, ring->buff_addr, lenght - pos);
    }

    ring->head = (ring->head + lenght) % ring->lenght;
    return lenght;
}

uint8_t Ringbuff_PushBte(RINGBUFF *ring, uint8_t *byte)
{
    if(Ringbuff_GetLenght(ring) == 0) return RINGBUFF_FAIL; 

    *byte = ring->buff_addr[ring->head++];

    if(ring->head == ring->lenght) ring->head = 0;
    
    return RINGBUFF_SUCCESS;
}

void Ringbuff_Clear(RINGBUFF *ring, uint16_t lenght)
{
    uint16_t size = Ringbuff_GetLenght(ring);

    if(size > lenght) size = lenght;

    ring->head = (ring->head + size) % ring->lenght;
}

void Ringbuff_ClearAll(RINGBUFF *ring)
{
    ring->head = 0;
    ring->tail = 0;
}

uint8_t Ringbuff_ReadByte(RINGBUFF *ring, uint16_t pos)
{
    uint16_t des = (ring->head + pos) % ring->lenght;

    return ring->buff_addr[des];
}


