package com.sandro.xunit;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public abstract class TestCase {
    protected final String name;

    public TestCase(String name) {
        this.name = name;
    }

    public TestResult run() {
        setUp();

        try {
            Method method = getClass().getMethod(name);
            method.invoke(this);
        } catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
            throw new RuntimeException(e);
        }

        tearDown();
        return new TestResult();
    }

    protected void setUp() {}

    protected void tearDown() {}
}
