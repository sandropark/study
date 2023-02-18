package com.sandro.wordwrapper;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class WrapperTest {

    @Test
    void test() throws Exception {
        assertThat(wrap("word word", 4)).isEqualTo("word\nword");
    }

    private String wrap(String s, int length) {
        return s.replaceAll(" ", "\n");
    }

}