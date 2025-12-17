#pragma once 

#include "RandomLCG.hpp"
#include "Config.hpp"
#include "Field.hpp"

class Manager
{
private:
	RandomLCG rand;

	bool checkerCombinationsFromRow(int coord_y, int value);

	bool checkerCombinationsFromColumn(int coord_x, int value);

	bool checkerCombinationsFromBox(CoordinateTableSudoku coord, int value);

	// Функция проверки комбинации
	// Проверка можно ли поставить указанное значение по указанным координатам
	bool checkerCombinations(int indexCoordinateTableSudoku, int value);

	// Функция поиска пустой клетки в таблице
	bool findEmpty(int& indexCoordinateTableSudoku);

	// Заполняет таблицу судоку различными значениями. Генерация рандомных комбинаций игры
	bool fillGrid();

	// Удаление ячеек для генерации самой игры
	void unFixedCell(int quantityRemoves);

	// инициализируем счетчик, помещаем в него нашу вариацию игры
	void fillCounterFixedCells();

public:
	// Хранилище игрового поля
	Field gridCells;

	int pastValueCell = -1; // прошлое значение 
	int pastValueTableNumbers = -1;// прошлое значение таблицы с возможными значениями для судоку

	// Генерация игрового поля
	void generateNewGame(int quantityRemoves);

	// Пока разборка куда это поместить, будет временно здесь
	bool checkInputValueInCell(int coordinateCell, int inputValue);

	// счетчик фиксированных значений
	void counterFixedCells(int value);

	// Функция проверки соответствия чисел на поле. Подходит ли введенное с скрытым
	bool checkerMatchingNums(int inputValue, int indexTableValue);

	// Функция сравнение чисел и возврат булевого значения равны они или нет
	bool compareNums(int num1, int num2);
};