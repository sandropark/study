package com.sandro.primeFactors;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

class PrimeFactorsTest {

    @Test
    void canFactorIntoPrimes() throws Exception {
        assertThat(of(1)).isEqualTo(list());
        assertThat(of(2)).isEqualTo(list(2));
    }

    private List<Integer> list(Integer... ints) {
        return List.of(ints);
    }

    private List<Integer> of(int n) {
        List<Integer> factors = new ArrayList<>();
        if (n == 2) {
            factors.add(2);
        }
        return factors;
    }

}