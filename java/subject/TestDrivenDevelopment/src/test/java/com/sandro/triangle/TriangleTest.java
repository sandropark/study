package com.sandro.triangle;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

public class TriangleTest {

    @DisplayName("숫자가 0보다 작다면 예외가 발생한다.")
    @Test
    void argumentsShouldBeGreaterThan0() throws Exception {
        assertThatThrownBy(() -> new Triangle(0, 0, 0))
                .isInstanceOf(IllegalArgumentException.class);
        assertThatThrownBy(() -> new Triangle(-1, 1, 1))
                .isInstanceOf(IllegalArgumentException.class);
    }

    @DisplayName("한 변의 길이가 다른 두 변의 길이보다 작지 않다면 예외가 발생한다.")
    @Test
    void oneSideShouldBeSmallerThanSumOfTheOthers() throws Exception {
        assertThatThrownBy(() -> new Triangle(1, 1, 2))
                .isInstanceOf(IllegalArgumentException.class);
    }

    @DisplayName("정삼각형이라면 1을 반환한다.")
    @Test
    void shouldReturn1() throws Exception {
        Triangle triangle = new Triangle(1, 1, 1);
        assertThat(triangle.code()).isEqualTo(1);
    }

    @DisplayName("부등변 삼각형이라면 3을 반환한다.")
    @Test
    void shouldReturn2() throws Exception {
        Triangle triangle = new Triangle(2, 3, 4);
        assertThat(triangle.code()).isEqualTo(3);
    }

    private class Triangle {
        private final int a;
        private final int b;
        private final int c;
        public Triangle(int a, int b, int c) {
            validate(a, b, c);
            this.a = a;
            this.b = b;
            this.c = c;
        }

        private void validate(int a, int b, int c) {
            if (isSmallerThan1(a, b, c) || isNotTriangle(a, b, c))
                throw new IllegalArgumentException();
        }

        private boolean isNotTriangle(int a, int b, int c) {
            return a + b <= c || a + c <= b || b + c <= a;
        }

        private boolean isSmallerThan1(int a, int b, int c) {
            return a < 1 || b < 1 || c < 1;
        }

        public int code() {
            if (a == b && a == c)
                return 1;
            if (a != b && a != c && b != c)
                return 3;
            return 0;
        }
    }
}
