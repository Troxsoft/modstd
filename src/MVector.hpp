#ifndef _MVECTOR_CPP_EASY_
#define _MVECTOR_CPP_EASY_
#include <iostream>
#include <vector>

class MVectorException : public std::exception
{
private:
    char *message;

public:
    MVectorException(char *msg) : message(msg) {}
    char *what()
    {
        return message;
    }
};
template <typename T>
class MVector

{
public:
    MVector<T>()
    {
        this->vec = {};
        this->is_max_size = false;
    }
    MVector<T>(int max_size)
    {

        this->vec = {};
        this->max_size = max_size;
        this->is_max_size = true;
    }
    MVector<T>(std::vector<T> arr)
    {
        this->is_max_size = false;
        this->vec = arr;
    }
    MVector<T>(int max_size, std::vector<T> arr)
    {

        this->vec = arr;
        this->max_size = max_size;
        this->is_max_size = true;
        if (this->vec.size() > this->max_size)
        {
            throw new MVectorException("the vector size>max_size");
        }
    }
    T get_last()
    {
        return this->vec[this->size() - 1];
    }
    T get_first()
    {
        return this->vec[0];
    }
    T get(int index)
    {
        return this->vec[index];
    }
    void left_push(T t)
    {
        if (this->is_max_size == false)
        {
            std::vector<T> v;
            v.push_back(t);
            for (int i = 0; i < this->size(); i++)
            {
                v.push_back(this->vec[i]);
            }
            this->vec = v;
        }
        else
        {
            if (vec.size() + 1 < this->max_size)
            {
                std::vector<T> v;
                v.push_back(t);
                for (int i = 0; i < this->size(); i++)
                {
                    v.push_back(this->vec[i]);
                }
                this->vec = v;
            }
            else
            {
                throw new MVectorException("size error(vector size > max size)");
            }
        }
    }
    void right_push(T t)
    {
        if (this->is_max_size == false)
        {
            this->vec.push_back(t);
        }
        else
        {
            if (vec.size() + 1 < this->max_size)
            {
                this->vec.push_back(t);
            }
            else
            {
                throw new MVectorException("size error(vector size > max size)");
            }
        }
    }
    void push(int index, T t)
    {
        if (this->is_max_size == false)
        {
            auto it = this->vec.begin();
            this->vec.insert(it, index, t);
        }
        else
        {
            if (vec.size() + 1 < this->max_size)
            {
                auto it = this->vec.begin();
                this->vec.insert(it, index, t);
            }
            else
            {
                throw new MVectorException("size error(vector size > max size)");
            }
        }
    }
    std::vector<T> to_vec()
    {
        return this->vec;
    }

    friend std::ostream &operator<<(std::ostream &out, const MVector<T> &obj)
    {
        out << "{ ";
        for (int i = 0; i < obj.vec.size(); i++)
        {
            if (i + 1 < obj.vec.size())
            {
                out << obj.vec[i] << ",";
            }
            else
            {
                out << obj.vec[i];
            }
        }
        out << " }";
        // do what you want
        return out;
    }
    T &operator[](int idx)
    {
        return this->vec[idx];
    }

    T operator[](int idx) const
    {
        return this->vec[idx];
    }
    bool operator==(MVector mv)
    {
        if (this->vec == mv.vec)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator==(std::vector<T> mv)
    {
        if (this->vec == mv)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    MVector<T> get_range(int index1, int index2)
    {
        auto vec2 = this->vec;
        vec2.clear();
        for (int i = index1; i < index2; i++)
        {

            vec2.push_back(this->get(i));
        }
        return vec2;
    }

    int size()
    {
        return this->vec.size();
    }

private:
    std::vector<T> vec;
    T t;
    bool is_max_size;
    int max_size;
};
#endif