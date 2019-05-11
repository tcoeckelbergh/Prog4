#pragma once
#include <iostream>

class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute() = 0;
};

class FireCommand : public Command
{
public:
	void Execute() override
	{
		std::cout << "FIRE!\n";
	}
};

class DuckCommand : public Command
{
public:
	void Execute() override
	{
		std::cout << "DUCK!\n";
	}
};

class JumpCommand : public Command
{
public:
	void Execute() override
	{
		std::cout << "JUMP!\n";
	}
};

class FartCommand : public Command
{
public:
	void Execute() override
	{
		std::cout << "FART!\n";
	}
};