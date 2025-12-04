package RendererAndHandlerFromDesktop;

import Core.Cell;
import Core.Config;
import Core.Manager;

public class RendererDesktop {

    enum CommandsMenu {
        PLAY_GAME,
        EXIT_GAME
    }

    static class CoordinateState {
        int tableCoord = -1;
        int sudokuNumber = -1;
    }

    // Поля Renderer 

    private final Manager field;
    private final String pad;
    private final CoordinateState coord = new CoordinateState();

    // Конструктор

   public RendererDesktop(Manager field) {
    this.field = field;
    this.pad = repeatSpace(Config.BASE_OFFSET_X);
}

private String repeatSpace(int count) {
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < count; i++) {
        sb.append(' ');
    }
    return sb.toString();
}

    // Утилиты

    public void clearConsole() {
        // ANSI‑очистка
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public void initializeCoordinate() {
        coord.sudokuNumber = -1;
        coord.tableCoord = -1;
        field.pastValueCell = -1;
        field.pastValueTableNumbers = -1;
    }

    // Отрисовка основного поля и панели чисел

    public void drawElementaryField() {
        initializeCoordinate();
        clearConsole();

        // «шапка» с кнопкой «Вернуться»
        System.out.println(pad + "    1   2   3   4   5   6   7   8   9  ");
        System.out.println(pad + "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗");

        // 9×9 поле
        for (int r = 0; r < Config.SIZE_SUDOKU; r++) {
            if (r != 0) {
                System.out.println(pad + "  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣");
            }
            StringBuilder line = new StringBuilder();
            // номер строки слева (1–9)
            line.append(pad).append(r + 1).append(" ║");
            for (int c = 0; c < Config.SIZE_SUDOKU; c++) {
                int idx = r * Config.SIZE_SUDOKU + c;
                Cell cell = field.gridCells.field[idx];
                if (cell.is_fixed && cell.value != 0) {
                    line.append(" ").append(cell.value).append(" ║");
                } else {
                    line.append("   ║");
                }
            }
            System.out.println(line);
        }
        System.out.println(pad + "  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝");

        // мини‑таблица чисел 1–9
        System.out.println(pad + "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗");
        System.out.println(pad + "  ║ 1 ║ 2 ║ 3 ║ 4 ║ 5 ║ 6 ║ 7 ║ 8 ║ 9 ║");
        System.out.println(pad + "  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝");
    }

    // Логика установки значения (без ввода)

    public boolean tryPlaceValueInCell(int tableCoord, int num) {
        coord.tableCoord = tableCoord;
        coord.sudokuNumber = num;

        if (field.checkInputValueInCell(coord.tableCoord, coord.sudokuNumber)) {
            field.pastValueCell = coord.tableCoord;
            field.counterFixedCells(field.gridCells.field[coord.tableCoord].value);
            return true;
        } else {
            return false;
        }
    }

    // Отрисовка главного меню (без обработки ввода)

    public void drawMenu() {
        clearConsole();
        System.out.println(pad + "╔══════════════╗");
        System.out.println(pad + "║   Играть (1) ║");
        System.out.println(pad + "╚══════════════╝");
        System.out.println(pad + "╔══════════════╗");
        System.out.println(pad + "║   Выход  (2) ║");
        System.out.println(pad + "╚══════════════╝");
    }

    // Отрисовка меню сложностей (без обработки ввода)

    public void drawSettingsDifficulty() {
        clearConsole();
        System.out.println(pad + "╔═════════════════╗");
        System.out.println(pad + "║ Легкий      (1) ║");
        System.out.println(pad + "╚═════════════════╝");
        System.out.println(pad + "╔═════════════════╗");
        System.out.println(pad + "║ Средний     (2) ║");
        System.out.println(pad + "╚═════════════════╝");
        System.out.println(pad + "╔═════════════════╗");
        System.out.println(pad + "║ Сложный     (3) ║");
        System.out.println(pad + "╚═════════════════╝");
        System.out.println(pad + "╔═════════════════╗");
        System.out.println(pad + "║ Невозможный (4) ║");
        System.out.println(pad + "╚═════════════════╝");
        System.out.println(pad + "╔═════════════════╗");
        System.out.println(pad + "║ Вернуться   (5) ║");
        System.out.println(pad + "╚═════════════════╝");
    }
}
