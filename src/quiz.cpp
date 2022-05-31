#include "quiz.h"
#include <vector>

Quiz::Quiz()
{
  title = "Dummy quiz";
  questions.push_back(Question("Question 1", { "wrong", "wrong", "wrong" }, "correct"));
  questions.push_back(Question("Question 2", { "wrong", "wrong", "wrong" }, "correct"));
  questions.push_back(Question("Question 3", { "wrong", "wrong", "wrong" }, "correct"));
  questions.push_back(Question("Question 4", { "wrong", "wrong", "wrong" }, "correct"));
  questions.push_back(Question("Question 5", { "wrong", "wrong", "wrong" }, "correct"));
}

void Quiz::loadFromFile(std::string filename)
{

}
      
Question Quiz::getQuestion(std::size_t id)
{
  return questions.at(id);
}
