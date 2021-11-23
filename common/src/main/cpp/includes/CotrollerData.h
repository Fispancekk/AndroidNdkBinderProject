#pragma once

#include <android/binder_status.h>
#include "LogDefs.h"

namespace aidl {
    namespace com {
        namespace example {

            class CotrollerData
            {
            public:
                float C_CotrollerPosition[3];
                float C_CotrollerRotate[4];
                float T_TouchPadPosition[2];
                int B_ButtonPress;

            public:
                CotrollerData()
                {
                    memset(C_CotrollerPosition, 0, sizeof(C_CotrollerPosition));
                    memset(C_CotrollerRotate, 0, sizeof(C_CotrollerRotate));
                    memset(T_TouchPadPosition, 0, sizeof(T_TouchPadPosition));
                    B_ButtonPress= -1;
                }



                CotrollerData(float cCotrollerPosition[3], float cCotrollerRotate[4],
                              float tTouchPadPosition[2], int bButtonPress)
                {
                    memcpy(C_CotrollerPosition,cCotrollerPosition,sizeof(C_CotrollerPosition));
                    memcpy(C_CotrollerRotate,cCotrollerRotate,sizeof(C_CotrollerRotate));
                    memcpy(T_TouchPadPosition,tTouchPadPosition,sizeof(T_TouchPadPosition));
                    B_ButtonPress = bButtonPress;
                }

            public:
                binder_status_t readFromParcel(const AParcel* pParcel)
                {
                    LOGD("Fispancer1 %d", AParcel_getDataPosition(pParcel));
//                    int32_t iNotNull;
//                    AParcel_readInt32(pParcel, &iNotNull);
                    LOGD("Fispancer2 %d", AParcel_getDataPosition(pParcel));
//                    AParcel_setDataPosition(pParcel,8);
                    LOGD("Fispancer21423515341 %d", AParcel_getDataPosition(pParcel));
                    AParcel_readFloat(pParcel, &C_CotrollerPosition[0]);
                    AParcel_readFloat(pParcel, &C_CotrollerPosition[1]);
                    AParcel_readFloat(pParcel, &C_CotrollerPosition[2]);
                    LOGD("Fispancer3floats %d", AParcel_getDataPosition(pParcel));
                    AParcel_readFloat(pParcel, &C_CotrollerRotate[0]);
                    AParcel_readFloat(pParcel, &C_CotrollerRotate[1]);
                    AParcel_readFloat(pParcel, &C_CotrollerRotate[2]);
                    AParcel_readFloat(pParcel, &C_CotrollerRotate[3]);
                    LOGD("Fispancer4floats %d", AParcel_getDataPosition(pParcel));
                    AParcel_readFloat(pParcel, &T_TouchPadPosition[0]);
                    AParcel_readFloat(pParcel, &T_TouchPadPosition[1]);
                    AParcel_readInt32(pParcel, &B_ButtonPress);
                    LOGD("Fispancerfinals %d", AParcel_getDataPosition(pParcel));

                    return STATUS_OK;
                }

                binder_status_t writeToParcel(AParcel* pParcel) const
                {
                    LOGD("Fispancew1 %d", AParcel_getDataPosition(pParcel));

//                    int32_t iNotNull = 1;
//                    AParcel_writeInt32(pParcel, iNotNull);
                    LOGD("Fispancew2 %d", AParcel_getDataPosition(pParcel));

                    AParcel_writeFloat(pParcel, C_CotrollerPosition[0]);
                    AParcel_writeFloat(pParcel, C_CotrollerPosition[1]);
                    AParcel_writeFloat(pParcel, C_CotrollerPosition[2]);
                    LOGD("Fispancew3floats %d", AParcel_getDataPosition(pParcel));
                    AParcel_writeFloat(pParcel, C_CotrollerRotate[0]);
                    AParcel_writeFloat(pParcel, C_CotrollerRotate[1]);
                    AParcel_writeFloat(pParcel, C_CotrollerRotate[2]);
                    AParcel_writeFloat(pParcel, C_CotrollerRotate[3]);
                    LOGD("Fispancew4floats %d", AParcel_getDataPosition(pParcel));
                    AParcel_writeFloat(pParcel, T_TouchPadPosition[0]);
                    AParcel_writeFloat(pParcel, T_TouchPadPosition[1]);
                    AParcel_writeInt32(pParcel, B_ButtonPress);
                    LOGD("Fispancewfinals %d", AParcel_getDataPosition(pParcel));
//                    LOGD("Ewanw3 %d", AParcel_getDataPosition(pParcel));

                    return STATUS_OK;
                }

                void toString(std::string* pOutputString)
                {
                    char strBuf[1024];
                    snprintf(strBuf, 1024,
                             "CotrollerData{CotrollerPosition={%f,%f,%f},CotrollerRotate={%f,%f,%f,%f}, TouchPadPosition={%f,%f},ButtonPress=%d}",
                             C_CotrollerPosition[0],C_CotrollerPosition[1],C_CotrollerPosition[2],C_CotrollerRotate[0],C_CotrollerRotate[1],C_CotrollerRotate[2],C_CotrollerRotate[3]
                            ,T_TouchPadPosition[0], T_TouchPadPosition[1], B_ButtonPress);

                    pOutputString->append(strBuf);
                }
            };

        } // namespace example
    } // namespace com
} // namespace aidl