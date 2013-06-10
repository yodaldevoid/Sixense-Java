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
#include "com_sixense_utils_ViewAngles.h"

using sixenseUtils::FPSViewAngles;

JNIEXPORT jlong JNICALL Java_com_sixense_utils_ViewAngles_create(JNIEnv *, jobject) {
    FPSViewAngles * vAngles = new FPSViewAngles();
    return (jlong) vAngles;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_destroy(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    jlong peer = env->GetLongField(self, fid);
    if(peer == 0) {
        return;
    }
    free((void *) peer);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_setGame(JNIEnv *env, jobject self, jstring str) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    const char * nstr = env->GetStringUTFChars(str, NULL);
    if(nstr == NULL) {
        return;
    }
    vAngles->setGame(nstr);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_setMode(JNIEnv *env, jobject self, jobject enumObj) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumMode");
    if(enumClass == NULL) return;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "MOUSELOOK") == 0) {
        vAngles->setMode(FPSViewAngles::MOUSELOOK);
    } else if(strcmp(valueNative, "FREE_AIM_TWO_CONTROLLER") == 0) {
        vAngles->setMode(FPSViewAngles::FREE_AIM_TWO_CONTROLLER);
    } else if(strcmp(valueNative, "FREE_AIM_ONE_CONTROLLER") == 0) {
        vAngles->setMode(FPSViewAngles::FREE_AIM_ONE_CONTROLLER);
    } else if(strcmp(valueNative, "DUAL_ANALOG") == 0) {
        vAngles->setMode(FPSViewAngles::DUAL_ANALOG);
    }
    return;
}

