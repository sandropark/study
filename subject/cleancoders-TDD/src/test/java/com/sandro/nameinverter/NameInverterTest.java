package com.sandro.nameinverter;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class NameInverterTest {

    @Test
    void name() throws Exception {
        assertThat(invert(null)).isEqualTo("");
    }

    private String invert(String name) {
        return null;
    }
}
