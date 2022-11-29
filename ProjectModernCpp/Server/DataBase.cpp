#include "DataBase.h"

void DataBase::initializeAccount(Account a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::initializeQuestionInt(QuestionInt a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::initializeQuestionBool(QuestionBool a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::AddQuestions()
{
	
}
