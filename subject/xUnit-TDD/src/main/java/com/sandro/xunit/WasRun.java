package com.sandro.xunit;

public class WasRun extends TestCase {
    public String log;

    public WasRun(String name) {
        super(name);
    }

    @Override
    protected void setUp() {
        log = "setUp";
    }

    public void testMethod() {
        log += " testMethod";
    }

}