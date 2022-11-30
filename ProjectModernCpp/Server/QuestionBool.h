#include <iostream>
#include <string.h>
#include <unordered_map>
class QuestionBool
{
public:
	QuestionBool();
	QuestionBool(int id, std::string question, std::string rightanswer, std::string wronganswer1, std::string wronganswer2, std::string wronganswer3);
	~QuestionBool();
	
	void SetID(int id);
	int GetID()const;
	
	void SetQuestion(std::string question);
	std::string GetQuestion()const;

	void SetRightAnswer(std::string right_answer);
	std::string RightGetAnswer()const;
	
	void SetWrongAnswer1(std::string wrong_answer1);
	std::string WrongGetAnswer1()const;
	
	void SetWrongAnswer2(std::string wrong_answer2);
	std::string WrongGetAnswer2()const;
	
	void SetWrongAnswer3(std::string wrong_answer3);
	std::string WrongGetAnswer3()const;
	
private:
	int m_id;
	std::string m_question;
	std::string m_rightanswer;
	std::string m_wronganswer1;
	std::string m_wronganswer2;
	std::string m_wronganswer3;
};


