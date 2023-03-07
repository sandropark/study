package com.sandro.leetcode.longest_common_prefix;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class LongestCommonPrefixTest {

    @Test
    void testLongestCommonPrefix() throws Exception {
        assertThat(longestCommonPrefix("")).isEqualTo("");
        assertThat(longestCommonPrefix("a")).isEqualTo("a");
        assertThat(longestCommonPrefix("", "a")).isEqualTo("");
    }

    private String longestCommonPrefix(String... strings) {
        String preFix = "";
        for (String str : strings) {
            preFix = str;
        }
        return preFix;
    }
}
