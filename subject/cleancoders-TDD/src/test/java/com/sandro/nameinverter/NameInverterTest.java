package com.sandro.nameinverter;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

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
        assertThat(invert("Mr. first last")).isEqualTo("last, first");
    }

    private String invert(String name) {
        if (name == null || name.equals("")) {
            return "";
        }
        List<String> names = new ArrayList<>(Arrays.asList(name.trim().split("\\s+")));
        if (names.size() > 1) {
            if (names.get(0).equals("Mr.")) {
                names.remove(0);
            }
            return String.format("%s, %s", names.get(1), names.get(0));
        }
        return names.get(0);
    }
}
