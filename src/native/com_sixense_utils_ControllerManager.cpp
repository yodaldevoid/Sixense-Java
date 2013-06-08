#include "sixense_java_utils.h"
#include "controller_manager.hpp"
#include "com_sixense_utils_ControllerManager.h"

JavaVM* jvm;
jobject cbRef;

void callback(sixenseUtils::ControllerManager::setup_step step) {
    JNIEnv *env;
    jvm->GetEnv((void**) &env, JNI_VERSION_1_2);
    if(env == NULL) return;
    jclass cbCls = env->GetObjectClass(cbRef);
    if(cbCls == NULL) return;
    jmethodID mid = env->GetMethodID(cbCls, "onCallback", "(Lcom/sixense/utils/enums/EnumSetupStep;)V");
    if(mid == NULL) return;

    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumSetupStep");
    if(enumClass == NULL) return;
    jmethodID cid = env->GetMethodID(enumClass, "<init>", "(Ljava/lang/String;I)V");
    if(cid == NULL) return;
    jstring enumStr = NULL;
    jint i = -1;
    if(step == sixenseUtils::IControllerManager::SETUP_COMPLETE) {
        enumStr = env->NewStringUTF("SETUP_COMPLETE");
        i = 0;
    } else if(step == sixenseUtils::IControllerManager::P1C1_START) {
        enumStr = env->NewStringUTF("P1C1_START");
        i = 1;
    } else if(step == sixenseUtils::IControllerManager::P1C1_POWER_UP_0) {
        enumStr = env->NewStringUTF("P1C1_POWER_UP_0");
        i = 2;
    } else if(step == sixenseUtils::IControllerManager::P1C1_POWER_UP_DONE) {
        enumStr = env->NewStringUTF("P1C1_POWER_UP_DONE");
        i = 3;
    } else if(step == sixenseUtils::IControllerManager::P1C1_AIM_P1L) {
        enumStr = env->NewStringUTF("P1C1_AIM_P1L");
        i = 4;
    } else if(step == sixenseUtils::IControllerManager::P1C1_DONE) {
        enumStr = env->NewStringUTF("P1C1_DONE");
        i = 5;
    } else if(step == sixenseUtils::IControllerManager::P1C1_OUT_OF_RANGE) {
        enumStr = env->NewStringUTF("P1C1_OUT_OF_RANGE");
        i = 6;
    } else if(step == sixenseUtils::IControllerManager::P1C1_IDLE) {
        enumStr = env->NewStringUTF("P1C1_IDLE");
        i = 7;
    } else if(step == sixenseUtils::IControllerManager::P1C2_START) {
        enumStr = env->NewStringUTF("P1C2_START");
        i = 8;
    } else if(step == sixenseUtils::IControllerManager::P1C2_POWER_UP_0) {
        enumStr = env->NewStringUTF("P1C2_POWER_UP_0");
        i = 9;
    } else if(step == sixenseUtils::IControllerManager::P1C2_POWER_UP_1) {
        enumStr = env->NewStringUTF("P1C2_POWER_UP_1");
        i = 10;
    } else if(step == sixenseUtils::IControllerManager::P1C2_POWER_UP_DONE) {
        enumStr = env->NewStringUTF("P1C2_POWER_UP_DONE");
        i = 11;
    } else if(step == sixenseUtils::IControllerManager::P1C2_AIM_P1L) {
        enumStr = env->NewStringUTF("P1C2_AIM_P1L");
        i = 12;
    } else if(step == sixenseUtils::IControllerManager::P1C2_AIM_P1R) {
        enumStr = env->NewStringUTF("P1C2_AIM_P1R");
        i = 13;
    } else if(step == sixenseUtils::IControllerManager::P1C2_DONE) {
        enumStr = env->NewStringUTF("P1C2_DONE");
        i = 14;
    } else if(step == sixenseUtils::IControllerManager::P1C2_OUT_OF_RANGE) {
        enumStr = env->NewStringUTF("P1C2_OUT_OF_RANGE");
        i = 15;
    } else if(step == sixenseUtils::IControllerManager::P1C2_IDLE) {
        enumStr = env->NewStringUTF("P1C2_IDLE");
        i = 16;
    }
	if(enumStr == NULL) return;
    jobject stepEnum = env->NewObject(enumClass, cid, enumStr, i);

    env->CallVoidMethod(cbRef, mid, stepEnum);
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ControllerManager_setGameType(JNIEnv *env, jobject, jobject enumObj) {
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumGameType");
    if(enumClass == NULL) return;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "ONE_PLAYER_ONE_CONTROLLER") == 0) {
        sixenseUtils::getTheControllerManager()->setGameType(sixenseUtils::ControllerManager::ONE_PLAYER_ONE_CONTROLLER);
    } else if(strcmp(valueNative, "ONE_PLAYER_TWO_CONTROLLER") == 0) {
        sixenseUtils::getTheControllerManager()->setGameType(sixenseUtils::ControllerManager::ONE_PLAYER_TWO_CONTROLLER);
    } else if(strcmp(valueNative, "TWO_PLAYER_ONE_CONTROLLER") == 0) {
        sixenseUtils::getTheControllerManager()->setGameType(sixenseUtils::ControllerManager::TWO_PLAYER_ONE_CONTROLLER);
    } else if(strcmp(valueNative, "TWO_PLAYER_TWO_CONTROLLER") == 0) {
        sixenseUtils::getTheControllerManager()->setGameType(sixenseUtils::ControllerManager::TWO_PLAYER_TWO_CONTROLLER);
    } else if(strcmp(valueNative, "THREE_PLAYER_ONE_CONTROLLER") == 0) {
        sixenseUtils::getTheControllerManager()->setGameType(sixenseUtils::ControllerManager::THREE_PLAYER_ONE_CONTROLLER);
    } else if(strcmp(valueNative, "THREE_PLAYER_TWO_CONTROLLER") == 0) {
        sixenseUtils::getTheControllerManager()->setGameType(sixenseUtils::ControllerManager::THREE_PLAYER_TWO_CONTROLLER);
    } else if(strcmp(valueNative, "FOUR_PLAYER_ONE_CONTROLLER") == 0) {
        sixenseUtils::getTheControllerManager()->setGameType(sixenseUtils::ControllerManager::FOUR_PLAYER_ONE_CONTROLLER);
    } else if(strcmp(valueNative, "FOUR_PLAYER_TWO_CONTROLLER") == 0) {
        sixenseUtils::getTheControllerManager()->setGameType(sixenseUtils::ControllerManager::FOUR_PLAYER_TWO_CONTROLLER);
    }
    return;
}

