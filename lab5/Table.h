#pragma once
#include "Cell.h"

class Table {
private:
	int width = 0;
	int height = 0;
	Cell **table;

public:
	Table();

	void load();
	void save();

	/**
	* @param[in] row - numer wiersza
	* @param[in] column - numer kolumny
	* @return - Cell lub NULL podczas niepowodzenia
	*/
	Cell* getCell(int row, int column);
	/**
	* @param[in] width - liczba kolumn
	* @param[in] height - liczba wierszy
	*/
	void resize(int width, int height);
	/**
	* @param[in] type - typ komórki,
	* który bêdzie zastosowany do wszystkich komórek w tabeli
	*/
	void setTabelType(CellType type);
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
	* @return - d³ugoœæ najd³u¿ej zawartoœci komórki
	*/
	int getLenOfTheLongestValue();
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
	Cell** getTable();
};
