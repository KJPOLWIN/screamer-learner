#ifndef STYLE_H
#define STYLE_H

  #include <SFML/Graphics.hpp>

  namespace Style
  {
    const sf::Color textColor             { 252, 232, 106 };
    const sf::Color correctAnswerColor    { 77,  252, 58  };
    const sf::Color wrongAnswerColor      { 252, 55,  55  };

    const sf::Color backgroundColor        { 2,   8,   20  };
    const sf::Color activeBackgroundColor  { 5,   17,  40  };
    const sf::Color correctBackgroundColor { 9,   73,  7   };
    const sf::Color wrongBackgroundColor   { 48,  5,   5   };
  }

#endif
