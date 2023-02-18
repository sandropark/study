package com.sandro.bowling;

public class Game {
    public static final int MAX_FRAME = 10;
    private static final int MAX_ROLL = 21;
    private final int[] rolls = new int[MAX_ROLL];
    private int currentRoll;

    public void roll(int pins) {
        rolls[currentRoll++] = pins;
    }

    public int getScore() {
        int score = 0;
        for (int frame = 0; frame < MAX_FRAME; frame++) {
            score += rolls[frame * 2] + rolls[frame * 2 + 1];
        }
        return score;
    }

}
