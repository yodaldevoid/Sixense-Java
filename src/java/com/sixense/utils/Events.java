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

import com.sixense.ControllerData;
import com.sixense.EnumButton;
import com.sixense.utils.enums.*;

/*
 * @author Gabriel Smith
 */
public class Events {
    private long peer;

    public Events() {
        peer = create();
    }

    @Override
    protected void finalize() {
        destroy();
        peer = 0;
    }

    private native long create();

    private synchronized native void destroy();

    /**
     *
     * @param game_name
     */
    public native void setGame(String game_name);
    
    /**
     *
     * @param event
     * @param controller
     * @param action
     * @param param
     */
    public void setBinding(EnumEvent event, EnumController controller, EnumActionType action, EnumButton param) {
        setBinding(event, controller, action, param.ordinal());
    }
    
    /**
     *
     * @param event
     * @param controller
     * @param action
     * @param param
     */
    public void setBinding(EnumEvent event, EnumController controller, EnumActionType action, EnumDirection param) {
        setBinding(event, controller, action, param.ordinal());
    }

    /**
     *
     * @param event
     * @param controller
     * @param action
     * @param param
     */
    public native void setBinding(EnumEvent event, EnumController controller, EnumActionType action, int param);
    
    /**
     *
     * @param button
     */
    public void setPointGestureButton(EnumButton button) {
        setPointGestureButton(button.ordinal());
    }

    /**
     *
     * @param button
     */
    public native void setPointGestureButton(int button);

    /**
     *
     * @return
     */
    public native boolean isPointGestureActive();
    
    /**
     *
     * @param left
     * @param right
     * @return
     */
    public boolean update(ControllerData left, ControllerData right) {
        return update(left, right, 0);
    }

    /**
     *
     * @param left
     * @param right
     * @param frametime
     * @return
     */
    public native boolean update(ControllerData left, ControllerData right, float frametime);

    /**
     *
     * @param event
     * @return
     */
    public native boolean eventActive(EnumEvent event);

    /**
     *
     * @param event
     * @return
     */
    public native boolean eventStarted(EnumEvent event);

    /**
     *
     * @param event
     * @return
     */
    public native boolean eventStopped(EnumEvent event);

    /**
     *
     * @return
     */
    public native float[] getGrenadeThrowVelocity();

    /**
     *
     * @param param
     * @param val
     */
    public native void setParameter(EnumEventParam param, float val);

    /**
     *
     * @param param
     * @return
     */
    public native float getParameter(EnumEventParam param);
}
