package com.sandro.wordwrapper;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class WrapperTest {

    @Test
    void test() throws Exception {
        assertWraps(null, 1, "");
        assertWraps("", 1, "");
        assertWraps("x", 1, "x");
        assertWraps("xx", 1, "x\nx");
        assertWraps("xxx", 1, "x\nx\nx");
        assertWraps("x x", 1, "x\nx");
    }

    private String wrap(String s, int length) {
        if (s == null) return "";

        if (s.length() <= length)
            return s;
        else
            return s.substring(0, length) + "\n" + wrap(s.substring(length).trim(), length);
    }

    private void assertWraps(String s, int length, String expected) {
        assertThat(wrap(s, length)).isEqualTo(expected);
    }

}
