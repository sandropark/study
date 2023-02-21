package com.sandro.money;

public interface Expression {
    Money reduce(Bank bank, String to);
}
