#include "DataBase.h"

int main() {
	{
		DataBase db;
		db.AddQuestionsBool();
		db.AddQuestionsInt();
		return 0;
	}
}
