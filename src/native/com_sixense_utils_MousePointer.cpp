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
#include "sixense_math.hpp"
#include "mouse_pointer.hpp"
#include "com_sixense_utils_MousePointer.h"

using sixenseMath::Vector2;
using sixenseUtils::MousePointer;

JNIEXPORT jlong JNICALL Java_com_sixense_utils_MousePointer_create(JNIEnv *, jobject) {
	MousePointer * mouse = new MousePointer();
    return (jlong) mouse;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_destroy(JNIEnv *env, jobject self) {
	jfieldID fid = getPeerID(env, self);
    jlong peer = env->GetLongField(self, fid);
    if(peer == 0) {
        return;
    }
    free((void *) peer);
    return;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_MousePointer_update(JNIEnv *env, jobject self, jobject ref) {
	jfieldID fid = getPeerID(env, self);
	MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	sixenseControllerData * data = getControllerData(env, ref);
    jfloatArray pos = env->NewFloatArray(2);
	Vector2 pos2 = mouse->update(data);
	jfloat pos3[2] = {pos2[0], pos2[1]};
    env->SetFloatArrayRegion(pos, 0, 2, pos3);
	return pos;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setSensitivity(JNIEnv *env, jobject self, jfloat sens) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setSensitivity(sens);
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setAcceleration(JNIEnv *env, jobject self, jfloat acc) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setAcceleration(acc);
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setSlideEnabled(JNIEnv *env, jobject self, jboolean enabled) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setSlideEnabled(enabled == JNI_TRUE);
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setAspectRatio(JNIEnv *env, jobject self, jfloat aspect) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setAspectRatio(aspect == JNI_TRUE);
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setLockRelativeToWindow(JNIEnv *env, jobject self, jboolean lock) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setLockRelativeToWindow(lock == JNI_TRUE);
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setLockRelativeToClientBounds(JNIEnv *env, jobject self, jboolean lock) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setLockRelativeToClientBounds(lock == JNI_TRUE);
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_MousePointer_getMouseOffset(JNIEnv *env, jobject self) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	jfloatArray off = env->NewFloatArray(2);
	Vector2 off2 = mouse->getMouseOffset();
	jfloat off3[2] = {off2[0], off2[1]};
    env->SetFloatArrayRegion(off, 0, 2, off3);
	return off;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setMouseOffset(JNIEnv *env, jobject self, jfloat x, jfloat y) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setMouseOffset(Vector2(x, y));
}

JNIEXPORT jfloat JNICALL Java_com_sixense_utils_MousePointer_getRollAngle(JNIEnv *env, jobject self) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	return mouse->getRollAngle();
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setCenter(JNIEnv *env, jobject self) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setCenter();
}

JNIEXPORT void JNICALL Java_com_sixense_utils_MousePointer_setWindowCenter(JNIEnv *env, jobject self) {
	jfieldID fid = getPeerID(env, self);
    MousePointer * mouse = (MousePointer *)env->GetLongField(self, fid);
	mouse->setWindowCenter();
}