#include "Questions.h"


void populateStorage(Storage& storage)
{
	std::vector<QuestionsWithInteger>questions_integer = {
		QuestionsWithInteger{1,"În ce an s-a născut Regele Mihai I?",1921},
		QuestionsWithInteger{1,"În ce an a reușit Mihai Viteazul unirea celor trei mari țări medievale??",1600},
		QuestionsWithInteger{1,"Când a inceput Primul Război Mondial?",1914},
		QuestionsWithInteger{1,"În ce an a intrat România în Uniunea Europeana? ",2007},
		QuestionsWithInteger{1,"În ce an a murit Prințesa Diana?",1997},
		QuestionsWithInteger{1,"În ce an s-a proclamat independența de stat a României? ",1877},
		QuestionsWithInteger{1,"În ce an s-a născut Regele Carol I?",1839},

	};
	storage.insert_range(questions_integer.begin(), questions_integer.end());
}
