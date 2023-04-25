#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

char get_char_by_num(unsigned char num) //������� �������, ��� �� ����� ����� ��������� � char
{
    char result;
    result = 48 + num;
    return result;
}

void parse_sentence(char* str)
{
    char output_word[13]; //10 ������� - ������������ �����, 1 ������� - ������ �����, 2 ������� � ������ - ����� ���� ����� �����
    int start_pos = 0;
    int word_length = 0;
    char exit_flag = 0;

    // ����� ���� ������
    int str_length = strlen(str);

    // ������� ������� ������� ������
    for (int i = 0; i < str_length; i++)
    {
        if ((str[i] == ' ') || (str[i] == '.'))
        {
            //����� ��������� ������ '.', �� ������� �� ����� ����� ������� ���������� �����
            if (str[i] == '.')
                exit_flag = 1;
            // �������� �������� ����� ������
            str[i] = '\0';

            // ����� �����
            word_length = strlen(str + start_pos);

            // ���������, ��� ����� ����� �� ����� ���� (������, ������ ���� �� ������) � �� �������� ����� �������� � �����
            if ((word_length) && (word_length % 2 == 0))
            {
                // ��������� �����, ��������� �� ����� ���� � ������ �����
                if (word_length < 10)
                {
                    // ��������� ���� ������ � ������ ������������ �����
                    output_word[0] = get_char_by_num(word_length);

                    // �������� ������� ������ ����� ����� ������� �����
                    for (char j = 0; j < word_length; j++)
                        output_word[j + 1] = str[start_pos + j];

                    // � ����� ����� ��������� ������ ����� ������
                    output_word[1 + word_length] = '\0';
                }
                else if (word_length == 10)
                {
                    // ��������� ��� ������� � ������ ������������ �����
                    output_word[0] = '1';
                    output_word[1] = '0';

                    // �������� ������� ������ ����� ����� ������� �����
                    for (char j = 0; j < word_length; j++)
                        output_word[j + 2] = str[start_pos + j];

                    // � ����� ����� ��������� ������ ����� ������
                    output_word[2 + word_length] = '\0';
                }

                // ����� �� ������
                puts(output_word);
            }

            // �������������� ������� 1�� ����� ���������� �����
            start_pos = i + 1;
            //���� ��������� ������ '.', �� ������� �� ����� for, ����� ������� ���������� �����
            if (exit_flag)
                break;
        }
    }
}

int main()
{
    char input_string[1001];
    char* inp;
    // ��������� ������
    gets(input_string);
    inp = strtok(input_string, ".");
    puts(input_string);

    // ��������� ������, ��������� � ������� �����
    parse_sentence(input_string);

    return 0;
}
