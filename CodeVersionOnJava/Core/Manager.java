package Core;
public class Manager {

    private final RandomLCG rand = new RandomLCG();

    // Игровое поле
    public Field gridCells = new Field();

    // Прошлые значения (может быть изменено)
    public int pastValueCell = -1;
    public int pastValueTableNumbers = -1;

    public static int Utilit_toIndex(int row0, int col0) {
        return row0 * Config.SIZE_SUDOKU + col0;
    }

    // Проверка значения в строке
    private boolean checkerCombinationsFromRow(int coord_y, int value) {
        int idx;
        for (int i = 0; i < Config.SIZE_SUDOKU; i++) {
            idx = Utilit_toIndex(coord_y, i);
            if (gridCells.field[idx].value == value) {
                return false;
            }
        }
        return true;
    }

    // Проверка значения в столбце
    private boolean checkerCombinationsFromColumn(int coord_x, int value) {
        int idx;
        for (int i = 0; i < Config.SIZE_SUDOKU; i++) {
            idx = Utilit_toIndex(i, coord_x);
            if (gridCells.field[idx].value == value) {
                return false;
            }
        }
        return true;
    }

    // Проверка значения в квадрате 3x3
    private boolean checkerCombinationsFromBox(CoordinateTableSudoku coord, int value) {
        int offsetY = coord.pos_y - coord.pos_y % Config.SIZE_SQUARE_SUDOKU;
        int offsetX = coord.pos_x - coord.pos_x % Config.SIZE_SQUARE_SUDOKU;

        int idx;
        for (int i = offsetY; i < offsetY + Config.SIZE_SQUARE_SUDOKU; i++) {
            for (int j = offsetX; j < offsetX + Config.SIZE_SQUARE_SUDOKU; j++) {
                idx = Utilit_toIndex(i, j);
                if (gridCells.field[idx].value == value) {
                    return false;
                }
            }
        }
        return true;
    }

    // Общая проверка: строка, столбец, квадрат
    private boolean checkerCombinations(int indexCoordinateTableSudoku, int value) {
        CoordinateTableSudoku coord =
                gridCells.translatorIndexInRowCol(indexCoordinateTableSudoku);
        return checkerCombinationsFromRow(coord.pos_y, value)
                && checkerCombinationsFromColumn(coord.pos_x, value)
                && checkerCombinationsFromBox(coord, value);
    }

    // Найти первую пустую клетку (value == 0)
    private boolean findEmpty(IntRef indexCoordinateTableSudoku) {
        for (int i = 0; i < Config.SIZE_SUDOKU_N_X_N; i++) {
            if (gridCells.field[i].value == 0) {
                indexCoordinateTableSudoku.value = i;
                return true;
            }
        }
        return false;
    }

    // Рекурсивное заполнение сетки - backtracking
    private boolean fillGrid() {
        IntRef indexRef = new IntRef();
        if (!findEmpty(indexRef)) {
            return true; // нет пустых — поле заполнено
        }

        int index = indexRef.value;

        // кандидаты 1..9
        int[] candidates = rand.randomGenerateReverseMassive(1, 9);
        rand.randomReverseMassive(candidates, Config.SIZE_SUDOKU);

        for (int val : candidates) {
            if (checkerCombinations(index, val)) {
                gridCells.field[index].value = val;

                if (fillGrid()) {
                    return true;
                }

                gridCells.field[index].value = 0;
            }
        }
        return false;
    }

    // Сделать часть клеток нефиксированными (для загадки)
    private void unFixedCell(int quantityRemoves) {
        int[] massiveIndexesGrid = rand.randomGenerateReverseMassive(1,
                Config.SIZE_SUDOKU_N_X_N);
        for (int i = 0; i < quantityRemoves && i < massiveIndexesGrid.length; i++) {
            int idx = massiveIndexesGrid[i] - 1; // если там 1..81
            gridCells.field[idx].is_fixed = false;
        }
    }

    // Подсчёт фиксированных чисел
    private void fillCounterFixedCells() {
        for (int i = 0; i < Config.SIZE_SUDOKU_N_X_N; i++) {
            if (gridCells.field[i].is_fixed) {
                gridCells.quantityValues[0]++;
                gridCells.quantityValues[gridCells.field[i].value]++;
            }
        }
    }

    // Учёт нового фиксированного значения
    public void counterFixedCells(int valueCell) {
        gridCells.quantityValues[0]++;
        gridCells.quantityValues[valueCell]++;
    }

    // Генерация новой игры
    public void generateNewGame(int quantityRemoves) {
        gridCells.initializeFieldEmptyValues();
        gridCells.initializeQuantityEmptyValues();

        fillGrid();

        unFixedCell(quantityRemoves);

        fillCounterFixedCells();
    }

    // Проверка ввода в ячейку: если всё ок, фиксируем её
    public boolean checkInputValueInCell(int coordinateCell, int inputValue) {
        boolean result = true;

        if (coordinateCell < 0 || coordinateCell >= Config.SIZE_SUDOKU_N_X_N) {
            throw new IndexOutOfBoundsException("Координата клетки вне диапазона 0..80");
        }
        if (inputValue < 1 || inputValue > 9) {
            throw new IllegalArgumentException("Число должно быть 1..9");
        }

        if (gridCells.field[coordinateCell].is_fixed
                || gridCells.field[coordinateCell].value != inputValue) {
            result = false;
        } else {
            gridCells.field[coordinateCell].is_fixed = true;
        }

        return result;
    }

    // Проверка соответствия значения в ячейке
    public boolean checkerMatchingNums(int inputValue, int indexTableValue) {
        return gridCells.field[indexTableValue].value == inputValue;
    }

    // Простое сравнение двух чисел
    public boolean compareNums(int num1, int num2) {
        return num1 == num2;
    }

    // Вспомогательный класс для "возврата" int по ссылке (аналог int* в C++)
    private static class IntRef {
        int value;
    }
}