JNIEXPORT jobject JNICALL Java_com_sixense_utils_ControllerManager_getGameType(JNIEnv *env, jobject) {
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumGameType");
    if(enumClass == NULL) return NULL;
    jmethodID cid = env->GetMethodID(enumClass, "<init>", "(Ljava/lang/String;I)V");
    if(cid == NULL) return NULL;
    sixenseUtils::ControllerManager::game_type gt = sixenseUtils::getTheControllerManager()->getGameType();
    jstring enumStr = NULL;
    jint i = -1;
    if(gt == sixenseUtils::IControllerManager::ONE_PLAYER_ONE_CONTROLLER) {
        enumStr = env->NewStringUTF("ONE_PLAYER_ONE_CONTROLLER");
        i = 0;
    } else if(gt == sixenseUtils::IControllerManager::ONE_PLAYER_TWO_CONTROLLER) {
        enumStr = env->NewStringUTF("ONE_PLAYER_TWO_CONTROLLER");
        i = 1;
    } else if(gt == sixenseUtils::IControllerManager::TWO_PLAYER_ONE_CONTROLLER) {
        enumStr = env->NewStringUTF("TWO_PLAYER_ONE_CONTROLLER");
        i = 2;
    } else if(gt == sixenseUtils::IControllerManager::TWO_PLAYER_TWO_CONTROLLER) {
        enumStr = env->NewStringUTF("TWO_PLAYER_TWO_CONTROLLER");
        i = 3;
    } else if(gt == sixenseUtils::IControllerManager::THREE_PLAYER_ONE_CONTROLLER) {
        enumStr = env->NewStringUTF("THREE_PLAYER_ONE_CONTROLLER");
        i = 4;
    } else if(gt == sixenseUtils::IControllerManager::THREE_PLAYER_TWO_CONTROLLER) {
        enumStr = env->NewStringUTF("THREE_PLAYER_TWO_CONTROLLER");
        i = 5;
    } else if(gt == sixenseUtils::IControllerManager::FOUR_PLAYER_ONE_CONTROLLER) {
        enumStr = env->NewStringUTF("FOUR_PLAYER_ONE_CONTROLLER");
        i = 6;
    } else if(gt == sixenseUtils::IControllerManager::FOUR_PLAYER_TWO_CONTROLLER) {
        enumStr = env->NewStringUTF("FOUR_PLAYER_TWO_CONTROLLER");
        i = 7;
    }
	if(enumStr == NULL) return NULL;
    jobject result = env->NewObject(enumClass, cid, enumStr, i);
    env->DeleteLocalRef(enumClass);
    env->DeleteLocalRef(enumStr);
    return result;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ControllerManager_update(JNIEnv *env, jobject, jobjectArray arr) {
    int i;
    sixenseAllControllerData * data = new sixenseAllControllerData;
    for(i = 0; i < 4; i++) {
        jobject ref = env->GetObjectArrayElement(arr, i);
        if(ref == NULL) return;
        data->controllers[i] = *getControllerData(env, ref);
    }
    sixenseUtils::getTheControllerManager()->update(data);
    return;
}

JNIEXPORT jint JNICALL Java_com_sixense_utils_ControllerManager_getIndex(JNIEnv *env, jobject, jobject enumObj) {
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumGameType");
    if(enumClass == NULL) return NULL;
    jmethodID getNameMethod = env->GetMethodID(enumClass, "name", "()Ljava/lang/String;");
    if(getNameMethod == NULL) return NULL;
    jstring value = (jstring) env->CallObjectMethod(enumObj, getNameMethod);
    const char* valueNative = env->GetStringUTFChars(value, JNI_FALSE);
    if(strcmp(valueNative, "P1L") == 0) {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::P1L);
    } else if(strcmp(valueNative, "P1R") == 0) {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::P1R);
    } else if(strcmp(valueNative, "P2L") == 0) {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::P2L);
    } else if(strcmp(valueNative, "P2R") == 0) {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::P2R);
    } else if(strcmp(valueNative, "P3L") == 0) {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::P3L);
    } else if(strcmp(valueNative, "P3R") == 0) {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::P3R);
    } else if(strcmp(valueNative, "P4L") == 0) {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::P4L);
    } else if(strcmp(valueNative, "P4R") == 0) {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::P4R);
    } else {
        return sixenseUtils::getTheControllerManager()->getIndex(sixenseUtils::ControllerManager::LAST_CONTROLLER_DESC);
    }
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ControllerManager_rebind(JNIEnv *, jobject) {
    sixenseUtils::getTheControllerManager()->rebind();
    return;
}

