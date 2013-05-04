#include "sixense_java_utils.h"

jfieldID getPeerID(JNIEnv *env, jobject self) {
    jclass clazz = env->GetObjectClass(self);
    return env->GetFieldID(clazz, "peer", "J");
}