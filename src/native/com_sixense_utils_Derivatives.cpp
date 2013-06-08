#include "sixense_java_utils.h"
#include "derivatives.hpp"
#include "sixense_math.hpp"
#include "com_sixense_utils_Derivatives.h"

using sixenseMath::Vector3;
using sixenseUtils::Derivatives;

JNIEXPORT jlong JNICALL Java_com_sixense_utils_Derivatives_create(JNIEnv *, jobject, jfloat x, jfloat y, jfloat z) {
    Derivatives * deriv = new Derivatives(Vector3(x, y, z));
    return (jlong) deriv;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_Derivatives_destroy(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    jlong peer = env->GetLongField(self, fid);
    if(peer == 0) {
        return;
    }
    free((void *) peer);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_Derivatives_update(JNIEnv *env, jobject self, jobject ref) {
    jfieldID fid = getPeerID(env, self);
    Derivatives * deriv = (Derivatives *)env->GetLongField(self, fid);
    sixenseControllerData * data = getControllerData(env, ref);
    deriv->update(data);
    return;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_Derivatives_getPosition(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    Derivatives * deriv = (Derivatives *)env->GetLongField(self, fid);
    Vector3 vec = deriv->getPosition();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_Derivatives_getVelocity(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    Derivatives * deriv = (Derivatives *)env->GetLongField(self, fid);
    Vector3 vec = deriv->getVelocity();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_Derivatives_getAcceleration(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    Derivatives * deriv = (Derivatives *)env->GetLongField(self, fid);
    Vector3 vec = deriv->getAcceleration();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_Derivatives_getRSquared(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    Derivatives * deriv = (Derivatives *)env->GetLongField(self, fid);
    Vector3 vec = deriv->getRSquared();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_Derivatives_setOffset(JNIEnv *env, jobject self, jfloat x, jfloat y, jfloat z) {
    jfieldID fid = getPeerID(env, self);
    Derivatives * deriv = (Derivatives *)env->GetLongField(self, fid);
    Vector3 vec = Vector3(x, y, z);
    deriv->setOffset(vec);
    return;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_utils_Derivatives_getOffset(JNIEnv *env, jobject self) {
    jfieldID fid = getPeerID(env, self);
    Derivatives * deriv = (Derivatives *)env->GetLongField(self, fid);
    Vector3 vec = deriv->getOffset();
    jfloatArray arr = NULL;
    jfloat arr2[3] = {vec[0], vec[1], vec[2]};
    env->SetFloatArrayRegion(arr, 0, 3, arr2);
    return arr;
}
