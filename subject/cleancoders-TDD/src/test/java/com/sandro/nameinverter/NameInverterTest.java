package com.sandro.nameinverter;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class NameInverterTest {

    @Test
    void name() throws Exception {
        assertThat(invert(null)).isEqualTo("");
        assertThat(invert("")).isEqualTo("");
        assertThat(invert("name")).isEqualTo("name");
        assertThat(invert("first last")).isEqualTo("last, first");
        assertThat(invert("   name   ")).isEqualTo("name");
        assertThat(invert("first     last")).isEqualTo("last, first");
    }

    private String invert(String name) {
        if (name == null || name.equals("")) {
            return "";
        }
        String[] names = name.trim().split("\\s+");
        if (names.length > 1) {
            return String.format("%s, %s", names[1], names[0]);
        }
        return names[0];
    }
}
