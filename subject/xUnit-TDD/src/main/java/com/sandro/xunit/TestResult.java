package com.sandro.xunit;

public class TestResult {
    private int runCount;

    public String getSummary() {
        return runCount + " run, 0 failed";
    }

    public void testStarted() {
        runCount++;
    }

    public void testFailed() {

    }
}
