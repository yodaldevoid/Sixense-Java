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

/*
 * @author Gabriel Smith
 */
public class MousePointer {
    private long peer;

    public MousePointer() {
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
     * Update the
     * <code>MousePointer</code>. Should be called each frame.
     *
     * @param data single <code>ControllerData</code> from the same controller
     * each time
     * @return an array containing the new x and y position of the mouse
     */
    public native float[] update(ControllerData data);

    /**
     * @param sensitivity default 1.0
     */
    public native void setSensitivity(float sensitivity);

    /**
     * @param acceleration default 1.0
     */
    public native void setAcceleration(float acceleration);

    /**
     * Enables the mouse offset to be changed if the mouse is pushed against 
     * the edge of the screen so that when the mouse is moved in the opposite 
     * direction it will instantly move away from the edge.
     * 
     * @param slide_enabled default true
     */
    public native void setSlideEnabled(boolean slide_enabled);

    /**
     * @param aspect_ratio default 16.0/9.0
     */
    public native void setAspectRatio(float aspect_ratio);

    /**
     * Locks the cursor to bounds of the active window. Does nothing if 
     * slide_enabled has not been set to true.
     *
     * @param lock default false
     */
    public native void setLockRelativeToWindow(boolean lock);

    /**
     * Lock using client bounds rather than window bounds. Does nothing if 
     * <code>setLockRelativeToWindow(true)</code> has not been called and 
     * slide_enabled has not been set to true.
     * 
     * @param lock default true
     */
    public native void setLockRelativeToClientBounds(boolean lock);

    /**
     * Get the offset of the base from the virtual screen.
     * 
     * @return an array containing the x and y offsets in mm
     */
    public native float[] getMouseOffset();

    /**
     * Set the offset of the base from the virtual screen.
     * 
     * @param x distance horizontally in mm
     * @param y distance vertically in mm
     */
    public native void setMouseOffset(float x, float y);

    /**
     * @return the rotation of the controller on the plane of the screen where 
     * 0 is straight up
     */
    public native float getRollAngle();

    /**
     * Set the mouse to the center of the screen so that all following 
     * movements are relative to the current position of the controller.
     */
    public native void setCenter();

    /**
     * Set the mouse to the center of the active window so that all following 
     * movements are relative to the current position of the controller.
     */
    public native void setWindowCenter();
}
