#include "Account.h"

void initAccounts(Accounts& db)
{
	db.sync_schema();
}

void ReadAccounts(Accounts& db)
{
}

void addAccount(Accounts& db, const Account& account)
{
	db.insert(account);
}

