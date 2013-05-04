#include "sixense.h"
#include "com_sixense_Sixense.h"
#include "sixense_java_utils.h"

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_init(JNIEnv *, jclass) {
    int i;
    i = sixenseInit();
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_exit(JNIEnv *, jclass) {
    int i;
    i = sixenseExit();
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jint JNICALL Java_com_sixense_Sixense_getMaxBases(JNIEnv *, jclass) {
    jint i;
    i = sixenseGetMaxBases();
    return i;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_setActiveBase(JNIEnv *, jclass, jint j) {
    int i;
    i = sixenseSetActiveBase((int) j);
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_isBaseConnected(JNIEnv *, jclass, jint j) {
    int i;
    i = sixenseIsBaseConnected((int) j);
    return (i == 1) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jint JNICALL Java_com_sixense_Sixense_getMaxControllers(JNIEnv *, jclass) {
    jint i;
    i = sixenseGetMaxControllers();
    return i;
}

JNIEXPORT jint JNICALL Java_com_sixense_Sixense_getNumActiveControllers(JNIEnv *, jclass) {
    jint i;
    i = sixenseGetNumActiveControllers();
    return i;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_isControllerEnabled(JNIEnv *, jclass, jint which) {
    int i;
    i = sixenseIsControllerEnabled((int) which);
    return (i == 1) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_getAllNewestData(JNIEnv *env, jclass, jobjectArray arr) {
    int i, j;
    sixenseAllControllerData * data = new sixenseAllControllerData;
    i = sixenseGetAllNewestData(data);
    //	if(i == -1) return JNI_FALSE;
    for(j = 0; j < 4; j++) {
        jobject ref = env->GetObjectArrayElement(arr, j);
        setControllerData(env, ref, data->controllers[j]);
        env->DeleteLocalRef(ref);
    }
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_getAllData(JNIEnv *env, jclass, jint j, jobjectArray arr) {
    int i, k;
    sixenseAllControllerData * data = new sixenseAllControllerData;
    i = sixenseGetAllData((int) j, data);
    //	if(i == -1) return JNI_FALSE;
    for(k = 0; k < 4; k++) {
        jobject ref = env->GetObjectArrayElement(arr, k);
        setControllerData(env, ref, data->controllers[k]);
        env->DeleteLocalRef(ref);
    }
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_getNewestData(JNIEnv *env, jclass, jint j, jobject ref) {
    int i;
    sixenseControllerData * data = new sixenseControllerData;
    i = sixenseGetNewestData((int) j, data);
    setControllerData(env, ref, (*data));
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_getData(JNIEnv *env, jclass, jint j, jint k, jobject ref) {
    int i;
    sixenseControllerData * data = new sixenseControllerData;
    i = sixenseGetData((int) j, (int) k, data);
    setControllerData(env, ref, (*data));
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jint JNICALL Java_com_sixense_Sixense_getHistorySize(JNIEnv *, jclass) {
    jint i;
    i = sixenseGetHistorySize();
    return i;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_setFilterEnabled(JNIEnv *, jclass, jboolean bool1) {
    int i;
    i = sixenseSetFilterEnabled((bool1 == JNI_TRUE) ? 1 : 0);
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_getFilterEnabled(JNIEnv *, jclass) {
    int i, *j = 0;
    i = sixenseGetFilterEnabled(j);
    return ((i == 0) && ((*j) == 1)) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_setFilterParams(JNIEnv *, jclass, jfloat near_range, jfloat near_val, jfloat far_range, jfloat far_val) {
    int i;
    i = sixenseSetFilterParams((float) near_range, (float) near_val, (float) far_range, (float) far_val);
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jfloatArray JNICALL Java_com_sixense_Sixense_getFilterParams(JNIEnv *env, jclass) {
    int i;
    float *near_range = 0, *near_val = 0, *far_range = 0, *far_val = 0;
    jfloatArray arr = NULL;
    i = sixenseGetFilterParams(near_range, near_val, far_range, far_val);
    if(i == -1) return NULL;
    jfloat arr2[4] = {(*near_range), (*near_val), (*far_range), (*far_val)};
    env->SetFloatArrayRegion(arr, 0, 4, arr2);
    return arr;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_triggerVibration(JNIEnv *, jclass, jint controller_id, jint duration, jint pattern_id) {
    int i;
    i = sixenseTriggerVibration((int) controller_id, (int) duration, (int) pattern_id);
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_autoEnableHemisphereTracking(JNIEnv *, jclass, jint j) {
    int i;
    i = sixenseAutoEnableHemisphereTracking((int) j);
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_setHighPriorityBinding(JNIEnv *, jclass, jboolean bool1) {
    int i;
    i = sixenseSetHighPriorityBindingEnabled((bool1 == JNI_FALSE) ? 0 : 1);
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_getHighPriorityBinding(JNIEnv *, jclass) {
    int i, *j = 0;
    i = sixenseGetHighPriorityBindingEnabled(j);
    return ((i == 0) && ((*j) == 1)) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_Sixense_setBaseColor(JNIEnv *, jclass, jint red, jint green, jint blue) {
    int i;
    i = sixenseSetBaseColor((unsigned char) red, (unsigned char) green, (unsigned char) blue);
    return (i == -1) ? JNI_FALSE : JNI_TRUE;
}

JNIEXPORT jintArray JNICALL Java_com_sixense_Sixense_getColorBase(JNIEnv *env, jclass) {
    int i;
    unsigned char *red = 0, *green = 0, *blue = 0;
    jintArray arr = NULL;
    i = sixenseGetBaseColor(red, green, blue);
    if(i == -1) return JNI_FALSE;
    jint arr2[3] = {(*red), (*green), (*blue)};
    env->SetIntArrayRegion(arr, 0, 3, arr2);
    return arr;
}

void setControllerData(JNIEnv *env, jobject ref, sixenseControllerData data) {
    int i, j;
    jclass cls = env->GetObjectClass(ref);
    jfieldID fid;
    //pos[3]
    fid = env->GetFieldID(cls, "pos", "[F");
    jfloatArray pos = env->NewFloatArray(3);
    if(pos == NULL) return;
    jfloat pos2[3];
    for(i = 0; i < 3; i++) {
        pos2[i] = data.pos[i];
    }
    env->SetFloatArrayRegion(pos, 0, 3, pos2);
    env->SetObjectField(ref, fid, pos);
    env->DeleteLocalRef(pos);
    //rot_mat[3][3]
    fid = env->GetFieldID(cls, "rot_mat", "[[F");
    jclass floatArrCls = env->FindClass("[F");
    if(floatArrCls == NULL) return;
    jobjectArray rot_mat = env->NewObjectArray(3, floatArrCls, NULL);
    for(i = 0; i < 3; i++) {
        jfloatArray farr = env->NewFloatArray(3);
        if(farr == NULL) return;
        jfloat tmp[3];
        for(j = 0; j < 3; j++) {
            tmp[j] = data.rot_mat[i][j];
        }
        env->SetFloatArrayRegion(farr, 0, 3, tmp);
        env->SetObjectArrayElement(rot_mat, i, farr);
        env->DeleteLocalRef(farr);
    }
    env->SetObjectField(ref, fid, rot_mat);
    env->DeleteLocalRef(rot_mat);
    env->DeleteLocalRef(floatArrCls);
    //joystick_x
    fid = env->GetFieldID(cls, "joystick_x", "F");
    env->SetFloatField(ref, fid, (jfloat) data.joystick_x);
    //joystick_y
    fid = env->GetFieldID(cls, "joystick_y", "F");
    env->SetFloatField(ref, fid, (jfloat) data.joystick_y);
    //trigger
    fid = env->GetFieldID(cls, "trigger", "F");
    env->SetFloatField(ref, fid, (jfloat) data.trigger);
    //buttons
    fid = env->GetFieldID(cls, "buttons", "I");
    env->SetIntField(ref, fid, (jint) data.buttons);
    //sequence_number
    fid = env->GetFieldID(cls, "sequence_number", "I");
    env->SetIntField(ref, fid, (jint) data.sequence_number);
    //rot_quat[4]
    fid = env->GetFieldID(cls, "rot_quat", "[F");
    jfloatArray rot_quat = env->NewFloatArray(4);
    if(rot_quat == NULL) return;
    jfloat rot_quat2[4];
    for(i = 0; i < 4; i++) {
        rot_quat2[i] = data.rot_quat[i];
    }
    env->SetFloatArrayRegion(rot_quat, 0, 4, rot_quat2);
    env->SetObjectField(ref, fid, rot_quat);
    env->DeleteLocalRef(rot_quat);
    //firmware_revision
    fid = env->GetFieldID(cls, "firmware_revision", "I");
    env->SetIntField(ref, fid, (jint) data.firmware_revision);
    //hardware_revision
    fid = env->GetFieldID(cls, "hardware_revision", "I");
    env->SetIntField(ref, fid, (jint) data.hardware_revision);
    //packet_type
    fid = env->GetFieldID(cls, "packet_type", "I");
    env->SetIntField(ref, fid, (jint) data.packet_type);
    //magnetic_frequency
    fid = env->GetFieldID(cls, "magnetic_frequency", "I");
    env->SetIntField(ref, fid, (jint) data.magnetic_frequency);
    //enabled
    fid = env->GetFieldID(cls, "enabled", "Z");
    env->SetBooleanField(ref, fid, (data.enabled > 0) ? JNI_TRUE : JNI_FALSE);
    //controller_index
    fid = env->GetFieldID(cls, "controller_index", "I");
    env->SetIntField(ref, fid, (jint) data.controller_index);
    //is_docked
    fid = env->GetFieldID(cls, "is_docked", "Z");
    env->SetBooleanField(ref, fid, (data.is_docked > 0) ? JNI_TRUE : JNI_FALSE);
    //which_hand
    fid = env->GetFieldID(cls, "which_hand", "I");
    env->SetIntField(ref, fid, (jint) data.which_hand);
    //hemi_tracking_enabled
    fid = env->GetFieldID(cls, "hemi_tracking_enabled", "Z");
    env->SetBooleanField(ref, fid, (data.hemi_tracking_enabled > 0) ? JNI_TRUE : JNI_FALSE);
    return;
}
