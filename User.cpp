#include "User.h"

User::User() {

}
User::User(String^ newName, String^ newSurname, int newCredit) {
	name = newName;
	surname = newSurname;
	credit = newCredit;
}