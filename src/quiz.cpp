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
  
  /*auto questionList{ quizData["questions"] };
  for(auto& question : questionList)
  {
    questions.push_back(question["question"], question["dummyAnswers"], question["correctAnswer"]);
  }*/

  std::size_t questionCount{ quizData["questions"].size() };
 
  for(std::size_t iii{ 0 }; iii < questionCount; ++iii)
  {
    questions.push_back(Question(quizData["questions"][iii]["question"],
                                 quizData["questions"][iii]["dummyAnswers"], 
                                 quizData["questions"][iii]["correctAnswer"]));
    
  }  

  std::cout << title << "\n";
  std::cout << questionCount << " questions\n\n";
  int i{ 0 };
  for(auto& question : questions)
  {
    ++i;
    std::cout << i << ". " << question.getQuestion() << "\n";
    std::cout << question.getDummyAnswer(0) << "\t" << question.getDummyAnswer(1) << "\n";
    std::cout << question.getDummyAnswer(2) << "\t" << question.getCorrectAnswer() << "[CORRECT]\n\n";
     
  }
}
      
Question Quiz::getQuestion(std::size_t id)
{
  return questions.at(id);
}
