#include <SFML/Graphics.hpp>
#include<SFML\Audio.hpp>
#include<ctime>
#include<iostream>


float getRandomNumber() {
    //srand(time(0));
    float anyRandom;
    float diff = 510.0f;
    anyRandom = float(rand() % int(diff));
    anyRandom = anyRandom + 140.0f;
    return anyRandom;
}

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(840, 650), "Racing Car");

    //BACKGROUND STUFFS

    sf::Texture backtexture;
    backtexture.loadFromFile("images/background.png");
    sf::Sprite background(backtexture);
    sf::Sprite background1(backtexture);

    //FLOAT VALUE FOR MOOVING BACKGROUND

    float backgroundy1 = 0.0f, backgroundy2 = -649.0f;


    //PLAYER CAR STUFFS

    sf::Texture playerCar;
    playerCar.loadFromFile("images/racer.png");
    sf::Sprite playerCarSprite(playerCar);
    playerCarSprite.setPosition(sf::Vector2f(840.0f / 2.0f - playerCarSprite.getGlobalBounds().width / 2, 648.0f - playerCarSprite.getGlobalBounds().height));

    float playerCarSpeed = 0.2f;

    //CAR STUFFS

    sf::Texture carText1;
    sf::Texture carText2;
    sf::Texture carText3;
    sf::Texture carText4;
    carText1.loadFromFile("images/car1.png");
    carText2.loadFromFile("images/car2.png");
    carText3.loadFromFile("images/car3.png");
    carText4.loadFromFile("images/car4.png");

    sf::Sprite car1(carText1);
    sf::Sprite car2(carText2);
    sf::Sprite car3(carText3);
    sf::Sprite car4(carText4);

    sf::Vector2f car1Pos(getRandomNumber(), -100.0f);
    sf::Vector2f car2Pos(getRandomNumber(), -200.0f);
    sf::Vector2f car3Pos(getRandomNumber(), -300.0f);
    sf::Vector2f car4Pos(getRandomNumber(), -400.0f);

    car1.setPosition(car1Pos);
    car2.setPosition(car2Pos);
    car3.setPosition(car3Pos);
    car4.setPosition(car4Pos);

    float carspeed = 0.2f;


    //GAME OVER STUFFS && BOOLEAN STUFFS

    bool gameover = false;
    bool gamefinish = false;


    //FONT & TEXT STUFFS

    sf::Font font;
    if (!font.loadFromFile("fonts/LinotypeCutter.ttf")) std::cout << "Error";

    sf::Text gameoverText("GAME OVER", font, 100);
    sf::Text continueText("Enter To Continue", font, 50);
    continueText.setFillColor(sf::Color::Red);
    gameoverText.setFillColor(sf::Color::Red);

    std::string stringTextScore;

    sf::Text pointText;

    //POINT STUFFS


    int point = 0;

    //AUDIO STUFFS

    sf::SoundBuffer soundbuffer;
    soundbuffer.loadFromFile("audio/game.wav");
    sf::Sound gameSound;
    gameSound.setBuffer(soundbuffer);

    gameSound.play();
    gameSound.setLoop(true);

    sf::SoundBuffer crashbuffer;
    crashbuffer.loadFromFile("audio/crash.wav");
    sf::Sound crash;
    crash.setBuffer(crashbuffer);


    //GAME STARTS

    while (!gamefinish) {



        while (window.isOpen() && !gameover)
        {

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::Resized) {
                    float ratio = 840.0f / 650.f;
                    window.setSize(sf::Vector2u(840 * int(ratio), 650 * int(ratio)));
                }
            }

            //DISPLAYING SCORE

            stringTextScore = "Your Score " + std::to_string(point);
            sf::Text scoreText(stringTextScore, font, 20);
            scoreText.setFillColor(sf::Color::Yellow);
            scoreText.setPosition(sf::Vector2f(140.0f, 5.0f));


            //UPDATING BACKGROUND

            if (backgroundy2 >= 0.0f) {

                backgroundy1 = 0.0f;
                backgroundy2 = -649.f;

            }
            backgroundy1 += 0.1f;
            backgroundy2 += 0.1f;

            background.setPosition(sf::Vector2f(0.0f, backgroundy1));
            background1.setPosition(sf::Vector2f(0.0f, backgroundy2));

            //UPDATING BACKGROUD FINISHED

            //PLAYER CAR UPDATING

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                playerCarSprite.move(sf::Vector2f(playerCarSpeed, 0.0f));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                playerCarSprite.move(sf::Vector2f(-playerCarSpeed, 0.0f));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                playerCarSprite.move(sf::Vector2f(0.0f, -playerCarSpeed));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                playerCarSprite.move(sf::Vector2f(0.0f, playerCarSpeed));
            }

            //COLLIDE WITH WALLS
            if (playerCarSprite.getPosition().x < 140.0f) {
                playerCarSprite.setPosition(sf::Vector2f(140.0f, playerCarSprite.getPosition().y));
            }

            if (playerCarSprite.getPosition().x > 650.0f) {
                playerCarSprite.setPosition(sf::Vector2f(650.0f, playerCarSprite.getPosition().y));
            }

            if (playerCarSprite.getPosition().y > 650.0f - playerCarSprite.getGlobalBounds().height) {
                playerCarSprite.setPosition(sf::Vector2f(playerCarSprite.getPosition().x, 650.0f - playerCarSprite.getGlobalBounds().height));
            }

            if (playerCarSprite.getPosition().y < 0.0f) {
                playerCarSprite.setPosition(sf::Vector2f(playerCarSprite.getPosition().x, 0.0f));
            }

            //PLAYER CAR UPDATE FINISHED


            //CAR STUFF POSITIONS

            if (car1.getPosition().y > 660) {
                car1.setPosition(getRandomNumber(), -100.0f);
                point = point + 1;
            }
            else {
                car1.setPosition(car1.getPosition().x, car1.getPosition().y + carspeed);
            }


            if (car2.getPosition().y > 660) {
                car2.setPosition(getRandomNumber(), -240.0f);
                point = point + 1;
            }
            else {
                car2.setPosition(car2.getPosition().x, car2.getPosition().y + carspeed);
            }


            if (car3.getPosition().y > 660) {
                car3.setPosition(getRandomNumber(), -340.0f);
                point = point + 1;
            }
            else {
                car3.setPosition(car3.getPosition().x, car3.getPosition().y + carspeed);
            }


            if (car4.getPosition().y > 660) {
                car4.setPosition(getRandomNumber(), -440.0f);
                point = point + 1;
            }
            else {
                car4.setPosition(car4.getPosition().x, car4.getPosition().y + carspeed);
            }

            //CAR STUFF POSITIONS FINISHED




            //CHECK SPEED

            if (point > 10) {
                carspeed = 0.25f;
                playerCarSpeed = 0.25f;
            }
            if (point > 20) {
                carspeed = 0.3f;
                playerCarSpeed = 0.3f;

            }
            if (point > 30) {
                carspeed = 0.35f;
                playerCarSpeed = 0.35f;

            }
            if (point > 40) {
                carspeed = 0.4f;
                playerCarSpeed = 0.4f;

            }
            if (point > 50) {
                carspeed = 0.5f;
                playerCarSpeed = 0.5f;
            }




            //CAR STUFFS COLLISION

            if (car1.getGlobalBounds().intersects(car2.getGlobalBounds()) ||
                car1.getGlobalBounds().intersects(car3.getGlobalBounds()) ||
                car1.getGlobalBounds().intersects(car4.getGlobalBounds())
                ) {
                car1.setPosition(getRandomNumber(), -100.0f);
            }

            if (car2.getGlobalBounds().intersects(car3.getGlobalBounds()) ||
                car2.getGlobalBounds().intersects(car4.getGlobalBounds()) ||
                car2.getGlobalBounds().intersects(car1.getGlobalBounds())
                ) {
                car2.setPosition(getRandomNumber(), -200.0f);
            }
            if (car3.getGlobalBounds().intersects(car1.getGlobalBounds()) ||
                car3.getGlobalBounds().intersects(car2.getGlobalBounds()) ||
                car3.getGlobalBounds().intersects(car4.getGlobalBounds())
                ) {
                car3.setPosition(getRandomNumber(), -300.0f);
            }




            //CARS & PLAYER CAR COLLISION

            if (car1.getGlobalBounds().intersects(playerCarSprite.getGlobalBounds())) {
                gameSound.stop();
                crash.play();
                gameover = true;
            }
            if (car2.getGlobalBounds().intersects(playerCarSprite.getGlobalBounds())) {
                gameSound.stop();
                crash.play();
                gameover = true;
            }
            if (car3.getGlobalBounds().intersects(playerCarSprite.getGlobalBounds())) {
                gameSound.stop();
                crash.play();
                gameover = true;
            }
            if (car4.getGlobalBounds().intersects(playerCarSprite.getGlobalBounds())) {
                gameSound.stop();
                crash.play();
                gameover = true;
            }



            window.clear();
            window.draw(background);
            window.draw(background1);

            window.draw(playerCarSprite);
            window.draw(car1);
            window.draw(car2);
            window.draw(car3);
            window.draw(car4);
            window.draw(scoreText);

            window.display();
        }


        while (window.isOpen() && gameover) {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }


            window.clear();


            //SETTING GAME OVER TEXT POSITON

            gameoverText.setPosition(sf::Vector2f(840.0f / 2.0f - gameoverText.getGlobalBounds().width / 2, 650.0f / 2.0f - gameoverText.getGlobalBounds().height / 2));
            continueText.setPosition(sf::Vector2f(840.0f / 2.0f - continueText.getGlobalBounds().width / 2, 650.0f / 2.0f - continueText.getGlobalBounds().height / 2 + gameoverText.getGlobalBounds().height + 10.0f));

            sf::Text scoreText(stringTextScore, font, 20);
            scoreText.setFillColor(sf::Color::Red);

            scoreText.setPosition(sf::Vector2f(840.0f / 2.0f - scoreText.getGlobalBounds().width / 2, 650.0f / 2.0f - scoreText.getGlobalBounds().height / 2 + gameoverText.getGlobalBounds().height + 80.0f));

            //CHECKING IF ENTER PRESSED

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                gameSound.play();
                gameSound.setLoop(true);
                point = 0;
                carspeed = 0.2f;
                playerCarSpeed = 0.2f;
                gameover = false;
            }

            //UPDATING CAR STUFFS TO INITIAL POSITION
            car1.setPosition(car1Pos);
            car2.setPosition(car2Pos);
            car3.setPosition(car3Pos);
            car4.setPosition(car4Pos);

            window.draw(gameoverText);
            window.draw(continueText);
            window.draw(scoreText);
            window.display();
        }
    }
    return 0;
}