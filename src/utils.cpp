#include "rando/utils.hpp"

#include <algorithm>
#include <cmath>
#include <ios>
#include <sstream>
#include <stdexcept>
#include <iomanip>

string hex_to_binary(const string& hex)
{
    std::stringstream binary;

    for (int i = 0; i < hex.size(); i++)
    {
        switch (hex[i])
        {
        case '0':
            binary << "0000";
            break;
        case '1':
            binary << "0001";
            break;
        case '2':
            binary << "0010";
            break;
        case '3':
            binary << "0011";
            break;
        case '4':
            binary << "0100";
            break;
        case '5':
            binary << "0101";
            break;
        case '6':
            binary << "0110";
            break;
        case '7':
            binary << "0111";
            break;
        case '8':
            binary << "1000";
            break;
        case '9':
            binary << "1001";
            break;
        case 'A':
        case 'a':
            binary << "1010";
            break;
        case 'B':
        case 'b':
            binary << "1011";
            break;
        case 'C':
        case 'c':
            binary << "1100";
            break;
        case 'D':
        case 'd':
            binary << "1101";
            break;
        case 'E':
        case 'e':
            binary << "1110";
            break;
        case 'F':
        case 'f':
            binary << "1111";
            break;
        default:
            throw std::runtime_error("Invalid character");
        }
    }

    return binary.str();
}

string dec_to_hex(int number)
{
    number %= 256;

    std::stringstream hex;

    hex << std::setw(2) << std::setfill('0') << std::uppercase << std::hex << number;

    return hex.str();
}

#include <iostream>

std::string hex_to_string(const std::string &input)
{
    std::stringstream output;
    for (size_t i = 0; i < input.size(); i += 2)
    {
        output << static_cast<unsigned char>(stoi(input.substr(i, 2), 0, 16));
    }
    return output.str();
}


// converts a hexadecimal string to a decimal integer
int hex_to_decimal(const std::string& hex)
{
    if (hex.empty())
    {
        return 0;
    }
    return std::stoul(hex, 0, 16);
}

int string_to_dec(string text)
{
    int number = 0;

    for (int i = 0; i < text.size(); i++)
    {
        number *= 10;
        number += (text[i] - '0');
    }

    return number;
}

string dec_to_string(int dec, int depth)
{
    char digit;

    if (dec == 0)
    {
        if (depth == 0)
        {
            return "0";
        }
        else
        {
            return "";
        }
    }
    else
    {
        digit = (dec % 10) + '0';
        return dec_to_string(dec / 10, ++depth) + digit;
    }
}

bool isNumber(string text)
{
    for (int i = 0; i < text.size(); i++)
    {
        if ((text[i] - '0') > 9)
        {
            return false;
        }
    }

    return true;
}

string binary_to_hex(string binary)
{
    string hex = "";
    string single;

    for (int i = 0; i < binary.size(); i += 4)
    {
        single = binary.substr(i, 4);

        if (single == "0000")
        {
            hex += "0";
        }
        else if (single == "0001")
        {
            hex += "1";
        }
        else if (single == "0010")
        {
            hex += "2";
        }
        else if (single == "0011")
        {
            hex += "3";
        }
        else if (single == "0100")
        {
            hex += "4";
        }
        else if (single == "0101")
        {
            hex += "5";
        }
        else if (single == "0110")
        {
            hex += "6";
        }
        else if (single == "0111")
        {
            hex += "7";
        }
        else if (single == "1000")
        {
            hex += "8";
        }
        else if (single == "1001")
        {
            hex += "9";
        }
        else if (single == "1010")
        {
            hex += "A";
        }
        else if (single == "1011")
        {
            hex += "B";
        }
        else if (single == "1100")
        {
            hex += "C";
        }
        else if (single == "1101")
        {
            hex += "D";
        }
        else if (single == "1110")
        {
            hex += "E";
        }
        else if (single == "1111")
        {
            hex += "F";
        }
        else
        {
            hex += "";
        }
    }

    return hex;
}

string decimal_to_hex(int dec)
{
    string hex = "";
    int d = 0;

    if (dec == 0)
    {
        return "";
    }
    else
    {
        d = (dec % 16);

        if (d >= 10)
        {
            hex = (d / 10) + '0';
            hex += (d % 10) + '0';
        }
        else
        {
            hex = d + '0';
        }

        if (hex == "10")
        {
            hex = "A";
        }
        else if (hex == "11")
        {
            hex = "B";
        }
        else if (hex == "12")
        {
            hex = "C";
        }
        else if (hex == "13")
        {
            hex = "D";
        }
        else if (hex == "14")
        {
            hex = "E";
        }
        else if (hex == "15")
        {
            hex = "F";
        }

        return decimal_to_hex(dec / 16) + hex;
    }
}


// replace each 1 with a 0, and each 0 with a 1
string invert_binary(string binary)
{
    string inverted = "";

    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == '0')
        {
            inverted += "1";
        }
        else
        {
            inverted += "0";
        }
    }

    return inverted;
}

