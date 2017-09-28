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
  * @brief  ѭ�����г�ʼ��
  * @param  [in]*Q:Ҫ��ʼ���Ķ��е�ָ��
            [in]*pbuf:���л�����ָ��
            [in]qsize:���еĴ�С
  * @retval FUN_ERROR:��ʼ��ʧ��
            FUN_OK:��ʼ���ɹ�
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
  * @brief  �����
  * @param  [out]*Q: ����ָ��
            [in]element: Ҫ����е�Ԫ��
  * @retval FUN_ERROR:�����ʧ��  ������
            FUN_OK:����гɹ�
  */
 FUN_StatusTypeDef EnRingQueue(RingQueue_TypeDef*Q,QElemType element)
 {
     if((Q->rear + 1)%(Q->qsize) == Q->front)   /* ������ */
     {
	     return FUN_ERROR;
     }
	 Q->pbuf[Q->rear] = element;
	 Q->rear = (Q->rear +1 )%(Q->qsize);
     return FUN_OK;
 }
/**
  * @brief  ������
  * @param  None
  * @retval FUN_ERROR:������ʧ��  ���п�
            FUN_OK:�����гɹ�
  */
FUN_StatusTypeDef DeRingQueue(RingQueue_TypeDef*Q,QElemType* element)
{
    if(Q->front == Q->rear)   /* ���п� */
    {
	    return FUN_ERROR;
    }
	*element = Q->pbuf[Q->front];
	Q->front = (Q->front + 1)%(Q->qsize);
    return FUN_OK;
 }
/**
  * @brief  ������
  * @param  None
  * @retval
  */
uint16_t RingQueueGetLen(RingQueue_TypeDef Q)
{
    return (Q.rear - Q.front + (Q.qsize))%(Q.qsize);
}

 	









/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/

