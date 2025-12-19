package Core;
// public class Cell {
// 	public int value;
// 	public boolean is_fixed;

//     public Cell() {
//         value = 0;
//         is_fixed = true;
//     }
// }

// ВРЕМЕННО. Делаю класс ячейки клонируемым
//------------------
public class Cell implements Cloneable {
	public int value;
	public boolean is_fixed;

    public Cell() {
        value = 0;
        is_fixed = true;
    }

    @Override
    public Cell clone() {
        try {
            return (Cell) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new AssertionError(e);
        }
    }
}
//------------------
