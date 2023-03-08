package com.sandro.leetcode.three_sum;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

public class ThreeSumTest {
    @Test
    void threeSumTest() throws Exception {
        assertThat(threeSum(0, 0, 0)).isEqualTo(List.of(List.of(0, 0, 0)));
        assertThat(threeSum(0, 1, 1)).isEqualTo(List.of());
    }

    private List<List<Integer>> threeSum(int... nums) {
        return List.of(List.of(0, 0, 0));
    }
}
