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
        assertThat(longestCommonPrefix("ab", "a")).isEqualTo("a");
    }

    private String longestCommonPrefix(String... strings) {
        String preFix = strings[0];
        for (int i = 1; i < strings.length; i++) {
            String str = strings[i];
            if (str.isEmpty()) return "";
            StringBuilder tmp = new StringBuilder();
            for (int j = 0; j < Math.min(preFix.length(), str.length()); j++) {
                if (preFix.charAt(j) == str.charAt(j))
                    tmp.append(preFix.charAt(j));
            }
            preFix = tmp.toString();
        }
        return preFix;
    }
}
