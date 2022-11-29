#include <iostream>
#include <string.h>
#include <unordered_map>
class QuestionBool
{
public:
	QuestionBool();
	QuestionBool(int id,std::string question, std::unordered_map<std::string, bool> answer);
	~QuestionBool();
	
	void SetID(int id);
	int GetID()const;
	
	void SetQuestion(std::string question);
	std::string GetQuestion()const;

	void SetAnswer(std::unordered_map<std::string, bool> answer);
	std::unordered_map<std::string, bool> GetAnswer()const;
	
private:
	int m_id;
	std::string m_question;
	std::unordered_map<std::string,bool> m_answer;
};


