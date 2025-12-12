package com.example.sudoku.core;

public class CoordinateTableSudoku {
    private int position_x;
    private int position_y;

    public CoordinateTableSudoku(int x, int y) {
        position_x = x;
        position_y = y;
    }

    public int getPosition_x() {
        return position_x;
    }

    public int getPosition_y() {
        return position_y;
    }
}
