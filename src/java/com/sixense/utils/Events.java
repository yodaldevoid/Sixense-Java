package com.sixense.utils;

import com.sixense.ControllerData;
import com.sixense.EnumButton;
import com.sixense.utils.enums.*;

/**
 * @author Yoda12999
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

    public native void setGame(String game_name);
    
    public void setBinding(EnumEvent event, EnumController controller, EnumActionType action, EnumButton param) {
        setBinding(event, controller, action, param.ordinal());
    }
    
    public void setBinding(EnumEvent event, EnumController controller, EnumActionType action, EnumDirection param) {
        setBinding(event, controller, action, param.ordinal());
    }

    public native void setBinding(EnumEvent event, EnumController controller, EnumActionType action, int param);
    
    public void setPointGestureButton(EnumButton button) {
        setPointGestureButton(button.ordinal());
    }

    public native void setPointGestureButton(int button);

    public native boolean isPointGestureActive();
    
    public boolean update(ControllerData left, ControllerData right) {
        return update(left, right, 0);
    }

    public native boolean update(ControllerData left, ControllerData right, float frametime);

    public native boolean eventActive(EnumEvent event);

    public native boolean eventStarted(EnumEvent event);

    public native boolean eventStopped(EnumEvent event);

    public native float[] getGrenadeThrowVelocity();

    public native void setParameter(EnumEventParam param, float val);

    public native float getParameter(EnumEventParam param);
}
