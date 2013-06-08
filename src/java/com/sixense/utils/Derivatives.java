package com.sixense.utils;

import com.sixense.ControllerData;

/*
 * @author Yoda12999
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
