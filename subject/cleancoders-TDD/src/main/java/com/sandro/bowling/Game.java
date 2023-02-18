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
        int i = 0;
        for (int frame = 0; frame < MAX_FRAME; frame++) {
            if (isStrike(i)) {
                score += 10 + rolls[i + 1] + rolls[i + 2];
                i--;
            } else if (isSpare(i)) {
                    score += 10 + rolls[i + 2];
            } else {
                score += rolls[i] + rolls[i + 1];
            }
            i += 2;
        }
        return score;
    }

    private boolean isStrike(int i) {
        return rolls[i] == 10;
    }

    private boolean isSpare(int i) {
        return rolls[i] + rolls[i + 1] == 10;
    }

}
