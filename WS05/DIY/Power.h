/**********************************************************************
 * Name: Sujan Sharma
 * Email: ssharma627@myseneca.ca
 * StudentID: 157775222
 * Section: ZAA
 *
 * I have done all the coding by myself and only copied the code that
 * my professor provided to complete my workshop and assignments.
 ***********************************************************************/
#ifndef SENECA_POWER_H
#define SENECA_POWER_H

namespace seneca
{
	const int MAX_NAME_LENGTH = 50;

	class Power
	{
		char m_name[MAX_NAME_LENGTH + 1];
		int m_rarity;

	public:
		Power();
		Power(const char *name, int rarity);
		void setEmpty();
		void createPower(const char *name, int rarity);

		const char *checkName() const;
		int checkRarity() const;
		bool isEmpty() const;
	};
	void displayDetails(Power *powers, int size);
}
#endif