package com.sixense.utils;

/*
 * @author Yoda12999
 * @depreciated Acording to Danny this utility was never finished and has been dropped.
 */
public class LaserPointer {
    private long peer;

    public LaserPointer() {
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
     * @param width
     * @param height
     */
    public native void setScreenSize(float width, float height);

    /**
     *
     * @param x
     * @param y
     * @param z
     */
    public native void setScreenCenterOffset(float x, float y, float z);

    /**
     *
     * @return
     */
    public native float[] getScreenSize();

    /**
     *
     * @return
     */
    public native float[] getScreenCenterOffset();

    /**
     *
     * @param pos
     * @param rot
     * @return
     */
    public float[] getIntersection(float[] pos, float[][] rot) {
        return getIntersection(pos[0], pos[1], pos[2], rot[0][0], rot[0][1], rot[0][2], rot[1][0], rot[1][1], rot[1][2], rot[2][0], rot[2][1], rot[2][2]);
    }
    
    private native float[] getIntersection(float x, float y, float z, float _00, float _01, float _02, float _10, float _11, float _12, float _20, float _21, float _22);

    /**
     *
     * @param bottomLeftA
     * @param topRightA
     * @param bottomLeftB
     * @param topRightB
     * @return
     */
//    public boolean compute(float[] bottomLeftA, float[] topRightA, float[] bottomLeftB, float[] topRightB) {
//        return false;
//    }

    /**
     *
     * @param width
     * @param aspect
     * @param bottomLeft
     * @param topRight
     * @return
     */
//    public boolean compute(float width, float aspect, float[] bottomLeft, float[] topRight) {
//        return false;
//    }
}
