package com.sandro.bowlling;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class GameTest {

    private Game game;

    @BeforeEach
    void setUp() {
        game = new Game();
    }


    @DisplayName("공을 굴린다.")
    @Test
    void canRoll() throws Exception {
        game.roll(0);
    }

    @DisplayName("한 번도 핀을 쓰러트리지 못하는 경우 0점을 반환한다.")
    @Test
    void gutterGame() throws Exception {
        for (int i = 0; i < 20; i++) {
            game.roll(0);
        }
        assertThat(game.getScore()).isEqualTo(0);
    }

    @DisplayName("20번 공을 굴려 핀 20개를 쓰러트린 경우 20점을 반환한다.")
    @Test
    void allOnes() throws Exception {
        for (int i = 0; i < 20; i++) {
            game.roll(1);
        }
        assertThat(game.getScore()).isEqualTo(20);
    }

}