JNIEXPORT void JNICALL Java_com_sixense_utils_ControllerManager_registerSetupCallback(JNIEnv *env, jobject, jobject ref) {
    env->GetJavaVM(&jvm);
    cbRef = env->NewGlobalRef(ref);
    sixenseUtils::getTheControllerManager()->registerSetupCallback(callback);
    return;
}

JNIEXPORT jboolean JNICALL Java_com_sixense_utils_ControllerManager_isMenuVisible(JNIEnv *, jobject) {
    return sixenseUtils::getTheControllerManager()->isMenuVisible() ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jstring JNICALL Java_com_sixense_utils_ControllerManager_getTextureFileName(JNIEnv *env, jobject) {
    const char* str = sixenseUtils::getTheControllerManager()->getTextureFileName();
    jstring retval = env->NewStringUTF(str);
    return retval;
}

JNIEXPORT jstring JNICALL Java_com_sixense_utils_ControllerManager_getStepString(JNIEnv *env, jobject) {
    const char* str = sixenseUtils::getTheControllerManager()->getStepString();
    jstring retval = env->NewStringUTF(str);
    return retval;
}

JNIEXPORT jobject JNICALL Java_com_sixense_utils_ControllerManager_shouldPlaySound(JNIEnv *env, jobject) {
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumSoundType");
    if(enumClass == NULL) return NULL;
    jmethodID cid = env->GetMethodID(enumClass, "<init>", "(Ljava/lang/String;I)V");
    if(cid == NULL) return NULL;
    sixenseUtils::ControllerManager::sound_type st = sixenseUtils::getTheControllerManager()->shouldPlaySound();
    jstring enumStr;
    jint i;
    if(st == sixenseUtils::IControllerManager::NO_SOUND) {
        enumStr = env->NewStringUTF("NO_SOUND");
        i = 0;
    } else if(st == sixenseUtils::IControllerManager::SUCCESS_BEEP) {
        enumStr = env->NewStringUTF("SUCCESS_BEEP");
        i = 1;
    } else {
        enumStr = env->NewStringUTF("FAIL_BEEP");
        i = 2;
    }
	if(enumStr == NULL) return NULL;
    jobject result = env->NewObject(enumClass, cid, enumStr, i);
    env->DeleteLocalRef(enumClass);
    env->DeleteLocalRef(enumStr);
    return result;
}

JNIEXPORT jobject JNICALL Java_com_sixense_utils_ControllerManager_getCurrentStep(JNIEnv *env, jobject) {
    jclass enumClass = env->FindClass("com/sixense/utils/enums/EnumSetupStep");
    if(enumClass == NULL) return NULL;
    jmethodID cid = env->GetMethodID(enumClass, "<init>", "(Ljava/lang/String;I)V");
    if(cid == NULL) return NULL;
    sixenseUtils::ControllerManager::setup_step step = sixenseUtils::getTheControllerManager()->getCurrentStep();
    jstring enumStr = NULL;
    jint i = -1;
    if(step == sixenseUtils::IControllerManager::SETUP_COMPLETE) {
        enumStr = env->NewStringUTF("SETUP_COMPLETE");
        i = 0;
    } else if(step == sixenseUtils::IControllerManager::P1C1_START) {
        enumStr = env->NewStringUTF("P1C1_START");
        i = 1;
    } else if(step == sixenseUtils::IControllerManager::P1C1_POWER_UP_0) {
        enumStr = env->NewStringUTF("P1C1_POWER_UP_0");
        i = 2;
    } else if(step == sixenseUtils::IControllerManager::P1C1_POWER_UP_DONE) {
        enumStr = env->NewStringUTF("P1C1_POWER_UP_DONE");
        i = 3;
    } else if(step == sixenseUtils::IControllerManager::P1C1_AIM_P1L) {
        enumStr = env->NewStringUTF("P1C1_AIM_P1L");
        i = 4;
    } else if(step == sixenseUtils::IControllerManager::P1C1_DONE) {
        enumStr = env->NewStringUTF("P1C1_DONE");
        i = 5;
    } else if(step == sixenseUtils::IControllerManager::P1C1_OUT_OF_RANGE) {
        enumStr = env->NewStringUTF("P1C1_OUT_OF_RANGE");
        i = 6;
    } else if(step == sixenseUtils::IControllerManager::P1C1_IDLE) {
        enumStr = env->NewStringUTF("P1C1_IDLE");
        i = 7;
    } else if(step == sixenseUtils::IControllerManager::P1C2_START) {
        enumStr = env->NewStringUTF("P1C2_START");
        i = 8;
    } else if(step == sixenseUtils::IControllerManager::P1C2_POWER_UP_0) {
        enumStr = env->NewStringUTF("P1C2_POWER_UP_0");
        i = 9;
    } else if(step == sixenseUtils::IControllerManager::P1C2_POWER_UP_1) {
        enumStr = env->NewStringUTF("P1C2_POWER_UP_1");
        i = 10;
    } else if(step == sixenseUtils::IControllerManager::P1C2_POWER_UP_DONE) {
        enumStr = env->NewStringUTF("P1C2_POWER_UP_DONE");
        i = 11;
    } else if(step == sixenseUtils::IControllerManager::P1C2_AIM_P1L) {
        enumStr = env->NewStringUTF("P1C2_AIM_P1L");
        i = 12;
    } else if(step == sixenseUtils::IControllerManager::P1C2_AIM_P1R) {
        enumStr = env->NewStringUTF("P1C2_AIM_P1R");
        i = 13;
    } else if(step == sixenseUtils::IControllerManager::P1C2_DONE) {
        enumStr = env->NewStringUTF("P1C2_DONE");
        i = 14;
    } else if(step == sixenseUtils::IControllerManager::P1C2_OUT_OF_RANGE) {
        enumStr = env->NewStringUTF("P1C2_OUT_OF_RANGE");
        i = 15;
    } else if(step == sixenseUtils::IControllerManager::P1C2_IDLE) {
        enumStr = env->NewStringUTF("P1C2_IDLE");
        i = 16;
    }
	if(enumStr == NULL) return NULL;
    jobject result = env->NewObject(enumClass, cid, enumStr, i);
    env->DeleteLocalRef(enumClass);
    env->DeleteLocalRef(enumStr);
    return result;
}

sixenseControllerData * getControllerData(JNIEnv *env, jobject ref) {
    sixenseControllerData * data = new sixenseControllerData;
    int j, k;
    jclass cls = env->GetObjectClass(ref);
    if(cls == NULL) return NULL;
    //pos[3]
    jfieldID fid = env->GetFieldID(cls, "pos", "[F");
    if(fid == NULL) return NULL;
    jfloatArray pos = env->NewFloatArray(3);
    if(pos == NULL) return NULL;
    pos = (jfloatArray) env->GetObjectField(ref, fid);
    env->GetFloatArrayRegion(pos, 0, 3, (*data).pos);
    env->DeleteLocalRef(pos);
    //rot_mat[3][3]
    fid = env->GetFieldID(cls, "rot_mat", "[[F");
    jclass floatArrCls = env->FindClass("[F");
    if(floatArrCls == NULL) return NULL;
    jobjectArray rot_mat = env->NewObjectArray(3, floatArrCls, NULL);
    if(rot_mat == NULL) return NULL;
    rot_mat = (jobjectArray) env->GetObjectField(ref, fid);
    for(j = 0; j < 3; j++) {
        jfloatArray farr = env->NewFloatArray(3);
        if(farr == NULL) return NULL;
        farr = (jfloatArray) env->GetObjectArrayElement(rot_mat, j);
        jfloat tmp[3];
        for(k = 0; k < 3; k++) {
            (*data).rot_mat[j][k] = tmp[k];
        }
        env->DeleteLocalRef(farr);
    }
    env->DeleteLocalRef(rot_mat);
    env->DeleteLocalRef(floatArrCls);
    //joystick_x
    fid = env->GetFieldID(cls, "joystick_x", "F");
    (*data).joystick_x = env->GetFloatField(ref, fid);
    //joystick_y
    fid = env->GetFieldID(cls, "joystick_y", "F");
    (*data).joystick_y = env->GetFloatField(ref, fid);
    //trigger
    fid = env->GetFieldID(cls, "trigger", "F");
    (*data).trigger = env->GetFloatField(ref, fid);
    //buttons
    fid = env->GetFieldID(cls, "buttons", "I");
    (*data).buttons = env->GetIntField(ref, fid);
    //sequence_number
    fid = env->GetFieldID(cls, "sequence_number", "I");
    (*data).sequence_number = (unsigned char) env->GetIntField(ref, fid);
    //rot_quat[4]
    fid = env->GetFieldID(cls, "rot_quat", "[F");
    jfloatArray rot_quat = env->NewFloatArray(4);
    rot_quat = (jfloatArray) env->GetObjectField(ref, fid);
    env->GetFloatArrayRegion(rot_quat, 0, 4, (*data).rot_quat);
    env->DeleteLocalRef(rot_quat);
    //firmware_revision
    fid = env->GetFieldID(cls, "firmware_revision", "I");
    (*data).firmware_revision = (unsigned short) env->GetIntField(ref, fid);
    //hardware_revision
    fid = env->GetFieldID(cls, "hardware_revision", "I");
    (*data).hardware_revision = (unsigned short) env->GetIntField(ref, fid);
    //packet_type
    fid = env->GetFieldID(cls, "packet_type", "I");
    (*data).packet_type = (unsigned short) env->GetIntField(ref, fid);
    //magnetic_frequency
    fid = env->GetFieldID(cls, "magnetic_frequency", "I");
    (*data).magnetic_frequency = (unsigned short) env->GetIntField(ref, fid);
    //enabled
    fid = env->GetFieldID(cls, "enabled", "Z");
    (*data).enabled = (env->GetBooleanField(ref, fid) == JNI_TRUE ? 1 : 0);
    //controller_index
    fid = env->GetFieldID(cls, "controller_index", "I");
    (*data).controller_index = env->GetIntField(ref, fid);
    //is_docked
    fid = env->GetFieldID(cls, "is_docked", "Z");
    (*data).is_docked = (env->GetBooleanField(ref, fid) == JNI_TRUE ? 1 : 0);
    //which_hand
    fid = env->GetFieldID(cls, "which_hand", "I");
    (*data).which_hand = (unsigned char) env->GetIntField(ref, fid);
    //hemi_tracking_enabled
    fid = env->GetFieldID(cls, "hemi_tracking_enabled", "Z");
    (*data).hemi_tracking_enabled = (env->GetBooleanField(ref, fid) == JNI_TRUE ? 1 : 0);
    return data;
}
