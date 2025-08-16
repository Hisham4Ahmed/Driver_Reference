/**
 * @file GPR_Config.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-13
 * 
 * @copyright Copyright (c) 2025 , Gestell Company 
 * 
 */



#ifndef _GPR_CONFIG_H
#define _GPR_CONFIG_H


#define MaxGPR          2 

/*GPR1*/
#define GPR1_Group          GroupA
#define GPR1_RedPin         Pin0
#define GPR1_GreenPin       Pin1
#define GPR1_BluePin        Pin2 

/*GPR2*/
#define GPR2_Group          GroupB
#define GPR2_RedPin         Pin0
#define GPR2_GreenPin       Pin1
#define GPR2_BluePin        Pin2 

#define GPRGROUPVALUE {GPR1_Group,GPR2_Group}
#define GPRPINVALUE  {{GPR1_RedPin,GPR1_GreenPin,GPR1_BluePin},\
                      {GPR2_RedPin,GPR2_GreenPin,GPR2_BluePin},}

#endif 

