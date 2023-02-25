package com.sandro.triangle;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThatThrownBy;

public class TriangleTest {

    @DisplayName("숫자가 0보다 작다면 예외가 발생한다.")
    @Test
    void argumentsShouldGreaterThan0() throws Exception {
        assertThatThrownBy(() -> new Triangle(0, 0, 0))
                .isInstanceOf(IllegalArgumentException.class);
    }

    private class Triangle {
        public Triangle(int a, int b, int c) {

        }

    }
}
