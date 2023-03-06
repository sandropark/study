package com.sandro.leetcode.roman_to_integer;

import org.junit.jupiter.api.Test;

import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.assertThat;

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
        assertThat(romanToInt("II")).isEqualTo(2);
        assertThat(romanToInt("IV")).isEqualTo(4);
        assertThat(romanToInt("IX")).isEqualTo(9);
    }

    private int romanToInt(String s) {
        Map<String, Integer> map = Map.of("I", 1, "V", 5, "X", 10, "L", 50, "C", 100, "D", 500, "M", 1000);
        String[] strings = s.split("");
        int result = map.get(strings[0]);
        for (int i = 1; i < strings.length; i++) {
            Integer preValue = map.get(strings[i - 1]);
            Integer tempValue = map.get(strings[i]);
            if (preValue == tempValue * 0.2)
                tempValue = (int)(tempValue * 0.6);
            if (preValue == tempValue * 0.1)
                tempValue = (int)(tempValue * 0.8);
            result += tempValue;
        }
        return result;
    }
}
