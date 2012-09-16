package com.sixense.utils;

import com.sixense.utils.enums.EnumSetupStep;

/**
 * @author Yoda12999
 */
public interface ManagerCallback {
    /**
     * This function is called when the current step changes. It should never be explicitly called.
     *
     * @param step current step
     */
    public void onCallback(EnumSetupStep step);
}
