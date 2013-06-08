package com.sixense.utils;

import com.sixense.ControllerData;
import com.sixense.utils.enums.*;

/*
 * @author Yoda12999
 */
public class ViewAngles {
    private long peer;
    
    public ViewAngles()  {
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
     * @param gameName
     */
    public native void setGame(String gameName);

    /**
     *
     * @param mode
     */
    public native void setMode(EnumMode mode);

    /**
     *
     * @return
     */
    public native EnumMode getMode();

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
     * @return
     */
    public native float[] getViewAngles();

    /**
     *
     * @return
     */
    public native float[] getViewAngleOffset();

    /**
     *
     * @return
     */
    public native float[] getSpinSpeed();

    /**
     *
     * @param mode
     * @param angles
     */
    public void forceViewAngles(EnumMode mode, float[] angles) {
        forceViewAngles(mode, angles[0], angles[1], angles[2]);
    }
    
    /**
     *
     * @param mode
     * @param alpha
     * @param beta
     * @param gamma
     */
    public native void forceViewAngles(EnumMode mode, float alpha, float beta, float gamma);

    /**
     *
     * @param angles
     */
    public void setFeetAnglesMetroid(float[] angles) {
        setFeetAnglesMetroid(angles[0], angles[1], angles[2]);
    }
    
    /**
     *
     * @param alpha
     * @param beta
     * @param gamma
     */
    public native void setFeetAnglesMetroid(float alpha, float beta, float gamma);

    /**
     *
     * @return
     */
    public native float[] getFeetAnglesMetroid();

    /**
     *
     * @param param
     * @param val
     */
    public native void setParameter(EnumViewParam param, float val);

    /**
     *
     * @param param
     * @return
     */
    public native float getParameter(EnumViewParam param);

    /**
     *
     * @param hfov
     * @param vfov
     */
    public native void setFov(float hfov, float vfov);

    /**
     *
     * @return
     */
    public native float[] getFov();

    /**
     *
     * @param horiz
     * @param vert
     */
    public native void setHoldingTurnSpeed(float horiz, float vert);

    /**
     *
     * @param b
     */
    public native void setRatcheting(boolean b);

    /**
     *
     * @return
     */
    public native boolean isRatcheting();

    /**
     *
     */
    public native void reset();

    /**
     *
     * @param blendFraction
     */
    public native void forceMetroidBlend(float blendFraction);
}
