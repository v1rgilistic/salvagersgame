#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "includes.h"
#include "player.h"
#include <fstream>
#include "enemy.h"
#include "items.h"
#include <random>
#include <chrono>
using namespace sf;
using namespace std;

int main() {
    sf::Texture backText;
    backText.loadFromFile("");
    std::vector<Texture> playerTextures(18);
    playerTextures[0].loadFromFile("0frame.png");
    playerTextures[1].loadFromFile("1frame.png");
    playerTextures[2].loadFromFile("2frame.png");
    playerTextures[3].loadFromFile("3frame.png");
    playerTextures[4].loadFromFile("4frame.png");
    playerTextures[5].loadFromFile("5frame.png");
    playerTextures[6].loadFromFile("6frame.png");
    playerTextures[7].loadFromFile("7frame.png");
    playerTextures[8].loadFromFile("8frame.png");
    for (int i = 0; i < 9; ++i) {
        std::string filename = std::to_string(i) + "frame.png";
        if (!playerTextures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }
    playerTextures[9].loadFromFile("left0.png");
    playerTextures[10].loadFromFile("left1.png");
    playerTextures[11].loadFromFile("left2.png");
    playerTextures[12].loadFromFile("left3.png");
    playerTextures[13].loadFromFile("left4.png");
    playerTextures[14].loadFromFile("left5.png");
    playerTextures[15].loadFromFile("left6.png");
    playerTextures[16].loadFromFile("left7.png");
    playerTextures[17].loadFromFile("left8.png");
    for (int i = 9; i < 18; ++i) {
        std::string filename = "left" + std::to_string(i - 9) + ".png";
        if (!playerTextures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }
    std::vector<Texture> enemy1Textures(8);
    enemy1Textures[0].loadFromFile("trashmonsterF1.png");
    enemy1Textures[1].loadFromFile("trashmonsterF2.png");
    enemy1Textures[2].loadFromFile("trashmonsterF3.png");
    enemy1Textures[3].loadFromFile("trashmonsterF4.png");
    enemy1Textures[4].loadFromFile("trashmonsterF5.png");
    enemy1Textures[5].loadFromFile("trashmonsterF6.png");
    enemy1Textures[6].loadFromFile("trashmonsterF7.png");
    enemy1Textures[7].loadFromFile("trashmonsterF8.png");
    for (int i = 0; i < 8; ++i) {
        std::string filename = std::to_string(i) + ".png";
        if (!enemy1Textures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }

    std::vector<Texture> enemy2Textures(8);
    enemy2Textures[0].loadFromFile("barrelF1.png");
    enemy2Textures[1].loadFromFile("barrelF2.png");
    enemy2Textures[2].loadFromFile("barrelF3.png");
    enemy2Textures[3].loadFromFile("barrelF4.png");
    enemy2Textures[4].loadFromFile("barrelF5.png");
    enemy2Textures[5].loadFromFile("barrelF6.png");
    enemy2Textures[6].loadFromFile("barrelF7.png");
    enemy2Textures[7].loadFromFile("barrelF8.png");
    for (int i = 0; i < 8; ++i) {
        std::string filename = std::to_string(i) + ".png";
        if (!enemy2Textures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }

    std::vector<Texture> enemy3Textures(8);
    enemy3Textures[0].loadFromFile("oilF1.png");
    enemy3Textures[1].loadFromFile("oilF2.png");
    enemy3Textures[2].loadFromFile("oilF3.png");
    enemy3Textures[3].loadFromFile("oilF4.png");
    enemy3Textures[4].loadFromFile("oilF5.png");
    enemy3Textures[5].loadFromFile("oilF6.png");
    enemy3Textures[6].loadFromFile("oilF7.png");
    enemy3Textures[7].loadFromFile("oilF8.png");
    for (int i = 0; i < 8; ++i) {
        std::string filename = std::to_string(i) + ".png";
        if (!enemy3Textures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }

    std::vector<Texture> enemy4Textures(8);
    enemy4Textures[0].loadFromFile("bottleF1.png");
    enemy4Textures[1].loadFromFile("bottleF2.png");
    enemy4Textures[2].loadFromFile("bottleF3.png");
    enemy4Textures[3].loadFromFile("bottleF4.png");
    enemy4Textures[4].loadFromFile("bottleF5.png");
    enemy4Textures[5].loadFromFile("bottleF6.png");
    enemy4Textures[6].loadFromFile("bottleF7.png");
    enemy4Textures[7].loadFromFile("bottleF8.png");
    for (int i = 0; i < 8; ++i) {
        std::string filename = std::to_string(i) + ".png";
        if (!enemy4Textures[i].loadFromFile(filename)) {
            cout << "Error loading texture " << i << " from file: " << filename << endl;
            return -1;
        }
    }

    Sprite enemysprite1;
    Sprite enemysprite2;
    Sprite enemysprite3;
    Sprite enemysprite4;

    Sprite playersprite;
    playersprite.setOrigin(64, 64); // Adjust origin for smaller sprite
    playersprite.setPosition(300, 390);
    playersprite.setTexture(playerTextures[0]);
    playersprite.setScale(0.5f, 0.5f); // Scale down by 50%

    RenderWindow window(VideoMode(1920, 1080), "Salvagers");

    View camera(Vector2f(810, 540), Vector2f(1920, 1080));

    Font font;
    if (!font.loadFromFile("PixelifySans-Regular.ttf")) {
        cout << "Error loading font" << endl;
        return -1;
    }


    Text inputText("", font, 30);
    inputText.setFillColor(Color::White);
    inputText.setPosition(100, 100);

    Text dialogueText("", font, 30);
    dialogueText.setFillColor(Color::White);
    dialogueText.setPosition(100, 200); // Position for dialogue below input text

    RectangleShape dialogueBox(Vector2f(1600, 100)); // Adjust height if needed
    dialogueBox.setFillColor(Color(0, 0, 0, 150)); // Semi-transparent black
    dialogueBox.setPosition(100, 200); // Position for dialogue box below input text

    string playername;

    bool enteringName = true;
    bool nameEntered = false;
    bool dialogueMode = false;
    vector<string> dialogues = { "Your task is to save the world." };
    size_t currentDialogue = 0;
    float inputFadeDuration = 2.0f; // Duration to fade out input text
    float fadeTimer = 0.0f;

    fstream firstsave;

    bool moveup = false;
    bool movedown = false;
    bool moveright = false;
    bool moveleft = false;
    bool canMove = false; // Flag to control player movement
    bool canAnimate = false; // Flag to control sprite animation
    random_device r;
    Weapon broom("MELEE", r() % 30 + 1);
    Weapon mop("MELEE", r() % 40 + 8);
    Weapon trashclaw("MELEE", r() % 50 + 10);
    Weapon vacuum("RANGED", r() % 60 + 10);
    Weapon cleaningspray("RANGED", r() % 70 + 20);
    Weapon powerwasher("RANGED", r() % 100 + 50);
    enemy trashmonster("Trash Monster", 200, 2, &vacuum, 1, 2, enemysprite1, enemy1Textures);
    enemy hazardouswaste("Hazardous Waste", 700, 7, &trashclaw, 10, 3, enemysprite2, enemy2Textures);
    enemy oilspill("Oil Spill", 1000, 10, &cleaningspray, 30, 2, enemysprite3, enemy3Textures);
    enemy microplastics("Microplastics", 500, 5, &broom, 20, 1, enemysprite4, enemy4Textures);
    InventoryExtendingItem trashbag("Trash Bag", 3);
    HpRestoreItem soap("Soap", 10);
    HpRestoreItem sanitizer("Hand Sanitizer", 20);
    HpRestoreItem bleach("Bleach", 40);
    ImmunityItem gasmask("Gas Mask", 20, 2);
    player PLAYER(playername, 1000, 10, &broom, 1, 1, playersprite, playerTextures);
    Clock walkingtimer;
    Clock inputFadeTimer;
    float thetimeiswalking = 0;

    while (window.isOpen()) {
        thetimeiswalking = walkingtimer.getElapsedTime().asSeconds();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (enteringName) {
                if (event.type == Event::TextEntered) {
                    if (event.text.unicode == '\b') {
                        if (!playername.empty())
                            playername.pop_back();
                    }
                    else if (event.text.unicode == '\r') {
                        enteringName = false;
                        nameEntered = true;
                        firstsave.open("firstsavefile", ios::in | ios::out | ios::trunc);
                        firstsave << playername;
                        firstsave.close();
                        cout << "DATA HAS BEEN SAVED" << endl;
                        dialogueMode = true; // Activate dialogue mode
                        dialogueText.setString(dialogues[0]);
                        fadeTimer = 0.0f; // Reset fade timer for input text
                        inputFadeTimer.restart(); // Start fade timer
                    }
                    else if (event.text.unicode < 128) {
                        playername += static_cast<char>(event.text.unicode);
                    }
                    inputText.setString("WHAT IS YOUR NAME?\n" + playername);
                }
            }
            else {
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::A)
                        moveleft = true;
                    if (event.key.code == Keyboard::D)
                        moveright = true;
                }
                if (event.type == Event::KeyReleased) {
                    if (event.key.code == Keyboard::A) {
                        moveleft = false;
                        playersprite.setTexture(playerTextures[9]); // Set to left0.png
                    }
                    if (event.key.code == Keyboard::D)
                        moveright = false;
                    playersprite.setTexture(playerTextures[0]);
                }
            }
        }

        // Allow movement and animation only after input text has completely faded
        if (!enteringName && inputFadeTimer.getElapsedTime().asSeconds() >= inputFadeDuration) {
            canMove = true;
            canAnimate = true;
        }

        if (canMove) {
            if (moveleft) {
                PLAYER.walkleftanimate();
            }
            if (moveright) {
                PLAYER.walkrightanimate();
            }
            if (!moveleft && !moveright) {
                PLAYER.idleanimate();
            }
        }

        if (canAnimate && thetimeiswalking >= 0.1f) {
            walkingtimer.restart();
        }

        // Update input text fade effect
        if (!enteringName && inputFadeTimer.getElapsedTime().asSeconds() < inputFadeDuration) {
            float elapsed = inputFadeTimer.getElapsedTime().asSeconds();
            int alpha = 255 - static_cast<int>((elapsed / inputFadeDuration) * 255);
            inputText.setFillColor(Color(255, 255, 255, alpha));
        }
        else if (!enteringName && inputFadeTimer.getElapsedTime().asSeconds() >= inputFadeDuration) {
            inputText.setString(""); // Hide text after fading out
        }

        window.setView(camera);
        window.clear();
        window.draw(PLAYER.playersprite);
        window.draw(inputText);
        if (dialogueMode) {
            window.draw(dialogueBox);
            window.draw(dialogueText);
        }
        window.display();
    }

    return 0;
}