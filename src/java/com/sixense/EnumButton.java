package com.sixense;

/*
 * @author Yoda12999
 */
public enum EnumButton {
    BUTTON_1(0x01 << 5),
    BUTTON_2(0x01 << 6),
    BUTTON_3(0x01 << 3),
    BUTTON_4(0x01 << 4),
    BUMPER(0x01 << 7),
    JOYSTICK(0x01 << 8),
    START(0x01 << 0);
    
    private final int mask;
    
    EnumButton(int mask) {
        this.mask = mask;
    }
    
    public int mask() {
        return mask;
    }
}
