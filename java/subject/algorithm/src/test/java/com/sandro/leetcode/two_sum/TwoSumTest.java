package com.sandro.leetcode.two_sum;

import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class TwoSumTest {

    @Test
    void twoSumTest() throws Exception {
        assertThat(twoSum(new int[]{0, 0}, 0)).isEqualTo(new int[]{0, 1});
        assertThat(twoSum(new int[]{1, 0, 0}, 0)).isEqualTo(new int[]{1, 2});
    }

    private int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            int augend = nums[i];
            for (int j = 0; j < nums.length; j++) {
                int addend = nums[j];
                if (i != j && augend + addend == target)
                    return new int[]{i, j};
            }
        }
        throw new IllegalArgumentException();
    }

}
