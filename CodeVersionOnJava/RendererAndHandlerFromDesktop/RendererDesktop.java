package RendererAndHandlerFromDesktop;

import Core.Cell;
import Core.Config;
import Core.Manager;
import RendererAndHandlerFromDesktop.RendererDesktop.CoordinateState;

public class RendererDesktop extends RendererScreen {

    // ВРЕМЕННО. Переопределенный метод из родителя
    // ------------------------------
    @Override
    public void beforeDraw() {
        super.beforeDraw();
        System.out.println("Тест переопределения с дополнением");
    }

    @Override
    public void drawPrint() {
        System.out.println("Тест переопределения с заменой 456 456");
    }
    // ------------------------------


    enum CommandsMenu {
        PLAY_GAME,
        EXIT_GAME
    }

    static class CoordinateState {
        int tableCoord = -1;
        int sudokuNumber = -1;
    }

    private final CoordinateState coord = new CoordinateState();

    public RendererDesktop(Manager field) {
        super(field);
    }

    protected void initializeCoordinate() {
        coord.sudokuNumber = -1;
        coord.tableCoord = -1;
        field.pastValueCell = -1;
        field.pastValueTableNumbers = -1;
    }

    // ВРЕМЕННО. Переопределение двух виртуальных функций
    // ------------------------------
     @Override
        protected void drawName() {
            System.out.println("Sudoku 9x9");
        }

    @Override
    protected void drawLable() {
        System.out.println("456");
    }
    // ------------------------------

    @Override
    public void drawElementaryField() {
        initializeCoordinate();
        // clearConsole(); 
        
        // ВРЕМЕННО. Тест переопределенного метода
        // ------------------------------
        beforeDraw();
        drawPrint();
        // ------------------------------

        System.out.println(pad + "    1   2   3   4   5   6   7   8   9  ");
        System.out.println(pad + "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗");

        for (int r = 0; r < Config.SIZE_SUDOKU; r++) {
            if (r != 0) {
                System.out.println(pad + "  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣");
            }
            StringBuilder line = new StringBuilder();
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

        System.out.println(pad + "  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗");
        System.out.println(pad + "  ║ 1 ║ 2 ║ 3 ║ 4 ║ 5 ║ 6 ║ 7 ║ 8 ║ 9 ║");
        System.out.println(pad + "  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝");
    }

    @Override
    public boolean tryPlaceValueInCell(int tableCoord, int num) {
        coord.tableCoord = tableCoord;
        coord.sudokuNumber = num;

        if (field.checkInputValueInCell(coord.tableCoord, coord.sudokuNumber)) {
            field.pastValueCell = coord.tableCoord;
            field.counterFixedCells(field.gridCells.field[coord.tableCoord].value);
            return true;
        }
        return false;
    }

    @Override
    public void drawMenu() {
        clearConsole();
        System.out.println(pad + "╔══════════════╗");
        System.out.println(pad + "║   Играть (1) ║");
        System.out.println(pad + "╚══════════════╝");
        System.out.println(pad + "╔══════════════╗");
        System.out.println(pad + "║   Выход  (2) ║");
        System.out.println(pad + "╚══════════════╝");
    }

    @Override
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
