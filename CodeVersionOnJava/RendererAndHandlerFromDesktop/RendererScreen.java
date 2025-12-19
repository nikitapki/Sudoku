package RendererAndHandlerFromDesktop;

import Core.Config;
import Core.Manager;

public abstract class RendererScreen {
    protected final Manager field;
    protected final String pad;

    protected RendererScreen(Manager field) {
        this.field = field;
        this.pad = repeatSpace(Config.BASE_OFFSET_X);
    }

    protected String repeatSpace(int count) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < count; i++) sb.append(' ');
        return sb.toString();
    }

    public void clearConsole() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    // ВРЕМЕННО. Методы, которые наследник сможет переопределить
    // ------------------------------
    public void beforeDraw() {
        clearConsole();
    }   

    public void drawPrint() {
        System.out.println("Тест переопределения с заменой 123 123");
    }
    // ------------------------------

    // ВРЕМЕННО. Демонстрация вызова виртуальных функций в невиртуальной (той, которую нельзя переопределить)
    // ------------------------------
    public final void renderFrame() {
        clearConsole();
        drawName();          // виртуальный вызов
        drawElementaryField(); // виртуальный вызов
        drawLable();          // виртуальный вызов
    }

    protected void drawName() {
        System.out.println(pad + " Sudoku");
    }

    protected void drawLable() {
        System.out.println(pad + "123");
    }
    // ------------------------------

    public abstract void drawElementaryField();
    public abstract void drawMenu();
    public abstract void drawSettingsDifficulty();
    public abstract boolean tryPlaceValueInCell(int tableCoord, int num);
}
