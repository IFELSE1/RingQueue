/**
  ******************************************************************************
  * @file           : ringqueue.c
  * @author         : liuchengfei
  * @version        : v1.0
  * @date           : 2017.09
  * @brief          : 
  *
  ******************************************************************************
  * @attention  ˳��洢ѭ������
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
  * @brief  ѭ�����г�ʼ��
  * @param  None
  * @retval None
  */
 void QueueInit(SqQueue* Q)
 {
	Q->front = 0;
   	Q->rear = 0;
 }
/**
  * @brief  ��ȡѭ���������ݳ���
  * @param  None
  * @retval None
  */
 uint8_t QueueGetLen(SqQueue Q)
 {
	 return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
 }
 /**
  * @brief  �����
  * @param  None
  * @retval None
  */
 FUN_StatusTypeDef EnQueue(SqQueue*Q,QElemType e)
 {
	 if((Q->rear + 1)%MAXSIZE == Q->front)   /* �� */
	 return FUN_ERROR;
	 Q->data[Q->rear] = e;
	 Q->rear =  (Q->rear +1 )%MAXSIZE;
     return FUN_OK;
 }
  /**
  * @brief  ������
  * @param  None
  * @retval None
  */
FUN_StatusTypeDef DeQueue(SqQueue*Q,QElemType* e)
{
    if(Q->front == Q->rear)   /* �� */
	return FUN_ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1)%MAXSIZE;
    return FUN_OK;
 }
 
 	









/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/

