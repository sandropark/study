package com.sandro.tree.heap;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

class HeapTest {

    @DisplayName("isHeap 메서드는")
    @Nested
    class DescribeIsHeap {

        @DisplayName("힙이 주어지면")
        @Nested
        class ContextWithHeap {

            Heap heap1 = Heap.of(10, 1, 2);
            Heap heap2 = Heap.of(10, 5, 6, 1);

            @DisplayName("true 를 반환한다.")
            @Test
            void itReturnsTrue() throws Exception {
                assertThat(heap1.isHeap()).isTrue();
                assertThat(heap2.isHeap()).isTrue();
            }
        }

        @DisplayName("힙이 아닌 배열이 주어지면")
        @Nested
        class ContextWithNotHeap {

            Heap notHeap = Heap.of(10, 5, 6, 7);

            @DisplayName("false 를 반환한다.")
            @Test
            void itReturnsFalse() throws Exception {
                assertThat(notHeap.isHeap()).isFalse();
            }
        }
    }

    @DisplayName("makeHeap 메서드는")
    @Nested
    class DescribeMakeHeap {

        @DisplayName("힙이 아닌 객체가 주어지면")
        @Nested
        class ContextNotHeapObj {

            Heap heap = Heap.of(2, 8, 6);
            Heap heap2 = Heap.of(2, 8, 6, 1, 10, 15, 3, 12, 11);

            @BeforeEach
            void setUp() {
                assertThat(heap.isHeap()).isFalse();
                assertThat(heap2.isHeap()).isFalse();
            }

            @DisplayName("힙으로 만든다.")
            @Test
            void itMakesItHeap() throws Exception {
                heap.makeHeap();
                heap2.makeHeap();

                assertThat(heap.isHeap()).isTrue();
                assertThat(heap2.isHeap()).isTrue();
            }
        }
    }

}
