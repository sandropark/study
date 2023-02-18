package com.sandro.bowlling;

public class Game {

    private int score;

    /**
     * 공 굴리기
     * @param pins 쓰러트린 핀 수
     */
    public void roll(int pins) {
        this.score += pins;
    }

    public int getScore() {
        return score;
    }
}
