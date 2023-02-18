package com.sandro.wordwrapper;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class WrapperTest {

    @Test
    void test() throws Exception {
        assertThat(wrap("word word", 4)).isEqualTo("word\nword");
        assertThat(wrap("a dog", 5)).isEqualTo("a dog");
        assertThat(wrap("a dog with a bone", 6)).isEqualTo("a dog\nwith a\nbone");
    }

    private String wrap(String s, int length) {
        return s.length() > length
                ? s.replaceAll(" ", "\n")
                : s;
    }

}
