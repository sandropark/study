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
        String preFix = strings[0];
        for (int i = 1; i < strings.length; i++) {
            if (strings[i].equals("")) return "";
            if (!preFix.equals(strings[i])) return "";
        }
        return preFix;
    }
}
