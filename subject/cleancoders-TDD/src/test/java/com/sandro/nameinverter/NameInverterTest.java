package com.sandro.nameinverter;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class NameInverterTest {

    @Test
    void name() throws Exception {
        assertThat(invert(null)).isEqualTo("");
        assertThat(invert("")).isEqualTo("");
        assertThat(invert("name")).isEqualTo("name");
    }

    private String invert(String name) {
        if (name == null || name.equals("")) {
            return "";
        }
        return name;
    }
}
