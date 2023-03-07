package com.sandro.leetcode.longest_common_prefix;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class LongestCommonPrefixTest {

    @Test
    void testLongestCommonPrefix() throws Exception {
        assertThat(longestCommonPrefix("")).isEqualTo("");
        assertThat(longestCommonPrefix("a")).isEqualTo("a");
        assertThat(longestCommonPrefix("", "a")).isEqualTo("");
        assertThat(longestCommonPrefix("a", "a")).isEqualTo("a");
        assertThat(longestCommonPrefix("a", "b")).isEqualTo("");
    }

    private String longestCommonPrefix(String... strings) {
        String preFix = "";
        for (String str : strings) {
            if (str.equals("")) return "";
            if (preFix.equals("")) preFix = str;
        }
        return preFix;
    }
}
