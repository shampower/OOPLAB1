#include <iostream>
#include <windows.h>
#include "GameCharacter.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "=== СОЗДАНИЕ ОБЪЕКТОВ ===" << std::endl;

    GameCharacter hero;

    GameCharacter warrior(
        "Артур",
        80,
        5,
        20,
        15
    );

    GameCharacter copyHero = hero;

    std::cout << "\nКоличество объектов: "
              << GameCharacter::getObjectCount()
              << std::endl;

    std::cout << "\n=== НАЧАЛЬНОЕ СОСТОЯНИЕ ===" << std::endl;

    std::cout << "\nГерой:" << std::endl;
    hero.printInfo();

    std::cout << "\nВоин:" << std::endl;
    warrior.printInfo();

    std::cout << "\nКопия героя:" << std::endl;
    copyHero.printInfo();

    std::cout << "\n=== КОРРЕКТНЫЕ ОПЕРАЦИИ ===" << std::endl;

    std::cout << "\nВоин получает 30 урона." << std::endl;
    warrior.takeDamage(30);

    std::cout << "Воин лечится на 20." << std::endl;
    warrior.heal(20);

    std::cout << "Воин повышает уровень." << std::endl;
    warrior.levelUp();

    warrior.printInfo();

    std::cout << "\n=== НЕКОРРЕКТНЫЕ ОПЕРАЦИИ ===" << std::endl;

    std::cout << "\nПробуем нанести отрицательный урон." << std::endl;
    warrior.takeDamage(-50);

    std::cout << "Пробуем вылечить на отрицательное значение." << std::endl;
    warrior.heal(-30);

    std::cout << "Пробуем нанести слишком большой урон." << std::endl;
    warrior.takeDamage(1000);

    warrior.printInfo();

    std::cout << "\n=== ПРОВЕРКА НЕЗАВИСИМОСТИ ОБЪЕКТОВ ===" << std::endl;

    std::cout << "\nИзменяем только героя." << std::endl;
    hero.takeDamage(40);

    std::cout << "\nГерой после изменения:" << std::endl;
    hero.printInfo();

    std::cout << "\nВоин не должен измениться:" << std::endl;
    warrior.printInfo();

    std::cout << "\nКопия героя не должна измениться:" << std::endl;
    copyHero.printInfo();

    std::cout << "\n=== ПРОВЕРКА КОРРЕКТНОСТИ ДАННЫХ ===" << std::endl;

    GameCharacter invalidCharacter(
        "",
        500,
        0,
        -10,
        -20
    );

        std::cout << "\n=== ПРОВЕРКА ВРЕМЕНИ ЖИЗНИ ОБЪЕКТОВ ===" << std::endl;

    {
        GameCharacter temporary("Временный", 50, 2, 5, 5);

        std::cout << "После создания временного объекта: "
                  << GameCharacter::getObjectCount()
                  << std::endl;
    }

    std::cout << "После выхода из блока: "
              << GameCharacter::getObjectCount()
              << std::endl;

    return 0;

    invalidCharacter.printInfo();

    std::cout << "\nКоличество объектов перед завершением программы: "
              << GameCharacter::getObjectCount()
              << std::endl;


              
    return 0;
}