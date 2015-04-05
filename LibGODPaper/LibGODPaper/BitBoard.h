#ifndef BITBOARD_H__
#define BITBOARD_H__

#include <bitset>
#include <vector>

template<size_t nRows, size_t nCols>
class BitBoard
{
	typedef BitBoard<nRows, nCols> BoardType;
	typedef std::bitset<nCols> RowType;
	typedef std::bitset<nRows> ColumnType;

public:
	BitBoard(bool empty = false)
	{
		m_nRows = nRows;
		m_nCols = nCols;

		if (!empty)
		{
			for (size_t i = 0; i < m_nRows; i++)
			{
				m_bits.push_back(new RowType());
			}
		}
	}

	BitBoard(const BitBoard& rhs)
	{
		m_nRows = nRows;
		m_nCols = nCols;

		for (size_t i = 0; i < m_nRows; i++)
		{
			m_bits.push_back(new RowType(rhs[i]));
		}
	}

	virtual ~BitBoard()
	{
		for (size_t i = 0; i < m_nRows; i++)
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

		BoardType* pBoard = createEmptyBoard();
		auto data = pBoard->getData();

		for (size_t i = 0; i < getRowCount(); i++)
		{
			auto row = getRow(i);
			auto rowRhs = rhs.getRow(i);

			data.push_back(new RowType(row &= rowRhs));
		}

		return pBoard;
	}

	//Should refactor to eliminate the duplicated code
	virtual BitBoard* or(const BitBoard& rhs) const
	{
		if (!match(rhs)) return nullptr;

		BitBoard<nRows, nCols>* pBoard = createEmptyBoard();
		auto data = pBoard->getData();

		for (size_t i = 0; i < getRowCount(); i++)
		{
			auto row = getRow(i);
			auto rowRhs = rhs.getRow(i);

			data.push_back(new RowType(row |= rowRhs));
		}

		return pBoard;
	}

	virtual BitBoard* xor(const BitBoard& rhs) const
	{
		if (!match(rhs)) return nullptr;

		BoardType* pBoard = createEmptyBoard();
		auto data = pBoard->getData();

		for (size_t i = 0; i < getRowCount(); i++)
		{
			auto row = getRow(i);
			auto rowRhs = rhs.getRow(i);

			data.push_back(new RowType(row ^= rowRhs));
		}

		return pBoard;
	}

	virtual BitBoard* not(const BitBoard& rhs) const
	{
		BoardType* pBoard = createEmptyBoard();
		auto data = pBoard->getData();

		for (size_t i = 0; i < getRowCount(); i++)
		{
			data.push_back(new RowType(data[i]->flip()));
		}

		return pBoard;
	}

	//rotate CCW
	virtual BitBoard* rotate90() const
	{
		return nullptr;
	}

	//TODO: why need this?
	virtual BitBoard* rotate45() const
	{
		return nullptr;
	}

	//reserve
	virtual BitBoard* reserve() const
	{
		return nullptr;
	}

	//misc..
	virtual const RowType& getRow(size_t iRow) const
	{
		return *m_bits[iRow];
	}

	virtual ColumnType getCol(size_t iCol) const
	{
		ColumnType column;

		for (size_t i = 0; i < column.size(); i++)
		{
			auto row = getRow(i);
			row[iCol] ? column.set(i) : column.reset(i);
		}

		return column;
	}
	
	virtual size_t getRowCount() const
	{
		return m_nRows;
	}

	virtual size_t getColCount() const
	{
		return m_nCols;
	}

private:
	std::vector<RowType*>& getData()
	{
		return m_bits;
	}

	const std::vector<RowType*>& getData() const
	{
		return m_bits;
	}

	bool match(const BitBoard& rhs) const
	{
		return (this->getRowCount() == rhs.getRowCount()) && (this->getColCount() == rhs.getColCount());
	}

	BoardType* createEmptyBoard() const
	{
		return new BitBoard<nRows, nCols>(true);
	}

private:
	std::vector<RowType*> m_bits;

	size_t m_nRows;
	size_t m_nCols;
};

#endif // BITBOARD_H__

