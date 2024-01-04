#pragma once

using namespace System;


ref class User
{
public:
	User();
	User(String^ newName, String^ newSurname, int newCredit);
	
	static String^ name;
	static String^ surname;
	static int age;
	static int credit;
};

