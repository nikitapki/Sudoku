package RendererAndHandlerFromDesktop;

public class MenuController {

    public static final int START_PROGRAM = 0;
    public static final int RETURN_FROM_STARTED_GAME = 1;

    private final RendererDesktop renderer;
    private final InputHandler input;

    public MenuController(RendererDesktop renderer, InputHandler input) {
        this.renderer = renderer;
        this.input = input;
    }

    // Меню при запуске программы
    public int menuForStartGame() {
        int result = -1;
        boolean exitLoop = false;

        do {
            renderer.drawMenu();
            int cmd = input.readIntInRange("Выберите пункт меню (1-2):", 1, 2);

            if (cmd == 1) {                 // Играть
                renderer.drawSettingsDifficulty();
                result = input.readIntInRange("Выберите сложность (1-5):", 1, 5);
                if (result == 5) {          // Вернуться
                    continue;
                }
                exitLoop = true;            // выбрана сложность 1–4
            } else {                        // Выход
                renderer.clearConsole();    // можно сделать публичным или обёртку
                System.exit(0);
            }
        } while (!exitLoop);

        return result; // номер сложности
    }

    // Меню, когда выходишь из игры
    public int menuForReturnFromGame() {
        renderer.drawSettingsDifficulty();
        int result = input.readIntInRange("Выберите сложность (1-5):", 1, 5);

        if (result == 5) {       // Вернуться
            result = menuForStartGame();
        }

        return result;
    }

    public int controlMenu(int mode) {
        if (mode == START_PROGRAM) {
            return menuForStartGame();
        } else if (mode == RETURN_FROM_STARTED_GAME) {
            return menuForReturnFromGame();
        }
        return -1;
    }
}
