/**
  ******************************************************************************
  * @file           : ringqueue.h
  * @author         : liuchengfei
  * @version        : v1.0
  * @date           : 2017.09
  * @brief          : 
  *
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RINGQUEUE_H
#define __RINGQUEUE_H	 
/* Includes ------------------------------------------------------------------*/
#include "nrf.h"
#include "nrf_delay.h"
#include "simple_hal.h"
#include "nrf_drv_config.h"
#include "pca10028.h"
#include "sys.h"

/* Private types -------------------------------------------------------------*/
/**
  * @brief  队列最大大小限制
  */
#define  MAXSIZE   1024

/**
  * @brief  
  */
typedef uint8_t QElemType;

/**
  * @brief  循环队列顺序存储结构 
  */
typedef struct
{
	QElemType * pbuf;  /* 缓冲区指针 */
    uint16_t qsize;   /* 队列大小 */
	uint8_t front;    /* 头指针 */
	uint8_t rear;     /* 尾指针 */
}RingQueue_TypeDef;

/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/ 
FUN_StatusTypeDef RingQueueInit(RingQueue_TypeDef* Q,QElemType * pbuf,uint16_t qsize);
FUN_StatusTypeDef EnRingQueue(RingQueue_TypeDef*Q,QElemType element);
FUN_StatusTypeDef DeRingQueue(RingQueue_TypeDef*Q,QElemType* element);
uint16_t RingQueueGetLen(RingQueue_TypeDef Q);






#endif /* __RINGQUEUE_H */
/************************ (C) COPYRIGHT ZiFiSense *****END OF FILE****/

