#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include "sixense.h"

void setControllerData(JNIEnv *, jobject, sixenseControllerData);

sixenseControllerData * getControllerData(JNIEnv *, jobject);

jfieldID getPeerID(JNIEnv *, jobject);
