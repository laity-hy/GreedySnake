//
// Created by HongYing on 2022/10/20.
//

#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "Controller.h"
#include "Tools.h"
#include "StartInterface.h"
#include "Map.h"
#include "Snake.h"


void Controller::Start() {
    SetWindowSize(40, 32);
    SetCursorNoVisible();
    SetColor(14);
    auto *startInterface = new StartInterface();
    startInterface->Action();
    delete startInterface;

    SetCursorPosition(13, 26);
    std::cout << "Press any key to start...";
    SetCursorPosition(13, 27);
    system("pause");
}

void Controller::Select() {
    SetColor(3);
    SetCursorPosition(13, 26);
    std::cout << "                          ";
    SetCursorPosition(13, 27);
    std::cout << "                          ";
    SetCursorPosition(6, 21);
    std::cout << "��ѡ����Ϸ�Ѷ�:";
    SetCursorPosition(6, 22);
    std::cout << "(���¼�ѡ�񣬻س�ȷ��)";
    SetCursorPosition(27, 22);
    SetBackColor();
    std::cout << "��ģʽ";
    SetCursorPosition(27, 24);
    SetColor(3);
    std::cout << "��ͨģʽ";
    SetCursorPosition(27, 26);
    SetColor(3);
    std::cout << "����ģʽ";
    SetCursorPosition(27, 28);
    SetColor(3);
    std::cout << "����ģʽ";

    int ch;
    key = 1;
    bool flag = false;
    while ((ch = _getch())) {
        switch (ch) {
            case 72:
                if (key > 1) {
                    switch (key) {
                        case 2:
                            SetCursorPosition(27, 22);
                            SetBackColor();
                            std::cout << "��ģʽ";

                            SetCursorPosition(27, 24);
                            SetColor(3);
                            std::cout << "��ͨģʽ";
                            --key;
                            break;
                        case 3:
                            SetCursorPosition(27, 24);
                            SetBackColor();
                            std::cout << "��ͨģʽ";

                            SetCursorPosition(27, 26);
                            SetColor(3);
                            std::cout << "����ģʽ";
                            --key;
                            break;
                        case 4:
                            SetCursorPosition(27, 26);
                            SetBackColor();
                            std::cout << "����ģʽ";

                            SetCursorPosition(27, 28);
                            SetColor(3);
                            std::cout << "����ģʽ";
                            --key;
                            break;
                    }
                }
                break;
            case 80:
                if (key < 4) {
                    switch (key) {
                        case 1:
                            SetCursorPosition(27, 24);
                            SetBackColor();
                            std::cout << "��ͨģʽ";

                            SetCursorPosition(27, 22);
                            SetColor(3);
                            std::cout << "��ģʽ";
                            ++key;
                            break;
                        case 2:
                            SetCursorPosition(27, 26);
                            SetBackColor();
                            std::cout << "����ģʽ";
                            SetCursorPosition(27, 24);
                            SetColor(3);
                            std::cout << "��ͨģʽ";
                            ++key;
                            break;
                        case 3:
                            SetCursorPosition(27, 28);
                            SetBackColor();
                            std::cout << "����ģʽ";
                            SetCursorPosition(27, 26);
                            SetColor(3);
                            std::cout << "����ģʽ";
                            ++key;
                            break;
                    }
                }
                break;
            case 13:
                flag = true;
                break;
            default:
                break;
        }
        if (flag)break;
    }

    switch (key) {
        case 1:
            speed = 135;
            break;
        case 2:
            speed = 100;
            break;
        case 3:
            speed = 60;
            break;
        case 4:
            speed = 30;
            break;
        default:
            break;
    }
}

void Controller::DrawGame() const {
    system("cls");

    SetColor(3);
    Map *init_map = new Map();
    init_map->PrintInitMap();
    delete init_map;

    SetColor(3);
    SetCursorPosition(33, 1);
    std::cout << "Greedy Snake";
    SetCursorPosition(34, 2);
    std::cout << "̰����";
    SetCursorPosition(33, 4);
    std::cout << "�Ѷ�:";
    SetCursorPosition(34, 5);
    switch (key) {
        case 1:
            std::cout << "��ģʽ";
            break;
        case 2:
            std::cout << "��ͨģʽ";
            break;
        case 3:
            std::cout << "����ģʽ";
            break;
        case 4:
            std::cout << "����ģʽ";
            break;
        default:
            break;
    }
    SetCursorPosition(33, 7);
    std::cout << "�÷�";
    SetCursorPosition(34, 8);
    std::cout << "0";
    SetCursorPosition(33, 13);
    std::cout << "������ƶ�";
    SetCursorPosition(33, 15);
    std::cout << "Esc����ͣ";
}

