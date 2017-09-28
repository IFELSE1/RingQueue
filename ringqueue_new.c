/**
  ******************************************************************************
  * @file           : ringqueue.c
  * @author         : liuchengfei
  * @version        : v1.0
  * @date           : 2017.09
  * @brief          : 
  *
  ******************************************************************************
  * @attention  顺序存储循环队列
  *
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "ringqueue.h" 
#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "app_error.h"
#include "sys.h"
/* Private define ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private function ----------------------------------------------------------*/

/* Exported function ----------------------------------------------------------*/

/**
  * @brief  循环队列初始化
  * @param  [in]*Q:要初始化的队列的指针
            [in]*pbuf:队列缓冲区指针
            [in]qsize:队列的大小
  * @retval FUN_ERROR:初始化失败
            FUN_OK:初始化成功
  */
 FUN_StatusTypeDef RingQueueInit(RingQueue_TypeDef* Q,QElemType * pbuf,uint16_t qsize)
 {
    if((Q==NULL)||(pbuf == NULL)||(qsize > MAXSIZE)||(qsize <= 0))
    {
        return FUN_ERROR;
    }
    Q->front = 0;
    Q->rear = 0;
    Q->qsize = qsize;
    Q->pbuf = pbuf;
    return FUN_OK;
 }

/**
  * @brief  入队列
  * @param  [out]*Q: 队列指针
            [in]element: 要入队列的元素
  * @retval FUN_ERROR:入队列失败  队列满
            FUN_OK:入队列成功
  */
 FUN_StatusTypeDef EnRingQueue(RingQueue_TypeDef*Q,QElemType element)
 {
     if((Q->rear + 1)%(Q->qsize) == Q->front)   /* 队列满 */
     {
	     return FUN_ERROR;
     }
	 Q->pbuf[Q->rear] = element;
	 Q->rear = (Q->rear +1 )%(Q->qsize);
     return FUN_OK;
 }
/**
  * @brief  出队列
  * @param  None
  * @retval FUN_ERROR:出队列失败  队列空
            FUN_OK:出队列成功
  */
FUN_StatusTypeDef DeRingQueue(RingQueue_TypeDef*Q,QElemType* element)
{
    if(Q->front == Q->rear)   /* 队列空 */
    {
	    return FUN_ERROR;
    }
	*element = Q->pbuf[Q->front];
	Q->front = (Q->front + 1)%(Q->qsize);
    return FUN_OK;
 }
/**
  * @brief  出队列
  * @param  None
  * @retval
  */
uint16_t RingQueueGetLen(RingQueue_TypeDef Q)
{
    return (Q.rear - Q.front + (Q.qsize))%(Q.qsize);
}

 	









/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/

