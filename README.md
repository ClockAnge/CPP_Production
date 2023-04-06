## Калькулятор

Программа основана на классе “Calculator” реализующий рекурсивный спуск для выполнения преобразований над выражениями. Краткий обзор работы класса и его методов:
1. Класс принимает на вход строку (‘m_input’), которая содержит в себе арифметическое выражение для выполнения.
2. Метод ‘calculate’ вызывается для старта процесса вычисления выражения. Используется для вызова метода ‘expr’, который запускает рекурсивный спуск и составляет полное выражение из операций отдельных токенов (+, -, /, *, ^).
3. Метод ‘term’ возвращает одно слагаемое, которое может являться числом, выражением в скобках или унарным минусом за которым следует слагаемое.
4. Метод ‘power’ возводит слагаемое в степень.
5. Метод ‘factor’ возвращает множитель, который может быть слагаемым
возведенным в степень или обычным слагаемым. Также в нем предусмотрена
обработка выражений находящихся в скобках (также при помощи ‘expr’)
6. Метод ‘getNextToken’ считывает следующий токен из входной строки и
возвращает его. Метод использует простой конечный автомат, чтобы
распознавать и токенизировать различные символы выражения.
7. Метод ‘putBackToken’ используется для сброса счетчика количества токенов
(‘m_index’)
В целом, класс Calculator использует алгоритм синтаксического анализа с рекурсивным спуском для вычисления арифметических выражений. Он разбивает входное выражение на более мелкие подвыражения и рекурсивно применяет операторы и круглые скобки до тех пор, пока не достигнет конечного результата. Реализация проста и понятна, хоть и способна обрабатывать сложные выражения с вложенными круглыми скобками, унарными операторами и числами с плавающей запятой.

## Входные данные

Арифметическое выражение

## Сборка

Из папки build вызываются следующие команды:
1. cmake ..
2. make calc_lib
3. make calculator
4. make calc_test
После этого, из папки bin будет доступен запуск тестов и самой программы.
Для запуска интеграционных тестов использовать pytest.