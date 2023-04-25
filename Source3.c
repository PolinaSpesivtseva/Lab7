#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

char get_char_by_num(unsigned char num) //создаем функцию, где по длине слова переводим в char
{
    char result;
    result = 48 + num;
    return result;
}

void parse_sentence(char* str)
{
    char output_word[13]; //10 позиций - максимальная длина, 1 позиция - символ конца, 2 позиции в начале - модет быть длина слова
    int start_pos = 0;
    int word_length = 0;
    char exit_flag = 0;

    // Длина всей строки
    int str_length = strlen(str);

    // Перебор каждого символа строки
    for (int i = 0; i < str_length; i++)
    {
        if ((str[i] == ' ') || (str[i] == '.'))
        {
            //Еслли встречаем символ '.', то выходим из цикла после разбора последнего слова
            if (str[i] == '.')
                exit_flag = 1;
            // Заменяем символом конец строки
            str[i] = '\0';

            // Длина слова
            word_length = strlen(str + start_pos);

            // проверяем, что длина слова не равна нулю (значит, пробел один за другим) и на четность числа символов в слове
            if ((word_length) && (word_length % 2 == 0))
            {
                // Формируем слово, состоящее из числа байт и самого слова
                if (word_length < 10)
                {
                    // Добавляем один символ в начало формируемого слова
                    output_word[0] = get_char_by_num(word_length);

                    // Копируем символы самого слова после символа длины
                    for (char j = 0; j < word_length; j++)
                        output_word[j + 1] = str[start_pos + j];

                    // В конце слова добавляем символ конца строки
                    output_word[1 + word_length] = '\0';
                }
                else if (word_length == 10)
                {
                    // Добавляем два символа в начало формируемого слова
                    output_word[0] = '1';
                    output_word[1] = '0';

                    // Копируем символы самого слова после символа длины
                    for (char j = 0; j < word_length; j++)
                        output_word[j + 2] = str[start_pos + j];

                    // В конце слова добавляем символ конца строки
                    output_word[2 + word_length] = '\0';
                }

                // Вывод на печать
                puts(output_word);
            }

            // Переопределяем позицию 1го байта следующего слова
            start_pos = i + 1;
            //Если встречаем символ '.', то выходим из цикла for, после разбора последнего слова
            if (exit_flag)
                break;
        }
    }
}

int main()
{
    char input_string[1001];
    char* inp;
    // Считываем строку
    gets(input_string);
    inp = strtok(input_string, ".");
    puts(input_string);

    // Разбираем строку, формируем и выводим слова
    parse_sentence(input_string);

    return 0;
}
