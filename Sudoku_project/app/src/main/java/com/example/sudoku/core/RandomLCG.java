package com.example.sudoku.core;

public class RandomLCG {
    private int state;

    private static final int A = 1664525;     // золотой стандарт для простых 32битных LCG
    private static final int C = 1013904223;  // золотой стандарт для простых 32битных LCG

	// Внутренняя реализация в самом классе, которая устанавливает Seed
	private void installingSeed() {
        state = (int) System.currentTimeMillis();
        state = (state < 0) ? state*(-1) : state;
        
    }

	// Устанавливает Seed для какого-то действия
	// Seed - начальное состояние генератора, с которого запускается формула
	// Временной промежуток, который используется для реализации функции рандома с использованием алгоритма LCG
	// Каждый Seed имеет только одну последовательность чисел
	public RandomLCG() {
        installingSeed();
    }

    // Функция поиска рандомного числа из заданного промежутка (не рассчитан на отрицательные числа)
	// Выбирает случайное натуральное число в заданном диапазоне от min (включительно) до max (включительно)
	public int random(int min, int max) {

        state = (A * state + C);
        state = (state < 0) ? state*(-1) : state;

        return min + (state % (max - min + 1));
    }

    // Функция рандомно перемешивает заданный масив заданной длины
	public void randomReverseMassive(int[] massiveNums, int lenMassive) {
        int bufferNum, bufferIndex;
        for (int i = 0; i < lenMassive; i++) {
            bufferNum = massiveNums[i];
            bufferIndex = random(0, lenMassive-1);
            massiveNums[i] = massiveNums[bufferIndex];
            massiveNums[bufferIndex] = bufferNum;
	    }
    }

    // Генерирует массив чисел в указанном диапазоне включительно
	public int[] randomGenerateReverseMassive(int start, int end) {
        int lenMassive = end - start + 1; // вычисляю длину массива

        int[] massiveNums = new int[lenMassive];

        for (int i = 0; i < lenMassive; i++) {
            massiveNums[i] = start++;
        }

        randomReverseMassive(massiveNums, lenMassive);

        return massiveNums;
    }
}
