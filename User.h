#pragma once

using namespace System;


ref class User
{
public:
	User(String^ newName, String^ newSurname, int newAge, int newCredit);
	
	String^ name;
	String^ surname;
	int age;
	int credit;
};

