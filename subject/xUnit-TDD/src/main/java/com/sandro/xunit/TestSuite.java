package com.sandro.xunit;

import java.util.ArrayList;
import java.util.List;

public class TestSuite implements Test {
    private final List<Test> tests = new ArrayList<>();

    public void add(Test test) {
        tests.add(test);
    }

    @Override
    public void run(TestResult result) {
        tests.forEach(t -> t.run(result));
    }
}
