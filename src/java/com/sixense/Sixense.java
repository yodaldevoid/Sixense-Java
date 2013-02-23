package com.sixense;

/**
 * @author Yoda12999
 */
public class Sixense {
    static {

        if("x86".equals(System.getProperty("os.arch"))) {
            System.loadLibrary("SixenseJava32");
        } else {
            System.loadLibrary("SixenseJava64");
        }
    }

    /**
     * Initializes the Sixense library. It must be called at least one time per
     * application. Subsequent calls will have no effect. Once initialized, the
     * other Sixense function calls will work as described until
     * <code>Sixense.exit()</code> is called.
     *
     * @return true on success, false on failure
     */
    public static native boolean init();

    /**
     * Shuts down the Sixense library. After this method call, all Sixense API
     * calls will return failure until
     * <code>Sixense.init()</code> is called again.
     *
     * @return true on success, false on failure
     */
    public static native boolean exit();

    /**
     * Gets the maximum number of base units supported by the Sixense control
     * system.
     *
     * @return number of bases supported.
     */
    public static native int getMaxBases();

    /**
     * Designates which base subsequent API calls are to be directed to.
     *
     * @param base_num an integer from <code>0</code> *
     * to <code>Sixense.getMaxBases()-1</code>
     * @return true on success, false on failure
     */
    public static native boolean setActiveBase(int base_num);

    /**
     * Determines if a base is currently connected to the system.
     *
     * @param base_num an integer from <code>0</code> *
     * to <code>Sixense.getMaxBases()-1</code>
     * @return true if connected, false otherwise
     */
    public static native boolean isBaseConnected(int base_num);

    /**
     * Returns the maximum number of controllers supported by the Sixense
     * control system.
     *
     * @return the number of controllers supported
     */
    public static native int getMaxControllers();

    /**
     * Returns the number of active controllers.
     *
     * @return the number of controllers linked to the base unit
     */
    public static native int getNumActiveControllers();

    /**
     * Returns true if the referenced controller is currently connected to the
     * Base Unit.
     *
     * @param controller_id an integer from 0 *
     * to <code>Sixense.getMaxControllers()</code>-1
     * @return true if connected, otherwise false
     */
    public static native boolean isControllerEnabled(int controller_id);

    /**
     * Gets the most recent state of all of the controllers.
     *
     * @param all_data an initialized ControllerData[4] that the controller data
     * will be put in
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static native boolean getAllNewestData(ControllerData[] all_data);

    /**
     * Gets state of all of the controllers, selecting how far back into a
     * history of the last 10 updates.
     *
     * @param index_back an integer from 0 to 9
     * @param all_data an initialized ControllerData[4] that the controller data
     * will be put in
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static native boolean getAllData(int index_back, ControllerData[] all_data);

    /**
     * Gets the most recent state of one of the controllers. If the desired
     * controller is not connected, an empty data packet is returned. Empty data
     * packets are initialized to a zero position and the identity rotation
     * matrix.
     *
     * @param controller_id an integer from 0 *
     * to <code>Sixense.getMaxControllers()</code>-1
     * @param data a ControllerData that the controller data will be put in
     * @return true on as long as the system has been initialized, false if the
     * controller is not connected
     */
    public static native boolean getNewestData(int controller_id, ControllerData data);

    /**
     * Gets state of one of the controllers, selecting how far back into a
     * history of the last 10 updates. If the desired controller is not
     * connected, an empty data packet is returned. Empty data packets are
     * initialized to a zero position and the identity rotation matrix.
     *
     * @param controller_id an integer from 0 *
     * to <code>Sixense.getMaxControllers()</code>-1
     * @param index_back an integer from 0 to 9
     * @param data a ControllerData that the controller data will be put in
     * @return true on as long as the system has been initialized, false if the
     * controller is not connected
     */
    public static native boolean getData(int controller_id, int index_back, ControllerData data);

    /**
     * Gets the size of the history buffer.
     *
     * @return the size of the history buffer
     */
    public static native int getHistorySize();

    /**
     * Sets the internal position and orientation filtering on or off.
     *
     * @param on_or_off true to enable, false to disable
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static native boolean setFilterEnabled(boolean on_or_off);

    /**
     * Returns the enable status of the internal position and orientation
     * filtering.
     *
     * @return true if enabled, false if disabled
     */
    public static native boolean getFilterEnabled();

    /**
     * Sets the parameters that control the position and orientation filtering
     * level.
     *
     * @param params
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static boolean setFilterParams(float[] params) {
        return setFilterParams(params[0], params[1], params[2], params[3]);
    }

    /**
     * Sets the parameters that control the position and orientation filtering
     * level.
     *
     * @param near_range
     * @param near_val
     * @param far_range
     * @param far_val
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static native boolean setFilterParams(float near_range, float near_val, float far_range, float far_val);

    /**
     * Gets the current filtering parameter values.
     *
     * @return current filter parameters
     */
    public static native float[] getFilterParams();

    /**
     * Enables a period of tactile feedback using the vibration motor. Note the
     * Razer Hydra does not support vibration.
     *
     * @param controller_id an integer from 0 *
     * to <code>Sixense.getMaxControllers()</code>-1
     * @param duration the duration of the vibration, in 100 millisecond units
     * @param pattern_id this argument is ignored and the vibration motor is
     * engaged for the full duration
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static native boolean triggerVibration(int controller_id, int duration, int pattern_id);

    /**
     * Enables Hemisphere Tracking when the controller is aiming at the base.
     * This call is deprecieated, as hemisphere tracking is automatically
     * enabled when the controllers are in the dock or by the
     * <code>sixense.utils.ControllerManager</code>. See the Sixense API
     * Overivew for more information.
     *
     * @param controller_id this argument is ignored and the vibration motor is
     * engaged for the full duration
     * @return true on as long as the system has been initialized, otherwise
     * false
     * @deprecated com.sixense.utils.ControllerManager
     */
    public static native boolean autoEnableHemisphereTracking(int controller_id);

    /**
     * Sets High Priority RF binding mode. This call is only used with the
     * wireless Sixense devkits.
     *
     * @param on_or_off true to enable, false to disable
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static native boolean setHighPriorityBinding(boolean on_or_off);

    /**
     * Gets the current state of High Priority RF binding mode. This call is
     * only used with the wireless Sixense devkits.
     *
     * @return true if enabled, false if disabled
     */
    public static native boolean getHighPriorityBinding();

    /**
     * Gets the color of the LED on the Sixense wireless devkits. Each value is
     * between 0 and 255, 0 is off and 255 is fully on.
     *
     * @param colors
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static boolean setBaseColor(int[] colors) {
        return setBaseColor(colors[0], colors[1], colors[2]);
    }

    /**
     * Gets the color of the LED on the Sixense wireless devkits. Each value is
     * between 0 and 255, 0 is off and 255 is fully on.
     *
     * @param red the red component of the led color
     * @param green the green component of the led color
     * @param blue the blue component of the led color
     * @return true on as long as the system has been initialized, otherwise
     * false
     */
    public static native boolean setBaseColor(int red, int green, int blue);

    /**
     * Gets the color of the LED on the Sixense wireless devkits.
     *
     * @return the color values
     */
    public static native int[] getColorBase();
}
