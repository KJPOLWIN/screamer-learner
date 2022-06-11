#include "quiz.h"
#include "json.hpp"
#include <vector>
#include <fstream>
#include <iostream>

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
  questions.clear();

  std::fstream file{ filename };
  nlohmann::json quizData{  };
  file >> quizData;

  title = quizData["title"];
  
  std::size_t questionCount{ quizData["questions"].size() };
 
  for(std::size_t iii{ 0 }; iii < questionCount; ++iii)
  {
    questions.push_back(Question(quizData["questions"][iii]["question"],
                                 quizData["questions"][iii]["dummyAnswers"], 
                                 quizData["questions"][iii]["correctAnswer"]));
    
  }  
}
      
Question Quiz::getQuestion(std::size_t id)
{
  return questions.at(id);
}
      
std::size_t Quiz::getQuestionCount()
{
  return questions.size();
}
