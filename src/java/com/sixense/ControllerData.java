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

package com.sixense;

/*
 * @author Gabriel Smith
 */
public class ControllerData {
    public int buttons = 0;
    public int controller_index = 0;
    public int firmware_revision = 0;
    public int hardware_revision = 0;
    public float joystick_x = 0;
    public float joystick_y = 0;
    public int magnetic_frequency = 0;
    public int packet_type = 0;
    public float[] pos = {0, 0, 0};
    public float[][] rot_mat = {
        {1, 0, 0}, {0, 1, 0}, {0, 0, 1}
    };
    public float[] rot_quat = {0, 0, 0, 0};
    public int sequence_number = 0;
    public float trigger = 0;
    public boolean is_docked = false;
    public boolean enabled = false;
    public int which_hand = 0;
    public boolean hemi_tracking_enabled = false;
}
