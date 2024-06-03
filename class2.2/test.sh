#!/bin/bash

# Тест 1: Проверка корректности обработки изображения
./favorite_color input.txt 0 0 0 output.txt
if diff -q expected_output.txt output.txt; then
    echo "Test 1 PASSED"
else
    echo "Test 1 FAILED"
fi

# Тест 2: Проверка обработки изображения с пикселями в разных местах
./favorite_color input2.txt 0 255 0 output2.txt
if diff -q expected_output2.txt output2.txt; then
    echo "Test 2 PASSED"
else
    echo "Test 2 FAILED"
fi

# Тест 3: Проверка обработки изображения без пикселей, соответствующих любимому цвету
./favorite_color input3.txt 0 0 255 output3.txt
if diff -q expected_output3.txt output3.txt; then
    echo "Test 3 PASSED"
else
    echo "Test 3 FAILED"
fi

# Тест 4: Проверка на некорректный ввод
./favorite_color input4.txt 255 255 255 output4.txt
# Ожидается вывод сообщения об ошибке, можно добавить проверку на код возврата программы

# Тест 5: Проверка обработки пустого файла
./favorite_color input5.txt 128 128 128 output5.txt
if diff -q expected_output5.txt output5.txt; then
    echo "Test 5 PASSED"
else
    echo "Test 5 FAILED"
fi
