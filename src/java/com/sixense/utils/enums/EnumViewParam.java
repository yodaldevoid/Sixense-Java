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

package com.sixense.utils.enums;

/**
 * @author Gabriel Smith
 */
public enum EnumViewParam {
    CONTROLLER_ANGLE_MODE,

    AIM_1TO1_HEADING_MULTIPLIER,
    AIM_1TO1_PITCH_MULTIPLIER,
    AIM_1TO1_RATCHET_VERTICAL,

    AIM_METROID_HEADING_MULTIPLIER,
    AIM_METROID_PITCH_MULTIPLIER,
    AIM_METROID_DEAD_ZONE_RADIUS,
    AIM_METROID_ACCEL_BAND_SIZE,
    AIM_METROID_MAX_SPEED,
    AIM_METROID_AUTO_LEVEL_RATE,
    AIM_METROID_ACCEL_BAND_EXPONENT,
    AIM_METROID_SWITCH_BLEND_TIME_ENTER,
    AIM_METROID_SWITCH_BLEND_TIME_EXIT,

    FEET_ANGLES_OFFSET_STICK_SPIN_HORIZ_MULTIPLIER,
    FEET_ANGLES_OFFSET_STICK_SPIN_VERT_MULTIPLIER,
    FEET_ANGLES_OFFSET_STICK_SPIN_INVERT_PITCH,
    FEET_ANGLES_OFFSET_STICK_SPIN_EXPONENT,

    PITCH_CHANGE_BLEND_VAL,

    SPRING_VIEW_ENABLED,
    SPRING_VIEW_MIN_SPRING,
    SPRING_VIEW_MAX_SPRING,
    SPRING_VIEW_MIN_ANGLE,
    SPRING_VIEW_MAX_ANGLE,
    
    FEET_ANGLES_ALLOW_VERT_STICK_SPIN,

    AIM_METROID_ACCEL_BAND_POWER,

    HOLDING_TURN_SPEED,

    ROLL_CORRECTION_BLEND,
    EXIT_METROID_BLEND,

    LEFT_HANDED,

    LAST_PARAM
}
