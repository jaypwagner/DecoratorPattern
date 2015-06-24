// DecoratorPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class IWorker
{

public:
	std::string name;
	int ssn;

	//pure virtual function
	virtual int doWork(int hours) = 0;

};

class Worker : public IWorker
{
	std::string name;
	int ssn;
public:
	Worker(std::string n, int social)
		: name{ n }, ssn{ social }
	{

	}

	int doWork(int hours)
	{
		int bucks = 0;

		while (hours > 0)
		{
			bucks += 1;
			std::cout << "doin work " << bucks << endl;
			hours--;
		}
		return bucks;
	}
};

class SkilledWorker : public IWorker
{
public:
	SkilledWorker(IWorker* inner)
		: name{ inner->name }, ssn{ inner->ssn }
	{
		m_wrappee = inner;
	}

	int doWork(int hours)
	{
		return m_wrappee->doWork(hours);
	}

private:
	IWorker* m_wrappee;
	std::string name;
	int ssn;
};

class LumberJack : public SkilledWorker
{
public:
	LumberJack(IWorker* core) : SkilledWorker(core){}

	int doWork(int hours)
	{
		int bucks = SkilledWorker::doWork(hours);;

		while (hours > 0)
		{
			bucks += 5;
			std::cout << "cuttin trees ... earned " << bucks << endl;
			hours--;
		}
		return bucks;
	}
};

class Nurse : public SkilledWorker
{
public:
	Nurse(IWorker* core) : SkilledWorker(core){}

	int doWork(int hours)
	{

		int bucks = SkilledWorker::doWork(hours);

		while (hours > 0)
		{

			bucks += 10;
			std::cout << "sponge bathing ... earned " << bucks << endl;
			hours--;
		}
		return bucks;
	}
};

class Cop : public SkilledWorker
{
public:
	Cop(IWorker* core) : SkilledWorker(core){}

	int doWork(int hours)
	{
		int bucks = SkilledWorker::doWork(hours);

		while (hours > 0)
		{
			bucks += 15;
			std::cout << "giving speeding tickets ... earned " << bucks << endl;
			hours--;
		}
		return bucks;
	}

};

// This is where my main function is 
int _tmain(int argc, _TCHAR* argv[]) // <--- This is where my main function is 
{ // ^ right here

	// Highly skilled Nurse Cop Nurse
	IWorker* nurseCopNurse = new Nurse(new Cop(new Nurse(new Worker("Nancy", 555))));

	IWorker* CopCopLumberJack = new Cop(new Cop(new LumberJack(new Worker("Pete", 888))));

	IWorker* NurseCopNurseCopCopLumberJackNurseCopNurseCopCopLumberJack = new Nurse(new Cop(new Nurse(new Cop(new Cop(new LumberJack(
		new Nurse(new Cop(new Nurse(new Cop(new Cop(new LumberJack(new Worker("Pete", 888)))))))))))));

	NurseCopNurseCopCopLumberJackNurseCopNurseCopCopLumberJack->doWork(5);
	SkilledWorker *skilledGuy = new Nurse(new Worker("Pete", 555));

	getchar();

	return 0;
}
