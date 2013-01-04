package com.sixense.utils;

import com.sixense.ControllerData;
import com.sixense.utils.enums.EnumMovementParam;

/**
 * @author Yoda12999
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

    public native void setGame(String game_name);

    public native boolean update(ControllerData left, ControllerData right, float frametime_in_ms);

    public native float[] getWalkDir();

    public native void setParameter(EnumMovementParam param, float val);
    public native float getParameter(EnumMovementParam param);
}
