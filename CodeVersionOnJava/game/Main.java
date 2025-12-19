package game;

import Core.Cell;
import Core.CellTime;

public class Main {
    public static void main(String[] args) {
        

        // ВРЕМЕННО. Демонстрация глубокого и поверхностного копирования (ссылка и новый объект класса)
        // -------------------------------------
        Cell c = new Cell();
        c.value = 5;

        CellTime a = new CellTime(c);
        CellTime shallow = a.clone();
        CellTime deep = a.deepClone();

        shallow.cell.value = 9;

        System.out.println(a.cell.value);    // 9  (shallow задел исходный)
        System.out.println(deep.cell.value); // 5  (deep не задел)
        // -------------------------------------


        new Game(); // запускает игровой цикл
    }
}
