package com.sixense.utils;

import com.sixense.ControllerData;

/**
 * @author Yoda12999
 */
public class Derivatives {
    private long peer;
    private static final float[] arr = {0, 0, 0};
    
    public Derivatives() {
        this(arr);
    }
    
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

    public native void update(ControllerData data);

    public native float[] getPosition();

    public native float[] getVelocity();

    public native float[] getAcceleration();

    public native float[] getRSquared();

    public void setOffset(float[] offset) {
        setOffset(offset[0], offset[1], offset[2]);
    }
    
    public native void setOffset(float x, float y, float z);

    public native float[] getOffset();
}
