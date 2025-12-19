package RendererAndHandlerFromDesktop;

// Создание интерфейса 
public interface Renderer {
    void clearConsole();
    void drawElementaryField();
    void drawMenu();
    void drawSettingsDifficulty();
    boolean tryPlaceValueInCell(int tableCoord, int num);
}
