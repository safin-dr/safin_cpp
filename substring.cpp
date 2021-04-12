#include <iostream>

struct string {
    char *str;
    size_t size;
    size_t capacity;

    string() // Конструктор пустой строки
    {
        size = 0;
        capacity = 2;
        str = new char[capacity];
        str[0] = NULL;
    }

    string(size_t cnt, char c) // Заполняющий конструктор
    {
        size = cnt;
        capacity = 2 * cnt;

        str = new char[capacity + 1];

        for (int i = 0; i < cnt; i++) {
            str[i] = c;
        }

        str[cnt] = '\0';
    }

    string(const string& s) // Копирующий конструктор
    {
        size = s.size;
        capacity = s.capacity;

        str = new char[capacity + 1];
        for (size_t i = 0; i < size; i++)
            str[i] = s.str[i];

        str[size] = '\0';
    }

    string(char c) // Конструктор строки из одного символа
    {
        size = 1;
        capacity = 2;
        str = new char[capacity + 1];
        str[0] = c;
        str[1] = '\0';
    }

    string(const char* c_str)  // Конструктор строки из c-style строки (массива символов)
    {
        size = 0;
        capacity = 2;
        str = new char[capacity];
        str[0] = '\0';

        size_t count = 0;
        while (c_str[count] != '\0')
            count++;

        while (capacity <= count)
            reallocate(capacity * 2);

        size = count;
        for (size_t i = 0; i < count; ++i)
            str[i] = c_str[i];

        str[count] = '\0';
    }

    ~string() //очистить всю используемую память
    {
        delete []str;
        str = NULL;
        size = 0;
        capacity = 0;
    };

    string& operator= (const string& new_str) {
        if (this->capacity > new_str.size)
        {
            size = new_str.size;
            if (str)
                delete[] str;

            str = new_str.str;
        }
        else
        {
            while (capacity <= new_str.size)
                reallocate(capacity * 2);

            size = new_str.size;

            for (size_t i = 0; i < size; i++)
                str[i] = new_str.str[i];

            str[size] = '\0';
        }
        return *this;
    }

    bool operator== (const string& other)
    {
        if (size != other.size)
            return false;

        for (size_t i = 0; i < size; i++)
            if (str[i] != other.str[i])
                return false;

        return true;
    }

    bool operator!= (const string& other)
    {
        return !(*this == other);
    }

    bool operator> (const string& other)
    {
        for (int i = 0; i < size; i++) {
            if (this->str[i] != '\0' && other.str[i] == '\0')
                return true;

            if (this->str[i] > other.str[i])
                return true;

            if (this->str[i] < other.str[i])
                return false;
        }
        return false;
    }

    bool operator< (const string& other)
    {
        for (int i = 0; i < size; i++) {
            if (this->str[i] == '\0' && other.str[i] != '\0')
                return true;

            if (this->str[i] > other.str[i])
                return false;

            if (this->str[i] < other.str[i])
                return true;
        }
        return false;
    }

    string& operator+= (const string& other)
    {
        size_t new_size = size + other.size;

        while (capacity <= new_size)
        {
            capacity = capacity * 2;
            realloc(str, capacity + 1);
        }

        for (size_t i = size; i < new_size; i++)
            str[i] = other.str[i - size];

        size = new_size;
        str[size] = '\0';

        return *this;
    }

    string& operator+= (char other) {

        size_t new_size = size + 1;

        while (capacity <= new_size)
        {
            capacity = capacity * 2;
            realloc(str, capacity + 1);
        }

        str[size] = other;

        size = new_size;

        str[size] = '\0';

        return *this;
    }

    char operator[] (unsigned int pos) const {
        return str[pos];
    }

    void append(const string other) {
        *this += other;
        }  // дописать в конец данной строки другую

    void resize(unsigned int new_capacity) // увеличить/уменьшить емкость строки
    {
        if (new_capacity >= capacity)
            reserve(new_capacity);
        else
        {
            str[new_capacity + 1] = '\0';
            realloc(str, new_capacity + 1);
        }
        capacity = new_capacity;

    };

    void reserve(unsigned int new_capacity) // зарезервировать память в нужном объеме
    {
        realloc(str, new_capacity + 1);
        capacity = new_capacity;
    }

    void reallocate(unsigned int new_capacity) {
        capacity = new_capacity;
        char* new_data = new char[capacity];
        for (size_t i = 0; i < size + 1 and i < capacity; ++i)
            new_data[i] = str[i];

        if (str)
            delete[] str;

        str = new_data;
    }  // реаллокация

    void insert(unsigned int pos, string other) {
        size_t new_size = size + other.size;
        string tmp = *this;

        while (capacity <= new_size)
            reallocate(capacity * 2);

        for (size_t i = pos; i < pos + other.size; i++)
            str[i] = other.str[i - pos];

        for (size_t i = pos + other.size; i < new_size; i++)
            str[i] = tmp[i - other.size];

        size = new_size;

        str[new_size] = '\0';

    }  // Вставка другой строки внутрь данной

    void shrink_to_fit(){
        reallocate(size + 1);
    }  //очистить неиспользуемую память

    void clear() //очистить содержимое строки, занимаемое место при этом не меняется
    {
        *str = 0;
        size = 0;
        str[0] = '\0';
    };

    friend std::ostream& operator<< (std::ostream& ostr, const string& str) {
        return ostr << str.str;
        }

    friend std::istream& operator>> (std::istream& istr, const string& str) {
        return istr >> str.str;
        }

};


string operator + (const string & str1, const string & str2) {
    string temp = str1;
    temp += str2;
    return temp;
}


int stoi(const string str, size_t pos = 0, int base = 10 ) {
    string tmp;
    {
        int i = 0;
        while ((str.str[i + pos] >= '0' && str.str[i + pos] < (base < 10 ? '0' + base : '9' + 1))
            || (str.str[i + pos] >= 'A' && str.str[i + pos] < 'A' + base - 10))
        {
            tmp += str.str[i + pos];
            i++;
        }
    }
    int pow = 1;
    int result = 0;

    for (size_t i = 0; i < tmp.size; i++)
    {
        if (tmp.str[tmp.size - 1 - i] >= '0' && tmp.str[tmp.size - 1 - i] < (base < 10 ? '0' + base : '9' + 1))
            result += (tmp[tmp.size - 1 - i] - '0') * pow;

        else if (tmp.str[tmp.size - 1 - i] >= 'A' && tmp.str[tmp.size - 1 - i] < 'A' + base - 10)
            result += (tmp[tmp.size - 1 - i] - 'A' + 10) * pow;

        pow *= base;
    }
    return result;
};

// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.

int main() {
    string a;
    string b(11, 'b');
    string c(b);
    string d('d');
    string e("abcd");

    a = e;

    std::cout << c << '\n';
    std::cout << (c > b) << '\n';
    std::cout << (c < b) << '\n';

    c += e;

    std::cout << c << '\n';
    std::cout << c[1] << '\n';

    c.insert(1, e);

    std::cout << c << '\n';

    c = c + c + c + c + c + c + c + c + c;

    c += 'U';

    std::cout << c << '\n';

    string mem("112123123412345");

    std::cout << stoi(mem, 0, 3) << '\n';

    return 0;
}
