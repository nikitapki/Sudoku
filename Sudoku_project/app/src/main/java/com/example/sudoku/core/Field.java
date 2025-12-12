package com.example.sudoku.core;

public class Field {
    public Cell[] field = new Cell[Config.SIZE_SUDOKU_N_X_N];
    public int[] quantityValues = new int[Config.SIZE_COUNTER_IMPUT_NUMS];

    public Field() {
        initializeFieldEmptyValues();
        initializeQuantityEmptyValues();
    }

    public void initializeFieldEmptyValues() {
        for (int i = 0; i < field.length; i++) {
            field[i] = new Cell();
        }
    }

    public void initializeQuantityEmptyValues() {
        for (int i = 0; i < quantityValues.length; i++) {
            quantityValues[i] = 0;
        }
    }

    public CoordinateTableSudoku translatorIndexInRowCol(int index) {
        int y = index / Config.SIZE_SUDOKU;
        int x = index % Config.SIZE_SUDOKU;
        return new CoordinateTableSudoku(x, y);
    }
}
