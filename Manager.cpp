#include "Manager.hpp"

void Manager::generateMassiveNums() {
	
	for (int z = 1; z < 8; z++) {
		for (int i = 0; i < SIZE_SUDOKU - 2; i++) {
			int ind_str = rand.random(0, 8);
			if (massive_sudoku[i][ind_str] == 0) {
				massive_sudoku[i][ind_str] = z;
				for (int k = i + 1; k < SIZE_SUDOKU; k++) {
					if (massive_sudoku[k][ind_str] == 0) {
						massive_sudoku[k][ind_str] = -1;
					}
				}
			}
			else {
				i--;
			}

			for (int d = 0; d < 9; d++) {
				for (int j = 0; j < 9; j++) {
					std::cout << std::setw(2) << std::setfill('0') << massive_sudoku[d][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		for (int i = SIZE_SUDOKU - 2; i < SIZE_SUDOKU; i++) {
			for (int j = 0; j < SIZE_SUDOKU; j++) {
				if (massive_sudoku[i][j] == 0) {
					massive_sudoku[i][j] = z;
				}
				for (int k = i + 1; k < SIZE_SUDOKU; k++) {
					massive_sudoku[k][j] = -1;
				}
			}	
		}

		for (int i = 1; i < SIZE_SUDOKU; i++) {
			for (int j = 0; j < SIZE_SUDOKU; j++) {
				if (massive_sudoku[i][j] == -1) {
					massive_sudoku[i][j] = 0;
				}
			}
		}

	}



}