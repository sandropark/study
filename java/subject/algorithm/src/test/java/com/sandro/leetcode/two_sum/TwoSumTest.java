package com.sandro.leetcode.two_sum;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class TwoSumTest {

    @Test
    void twoSumTest() throws Exception {
        int[] nums = new int[]{0, 0};
        int target = 0;
        int[] result = twoSum(nums, target);
        assertThat(result).isEqualTo(new int[]{0, 1});
    }

    private int[] twoSum(int[] nums, int target) {
        return null;
    }

}
