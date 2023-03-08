package com.sandro.leetcode.three_sum;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import static org.assertj.core.api.Assertions.assertThat;

public class ThreeSumTest {
    @Test
    void threeSumTest() throws Exception {
        assertThat(threeSum(0, 0, 0)).contains(List.of(0, 0, 0));
        assertThat(threeSum(0, 1, 1)).isEmpty();
        assertThat(threeSum(0, 1, -1).get(0)).contains(-1, 0, 1);
        assertThat(threeSum(0, 1, -1, 1).get(0)).contains(-1, 0, 1);
    }

    private List<List<Integer>> threeSum(int... nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (isSumZero(nums))
            result.add(Arrays.stream(nums).boxed().collect(Collectors.toList()));
        return result;
    }

    private boolean isSumZero(int[] nums) {
        return Arrays.stream(nums).sum() == 0;
    }
}