int Controller::PlayGame() {
    Snake *snake = new Snake();
    Food *food = new Food();
    SetColor(6);
    snake->InitSnake();
    srand((unsigned int) time(nullptr));
    food->DrawFood(*snake);

    while (!snake->OverEdge() && !snake->HitItself()) {
        if (!snake->ChangeDirection()) {
            int tmp = Menu();
            switch (tmp) {
                case 1:
                    break;
                case 2:
                    delete snake;
                    delete food;
                    return 1;
                case 3:
                    delete snake;
                    delete food;
                    return 2;
                default:
                    break;
            }
        }
        if (snake->GetFood(*food)) {
            snake->Move();
            UpdateScore(1);
            RewriteScore();
            food->DrawFood(*snake);
        } else {
            snake->NormalMove();
        }
        if (snake->GetBigFood(*food)) {
            snake->Move();
            UpdateScore(food->GetProgressBar() / 5);
            RewriteScore();
        }
        if (food->GetBigFlag()) {
            food->FlashBigFood();
        }
        Sleep(speed);
    }

    delete snake;
    delete food;
    int tmp = GameOver();
    switch (tmp) {
        case 1:
            return 1;//���¿�ʼ
        case 2:
            return 2;//�˳�
    }
}

void Controller::UpdateScore(const int &tmp) {
    score += key * 10 * tmp;
}

void Controller::RewriteScore() const {
    SetCursorPosition(34, 8);
    SetColor(11);
    std::cout << score;
}

int Controller::Menu() {
    SetColor(11);
    SetCursorPosition(32, 19);
    std::cout << "�˵�:";
    Sleep(100);
    SetCursorPosition(34, 21);
    SetBackColor();
    std::cout << "������Ϸ";
    Sleep(100);
    SetCursorPosition(34, 23);
    SetColor(11);
    std::cout << "���¿�ʼ";
    Sleep(100);
    SetCursorPosition(34, 25);
    std::cout << "�˳���Ϸ";

    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch())) {
        switch (ch) {
            case 72:
                if (tmp_key > 1) {
                    switch (tmp_key) {
                        case 2:
                            SetCursorPosition(34, 21);
                            SetBackColor();
                            std::cout << "������Ϸ";
                            SetCursorPosition(34, 23);
                            SetColor(11);
                            std::cout << "���¿�ʼ";
                            --tmp_key;
                            break;
                        case 3:
                            SetCursorPosition(34, 23);
                            SetBackColor();
                            std::cout << "���¿�ʼ";
                            SetCursorPosition(34, 25);
                            SetColor(11);
                            std::cout << "�˳���Ϸ";
                            --tmp_key;
                            break;
                    }
                }
                break;
            case 80://DOWN
                if (tmp_key < 3) {
                    switch (tmp_key) {
                        case 1:
                            SetCursorPosition(34, 23);
                            SetBackColor();
                            std::cout << "���¿�ʼ";
                            SetCursorPosition(34, 21);
                            SetColor(11);
                            std::cout << "������Ϸ";

                            ++tmp_key;
                            break;
                        case 2:
                            SetCursorPosition(34, 25);
                            SetBackColor();
                            std::cout << "�˳���Ϸ";
                            SetCursorPosition(34, 23);
                            SetColor(11);
                            std::cout << "���¿�ʼ";

                            ++tmp_key;
                            break;
                    }
                }
                break;
            case 13:
                flag = true;
                break;
            default:
                break;
        }
        if (flag) {
            break;
        }
    }
    if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
    {
        SetCursorPosition(32, 19);
        std::cout << "      ";
        SetCursorPosition(34, 21);
        std::cout << "        ";
        SetCursorPosition(34, 23);
        std::cout << "        ";
        SetCursorPosition(34, 25);
        std::cout << "        ";
    }
    return tmp_key;
}

void Controller::Game() {
    Start();
    while (true) {
        Select();
        DrawGame();
        int tmp = PlayGame();
        if (tmp == 1) {
            system("cls");
            continue;
        } else {
            break;
        }
    }
}

Controller::Controller() {
    speed = 200;
    key = 1;
    score = 0;

}

int Controller::GameOver() const {
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "������������������������������������������������������������������������������������";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ��               Game Over !!!              ��";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ��              ���ź��������              ��";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ��             ��ķ���Ϊ��                 ��";
    SetCursorPosition(24, 13);
    std::cout << score;
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ��   �Ƿ�����һ�֣�                         ��";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(10, 21);
    std::cout << "������������������������������������������������������������������������������������";

    Sleep(100);
    SetCursorPosition(12, 18);
    SetBackColor();
    std::cout << "�ţ��õ�";
    SetCursorPosition(0, 31);

    /*ѡ�񲿷�*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch())) {
        switch (ch) {
            case 75://LEFT
                if (tmp_key > 1) {
                    SetCursorPosition(12, 18);
                    SetBackColor();
                    std::cout << "�ţ��õ�";
                    SetCursorPosition(20, 18);
                    SetColor(11);
                    std::cout << "���ˣ�����ѧϰ����˼";
                    --tmp_key;
                }
                break;

            case 77://RIGHT
                if (tmp_key < 2) {
                    SetCursorPosition(20, 18);
                    SetBackColor();
                    std::cout << "���ˣ�����ѧϰ����˼";
                    SetCursorPosition(12, 18);
                    SetColor(11);
                    std::cout << "�ţ��õ�";
                    ++tmp_key;
                }
                break;

            case 13://Enter
                flag = true;
                break;

            default:
                break;
        }

        SetCursorPosition(0, 31);
        if (flag) {
            break;
        }
    }

    SetColor(11);
    switch (tmp_key) {
        case 1:
            return 1;//���¿�ʼ
        case 2:
            return 2;//�˳���Ϸ
        default:
            return 1;
    }
}


