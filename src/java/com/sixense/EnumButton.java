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
public enum EnumButton {
    BUTTON_1(0x01 << 5),
    BUTTON_2(0x01 << 6),
    BUTTON_3(0x01 << 3),
    BUTTON_4(0x01 << 4),
    BUMPER(0x01 << 7),
    JOYSTICK(0x01 << 8),
    START(0x01 << 0);
    
    private final int mask;
    
    EnumButton(int mask) {
        this.mask = mask;
    }
    
    public int mask() {
        return mask;
    }
}
