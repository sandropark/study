package com.sandro.wordwrapper;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class WrapperTest {

    @Test
    void test() throws Exception {
        assertWraps(null, 1, "");
        assertWraps("", 1, "");
        assertWraps("x", 1, "x");
    }

    private void assertWraps(String s, int length, String expected) {
        assertThat(wrap(s, length)).isEqualTo(expected);
    }

    private String wrap(String s, int length) {
        return s == null ? "" : s;
    }

}
