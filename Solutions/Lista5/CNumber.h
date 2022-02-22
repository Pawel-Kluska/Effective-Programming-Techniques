#pragma once

class CNumber
{
private:
	double* pd_value;
	void v_move(CNumber& pcOther);
	void v_copy(const CNumber& pcOther);

public:
	CNumber();
	CNumber(double* pd_val);
	CNumber(const CNumber& pcOther);
	CNumber(CNumber&& pcOther) noexcept;
	~CNumber();

	void ToString();
	void operator=(CNumber&& cOther) noexcept;
	void operator=(const CNumber& pcOther);
	CNumber operator+(CNumber& pcOther);
	CNumber operator-(CNumber& pcOther);

	
};
