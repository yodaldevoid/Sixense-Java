package com.sixense.utils;

import com.sixense.ControllerData;
import com.sixense.utils.enums.*;

/**
 * @author Yoda12999
 */
public class FPSViewAngles {
    private long peer;
    
    public FPSViewAngles()  {
        peer = create();
    }
    
    @Override
    protected void finalize() {
        destroy();
        peer = 0;
    }
    
    private native long create();

    private synchronized native void destroy();

    public native void setGame(String gameName);

    public native void setMode(EnumFPSMode mode);

    public native EnumFPSMode getMode();

    public native boolean update(ControllerData left, ControllerData right, float frametime);

    public native float[] getViewAngles();

    public native float[] getViewAngleOffset();

    public native float[] getSpinSpeed();

    public void forceViewAngles(EnumFPSMode mode, float[] angles) {
        forceViewAngles(mode, angles[0], angles[1], angles[2]);
    }
    
    public native void forceViewAngles(EnumFPSMode mode, float alpha, float beta, float gamma);

    public void setFeetAnglesMetroid(float[] angles) {
        setFeetAnglesMetroid(angles[0], angles[1], angles[2]);
    }
    
    public native void setFeetAnglesMetroid(float alpha, float beta, float gamma);

    public native float[] getFeetAnglesMetroid();

    public native void setParameter(EnumFPSParams param, float val);

    public native float getParameter(EnumFPSParams param);

    public native void setFov(float hfov, float vfov);

    public native float[] getFov();

    public native void setHoldingTurnSpeed(float horiz, float vert);

    public native void setRatcheting(boolean b);

    public native boolean isRatcheting();

    public native void reset();

    public native void forceMetroidBlend(float blendFraction);
}
