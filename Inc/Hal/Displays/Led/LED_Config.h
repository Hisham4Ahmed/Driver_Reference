/**
 * @file   LED_Config.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */


#ifndef _LED_CONFIG_H_
#define  _LED_CONFIG_H_

/**
 * @def  
 * @brief 
 *   Led_SourceConnection 
     Led_SinkConnection
 */
#define ConnectionType     Led_SourceConnection

#define BlinkTime      1000 
#define MaxLed         8


#define Led1_Group     GroupA
#define Led1_Pin       Pin0

#define Led2_Group     GroupA
#define Led2_Pin       Pin1


#define Led3_Group     GroupA
#define Led3_Pin       Pin2

#define Led4_Group     GroupA
#define Led4_Pin       Pin3

#define Led5_Group     GroupA
#define Led5_Pin       Pin4

#define Led6_Group     GroupA
#define Led6_Pin       Pin5


#define   LEDGROUPVALUE       {Led1_Group,Led2_Group,Led3_Group,Led4_Group,Led5_Group,Led6_Group}
#define   LEDPINVALUE         {Led1_Pin,Led2_Pin,Led3_Pin,Led4_Pin,Led5_Pin,Led6_Pin}

#endif 