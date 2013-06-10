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
#include "button_states.hpp"
#include "com_sixense_utils_ButtonStates.h"

using sixenseUtils::ButtonStates;

JNIEXPORT jlong JNICALL Java_com_sixense_utils_ButtonStates_create(JNIEnv *, jobject) {
    ButtonStates * bStates = new ButtonStates();
    return (jlong) bStates;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_destroy(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    jlong peer = env->GetLongField(self, fid);
    if(peer == 0) {
        return;
    }
    free((void *) peer);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_update(JNIEnv *env, jobject self, jobject ref) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    sixenseControllerData * data = getControllerData(env, ref);
    bStates->update(data);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_setTriggerThreshold(JNIEnv *env, jobject self, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    bStates->setTriggerThreshold(flo);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_setStickThreshold(JNIEnv *env, jobject self, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    bStates->setStickThreshold(flo);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_setAbsoluteTiltAngleThreshold(JNIEnv *env, jobject self, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    bStates->setAbsoluteTiltAngleThresholdInDeg(flo);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_setRelativeTiltAngleThreshold(JNIEnv *env, jobject self, jfloat flo) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    bStates->setRelativeTiltAngleThresholdInDeg(flo);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_setRelativeOrigin(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    bStates->setRelativeOrigin();
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_startPointGesture(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    bStates->startPointGesture();
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ButtonStates_stopPointGesture(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    bStates->stopPointGesture();
    return;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_utils_ButtonStates_justStarted(JNIEnv *env, jobject self, jobject enumObj, jint arg) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumActionType");
    if(enumClass == NULL) return JNI_FALSE;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return JNI_FALSE;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "BUTTON_PRESS") == 0) {
        return bStates->justStarted(ButtonStates::ACTION_BUTTON_PRESS, arg);
    } else if(strcmp(valueNative, "JOYSTICK_MOVE") == 0) {
        return bStates->justStarted(ButtonStates::ACTION_JOYSTICK_MOVE, arg);
    } else if(strcmp(valueNative, "TRIGGER_PRESS") == 0) {
        return bStates->justStarted(ButtonStates::ACTION_TRIGGER_PRESS, arg);
    } else if(strcmp(valueNative, "TILT_GESTURE") == 0) {
        return bStates->justStarted(ButtonStates::ACTION_TILT_GESTURE, arg);
    } else if(strcmp(valueNative, "POINT_GESTURE") == 0) {
        return bStates->justStarted(ButtonStates::ACTION_POINT_GESTURE, arg);
    } else if(strcmp(valueNative, "VELOCITY_GESTURE") == 0) {
        return bStates->justStarted(ButtonStates::ACTION_VELOCITY_GESTURE, arg);
    }
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_utils_ButtonStates_justStopped(JNIEnv *env, jobject self, jobject enumObj, jint arg) {
    jfieldID fid = getPeerID(env, self);
    ButtonStates * bStates = (ButtonStates *)env->GetLongField(self, fid);
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumActionType");
    if(enumClass == NULL) return JNI_FALSE;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return JNI_FALSE;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "BUTTON_PRESS") == 0) {
        return bStates->justStopped(ButtonStates::ACTION_BUTTON_PRESS, arg);
    } else if(strcmp(valueNative, "JOYSTICK_MOVE") == 0) {
        return bStates->justStopped(ButtonStates::ACTION_JOYSTICK_MOVE, arg);
    } else if(strcmp(valueNative, "TRIGGER_PRESS") == 0) {
        return bStates->justStopped(ButtonStates::ACTION_TRIGGER_PRESS, arg);
    } else if(strcmp(valueNative, "TILT_GESTURE") == 0) {
        return bStates->justStopped(ButtonStates::ACTION_TILT_GESTURE, arg);
    } else if(strcmp(valueNative, "POINT_GESTURE") == 0) {
        return bStates->justStopped(ButtonStates::ACTION_POINT_GESTURE, arg);
    } else if(strcmp(valueNative, "VELOCITY_GESTURE") == 0) {
        return bStates->justStopped(ButtonStates::ACTION_VELOCITY_GESTURE, arg);
    }
    return JNI_FALSE;
}


