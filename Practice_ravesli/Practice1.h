#ifndef PRACTICE1_H
#define PRACTICE1_H

#include<iostream>
#include<string>	
#include<cassert>

//Напишите программу, которая возвращает true, если строка, введенная пользователем, 
//является сэндвичем с мороженым, и false — в противном случае.
//
//	std::cout << std::boolalpha;
//	std::cout << isSandwitch("AABBBAA") << '\n';
//	std::cout << isSandwitch("3&&3") << '\n';
//	std::cout << isSandwitch("yyyyymmmmmmmmyyyyy") << '\n';
//	std::cout << isSandwitch("hhhhhhhhmhhhhhhhh") << '\n';
//
//	std::cout << isSandwitch("BBBBB") << '\n';
//	std::cout << isSandwitch("AAACCCAA ") << '\n';
//	std::cout << isSandwitch("AACDCAA") << '\n';
//	std::cout << isSandwitch("A") << '\n';
//
//	std::cout << isSandwitch("CDC") << '\n';
//	std::cout << isSandwitch("AAABB") << '\n';
//	std::cout << isSandwitch("AA") << '\n';

void sandwitch();


//Напишите программу, которая определяет минимальное число в последовательности положительных чисел, 
//которую ввел пользователь.Если в последовательности есть отрицательные числа, то вы должны сообщить 
//об этом пользователю и предложить повторить ввод еще раз.

void minNumber();

//Напишите программу, которая запрашивает у пользователя номер месяца и затем выводит соответствующее название времени года.
//В случае, если пользователь введет недопустимое число, программа должна вывести сообщение об ошибке.
//Пример результата выполнения программы :
//Введите номер месяца(число от 1 до 12) : 12
//Зима

void season();

#endif