package com.example.sudoku.core;

public class Cell {
	private int value;
    private boolean is_fixed;

    public Cell() {
        value = 0;
        is_fixed = true;
    }

    public void setValue(int val) {
        value = val;
    }

    public void setIs_fixed(boolean isFixed) {
        is_fixed = isFixed;
    }

    public int getValue() {
        return value;
    }

    public boolean getIs_fixed() {
        return is_fixed;
    }
}
