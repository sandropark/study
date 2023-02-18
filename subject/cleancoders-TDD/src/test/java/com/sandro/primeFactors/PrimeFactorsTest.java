package com.sandro.primeFactors;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

class PrimeFactorsTest {

    @Test
    void canFactorIntoPrimes() throws Exception {
        assertThat(of(1)).isEqualTo(List.of());
    }

    private List<Integer> of(int n) {
        return List.of();
    }

}