string Hex_Minus(string hex, string hex_2)
{
    string New_Hex;
    int Hex_Dec = hex_to_decimal(hex);
    int Hex_2_Dec = hex_to_decimal(hex_2);
    int New_Hex_Dec = Hex_Dec - Hex_2_Dec;

    // if it's negative then get FFFF - the value
    if (New_Hex_Dec < 0)
    {
        New_Hex_Dec *= -1; // make it positive
        New_Hex_Dec -=
          1; // if it goes over 100, then the game ignores the 1 and only looks at the 00,
             // but it's 1 too high, so doing this fixes it to give the correct item
        New_Hex = dec_to_hex(New_Hex_Dec); // convert back to hex
        New_Hex = hex_to_binary(New_Hex);  // convert the new hex to binary
        New_Hex = invert_binary(New_Hex);  // invert the binary
        New_Hex = binary_to_hex(New_Hex);  // convert the inverted binary to hex
    }
    else
    {
        New_Hex = dec_to_hex(New_Hex_Dec); // convert from positive number back to hex
    }

    return New_Hex;
}


string Even_Hex(string hex)
{
    if (hex.size() / 2 == 0)
    {
        return "0" + hex;
    }
    else
    {
        return hex;
    }
}

string Bits_Or(string bits_1, string bits_2)
{
    if (bits_1.length() == 0 && bits_2.length() == 0)
    {
        return "";
    }
    else if (bits_1.length() == 0)
    {
        return bits_2;
    }
    else if (bits_2.length() == 0)
    {
        return bits_1;
    }
    else
    {
        if (bits_1.length() > bits_2.length())
        {
            return bits_1[0] + Bits_Or(bits_1.substr(1), bits_2);
        }
        else if (bits_1.length() < bits_2.length())
        {
            return bits_2[0] + Bits_Or(bits_1, bits_2.substr(1));
        }
        else
        {
            if (bits_1[0] == '1' || bits_2[0] == '1')
            {
                return "1" + Bits_Or(bits_1.substr(1), bits_2.substr(1));
            }
            else
            {
                return "0" + Bits_Or(bits_1.substr(1), bits_2.substr(1));
            }
        }
    }
}

// clears the bit at index bit_index of a byte
string Bit_Clear(string byte, int bit_index)
{
    string new_byte = "";

    for (int b = 0; b < byte.size(); b++)
    {
        if (b != bit_index)
        {
            new_byte += byte[b];
        }
        else
        {
            new_byte += "0";
        }
    }

    return new_byte;
}

std::string string_to_hex(const std::string &input)
{
    static const char *const lut = "0123456789ABCDEF";
    size_t len = input.length();

    string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

string Replace(string bigger_text, string smaller_text, string new_smaller_text)
{
    string new_text = "";
    for (int a = 0; a < bigger_text.size(); a++)
    {
        int c = a;
        int b = 0;

        for (b = 0; b < smaller_text.size(); b++)
        {
            // not equal
            if (bigger_text[c] != smaller_text[b])
            {
                b = smaller_text.size();
            }
            c++;
        }
        // found a match
        if (b == smaller_text.size())
        {
            new_text += new_smaller_text; // get the replacement
            a += smaller_text.size() -
                 1; // skip passed the old text (-1 cause for loop will increase it by 1)
        }
        else
        {
            new_text += bigger_text[a];
        }
    }

    return new_text;
}

vector<string> Split(string line, string Splitter)
{
    vector<string> List;

    // while the line contains the splitter
    while (IndexOf_S(line, Splitter) != -1)
    {
        List.push_back(line.substr(0, IndexOf_S(line, Splitter)));
        line = line.substr(IndexOf_S(line, Splitter) + Splitter.size());
    }
    List.push_back(line);

    return List;
}

bool Contains(string text, char chr)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == chr)
        {
            return true;
        }
    }

    return false;
}

string Remove_Whitespace(string text)
{
    text = RemoveAll(text, ' ');
    text = RemoveAll(text, '\t');

    return text;
}


string RemoveAll(string text, char chr)
{
    string newText = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != chr)
        {
            newText += text[i];
        }
    }

    return newText;
}

int IndexOf_S(string Data, string Text)
{
    size_t pos = Data.find(Text);
    if (pos == std::string::npos)
    {
        return -1;
    }
    return pos;
}

/// Gets the word at index 'word_index' from 'text' (0 based)
string Get_Word(string text, int word_index)
{
    vector<string> words = Split(text, " ");

    if (words.size() > word_index)
    {
        return words[word_index];
    }
    else
    {
        return "";
    }
}

vector<string> String_Split(string text, int split)
{
    vector<string> Data;

    for (int i = 0; i < text.size(); i += split)
    {
        Data.push_back(text.substr(i, split));
    }

    return Data;
}

string Leading_Zeroes(string hex, int total_length)
{
    while (hex.size() < total_length)
    {
        hex = "0" + hex;
    }

    return hex;
}