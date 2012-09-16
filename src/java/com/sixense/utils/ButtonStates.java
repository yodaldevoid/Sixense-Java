package com.sixense.utils;

import com.sixense.ControllerData;
import com.sixense.EnumButton;
import com.sixense.utils.enums.*;

/**
 * @author Yoda12999
 */
public class ButtonStates {
    private long peer;

    public ButtonStates() {
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
     * Update the <code>ButtonStates</code>. Should be called each frame.
     *
     * @param data single <code>ControllerData</code> from the same controller each time
     */
    public native void update(ControllerData data);
    
    /**
     * Checks if the requested button was just pressed.
     *
     * @param button the button to check
     * @return true if the button was pressed
     */
    public boolean buttonJustPressed(EnumButton b) {
        return buttonJustPressed(b.mask());
    }
    
    private native boolean buttonJustPressed(int button);

    /**
     * Checks if the requested button was just released.
     *
     * @param button the button to check
     * @return true if the button was released
     */
    public boolean buttonJustReleased(EnumButton b) {
        return buttonJustReleased(b.mask());
    }
    
    private native boolean buttonJustReleased(int button);

    /**
     * Sets the threshold to check against to tell if the trigger has been pressed.
     *
     * @param thresh
     */
    public native void setTriggerThreshold(float thresh);

    /**
     * Checks if the trigger was just pressed.
     *
     * @return true if the trigger was pressed past the threshold
     */
    public native boolean triggerJustPressed();

    /**
     * Checks if the trigger was just released.
     *
     * @return true if the trigger was released past the threshold
     */
    public native boolean triggerJustReleased();

    /**
     * Sets the threshold to check against to tell if the stick has been pressed in a direction.
     *
     * @param thresh
     */
    public native void setStickThreshold(float thresh);

    /**
     * Checks if the stick has been pressed in the specified direction.
     *
     * @param direction direction to check
     * @return true if stick was pressed past the threshold
     */
    public native boolean stickJustPressed(EnumDirection direction);

    /**
     * Checks if the stick has been released from the specified direction.
     *
     * @param direction direction to check
     * @return true if stick was released past the threshold
     */
    public native boolean stickJustReleased(EnumDirection direction);

    /**
     * @param thresh threshold angle in degrees
     */
    public native void setAbsoluteTiltAngleThreshold(float thresh);

    /**
     * @param thresh threshold angle in degrees
     */
    public native void setRelativeTiltAngleThreshold(float thresh);

    /**
     * Sets the origin for all following relative tilts. Relative tilts are an orientation change relative to the orientation last time setRelativeOrigin() was called.
     */
    public native void setRelativeOrigin();

    /**
     * Starts a point gesture. Calls <code>setRelativeOrigin()</code>.
     */
    public native void startPointGesture();

    /**
     * Stops the point gesture.
     */
    public native void stopPointGesture();

    /**
     * Checks if the specified relative tilt just started. Must be used in durring with a Point Gesture.
     *
     * @param direction direction of the relative tilt
     * @return true if the relative tilt started
     */
    public native boolean relativeTiltJustStarted(EnumDirection direction);

    /**
     * Checks if the specified relative tilt just stopped. Must be used in durring with a Point Gesture.
     *
     * @param direction direction of the relative tilt
     * @return true if the relative tilt stopped
     */
    public native boolean relativeTiltJustStopped(EnumDirection direction);

    /**
     * Checks if the specified absolute tilt just started. Absolute gestures are just relative to the world. Cannot be used during a Point Gesture.
     *
     * @param direction direction of the absolute tilt
     * @return true if the absolute tilt started
     */
    public native boolean absoluteTiltJustStarted(EnumDirection direction);

    /**
     * Checks if the specified absolute tilt just stopped. Absolute gestures are just relative to the world. Cannot be used during a Point Gesture.
     *
     * @param direction direction of the absolute tilt
     * @return true if the absolute tilt stopped
     */
    public native boolean absoluteTiltJustStopped(EnumDirection direction);
    
    private native boolean justStarted(EnumActionType action, int arg);
    
    private native boolean justStopped(EnumActionType action, int arg);
    
    /**
     *
     *
     * @param action action type to judge the direction by
     * @param arg 
     * @return true if the specified direction of joystick press/gesture just stopped
     */
    public boolean justStarted(EnumActionType action, Enum arg) {
        if(arg instanceof EnumButton) {
            return justStarted(action, ((EnumButton) arg).mask());
        } else {
            return justStarted(action, arg.ordinal());
        }
    }
    
    /**
     * 
     *
     * @param action action type to judge the direction by
     * @param arg 
     * @return true if the specified direction of joystick press/gesture just stopped
     */
    public boolean justStopped(EnumActionType action, Enum arg) {
        if(arg instanceof EnumButton) {
            return justStarted(action, ((EnumButton) arg).mask());
        } else {
            return justStopped(action, arg.ordinal());
        }
    }
}
