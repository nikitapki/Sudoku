package com.example.sudoku;

import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.sudoku.core.Cell;
import com.example.sudoku.core.Config;
import com.example.sudoku.core.CoordinateTableSudoku;
import com.example.sudoku.core.Manager;

public class GameActivity extends AppCompatActivity {

    private final TextView[][] cells = new TextView[Config.SIZE_SUDOKU][Config.SIZE_SUDOKU];

    private String selectedNumber = null;
    private int selectedRow = -1;
    private int selectedCol = -1;

    private Manager manager_field;

    private Button activeButton = null;

    private Button[] numberButtons; // индекс 1..9


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);


        int difficulty = getIntent().getIntExtra("DIFFICULTY", 10);

        manager_field = new Manager();
        manager_field.generateNewGame(difficulty);

        numberButtons = new Button[10]; // индекс 1..9

        // Назначаем listener всем 81 ячейкам (покажу на первой строке)
        int[][] ids = {
                {R.id.cell_0_0, R.id.cell_0_1, R.id.cell_0_2, R.id.cell_0_3, R.id.cell_0_4,
                        R.id.cell_0_5, R.id.cell_0_6, R.id.cell_0_7, R.id.cell_0_8},
                {R.id.cell_1_0, R.id.cell_1_1, R.id.cell_1_2, R.id.cell_1_3, R.id.cell_1_4,
                        R.id.cell_1_5, R.id.cell_1_6, R.id.cell_1_7, R.id.cell_1_8},
                {R.id.cell_2_0, R.id.cell_2_1, R.id.cell_2_2, R.id.cell_2_3, R.id.cell_2_4,
                        R.id.cell_2_5, R.id.cell_2_6, R.id.cell_2_7, R.id.cell_2_8},
                {R.id.cell_3_0, R.id.cell_3_1, R.id.cell_3_2, R.id.cell_3_3, R.id.cell_3_4,
                        R.id.cell_3_5, R.id.cell_3_6, R.id.cell_3_7, R.id.cell_3_8},
                {R.id.cell_4_0, R.id.cell_4_1, R.id.cell_4_2, R.id.cell_4_3, R.id.cell_4_4,
                        R.id.cell_4_5, R.id.cell_4_6, R.id.cell_4_7, R.id.cell_4_8},
                {R.id.cell_5_0, R.id.cell_5_1, R.id.cell_5_2, R.id.cell_5_3, R.id.cell_5_4,
                        R.id.cell_5_5, R.id.cell_5_6, R.id.cell_5_7, R.id.cell_5_8},
                {R.id.cell_6_0, R.id.cell_6_1, R.id.cell_6_2, R.id.cell_6_3, R.id.cell_6_4,
                        R.id.cell_6_5, R.id.cell_6_6, R.id.cell_6_7, R.id.cell_6_8},
                {R.id.cell_7_0, R.id.cell_7_1, R.id.cell_7_2, R.id.cell_7_3, R.id.cell_7_4,
                        R.id.cell_7_5, R.id.cell_7_6, R.id.cell_7_7, R.id.cell_7_8},
                {R.id.cell_8_0, R.id.cell_8_1, R.id.cell_8_2, R.id.cell_8_3, R.id.cell_8_4,
                        R.id.cell_8_5, R.id.cell_8_6, R.id.cell_8_7, R.id.cell_8_8}
        };

        // Обработка всех кнопок меню выбора цифры
        Button btnOne = findViewById(R.id.buttonOne);
        Button btnTwo = findViewById(R.id.buttonTwo);
        Button btnThree = findViewById(R.id.buttonThree);
        Button btnFour = findViewById(R.id.buttonFour);
        Button btnFive = findViewById(R.id.buttonFive);
        Button btnSix = findViewById(R.id.buttonSix);
        Button btnSeven = findViewById(R.id.buttonSeven);
        Button btnEight = findViewById(R.id.buttonEight);
        Button btnNine = findViewById(R.id.buttonNine);

        numberButtons[1] = btnOne;
        numberButtons[2] = btnTwo;
        numberButtons[3] = btnThree;
        numberButtons[4] = btnFour;
        numberButtons[5] = btnFive;
        numberButtons[6] = btnSix;
        numberButtons[7] = btnSeven;
        numberButtons[8] = btnEight;
        numberButtons[9] = btnNine;


        // Обработка кнопки возврата
        Button btnBack = findViewById(R.id.buttonDifficultReturnBack2);

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish(); // просто закрываем GameActivity и возвращаемся назад
            }
        });

        View.OnClickListener numberClick = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                    // если нажали ещё раз на ту же кнопку — снимаем выбор
                if (activeButton == v) {
                    activeButton.setSelected(false);
                    activeButton.setBackgroundColor(Color.TRANSPARENT);
                    activeButton = null;
                    selectedNumber = null;
                    updateAllHighlights();
                    return;
                }

                // снять выделение с прошлой кнопки
                if (activeButton != null) {
                    activeButton.setSelected(false);
                    activeButton.setBackgroundColor(Color.TRANSPARENT);
                }

                // выделить новую
                activeButton = (Button) v;
                activeButton.setSelected(true);
                activeButton.setBackgroundColor(0xFF66BB6A); // зелёный

                // логика выбора числа
                selectedNumber = activeButton.getText().toString();
                updateAllHighlights();
            }
        };

        btnOne.setOnClickListener(numberClick);
        btnTwo.setOnClickListener(numberClick);
        btnThree.setOnClickListener(numberClick);
        btnFour.setOnClickListener(numberClick);
        btnFive.setOnClickListener(numberClick);
        btnSix.setOnClickListener(numberClick);
        btnSeven.setOnClickListener(numberClick);
        btnEight.setOnClickListener(numberClick);
        btnNine.setOnClickListener(numberClick);

        View.OnClickListener cellClickListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // узнаём, какая это ячейка
                String idName = getResources().getResourceEntryName(v.getId());
                // id вида "cell_0_0" → парсим номер строки и столбца
                String[] parts = idName.split("_"); // ["cell","0","0"]
                int row = Integer.parseInt(parts[1]);
                int col = Integer.parseInt(parts[2]);

                selectedRow = row;
                selectedCol = col;

                // если есть выбранное число — пробуем записать его
                if (selectedNumber != null) {
                    int index = row * Config.SIZE_SUDOKU + col;
                    int value = Integer.parseInt(selectedNumber);

                    boolean ok = manager_field.checkInputValueInCell(index, value);
                    if (ok) {
                        // обновляем UI: показываем число и перекрашиваем как фиксированную
                        cells[row][col].setText(selectedNumber);
                        manager_field.counterFixedCells(value);
                        updateNumberButtonsState();
                        checkGameFinished();
                    }
                }

                updateAllHighlights();
            }
        };

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cells[i][j] = findViewById(ids[i][j]);
                cells[i][j].setOnClickListener(cellClickListener);
            }
        }

        applyGeneratedBoard(manager_field.gridCells.field);
    }

    // Функция, которая записывает значения в таблицу
    private void applyGeneratedBoard(Cell[] field) {
        for (int ind = 0; ind < Config.SIZE_SUDOKU_N_X_N; ind++) {

            CoordinateTableSudoku coordsInd = manager_field.gridCells.translatorIndexInRowCol(ind);
            int r = coordsInd.getPosition_y();
            int c = coordsInd.getPosition_x();

            if (!(field[ind].getIs_fixed())) {
                // пустая ячейка
                cells[r][c].setText("");
                cells[r][c].setTextColor(Color.WHITE); // или какой тебе нужен
            } else {
                // стартовое (зафиксированное) число
                cells[r][c].setText(String.valueOf(field[ind].getValue()));
                cells[r][c].setTextColor(Color.WHITE); // другой цвет для "данных"
                // если хочешь запретить изменение пользователем:
                // cells[r][c].setEnabled(false);
            }

        }
    }

    private void updateAllHighlights() {
        for (int r = 0; r < Config.SIZE_SUDOKU; r++) {
            for (int c = 0; c < Config.SIZE_SUDOKU; c++) {

                // базовый цвет
                int color = Color.BLACK;

                // слой строки/столбца/квадрата
                if (selectedRow != -1 && selectedCol != -1) {
                    boolean sameRow = (r == selectedRow);
                    boolean sameCol = (c == selectedCol);
                    boolean sameBox =
                            (r / Config.SIZE_SQUARE_SUDOKU == selectedRow /
                                    Config.SIZE_SQUARE_SUDOKU) &&
                                    (c / Config.SIZE_SQUARE_SUDOKU == selectedCol /
                                            Config.SIZE_SQUARE_SUDOKU);

                    if (sameRow || sameCol || sameBox) {
                        color = 0x33BBBBBB; // серый
                    }
                    if (r == selectedRow && c == selectedCol) {
                        color = 0x55BBBBBB; // выделенная клетка
                    }
                }

                // слой одинаковых чисел
                if (selectedNumber != null) {
                    String cellText = cells[r][c].getText().toString();
                    if (cellText.equals(selectedNumber)) {
                        color = 0x5566BBFF; // синий сверху
                    }
                }

                GradientDrawable gd = new GradientDrawable();
                gd.setColor(color);
                gd.setStroke(1, 0xFFFFFFFF); // обводка
                cells[r][c].setBackground(gd);

            }
        }
    }

    private void updateNumberButtonsState() {
        // предполагаем, что максимум по 9 штук каждой цифры
        int maxPerDigit = 9;
        for (int d = 1; d <= 9; d++) {
            int used = manager_field.gridCells.quantityValues[d];
            Button b = numberButtons[d];
            if (b == null) continue;

            if (used >= maxPerDigit) {
                b.setEnabled(false);
                b.setAlpha(0.3f); // визуально "потухшая"
            } else {
                b.setEnabled(true);
                b.setAlpha(1.0f);
            }
        }

        // если активная кнопка стала недоступной — сбрасываем выбор
        if (activeButton != null && !activeButton.isEnabled()) {
            activeButton = null;
            selectedNumber = null;
            updateAllHighlights();
        }
    }

    private void checkGameFinished() {
        if (manager_field.gridCells.quantityValues[0] >= Config.SIZE_SUDOKU_N_X_N) {
            finish();
        }
    }
}
