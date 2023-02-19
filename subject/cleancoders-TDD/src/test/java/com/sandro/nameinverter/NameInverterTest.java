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
        assertThat(invert("Mrs. first last")).isEqualTo("last, first");
        assertThat(invert("first last SR.")).isEqualTo("last, first SR.");
        assertThat(invert("first last BS. Phd.")).isEqualTo("last, first BS. Phd.");
    }

    private String invert(String name) {
        if (name == null || name.equals("")) {
            return "";
        }
        List<String> names = splitNames(name);
        if (names.size() == 1) {
            return names.get(0);
        }
        removeHonorific(names);

        return String.format("%s, %s %s", names.get(1), names.get(0), String.join(" ", names.subList(2, names.size()))).trim();
    }

    private void removeHonorific(List<String> names) {
        if (isHonorific(names)) {
            names.remove(0);
        }
    }

    private ArrayList<String> splitNames(String name) {
        return new ArrayList<>(Arrays.asList(name.trim().split("\\s+")));
    }

    private boolean isHonorific(List<String> names) {
        return names.get(0).matches("Mr\\.|Mrs\\.");
    }
}
