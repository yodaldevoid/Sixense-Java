package com.sixense;

public class ControllerData {
    public int buttons = 0;
    public int controller_index = 0;
    public int firmware_revision = 0;
    public int hardware_revision = 0;
    public float joystick_x = 0;
    public float joystick_y = 0;
    public int magnetic_frequency = 0;
    public int packet_type = 0;
    public float[] pos = {0, 0, 0};
    public float[][] rot_mat = {
        {1, 0, 0}, {0, 1, 0}, {0, 0, 1}
    };
    public float[] rot_quat = {0, 0, 0, 0};
    public int sequence_number = 0;
    public float trigger = 0;
    public boolean is_docked = false;
    public boolean enabled = false;
    public int which_hand = 0;
    public boolean hemi_tracking_enabled = false;
}
