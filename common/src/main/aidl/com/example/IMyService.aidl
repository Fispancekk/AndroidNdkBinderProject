// IMyService.aidl
package com.example;

// Declare any non-default types here with import statements
import com.example.ComplexType;
import com.example.CotrollerData;

interface IMyService {
    /**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
//    void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat,
//            double aDouble, String aString);
//
//    /**
//     * Demonstrates complex type that you can use as a parameter in AIDL.
//     */
//    String complexType(in ComplexType aComplexObject);
//
//    /**
//     * Demonstrates complex type that you can use as a return value in AIDL.
//     */
//    ComplexType returnComplexType(int anInt, long aLong, boolean aBoolean,
//            float aFloat, double aDouble, String aString);

    String cotrollerData(in CotrollerData aCotrollerObject);

    CotrollerData returnCoTrollerData(in CotrollerData aCotrollerObject);
}
