#ifndef BITBOARD_H__
#define BITBOARD_H__

#include <bitset>
#include <vector>

template<size_t nRows, size_t nCols>
class BitBoard
{
public:
	BitBoard()
	{
		m_nRows = nRows;
		m_nCols = nCols;

		for (int i = 0; i < m_nRows; i++)
		{
			m_bits.push_back(new std::bitset<nCols>());
		}
	}

	virtual ~BitBoard()
	{
		for (int i = 0; i < m_nRows; i++)
		{
			delete m_bits[i];
			m_bits[i] = nullptr;
		}
		m_bits.clear();
	}

public:
	virtual BitBoard* and(const BitBoard& rhs) const
	{
		if (!match(rhs)) return nullptr;

		for (size_t i = 0; i < getRowCount(); i++)
		{
			auto row = getRow();
		}
	}

	virtual BitBoard* or(const BitBoard& rhs) const;
	virtual BitBoard* xor(const BitBoard& rhs) const;
	virtual BitBoard* not(const BitBoard& rhs) const;

	//rotate
	virtual BitBoard* rotate90() const;
	virtual BitBoard* rotate45() const;

	//reverse
	virtual BitBoard* reverse() const;

	//misc..
	virtual const std::bitset<nCols>& getRow(size_t iRow) const;
	virtual const std::bitset<nCols>& getCol(size_t iCol) const;
	
	virtual size_t getRowCount() const
	{

	}

	virtual size_t getColCount() const
	{

	}

	//the summed celled of cells.
	virtual int celled() const;

private:
	bool match(const BitBoard& rhs) const
	{
		return (this->getRowCount() == rhs.getRowCount()) && (this->getColCount() == rhs.getColCount());
	}

private:
	std::vector<std::bitset<nCols>*> m_bits;

	size_t m_nRows;
	size_t m_nCols;
};

#endif // BITBOARD_H__

