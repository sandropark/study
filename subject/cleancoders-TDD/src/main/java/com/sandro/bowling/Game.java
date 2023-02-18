package com.sandro.bowling;

public class Game {
    private int score;
    private int rollCount;
    private int bonusCount;
    private int currentScore;

    public int getScore() {
        return score;
    }

    /**
     * 공 굴리기
     * @param pins 쓰러트린 핀 수
     */
    public void roll(int pins) {
        checkBonus(pins);

        initRollCountAndCurrentScore();

        score += pins;
        currentScore += pins;

        rollCount--;

        isSpare();
    }

    private void checkBonus(int pins) {
        if (bonusCount > 0) {
            score += pins;
            bonusCount--;
        }
    }

    private void initRollCountAndCurrentScore() {
        if (rollCount == 0) {
            rollCount = 2;
            currentScore = 0;
        }
    }

    private void isSpare() {
        if (rollCount == 0 & currentScore == 10) {
            bonusCount = 1;
        }
    }

}
