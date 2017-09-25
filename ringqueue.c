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
  * @param  None
  * @retval None
  */
 void QueueInit(SqQueue* Q)
 {
	Q->front = 0;
   	Q->rear = 0;
 }
/**
  * @brief  获取循环队列数据长度
  * @param  None
  * @retval None
  */
 uint8_t QueueGetLen(SqQueue Q)
 {
	 return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
 }
 /**
  * @brief  入队列
  * @param  None
  * @retval None
  */
 FUN_StatusTypeDef EnQueue(SqQueue*Q,QElemType e)
 {
	 if((Q->rear + 1)%MAXSIZE == Q->front)   /* 满 */
	 return FUN_ERROR;
	 Q->data[Q->rear] = e;
	 Q->rear =  (Q->rear +1 )%MAXSIZE;
     return FUN_OK;
 }
  /**
  * @brief  出队列
  * @param  None
  * @retval None
  */
FUN_StatusTypeDef DeQueue(SqQueue*Q,QElemType* e)
{
    if(Q->front == Q->rear)   /* 空 */
	return FUN_ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1)%MAXSIZE;
    return FUN_OK;
 }
 
 	









/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/

