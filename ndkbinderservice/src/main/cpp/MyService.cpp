#include "MyService.h"
#include <LogDefs.h>

using aidl::com::example::MyService;
using aidl::com::example::CotrollerData;

//ScopedAStatus MyService::basicTypes(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean,
//        float in_aFloat, double in_aDouble, const std::string &in_aString)
//{
//    LOGD("[MyService] [cpp] basicTypes: int=%d, long=%lld, bool=%d, float=%f, double=%f, string=%s",
//            in_anInt, in_aLong, in_aBoolean, in_aFloat, in_aDouble, in_aString.c_str());
//
//    return ScopedAStatus::ok();
//}

//ScopedAStatus MyService::complexType(const ComplexType &in_aComplexObject, std::string* _aidl_return)
//{
//    LOGD("[MyService] [cpp] complexType: int=%d, long=%ld, bool=%d, float=%f, double=%lf, string=%s"
//    , in_aComplexObject.i_Int,
//         in_aComplexObject.l_Long,
//         in_aComplexObject.b_Boolean,
//         in_aComplexObject.f_Float,
//         in_aComplexObject.d_Double
//         ,in_aComplexObject.s_String.c_str()
//         );

//    char strBuf[1024];
//
//    snprintf(strBuf, 1024, "int=%d, long=%ld, bool=%d, float=%f, double=%lf, string=%s",
//            in_aComplexObject.i_Int,
//            in_aComplexObject.l_Long,
//            in_aComplexObject.b_Boolean,
//            in_aComplexObject.f_Float,
//            in_aComplexObject.d_Double
//            ,in_aComplexObject.s_String.c_str()
//            );
//    LOGD("[MyService] [cpp] complexTypes:returnstring=%s",strBuf);
//
//    *_aidl_return = std::string(strBuf);
//
//    return ScopedAStatus::ok();
//}

//ScopedAStatus complexArray(const ComplexArray& in_aComplexObject, ComplexType* _aidl_return){
//    char strBuf[1024];
//    int32_t in_anInt;
//    int readLen = 0;
//    float *readPencilData = NULL;
//
//    snprintf(strBuf, 1024, "int=%d, long=%ld, bool=%d, float=%f, double=%lf, string=%s",
//             in_aComplexObject.i_Int,
//             in_aComplexObject.l_Long,
//             in_aComplexObject.b_Boolean,
//             in_aComplexObject.f_Float,
//             in_aComplexObject.d_Double
//            ,in_aComplexObject.s_String.c_str()
//    );
//
//    _aidl_return->i_Int = in_anInt;
//
//    return ScopedAStatus::ok();
//
//}

//ScopedAStatus MyService::returnComplexType(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean,
//        float in_aFloat, double in_aDouble, const std::string &in_aString,
//        ComplexType *_aidl_return)
//{
//    LOGD("[MyService] [cpp] returnComplexType: bool");
//    in_aFloat=in_aFloat+1;
//    in_aDouble++;
//    in_anInt++;
//
//    LOGD("[MyService] [cpp] returnComplexType: float=%f, double=%f", in_aFloat+1, in_aDouble+1);
//    LOGD("Ewanw2 %d", in_anInt+1);
//    LOGD("[MyService] [cpp] returnComplexType: int=%d, long=%lld, bool=%d, float=%f, double=%f, string=%s",
//         in_anInt, in_aLong, in_aBoolean, in_aFloat, in_aDouble, in_aString.c_str());
//
//    _aidl_return->i_Int = in_anInt;
//    _aidl_return->l_Long = in_aLong;
//    _aidl_return->b_Boolean = in_aBoolean;
//    _aidl_return->f_Float = in_aFloat;
//    _aidl_return->d_Double = in_aDouble;
//    _aidl_return->s_String = in_aString;
//
//    return ScopedAStatus::ok();
//}


ScopedAStatus MyService::cotrollerData(const CotrollerData& in_aCotrollerObject, std::string* _aidl_return){
    char strBuf[1024];

    snprintf(strBuf, 1024, "CotrollerData{CotrollerPosition={%f,%f,%f},CotrollerRotate={%f,%f,%f,%f}, TouchPadPosition={%f,%f},ButtonPress=%d}",
             in_aCotrollerObject.C_CotrollerPosition[0],in_aCotrollerObject.C_CotrollerPosition[1],in_aCotrollerObject.C_CotrollerPosition[2],
            in_aCotrollerObject.C_CotrollerRotate[0],in_aCotrollerObject.C_CotrollerRotate[1],in_aCotrollerObject.C_CotrollerRotate[2],in_aCotrollerObject.C_CotrollerRotate[3],
            in_aCotrollerObject.T_TouchPadPosition[0],in_aCotrollerObject.T_TouchPadPosition[1],in_aCotrollerObject.B_ButtonPress
    );
    LOGD("[MyService] [cpp] ControllerDatas:return string=%s",strBuf);

    *_aidl_return = std::string(strBuf);

    return ScopedAStatus::ok();
}


ScopedAStatus MyService::returnCoTrollerData(const CotrollerData& in_aCotrollerObject, CotrollerData* _aidl_return) {
    LOGD("CotrollerData{CotrollerPosition={%f,%f,%f},CotrollerRotate={%f,%f,%f,%f}, TouchPadPosition={%f,%f},ButtonPress=%d}",
         in_aCotrollerObject.C_CotrollerPosition[0],in_aCotrollerObject.C_CotrollerPosition[1],in_aCotrollerObject.C_CotrollerPosition[2],
         in_aCotrollerObject.C_CotrollerRotate[0],in_aCotrollerObject.C_CotrollerRotate[1],in_aCotrollerObject.C_CotrollerRotate[2],in_aCotrollerObject.C_CotrollerRotate[3],
         in_aCotrollerObject.T_TouchPadPosition[0],in_aCotrollerObject.T_TouchPadPosition[1],in_aCotrollerObject.B_ButtonPress);

    _aidl_return->C_CotrollerPosition[0] = in_aCotrollerObject.C_CotrollerPosition[0];
    _aidl_return->C_CotrollerPosition[1] = in_aCotrollerObject.C_CotrollerPosition[1];
    _aidl_return->C_CotrollerPosition[2] = in_aCotrollerObject.C_CotrollerPosition[2];
    _aidl_return->C_CotrollerRotate[0] = in_aCotrollerObject.C_CotrollerRotate[0];
    _aidl_return->C_CotrollerRotate[1] = in_aCotrollerObject.C_CotrollerRotate[1];
    _aidl_return->C_CotrollerRotate[2] = in_aCotrollerObject.C_CotrollerRotate[2];
    _aidl_return->C_CotrollerRotate[3] = in_aCotrollerObject.C_CotrollerRotate[3];
    _aidl_return->T_TouchPadPosition[0] = in_aCotrollerObject.T_TouchPadPosition[0];
    _aidl_return->T_TouchPadPosition[1] = in_aCotrollerObject.T_TouchPadPosition[1];
    _aidl_return->B_ButtonPress=in_aCotrollerObject.B_ButtonPress;

    return ScopedAStatus::ok();
}
