package game;
import java.time.Duration;
import java.time.Instant;

import Core.Config;
import Core.Manager;
import RendererAndHandlerFromDesktop.InputHandler;
import RendererAndHandlerFromDesktop.MenuController;
import RendererAndHandlerFromDesktop.RendererDesktop;

public class Game {

    private final Manager field;
    private final RendererDesktop renderer;
    private final InputHandler input;

    public Game() {
        field = new Manager();
        renderer = new RendererDesktop(field);
        input = new InputHandler();

        MenuController menu = new MenuController(renderer, input);

        boolean endGame = false;

        while (!endGame) {

            // выбор сложности через главное меню
            int diffChoice = menu.controlMenu(MenuController.START_PROGRAM);
            // 1–4 — сложности, 5 (или что-то другое) — выход
            if (diffChoice < 1 || diffChoice > 4) {
                endGame = true;
                break;
            }

            int removedCells = mapDifficultyToRemoved(diffChoice);
            field.generateNewGame(removedCells);

            // время начала раунда
            Instant roundStart = Instant.now();

            // первая отрисовка поля
            renderer.drawElementaryField();

            boolean endRound = false;

            while (!endRound) {
                // «клик» по клетке
                int cellIdx = input.askCellIndex();
                if (cellIdx == -1) { // игрок хочет выйти/перезапустить
                    boolean restart = input.askRestartOrBackToMenu();
                    if (restart) {
                        // новая игра с новым выбором сложности
                        break; // выйти из раунда, вернуться во внешний while (!endGame)
                    } else {
                        endGame = true;
                        endRound = true;
                        continue;
                    }
                }

                // выбор числа
                int num = input.askNumber();
                if (num == 0) {
                    // пропустить ход
                    continue;
                }

                // попытка поставить число
                if (renderer.tryPlaceValueInCell(cellIdx, num)) {
                    // перерисовка после успешного хода
                    renderer.drawElementaryField();

                    // проверка: все клетки заполнены
                    if (field.gridCells.quantityValues[0] ==
                            Config.SIZE_SUDOKU * Config.SIZE_SUDOKU) {
                        endRound = true;
                    }

                } else {
                    // неверный ход
                    System.out.println("Нельзя поставить это число в эту клетку.");
                }
            }

            if (!endGame) {
                // показать статистику по раунду
                Instant roundEnd = Instant.now();
                long seconds = Duration.between(roundStart, roundEnd).getSeconds();
                System.out.println("Раунд завершён за " + seconds + " секунд.");
            }
        }
    }

    // Преобразование выбора сложности в кол-во убираемых клеток
    private int mapDifficultyToRemoved(int diffChoice) {
        switch (diffChoice) {
            case 1: return randomBetween(18, 27); // лёгкий
            case 2: return randomBetween(30, 40); // средний
            case 3: return randomBetween(41, 50); // сложный
            case 4: return randomBetween(51, 60); // невозможный
            default: return 30;
        }
    }

    private int randomBetween(int a, int b) {
        return a + (int) (Math.random() * (b - a + 1));
    }
}