JNIEXPORT jobject JNICALL Java_com_sixense_utils_ViewAngles_getMode(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumMode");
    if(enumClass == NULL) return NULL;
    jmethodID cid = env->GetMethodID(enumClass, "<init>", "(Ljava/lang/String;I)V");
    if(cid == NULL) return NULL;
    FPSViewAngles::fps_mode mode = vAngles->getMode();
    jstring enumStr = NULL;
    jint i = -1;
    if(mode == FPSViewAngles::MOUSELOOK) {
        enumStr = env->NewStringUTF("MOUSELOOK");
        i = 0;
    } else if(mode == FPSViewAngles::FREE_AIM_TWO_CONTROLLER) {
        enumStr = env->NewStringUTF("FREE_AIM_TWO_CONTROLLER");
        i = 1;
    } else if(mode == FPSViewAngles::FREE_AIM_ONE_CONTROLLER) {
        enumStr = env->NewStringUTF("FREE_AIM_ONE_CONTROLLER");
        i = 2;
    } else if(mode == FPSViewAngles::DUAL_ANALOG) {
        enumStr = env->NewStringUTF("DUAL_ANALOG");
        i = 3;
    }
	if(enumStr == NULL) return NULL;
    jobject result = env->NewObject(enumClass, cid, enumStr, i);
    env->DeleteLocalRef(enumClass);
    env->DeleteLocalRef(enumStr);
    return result;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_utils_ViewAngles_update(JNIEnv *env, jobject self, jobject leftRef, jobject rightRef, jfloat frametime) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    sixenseControllerData * leftData = getControllerData(env, leftRef);
    sixenseControllerData * rightData = getControllerData(env, rightRef);
    return vAngles->update(leftData, rightData, frametime) == SIXENSE_SUCCESS ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_ViewAngles_getViewAngles(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    Vector3 vec = vAngles->getViewAngles();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_ViewAngles_getViewAngleOffset(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    Vector3 vec = vAngles->getViewAngleOffset();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_ViewAngles_getSpinSpeed(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    Vector3 vec = vAngles->getSpinSpeed();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_forceViewAngles(JNIEnv *env, jobject self, jobject enumObj, jfloat flo1, jfloat flo2, jfloat flo3) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    FPSViewAngles::fps_mode mode;
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumMode");
    if(enumClass == NULL) return;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "MOUSELOOK") == 0) {
        mode = FPSViewAngles::MOUSELOOK;
    } else if(strcmp(valueNative, "FREE_AIM_TWO_CONTROLLER") == 0) {
        mode = FPSViewAngles::FREE_AIM_TWO_CONTROLLER;
    } else if(strcmp(valueNative, "FREE_AIM_ONE_CONTROLLER") == 0) {
        mode = FPSViewAngles::FREE_AIM_ONE_CONTROLLER;
    } else {
        mode = FPSViewAngles::DUAL_ANALOG;
    }
    Vector3 vec = Vector3(flo1, flo2, flo3);
    vAngles->forceViewAngles(mode, vec);
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_setFeetAnglesMetroid(JNIEnv *env, jobject self, jfloat flo1, jfloat flo2, jfloat flo3) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    Vector3 vec = Vector3(flo1, flo2, flo3);
    vAngles->setFeetAnglesMetroid(vec);
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_ViewAngles_getFeetAnglesMetroid(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    Vector3 vec = vAngles->getFeetAnglesMetroid();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_setParameter(JNIEnv *env, jobject self, jobject enumObj, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    FPSViewAngles::fps_params param;
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumViewParam");
    if(enumClass == NULL) return;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "CONTROLLER_ANGLE_MODE") == 0) {
        param = FPSViewAngles::CONTROLLER_ANGLE_MODE;
    } else if(strcmp(valueNative, "AIM_1TO1_HEADING_MULTIPLIER") == 0) {
        param = FPSViewAngles::AIM_1TO1_HEADING_MULTIPLIER;
    } else if(strcmp(valueNative, "AIM_1TO1_PITCH_MULTIPLIER") == 0) {
        param = FPSViewAngles::AIM_1TO1_PITCH_MULTIPLIER;
    } else if(strcmp(valueNative, "AIM_1TO1_RATCHET_VERTICAL") == 0) {
        param = FPSViewAngles::AIM_1TO1_RATCHET_VERTICAL;
    } else if(strcmp(valueNative, "AIM_METROID_HEADING_MULTIPLIER") == 0) {
        param = FPSViewAngles::AIM_METROID_HEADING_MULTIPLIER;
    } else if(strcmp(valueNative, "AIM_METROID_PITCH_MULTIPLIER") == 0) {
        param = FPSViewAngles::AIM_METROID_PITCH_MULTIPLIER;
    } else if(strcmp(valueNative, "AIM_METROID_DEAD_ZONE_RADIUS") == 0) {
        param = FPSViewAngles::AIM_METROID_DEAD_ZONE_RADIUS;
    } else if(strcmp(valueNative, "AIM_METROID_ACCEL_BAND_SIZE") == 0) {
        param = FPSViewAngles::AIM_METROID_ACCEL_BAND_SIZE;
    } else if(strcmp(valueNative, "AIM_METROID_MAX_SPEED") == 0) {
        param = FPSViewAngles::AIM_METROID_MAX_SPEED;
    } else if(strcmp(valueNative, "AIM_METROID_AUTO_LEVEL_RATE") == 0) {
        param = FPSViewAngles::AIM_METROID_AUTO_LEVEL_RATE;
    } else if(strcmp(valueNative, "AIM_METROID_ACCEL_BAND_EXPONENT") == 0) {
        param = FPSViewAngles::AIM_METROID_ACCEL_BAND_EXPONENT;
    } else if(strcmp(valueNative, "AIM_METROID_SWITCH_BLEND_TIME_ENTER") == 0) {
        param = FPSViewAngles::AIM_METROID_SWITCH_BLEND_TIME_ENTER;
    } else if(strcmp(valueNative, "AIM_METROID_SWITCH_BLEND_TIME_EXIT") == 0) {
        param = FPSViewAngles::AIM_METROID_SWITCH_BLEND_TIME_EXIT;
    } else if(strcmp(valueNative, "FEET_ANGLES_OFFSET_STICK_SPIN_HORIZ_MULTIPLIER") == 0) {
        param = FPSViewAngles::FEET_ANGLES_OFFSET_STICK_SPIN_HORIZ_MULTIPLIER;
    } else if(strcmp(valueNative, "FEET_ANGLES_OFFSET_STICK_SPIN_VERT_MULTIPLIER") == 0) {
        param = FPSViewAngles::FEET_ANGLES_OFFSET_STICK_SPIN_VERT_MULTIPLIER;
    } else if(strcmp(valueNative, "FEET_ANGLES_OFFSET_STICK_SPIN_INVERT_PITCH") == 0) {
        param = FPSViewAngles::FEET_ANGLES_OFFSET_STICK_SPIN_INVERT_PITCH;
    } else if(strcmp(valueNative, "FEET_ANGLES_OFFSET_STICK_SPIN_EXPONENT") == 0) {
        param = FPSViewAngles::FEET_ANGLES_OFFSET_STICK_SPIN_EXPONENT;
    } else if(strcmp(valueNative, "PITCH_CHANGE_BLEND_VAL") == 0) {
        param = FPSViewAngles::PITCH_CHANGE_BLEND_VAL;
    } else if(strcmp(valueNative, "SPRING_VIEW_ENABLED") == 0) {
        param = FPSViewAngles::SPRING_VIEW_ENABLED;
    } else if(strcmp(valueNative, "SPRING_VIEW_MIN_SPRING") == 0) {
        param = FPSViewAngles::SPRING_VIEW_MIN_SPRING;
    } else if(strcmp(valueNative, "SPRING_VIEW_MAX_SPRING") == 0) {
        param = FPSViewAngles::SPRING_VIEW_MAX_SPRING;
    } else if(strcmp(valueNative, "SPRING_VIEW_MIN_ANGLE") == 0) {
        param = FPSViewAngles::SPRING_VIEW_MIN_ANGLE;
    } else if(strcmp(valueNative, "SPRING_VIEW_MAX_ANGLE") == 0) {
        param = FPSViewAngles::SPRING_VIEW_MAX_ANGLE;
    } else if(strcmp(valueNative, "FEET_ANGLES_ALLOW_VERT_STICK_SPIN") == 0) {
        param = FPSViewAngles::FEET_ANGLES_ALLOW_VERT_STICK_SPIN;
    } else if(strcmp(valueNative, "AIM_METROID_ACCEL_BAND_POWER") == 0) {
        param = FPSViewAngles::AIM_METROID_ACCEL_BAND_POWER;
    } else if(strcmp(valueNative, "HOLDING_TURN_SPEED") == 0) {
        param = FPSViewAngles::HOLDING_TURN_SPEED;
    } else if(strcmp(valueNative, "ROLL_CORRECTION_BLEND") == 0) {
        param = FPSViewAngles::ROLL_CORRECTION_BLEND;
    } else if(strcmp(valueNative, "EXIT_METROID_BLEND") == 0) {
        param = FPSViewAngles::EXIT_METROID_BLEND;
    } else if(strcmp(valueNative, "LEFT_HANDED") == 0) {
        param = FPSViewAngles::LEFT_HANDED;
    } else {
        param = FPSViewAngles::LAST_FPS_VIEW_ANGLES_PARAM;
    }
    vAngles->setParameter(param, flo);
    return;
}

JNIEXPORT jfloat JNICALL Java_com_sixense_utils_ViewAngles_getParameter(JNIEnv *env, jobject self, jobject enumObj) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    FPSViewAngles::fps_params param;
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumViewParams");
    if(enumClass == NULL) return 0;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return 0;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "CONTROLLER_ANGLE_MODE") == 0) {
        param = FPSViewAngles::CONTROLLER_ANGLE_MODE;
    } else if(strcmp(valueNative, "AIM_1TO1_HEADING_MULTIPLIER") == 0) {
        param = FPSViewAngles::AIM_1TO1_HEADING_MULTIPLIER;
    } else if(strcmp(valueNative, "AIM_1TO1_PITCH_MULTIPLIER") == 0) {
        param = FPSViewAngles::AIM_1TO1_PITCH_MULTIPLIER;
    } else if(strcmp(valueNative, "AIM_1TO1_RATCHET_VERTICAL") == 0) {
        param = FPSViewAngles::AIM_1TO1_RATCHET_VERTICAL;
    } else if(strcmp(valueNative, "AIM_METROID_HEADING_MULTIPLIER") == 0) {
        param = FPSViewAngles::AIM_METROID_HEADING_MULTIPLIER;
    } else if(strcmp(valueNative, "AIM_METROID_PITCH_MULTIPLIER") == 0) {
        param = FPSViewAngles::AIM_METROID_PITCH_MULTIPLIER;
    } else if(strcmp(valueNative, "AIM_METROID_DEAD_ZONE_RADIUS") == 0) {
        param = FPSViewAngles::AIM_METROID_DEAD_ZONE_RADIUS;
    } else if(strcmp(valueNative, "AIM_METROID_ACCEL_BAND_SIZE") == 0) {
        param = FPSViewAngles::AIM_METROID_ACCEL_BAND_SIZE;
    } else if(strcmp(valueNative, "AIM_METROID_MAX_SPEED") == 0) {
        param = FPSViewAngles::AIM_METROID_MAX_SPEED;
    } else if(strcmp(valueNative, "AIM_METROID_AUTO_LEVEL_RATE") == 0) {
        param = FPSViewAngles::AIM_METROID_AUTO_LEVEL_RATE;
    } else if(strcmp(valueNative, "AIM_METROID_ACCEL_BAND_EXPONENT") == 0) {
        param = FPSViewAngles::AIM_METROID_ACCEL_BAND_EXPONENT;
    } else if(strcmp(valueNative, "AIM_METROID_SWITCH_BLEND_TIME_ENTER") == 0) {
        param = FPSViewAngles::AIM_METROID_SWITCH_BLEND_TIME_ENTER;
    } else if(strcmp(valueNative, "AIM_METROID_SWITCH_BLEND_TIME_EXIT") == 0) {
        param = FPSViewAngles::AIM_METROID_SWITCH_BLEND_TIME_EXIT;
    } else if(strcmp(valueNative, "FEET_ANGLES_OFFSET_STICK_SPIN_HORIZ_MULTIPLIER") == 0) {
        param = FPSViewAngles::FEET_ANGLES_OFFSET_STICK_SPIN_HORIZ_MULTIPLIER;
    } else if(strcmp(valueNative, "FEET_ANGLES_OFFSET_STICK_SPIN_VERT_MULTIPLIER") == 0) {
        param = FPSViewAngles::FEET_ANGLES_OFFSET_STICK_SPIN_VERT_MULTIPLIER;
    } else if(strcmp(valueNative, "FEET_ANGLES_OFFSET_STICK_SPIN_INVERT_PITCH") == 0) {
        param = FPSViewAngles::FEET_ANGLES_OFFSET_STICK_SPIN_INVERT_PITCH;
    } else if(strcmp(valueNative, "FEET_ANGLES_OFFSET_STICK_SPIN_EXPONENT") == 0) {
        param = FPSViewAngles::FEET_ANGLES_OFFSET_STICK_SPIN_EXPONENT;
    } else if(strcmp(valueNative, "PITCH_CHANGE_BLEND_VAL") == 0) {
        param = FPSViewAngles::PITCH_CHANGE_BLEND_VAL;
    } else if(strcmp(valueNative, "SPRING_VIEW_ENABLED") == 0) {
        param = FPSViewAngles::SPRING_VIEW_ENABLED;
    } else if(strcmp(valueNative, "SPRING_VIEW_MIN_SPRING") == 0) {
        param = FPSViewAngles::SPRING_VIEW_MIN_SPRING;
    } else if(strcmp(valueNative, "SPRING_VIEW_MAX_SPRING") == 0) {
        param = FPSViewAngles::SPRING_VIEW_MAX_SPRING;
    } else if(strcmp(valueNative, "SPRING_VIEW_MIN_ANGLE") == 0) {
        param = FPSViewAngles::SPRING_VIEW_MIN_ANGLE;
    } else if(strcmp(valueNative, "SPRING_VIEW_MAX_ANGLE") == 0) {
        param = FPSViewAngles::SPRING_VIEW_MAX_ANGLE;
    } else if(strcmp(valueNative, "FEET_ANGLES_ALLOW_VERT_STICK_SPIN") == 0) {
        param = FPSViewAngles::FEET_ANGLES_ALLOW_VERT_STICK_SPIN;
    } else if(strcmp(valueNative, "AIM_METROID_ACCEL_BAND_POWER") == 0) {
        param = FPSViewAngles::AIM_METROID_ACCEL_BAND_POWER;
    } else if(strcmp(valueNative, "HOLDING_TURN_SPEED") == 0) {
        param = FPSViewAngles::HOLDING_TURN_SPEED;
    } else if(strcmp(valueNative, "ROLL_CORRECTION_BLEND") == 0) {
        param = FPSViewAngles::ROLL_CORRECTION_BLEND;
    } else if(strcmp(valueNative, "EXIT_METROID_BLEND") == 0) {
        param = FPSViewAngles::EXIT_METROID_BLEND;
    } else if(strcmp(valueNative, "LEFT_HANDED") == 0) {
        param = FPSViewAngles::LEFT_HANDED;
    } else {
        param = FPSViewAngles::LAST_FPS_VIEW_ANGLES_PARAM;
    }
    return vAngles->getParameter(param);
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_setFov(JNIEnv *env, jobject self, jfloat flo1, jfloat flo2) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    vAngles->setFov(flo1, flo2);
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_ViewAngles_getFov(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    float *h = 0, *v = 0;
    vAngles->getFov(h, v);
    jfloatArray arr = NULL;
    jfloat arr2[2] = {*h, *v};
    env->SetFloatArrayRegion(arr, 0, 2, arr2);
    return arr;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_setHoldingTurnSpeed(JNIEnv *env, jobject self, jfloat flo1, jfloat flo2) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    vAngles->setHoldingTurnSpeed(flo1, flo2);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_setRatcheting(JNIEnv *env, jobject self, jboolean b) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    vAngles->setRatcheting(b == JNI_TRUE);
    return;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_utils_ViewAngles_isRatcheting(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    return vAngles->isRatcheting() ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_reset(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    vAngles->reset();
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ViewAngles_forceMetroidBlend(JNIEnv *env, jobject self, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    FPSViewAngles * vAngles = (FPSViewAngles *)env->GetLongField(self, fid);
    vAngles->forceMetroidBlend(flo);
    return;
}