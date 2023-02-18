package com.sandro.primeFactors;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

class PrimeFactorsTest {

    @Test
    void canFactorIntoPrimes() throws Exception {
        assertPrimeFactors(1, list());
        assertPrimeFactors(2, list(2));
        assertPrimeFactors(3, list(3));
    }

    private List<Integer> of(int n) {
        List<Integer> factors = new ArrayList<>();
        if (n > 1) {
            factors.add(n);
        }
        return factors;
    }

    private void assertPrimeFactors(int n, List<Integer> list) {
        assertThat(of(n)).isEqualTo(list);
    }

    private List<Integer> list(Integer... ints) {
        return List.of(ints);
    }

}