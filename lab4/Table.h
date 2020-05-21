#pragma once

class Table {
private:
	int width = 0;
	int height = 0;
	int **table;

public:
	Table();

	void load();
	void save();

	/**
	* @param[in] row - numer wiersza
	* @param[in] column - numer kolumny
	* @param[in] value - wartoœæ
	*/
	void setCellValue(int row, int column, int value);
	/**
	* @param[in] row - numer wiersza
	* @param[in] column - numer kolumny
	* @return - wartoœæ lub NULL jesli podczas niepowodzenia
	*/
	int getCellValue(int row, int column);
	/**
	* @param[in] width - liczba kolumn
	* @param[in] height - liczba wierszy
	*/
	void resize(int width, int height);
	/**
	* @param[in] column - nr kolumny
	* @return - suma wartosci w danej kolumnie
	*/
	int sumByColumn(int column);
	/**
	* @param[in] row - nr wiersza
	* @return - suma wartosci w danym wieszu
	*/
	int sumByRow(int row);
	/**
	* @return - najwiesza liczbe lub NULL jesli nie ma zadnej wartosci
	*/
	int getTheBiggestValue();
	/**
	* @return - najmniejsza liczbe lub NULL jesli nie ma zadnej wartosci
	*/
	int getTheSmallestValue();
	/**
	* @return - srednia wszystkich liczb
	*/
	float getAvgValue();

	/**
	* @return - ilosc kolumn
	*/
	int getWidth();
	/**
	* @return - ilosc wierszy
	*/
	int getHeight();
	/**
	* @return - tablice liczb
	*/
	int** getTable();
};
