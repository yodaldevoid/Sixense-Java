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
public class Derivatives {
    private long peer;
    private static final float[] arr = {0, 0, 0};
    
    public Derivatives() {
        this(arr);
    }
    
    /**
     *
     * @param offsetVec
     */
    public Derivatives(float[] offsetVec) {
        peer = create(offsetVec[0], offsetVec[1], offsetVec[2]);
    }
    
    @Override
    protected void finalize() {
        destroy();
        peer = 0;
    }

    private native long create(float x, float y, float z);

    private synchronized native void destroy();

    /**
     * Update the
     * <code>Derivatives</code>. Should be called each frame.
     *
     * @param data single <code>ControllerData</code> from the same controller
     * each time
     */
    public native void update(ControllerData data);

    /**
     *
     * @return 
     */
    public native float[] getPosition();

    /**
     *
     * @return
     */
    public native float[] getVelocity();

    /**
     *
     * @return
     */
    public native float[] getAcceleration();

    /**
     *
     * @return
     */
    public native float[] getRSquared();

    /**
     *
     * @param offset
     */
    public void setOffset(float[] offset) {
        setOffset(offset[0], offset[1], offset[2]);
    }
    
    /**
     *
     * @param x
     * @param y
     * @param z
     */
    public native void setOffset(float x, float y, float z);

    /**
     *
     * @return
     */
    public native float[] getOffset();
}
