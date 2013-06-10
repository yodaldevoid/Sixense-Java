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

package com.sixense.utils;

import com.sixense.utils.enums.*;

/*
 * @author Gabriel Smith
 */
public class ControllerManager {
    private static ControllerManager instance = null;

    protected ControllerManager() {
    }

    public static ControllerManager getInstance() {
        if(instance == null) {
            instance = new ControllerManager();
        }
        return instance;
    }

    /**
     * @param gameType
     */
    public native void setGameType(EnumGameType gameType);

    /**
     * @return current game type
     */
    public native EnumGameType getGameType();

    /**
     * Update the
     * <code>ControllerManager</code>. Should be called each frame.
     *
     * @param allData <code>ControllerData[]</code> filled
     * by <code>Sixense.update()</code>
     */
    public native void update(com.sixense.ControllerData[] allData);

    /**
     * Get the
     * <code>ControllerData[]</code> index for the given description.
     *
     * @param controllerDesc which controller
     * @return the index
     */
    public native int getIndex(EnumControllerDesc controllerDesc);

    /**
     * Force the user to rebind the controllers to the player slots. Does
     * nothing for now.
     */
    public native void rebind();

    /**
     * @param callback instance of ManagerCallback that will handle the callback
     */
    public native void registerSetupCallback(ManagerCallback callback);

    /**
     * Checks if the
     * <code>ControllerManager</code>'s instructions should be shown.
     *
     * @return true if the application should show the menu system
     */
    public native boolean isMenuVisible();

    /**
     * Gets the file name of the recommended image for the current step.
     *
     * @return String holding the file name
     */
    public native String getTextureFileName();

    /**
     * @return String holding the current step's instruction.
     */
    public native String getStepString();

    /**
     * @return sound to play
     */
    public native EnumSoundType shouldPlaySound();

    /**
     * @param str controller description name
     * @return controller description
     */
    public EnumControllerDesc getControllerDescFromString(String str) {
        if(str.equals("P1L")) {
            return EnumControllerDesc.P1L;
        } else if(str.equals("P1R")) {
            return EnumControllerDesc.P1R;
        } else if(str.equals("P2L")) {
            return EnumControllerDesc.P2L;
        } else if(str.equals("P2R")) {
            return EnumControllerDesc.P2R;
        } else {
            return EnumControllerDesc.P1L;
        }
    }

    /**
     * @return current step
     */
    public native EnumSetupStep getCurrentStep();
}
