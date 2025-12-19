package Core;

public class CellTime implements Cloneable {
    public Cell cell;

    public CellTime(Cell cell) {
        this.cell = cell;
    }

    // Поверхностное клонирование: копируется только ссылка на cell
    @Override
    public CellTime clone() {
        try {
            return (CellTime) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new AssertionError(e);
        }
    }

    // Глубокое клонирование: создаём новый Cell
    public CellTime deepClone() {
        CellTime copy = this.clone();
        copy.cell = this.cell.clone();
        return copy;
    }
}
