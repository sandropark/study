package com.sandro.xunit;

public class WasRun extends TestCase {
    public boolean wasRun;
    public boolean wasSetUp;

    public WasRun(String name) {
        super(name);
    }

    @Override
    protected void setUp() {
        wasSetUp = true;
    }

    public void testMethod() {
        wasRun = true;
    }

}
