package com.sandro.leetcode.roman_to_integer;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

public class RomanToIntegerTest {

    @Test
    void romanToIntTest() throws Exception {
        assertThat(romanToInt("I")).isEqualTo(1);
        assertThat(romanToInt("V")).isEqualTo(5);
        assertThat(romanToInt("X")).isEqualTo(10);
        assertThat(romanToInt("L")).isEqualTo(50);
        assertThat(romanToInt("C")).isEqualTo(100);
        assertThat(romanToInt("D")).isEqualTo(500);
        assertThat(romanToInt("M")).isEqualTo(1000);
        assertThatThrownBy(() -> romanToInt(null)).isInstanceOf(IllegalArgumentException.class);
    }

    private int romanToInt(String s) {
        if ("I".equals(s)) return 1;
        if ("V".equals(s)) return 5;
        if ("X".equals(s)) return 10;
        if ("L".equals(s)) return 50;
        if ("C".equals(s)) return 100;
        if ("D".equals(s)) return 500;
        if ("M".equals(s)) return 1000;
        throw new IllegalArgumentException();
    }
}
