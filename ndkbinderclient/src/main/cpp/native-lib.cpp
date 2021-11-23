#include <jni.h>
#include <aidl/com/example/IMyService.h>
#include <android/binder_ibinder_jni.h>
#include <LogDefs.h>

using aidl::com::example::IMyService;
using aidl::com::example::ComplexType;
using aidl::com::example::CotrollerData;
using ndk::ScopedAStatus;
using namespace std;

std::shared_ptr<IMyService> g_spMyService;

extern "C" JNIEXPORT void JNICALL
Java_com_example_ndkbinderclient_MainActivity_onServiceConnected(
        JNIEnv* env,
        jobject /* this */,
        jobject binder)
{
    AIBinder* pBinder = AIBinder_fromJavaBinder(env, binder);

    const ::ndk::SpAIBinder spBinder(pBinder);
    g_spMyService = IMyService::fromBinder(spBinder);

    LOGD("[App] [cpp] onServiceConnected");
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_ndkbinderclient_MainActivity_onServiceDisconnected(
        JNIEnv* env,
        jobject /* this */)
{
    g_spMyService = nullptr;

    LOGD("[App] [cpp] onServiceDisconnected");
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkbinderclient_MainActivity_talkToService(
        JNIEnv* env,
        jobject /* this */)
{
//    LOGD("[AppDebugging] TalkToServiceUsing");
//    ScopedAStatus basicTypesResult = g_spMyService->basicTypes(1017, 56653000,
//            true, 1.43f, 3.141592653589793238, "!");
//
//    if(basicTypesResult.isOk())
//    {
//        LOGD("[App] [cpp] IMyService.basicTypes - Succeeded");
//    }
//    else
//    {
//        LOGE("[App] [cpp] IMyService.basicTypes - Failed");
//    }
//
//    ComplexType ct(2021, 65535000, true, 3.14f,3.141592653589793238,
//            "Hello, World!");
//
    std::string sReturnedString;
//
//    ScopedAStatus complexTypeResult = g_spMyService->complexType(ct, &sReturnedString);
//
//    if(complexTypeResult.isOk())
//    {
//        LOGD("[App] [cpp] IMyService.complexType - Succeeded");
//    }
//    else
//    {
//        LOGE("[App] [cpp] IMyService.complexType - Failed");
//    }
//
//    ComplexType returnedComplexObject;
//
//    ScopedAStatus returnComplexTypeResult = g_spMyService->returnComplexType(2048,
//            65550333, true, 1.37f, 3.141592653589793238,
//            "!", &returnedComplexObject);
//
//    if(returnComplexTypeResult.isOk())
//    {
//        LOGD("[App] [cpp] IMyService.complexType - Succeeded");
//    }
//    else
//    {
//        LOGE("[App] [cpp] IMyService.complexType - Failed");
//    }
//
//    std::string sRet;
//    returnedComplexObject.toString(&sRet);
    //开始Array
     float devicePosi[3] = {3.14f,3.17f,3.20f};
     float deviceRota[4] = {3.15f,3.16f,3.17f,3.18f};
     float touchPosi[2] = {1.14f,1.19f};
     int buttonKey=4;

    CotrollerData cdata(devicePosi,deviceRota,touchPosi,buttonKey);

    std::string sReturnedData;

    ScopedAStatus cotrollerDataResult = g_spMyService->cotrollerData(cdata, &sReturnedString);

    if(cotrollerDataResult.isOk())
    {
        LOGD("[App] [cpp] IMyService.cotrollerData - Succeeded");
    }
    else
    {
        LOGE("[App] [cpp] IMyService.cotrollerData - Failed");
    }
    float devicePosit[3] = {5.14f,5.17f,5.20f};
    float deviceRotat[4] = {5.15f,5.16f,5.17f,5.18f};
    float touchPosit[2] = {2.14f,2.19f};
    int buttonKeyt=7;


    CotrollerData returncdata(devicePosit,deviceRotat,touchPosit,buttonKeyt);

    ScopedAStatus returnCtrollerDataResult = g_spMyService->returnCoTrollerData(returncdata,&returncdata);

    if(returnCtrollerDataResult.isOk())
    {
        LOGD("[App] [cpp] IMyService.returnCtrollerData - Succeeded");
    }
    else
    {
        LOGE("[App] [cpp] IMyService.returnCtrollerData - Failed");
    }
    std::string controlResult;
    returncdata.toString(&controlResult);


    return env->NewStringUTF(controlResult.c_str());
}
