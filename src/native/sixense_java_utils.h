#include <jni.h>
#include "sixense.h"

void setControllerData(JNIEnv *, jobject, sixenseControllerData);

sixenseControllerData * getControllerData(JNIEnv *, jobject);

jfieldID getPeerID(JNIEnv *, jobject);