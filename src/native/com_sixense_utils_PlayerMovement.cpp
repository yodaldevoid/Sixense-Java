/*
* This file is part of Sixense Java.
*
* Copyright © 2012-2013, Sixense Java Contributors
* FTB Launcher is licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "sixense_java_utils.h"
#include "fps.hpp"
#include "com_sixense_utils_PlayerMovement.h"

using sixenseUtils::FPSPlayerMovement;

JNIEXPORT jlong JNICALL Java_com_sixense_utils_PlayerMovement_create(JNIEnv *, jobject) {
    FPSPlayerMovement * pMovement = new FPSPlayerMovement();
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
    FPSPlayerMovement * pMovement = (FPSPlayerMovement *)env->GetLongField(self, fid);
    const char * nstr = env->GetStringUTFChars(str, NULL);
    if(nstr == NULL) {
        return;
    }
    pMovement->setGame(nstr);
    return;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_utils_PlayerMovement_update(JNIEnv *env, jobject self, jobject leftRef, jobject rightRef, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    FPSPlayerMovement * pMovement = (FPSPlayerMovement *)env->GetLongField(self, fid);
    sixenseControllerData * leftData = getControllerData(env, leftRef);
    sixenseControllerData * rightData = getControllerData(env, rightRef);
    return pMovement->update(leftData, rightData, flo) == SIXENSE_SUCCESS ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_PlayerMovement_getWalkDir(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSPlayerMovement * pMovement = (FPSPlayerMovement *)env->GetLongField(self, fid);
    Vector2 vec = pMovement->getWalkDir();
    jfloatArray arr = NULL;
    jfloat arr2[2] = {vec[0], vec[1]};
    env->SetFloatArrayRegion(arr, 0, 2, arr2);
    return arr;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_PlayerMovement_setParameter(JNIEnv *env, jobject self, jobject enumObj, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    FPSPlayerMovement * pMovement = (FPSPlayerMovement *)env->GetLongField(self, fid);
    FPSPlayerMovement::fps_movement_params param;
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumMovementParam");
    if(enumClass == NULL) return;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "DEAD_ZONE_PERCENT") == 0) {
        param = FPSPlayerMovement::DEAD_ZONE_PERCENT;
    } else if(strcmp(valueNative, "EXPONENTIAL") == 0) {
        param = FPSPlayerMovement::EXPONENTIAL;
    } else if(strcmp(valueNative, "USE_RIGHT_HAND") == 0) {
        param = FPSPlayerMovement::USE_RIGHT_HAND;
    } else if(strcmp(valueNative, "LEFT_HANDED") == 0) {
        param = FPSPlayerMovement::LEFT_HANDED;
    } else {
        param = FPSPlayerMovement::LAST_FPS_MOVEMENT_PARAM;
    }
    pMovement->setParameter(param, flo);
    return;
}

JNIEXPORT jfloat JNICALL Java_com_sixense_utils_PlayerMovement_getParameter(JNIEnv *env, jobject self, jobject enumObj) {
    jfieldID fid = getPeerID(env, self);
    FPSPlayerMovement * pMovement = (FPSPlayerMovement *)env->GetLongField(self, fid);
    FPSPlayerMovement::fps_movement_params param;
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumMovementParam");
    if(enumClass == NULL) return 0.0;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return 0.0;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "DEAD_ZONE_PERCENT") == 0) {
        param = FPSPlayerMovement::DEAD_ZONE_PERCENT;
    } else if(strcmp(valueNative, "EXPONENTIAL") == 0) {
        param = FPSPlayerMovement::EXPONENTIAL;
    } else if(strcmp(valueNative, "USE_RIGHT_HAND") == 0) {
        param = FPSPlayerMovement::USE_RIGHT_HAND;
    } else if(strcmp(valueNative, "LEFT_HANDED") == 0) {
        param = FPSPlayerMovement::LEFT_HANDED;
    } else {
        param = FPSPlayerMovement::LAST_FPS_MOVEMENT_PARAM;
    }
    return pMovement->getParameter(param);
}
