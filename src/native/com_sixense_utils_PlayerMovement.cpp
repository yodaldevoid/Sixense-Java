#include "sixense_java_utils.h"
#include "fps.hpp"
#include "com_sixense_utils_PlayerMovement.h"

JNIEXPORT jlong JNICALL Java_com_sixense_utils_PlayerMovement_create(JNIEnv *, jobject) {
    sixenseUtils::FPSPlayerMovement * pMovement = new sixenseUtils::FPSPlayerMovement();
    return (jlong) pMovement;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_PlayerMovement_destroy(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    jlong peer = env->GetLongField(self, fid);
    if(peer == 0) {
        return;
    }
    free((void *) peer);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_PlayerMovement_setGame(JNIEnv *env, jobject self, jstring str) {
    jfieldID fid = getPeerID(env, self);
    sixenseUtils::FPSPlayerMovement * pMovement = (sixenseUtils::FPSPlayerMovement *)env->GetLongField(self, fid);
    const char * nstr = env->GetStringUTFChars(str, NULL);
    if(nstr == NULL) {
        return;
    }
    pMovement->setGame(nstr);
    return;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_utils_PlayerMovement_update(JNIEnv *env, jobject self, jobject leftRef, jobject rightRef, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    sixenseUtils::FPSPlayerMovement * pMovement = (sixenseUtils::FPSPlayerMovement *)env->GetLongField(self, fid);
    sixenseControllerData * leftData = getControllerData(env, leftRef);
    sixenseControllerData * rightData = getControllerData(env, rightRef);
    return pMovement->update(leftData, rightData, flo) == SIXENSE_SUCCESS ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_PlayerMovement_getWalkDir(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    sixenseUtils::FPSPlayerMovement * pMovement = (sixenseUtils::FPSPlayerMovement *)env->GetLongField(self, fid);
    Vector2 vec = pMovement->getWalkDir();
    jfloatArray arr = NULL;
    jfloat arr2[2] = {vec[0], vec[1]};
    env->SetFloatArrayRegion(arr, 0, 2, arr2);
    return arr;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_PlayerMovement_setParameter(JNIEnv *env, jobject self, jobject enumObj, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    sixenseUtils::FPSPlayerMovement * pMovement = (sixenseUtils::FPSPlayerMovement *)env->GetLongField(self, fid);
    sixenseUtils::FPSPlayerMovement::fps_movement_params param;
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumMovementParam");
    if(enumClass == NULL) return;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "DEAD_ZONE_PERCENT") == 0) {
        param = sixenseUtils::FPSPlayerMovement::DEAD_ZONE_PERCENT;
    } else if(strcmp(valueNative, "EXPONENTIAL") == 0) {
        param = sixenseUtils::FPSPlayerMovement::EXPONENTIAL;
    } else if(strcmp(valueNative, "USE_RIGHT_HAND") == 0) {
        param = sixenseUtils::FPSPlayerMovement::USE_RIGHT_HAND;
    } else if(strcmp(valueNative, "LEFT_HANDED") == 0) {
        param = sixenseUtils::FPSPlayerMovement::LEFT_HANDED;
    } else {
        param = sixenseUtils::FPSPlayerMovement::LAST_FPS_MOVEMENT_PARAM;
    }
    pMovement->setParameter(param, flo);
    return;
}

JNIEXPORT jfloat JNICALL Java_com_sixense_utils_PlayerMovement_getParameter(JNIEnv *env, jobject self, jobject enumObj) {
    jfieldID fid = getPeerID(env, self);
    sixenseUtils::FPSPlayerMovement * pMovement = (sixenseUtils::FPSPlayerMovement *)env->GetLongField(self, fid);
    sixenseUtils::FPSPlayerMovement::fps_movement_params param;
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumMovementParam");
    if(enumClass == NULL) return 0.0;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return 0.0;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "DEAD_ZONE_PERCENT") == 0) {
        param = sixenseUtils::FPSPlayerMovement::DEAD_ZONE_PERCENT;
    } else if(strcmp(valueNative, "EXPONENTIAL") == 0) {
        param = sixenseUtils::FPSPlayerMovement::EXPONENTIAL;
    } else if(strcmp(valueNative, "USE_RIGHT_HAND") == 0) {
        param = sixenseUtils::FPSPlayerMovement::USE_RIGHT_HAND;
    } else if(strcmp(valueNative, "LEFT_HANDED") == 0) {
        param = sixenseUtils::FPSPlayerMovement::LEFT_HANDED;
    } else {
        param = sixenseUtils::FPSPlayerMovement::LAST_FPS_MOVEMENT_PARAM;
    }
    return pMovement->getParameter(param);
}
