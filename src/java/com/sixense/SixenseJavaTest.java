package com.sixense;

//import java.util.Scanner;
import com.sixense.utils.*;
import com.sixense.utils.enums.*;
import java.util.Arrays;

public class SixenseJavaTest implements ManagerCallback {
    private ControllerData[] allData = {new ControllerData(), new ControllerData(), new ControllerData(), new ControllerData()};
    private boolean menuVisible = false;
    private ButtonStates states1;
    private ButtonStates states2;
    //private static Scanner input;

    public static void main(String[] args) {
        //input = new Scanner(System.in);
        SixenseJavaTest test = new SixenseJavaTest();
        test.run();
    }

    public SixenseJavaTest() {
        System.out.println("Initializing...");
        Sixense.init();
        ControllerManager.getInstance().setGameType(EnumGameType.ONE_PLAYER_TWO_CONTROLLER);
        ControllerManager.getInstance().registerSetupCallback(this);

        states1 = new ButtonStates();
        states2 = new ButtonStates();
    }

    public void run() {
        System.out.println("Running...");
        while(true) {
            //input.next();

            Sixense.setActiveBase(0);
            Sixense.getAllNewestData(allData);
            ControllerManager.getInstance().update(allData);

            if(!menuVisible) {
                int leftIndex = ControllerManager.getInstance().getIndex(EnumControllerDesc.P1L);
                int rightIndex = ControllerManager.getInstance().getIndex(EnumControllerDesc.P1R);

                states1.update(allData[leftIndex]);
                states2.update(allData[rightIndex]);

                System.out.print("Pos1: " + Arrays.toString(allData[leftIndex].pos));
                System.out.println(" | Pos2: " + Arrays.toString(allData[rightIndex].pos));

                System.out.print("Quat1: " + Arrays.toString(allData[leftIndex].rot_quat));
                System.out.println(" | Quat2: " + Arrays.toString(allData[rightIndex].rot_quat));

                System.out.println();
            }
            try {
                Thread.sleep(1000);
            } catch(InterruptedException ex) {
                Thread.currentThread().interrupt();
            }
        }
    }

    @Override
    public void onCallback(EnumSetupStep step) {
        if(ControllerManager.getInstance().isMenuVisible()) {
            menuVisible = true;
            System.out.println(ControllerManager.getInstance().getStepString());
        } else {
            menuVisible = false;
        }
    }
}
