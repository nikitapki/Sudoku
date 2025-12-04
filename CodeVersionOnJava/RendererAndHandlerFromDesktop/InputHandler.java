package RendererAndHandlerFromDesktop;

import java.util.Scanner;

import Core.Config;

public class InputHandler {
    private final Scanner in = new Scanner(System.in);

    public int askDifficulty() {
        System.out.println("Выбери сложность: 1-легкий, 2-средний, 3-сложный, 4-невозможный, 5-выход");
        System.out.print("> ");
        int d = in.nextInt();
        return d;
    }

    public boolean askRestartOrBackToMenu() {
        System.out.println("1 - Новая игра с выбором сложности, 2 - Выход из игры");
        System.out.print("> ");
        int v = in.nextInt();
        return v == 1;
    }

    // «клик» по ячейке: ввод координат
    public int askCellIndex() {
        System.out.println("Введите координаты клетки (строка 1-9, столбец 1-9, 0 0 - назад в меню):");
        System.out.print("row col > ");
        int r = in.nextInt();
        int c = in.nextInt();
        if (r == 0 && c == 0) {
            return -1; // сигнал «назад»
        }
        return (r - 1) * Config.SIZE_SUDOKU + (c - 1);
    }

    // «клик» по числу 1–9 (или 0 – отмена)
    public int askNumber() {
        System.out.print("Число (1-9, 0 - отмена): ");
        return in.nextInt();
    }

    public int readIntInRange(String prompt, int min, int max) {
        while (true) {
            System.out.println(prompt);
            System.out.print("> ");
            if (in.hasNextInt()) {
                int v = in.nextInt();
                if (v >= min && v <= max) {
                    return v;
                }
                System.out.println("Введите число от " + min + " до " + max + ".");
            } else {
                System.out.println("Нужно ввести целое число.");
                in.next(); // сброс неверного ввода
            }
        }
    }
}
