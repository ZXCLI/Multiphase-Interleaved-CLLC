#include "MY_DEBUG.h"

void CLLC_HAL_DEBUG_Transnit(void)
{
    char DEBUG_Buffer[100];

    float32_t Vprim = (CLLC_vPrimSensedAvg_pu.out *
                       CLLC_VPRIM_MAX_SENSE_VOLTS);
    float32_t Vsec = (CLLC_vSecSensedAvg_pu.out *
                      CLLC_VSEC_MAX_SENSE_VOLTS);
    float32_t Iprim1 = (CLLC_iPrimMAINSensedAvg_pu.out *
                        CLLC_IPRIM_MAX_BRANCH_SENSE_AMPS * 100.0f);
    float32_t Isec1 = (CLLC_iSecMAINSensedAvg_pu.out *
                       CLLC_ISEC_MAX_BRACH_SENSE_AMPS * 100.0f);
    DEBUG2_TRACE_IN;
    formatData(Vprim, Vsec, Iprim1, Isec1, DEBUG_Buffer);
    // formatData(CLLC_iPrimMAINTankSensedOffset_pu * 1000.0f,
    //            CLLC_iSecMAINSensedOffset_pu * 1000.0f,
    //            CLLC_iPrimMAINSensedOffset_pu * 1000.0f,
    //            CLLC_iPrimSECONDARYTankSensedOffset_pu * 1000.0f, DEBUG_Buffer);

    UARTprintf(DEBUG_Buffer);
}
