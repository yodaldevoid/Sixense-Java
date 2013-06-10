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
import com.sixense.utils.enums.EnumMovementParam;

/*
 * @author Gabriel Smith
 */
public class PlayerMovement {
    private long peer;
    
    public PlayerMovement()  {
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
     * @param left
     * @param right
     * @param frametime_in_ms
     * @return
     */
    public native boolean update(ControllerData left, ControllerData right, float frametime_in_ms);

    /**
     *
     * @return
     */
    public native float[] getWalkDir();

    /**
     *
     * @param param
     * @param val
     */
    public native void setParameter(EnumMovementParam param, float val);
    /**
     *
     * @param param
     * @return
     */
    public native float getParameter(EnumMovementParam param);
}
