#ifndef _MSTRING_CPP_EASY_
#define _MSTRING_CPP_EASY_
#include <iostream>
#include <string.h>
#include <cctype>
#include <algorithm>
#include <functional>
#include <locale>
#include "MVector.hpp"
class MStringException : public std::exception
{
private:
    char *message;

public:
    MStringException(char *msg) : message(msg) {}
    char *what()
    {
        return message;
    }
};

class MString
{
public:
    MString()
    {
        this->str = "";
        this->length = 0;
    }
    MString(std::string str)
    {
        this->str = str;
        this->length = str.length();
    }
    MString(char str)
    {

        this->str = std::string(1, str);
        this->length = this->str.length();
    }
    MString(char str[])
    {
        this->str = std::string(str);
        this->length = this->str.length();
    }
    MString(const char str[])
    {
        this->str = std::string(str);
        this->length = this->str.length();
    }
    bool operator==(char str)
    {
        if (this->str == std::string(1, str) && std::string(1, str).length() == this->length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator==(std::string str)
    {
        if (this->str == str && str.length() == this->length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator==(char str[])
    {
        if (this->str == str && std::string(str).length() == this->length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator==(const char str[])
    {
        if (this->str == str && std::string(str).length() == this->length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator==(MString str)
    {
        if (this->str == str.str && str.length == this->length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void operator=(MString str)
    {
        this->str = str.str;
        this->length = this->str.length();
    }
    std::vector<std::string> split_to_vec(std::string delimiter)
    {
        std::string s = this->str;
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
        {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }
    std::vector<std::string> split_to_vec(MString delimiter)
    {
        std::string s = this->str;
        size_t pos_start = 0, pos_end, delim_len = delimiter.size();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter.to_string(), pos_start)) != std::string::npos)
        {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }
    std::vector<std::string> split_to_vec(const char delimiter[])
    {
        std::string s = this->str;
        size_t pos_start = 0, pos_end, delim_len = std::string(delimiter).size();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
        {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }
    MVector<MString> split(const char delimiter[])
    {
        std::string s = this->str;
        size_t pos_start = 0, pos_end, delim_len = std::string(delimiter).length();
        std::string token;
        MVector<MString> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
        {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.right_push(token);
        }

        res.right_push(s.substr(pos_start));
        return res;
    }
    MVector<MString> split(std::string delimiter)
    {
        std::string s = this->str;
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        MVector<MString> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
        {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.right_push(token);
        }

        res.right_push(s.substr(pos_start));
        return res;
    }
    MVector<MString> split(MString delimiter)
    {
        std::string s = this->str;
        size_t pos_start = 0, pos_end, delim_len = delimiter.size();
        std::string token;
        MVector<MString> res;

        while ((pos_end = s.find(delimiter.to_string(), pos_start)) != std::string::npos)
        {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.right_push(token);
        }

        res.right_push(s.substr(pos_start));
        return res;
    }

    void operator=(std::string str)
    {
        this->str = str;
        this->length = this->str.length();
    }
    void operator=(char str)
    {
        this->str = std::string(1, str);
        this->length = this->str.length();
    }
    void operator=(char str[])
    {
        this->str = std::string(str);
        this->length = this->str.length();
    }
    void operator=(const char str[])
    {
        this->str = std::string(str);
        this->length = this->str.length();
    }
    std::string to_string()
    {
        return this->str;
    }

    MString copy()
    {
        return MString(this->str);
    }
    bool starts_with(std::string str)
    {
        if (!this->str.compare(0, str.size(), str))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool starts_with(char str[])
    {
        if (!this->str.compare(0, std::string(str).length(), std::string(str)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool starts_with(const char str[])
    {
        if (!this->str.compare(0, std::string(str).length(), std::string(str)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool starts_with(MString str[])
    {
        if (!this->str.compare(0, str->size(), str->str))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool ends_with(std::string str)
    {
        return this->str.size() >= str.size() && 0 == this->str.compare(this->str.size() - str.size(), str.size(), str);
    }
    bool ends_with(MString str)
    {
        return this->str.size() >= str.size() && 0 == this->str.compare(this->str.size() - str.size(), str.size(), str.to_string());
    }
    bool ends_with(char str[])
    {
        return this->str.size() >= std::string(str).size() && 0 == this->str.compare(this->str.size() - std::string(str).size(), std::string(str).size(), str);
    }
    bool ends_with(const char str[])
    {
        return this->str.size() >= std::string(str).size() && 0 == this->str.compare(this->str.size() - std::string(str).size(), std::string(str).size(), str);
    }
    MString get(int index)
    {

        return MString(this->str.c_str()[index]);

        throw new MStringException("error");
    }
    int size()
    {
        return this->str.size();
    }

    void push(int index, char str)
    {
        this->str.insert(index, std::string(1, str));
        this->length = this->str.length();
    }
    void push(int index, std::string str)
    {
        this->str.insert(index, str);
        this->length = this->str.length();
    }
    void push(int index, MString str)
    {
        this->str.insert(index, str.to_string());
        this->length = this->str.length();
    }
    void push(int index, char str[])
    {
        this->str.insert(index, str);
        this->length = this->str.length();
    }

    void push(int index, const char str[])
    {
        this->str.insert(index, str);
        this->length = this->str.length();
    }
    friend std::ostream &operator<<(std::ostream &out, const MString &obj)
    {
        out << obj.str;
        // do what you want
        return out;
    }
    void right_push(char str)
    {
        this->str.insert(this->length, std::string(1, str));
        this->length = this->str.length();
    }
    void right_push(std::string str)
    {
        this->str.insert(this->length, str);
        this->length = this->str.length();
    }
    void right_push(MString str)
    {
        this->str.insert(this->length, str.to_string());
        this->length = this->str.length();
    }
    void right_push(char str[])
    {
        this->str.insert(this->length, str);
        this->length = this->str.length();
    }
    void right_push(const char str[])
    {
        this->str.insert(this->length, str);
        this->length = this->str.length();
    }
    void left_push(char str)
    {
        this->str.insert(0, std::string(1, str));
        this->length = this->str.length();
    }
    void left_push(std::string str)
    {
        this->str.insert(0, str);
        this->length = this->str.length();
    }
    void left_push(MString str)
    {
        this->str.insert(0, str.to_string());
        this->length = this->str.length();
    }
    void left_push(char str[])
    {

        this->str.insert(0, str);
        this->length = this->str.length();
    }
    void left_push(const char str[])
    {

        this->str.insert(0, str);
        this->length = this->str.length();
    }
    MString get(int index1, int index2)
    {
        MString ms;
        for (int i = index1; i < index2; i++)
        {
            ms.right_push(this->get(i));
        }
        return ms;
    }
    bool replace(const std::string &from, const std::string &to)
    {
        std::string &str = this->str;
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        this->str = str;
        this->length = this->str.length();
        return true;
    }
    bool replace(MString from, std::string to)
    {
        std::string &str = this->str;
        size_t start_pos = str.find(from.to_string());
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, from.to_string().length(), to);
        this->str = str;
        this->length = this->str.length();
        return true;
    }
    bool replace(MString from, MString to)
    {
        std::string &str = this->str;
        size_t start_pos = str.find(from.to_string());
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, from.to_string().length(), to.to_string());
        this->str = str;
        this->length = this->str.length();
        return true;
    }
    bool replace(std::string from, MString to)
    {
        std::string &str = this->str;
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, from.length(), to.to_string());
        this->str = str;
        this->length = this->str.length();
        return true;
    }
    bool replace(std::string from, std::string to)
    {
        std::string &str = this->str;
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        this->str = str;
        this->length = this->str.length();
        return true;
    }
    bool replace(const char from[], const std::string &to)
    {
        std::string &str = this->str;
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, std::string(from).length(), to);
        this->str = str;
        this->length = this->str.length();
        return true;
    }

    bool replace(const char from[], const char to[])
    {
        std::string &str = this->str;
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, std::string(from).length(), to);
        this->str = str;
        this->length = this->str.length();
        return true;
    }
    bool replace(std::string &from, std::string &to)
    {
        std::string &str = this->str;
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos)
            return false;
        str.replace(start_pos, std::string(from).length(), to);
        this->str = str;
        this->length = this->str.length();
        return true;
    }
    void replace_all(const std::string &from, const std::string &to)
    {
        std::string &str = this->str;
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
        this->str = str;
        this->length = this->str.length();
    }
    void replace_all(MString from, MString to)
    {
        std::string &str = this->str;
        if (from.to_string().empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from.to_string(), start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.to_string().length(), to.to_string());
            start_pos += to.to_string().length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
        this->str = str;
        this->length = this->str.length();
    }
    void replace_all(std::string from, MString to)
    {
        std::string &str = this->str;
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to.to_string());
            start_pos += to.to_string().length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
        this->str = str;
        this->length = this->str.length();
    }
    void replace_all(MString from, std::string &to)
    {
        std::string &str = this->str;
        if (from.to_string().empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from.to_string(), start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.to_string().length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
        this->str = str;
        this->length = this->str.length();
    }
    void replace_all(std::string &from, std::string &to)
    {
        std::string &str = this->str;
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
        this->str = str;
        this->length = this->str.length();
    }
    MString set(int index, char str)
    {
        this->str[index] = str;
        this->length = this->str.length();
    }
    void trim(std::string trimmer)
    {

        this->str.erase(str.find_last_not_of(trimmer) + 1); // suffixing spaces
        this->str.erase(0, str.find_first_not_of(trimmer)); // prefixing spaces
        this->length = this->str.length();
    }
    void trim(char trimmer[])
    {

        this->str.erase(str.find_last_not_of(trimmer) + 1); // suffixing spaces
        this->str.erase(0, str.find_first_not_of(trimmer)); // prefixing spaces
        this->length = this->str.length();
    }
    void trim(char trimmer)
    {

        this->str.erase(str.find_last_not_of(trimmer) + 1); // suffixing spaces
        this->str.erase(0, str.find_first_not_of(trimmer)); // prefixing spaces
        this->length = this->str.length();
    }
    void trim(MString trimmer)
    {

        this->str.erase(str.find_last_not_of(trimmer.to_string()) + 1); // suffixing spaces
        this->str.erase(0, str.find_first_not_of(trimmer.to_string())); // prefixing spaces
        this->length = this->str.length();
    }
    void trim(const char trimmer[])
    {
        this->str.erase(str.find_last_not_of(trimmer) + 1); // suffixing spaces

        this->str.erase(0, str.find_first_not_of(trimmer)); // prefixing spaces
        this->length = this->str.length();
    }

    void right_trim(std::string trimmer)
    {

        this->str.erase(str.find_last_not_of(trimmer) + 1); // suffixing spaces
        this->length = this->str.length();
    }
    void right_trim(char trimmer[])
    {

        this->str.erase(str.find_last_not_of(trimmer) + 1); // suffixing spaces
        this->length = this->str.length();
    }
    void right_trim(char trimmer)
    {

        this->str.erase(str.find_last_not_of(trimmer) + 1); // suffixing spaces
        this->length = this->str.length();
    }
    void right_trim(MString trimmer)
    {

        this->str.erase(str.find_last_not_of(trimmer.to_string()) + 1); // suffixing spaces
        this->length = this->str.length();
    }
    void right_trim(const char trimmer[])
    {

        this->str.erase(str.find_last_not_of(trimmer) + 1); // suffixing spaces

        this->length = this->str.length();
    }
    void left_trim(std::string trimmer)
    {

        this->str.erase(0, str.find_first_not_of(trimmer)); // prefixing spaces
        this->length = this->str.length();
    }
    void left_trim(const char trimmer[])
    {

        this->str.erase(0, str.find_first_not_of(trimmer)); // prefixing spaces
        this->length = this->str.length();
    }
    void left_trim(char trimmer[])
    {

        this->str.erase(0, str.find_first_not_of(trimmer)); // prefixing spaces
        this->length = this->str.length();
    }
    void left_trim(char trimmer)
    {

        this->str.erase(0, str.find_first_not_of(trimmer)); // prefixing spaces
        this->length = this->str.length();
    }
    void left_trim(MString trimmer)
    {

        this->str.erase(0, str.find_first_not_of(trimmer.to_string())); // prefixing spaces
        this->length = this->str.length();
    }

    // trim from end (in place)
    void left_trim_space()
    {
        this->left_trim(" ");
    }
    bool contains(std::string str)
    {
        if (this->str.find(str) != std::string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool contains(char str[])
    {
        if (this->str.find(str) != std::string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool contains(const char str[])
    {
        if (this->str.find(str) != std::string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool contains(char str)
    {
        if (this->str.find(str) != std::string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool contains(MString str)
    {
        if (this->str.find(str.to_string()) != std::string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int search(std::string str)
    {
        if (auto ret = this->str.find(str) != std::string::npos)
        {
            return ret;
        }
        else
        {
            return -1;
        }
    }
    int search(char str[])
    {
        if (auto ret = this->str.find(str) != std::string::npos)
        {
            return ret;
        }
        else
        {
            return -1;
        }
    }
    int search(const char str[])
    {
        if (auto ret = this->str.find(str) != std::string::npos)
        {
            return ret;
        }
        else
        {
            return -1;
        }
    }
    int search(MString str)
    {
        if (auto ret = this->str.find(str.to_string()) != std::string::npos)
        {
            return ret;
        }
        else
        {
            return -1;
        }
    }
    int search(char str)
    {
        if (auto ret = this->str.find(str) != std::string::npos)
        {
            return ret;
        }
        else
        {
            return -1;
        }
    }
    void clear()
    {
        this->str = "";
        this->length = 0;
    }
    void right_trim_space()
    {
        this->right_trim(" ");
    }
    void trim_space()
    {
        const std::string &s = this->str;
        auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c)
                                        { return std::isspace(c); });
        auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c)
                                       { return std::isspace(c); })
                          .base();

        MString go = MString((wsback <= wsfront ? std::string() : std::string(wsfront, wsback)));
        this->str = go.str;
        this->length = this->str.length();
    }

private:
    std::string str;
    int length;
};
// falta implementar el split para la clase MVector y std::vector
#endif