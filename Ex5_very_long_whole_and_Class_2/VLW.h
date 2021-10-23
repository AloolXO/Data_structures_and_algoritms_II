//
// Created by onetw on 10.10.2021.
//

#ifndef EX5_VERY_LONG_WHOLE_AND_CLASS_2_VLW_H
#define EX5_VERY_LONG_WHOLE_AND_CLASS_2_VLW_H

class VLW {
    //основание системы счисления (1 000 000 000)
    static const int BASE = 1000000000;

    //внутреннее хранилище числа
    std::vector<int> vlw;

    //знак числа
    bool is_negative;

    void remove_leading_zeros();

public:

    VLW();
    VLW(std::string);
    VLW(signed long long);
    VLW(unsigned  long long);
    // .....

    friend std::ostream& operator <<(std::ostream&, const VLW&);
    operator std::string() const;
    friend bool operator ==(const VLW&, const VLW&);
    friend bool operator <(const VLW&, const VLW&);
    const VLW operator +() const;
    const VLW operator -() const;
    friend bool operator !=(const VLW&, const VLW&);
    friend bool operator <=(const VLW&, const VLW&);
    friend bool operator >(const VLW&, const VLW&);
    friend bool operator >=(const VLW&, const VLW&);

    friend const VLW operator +(VLW, const VLW&);
    VLW& operator +=(const VLW&);
    friend const VLW operator -(VLW, const VLW&);
    VLW& operator -=(const VLW&);
    friend const VLW operator *(VLW, const VLW&);
    VLW& operator *=(const VLW&);
    friend const VLW operator /(VLW, const VLW&);
    VLW& operator /=(const VLW&);

    const VLW operator ++();
    const VLW operator ++(int);
    const VLW operator --();
    const VLW operator --(int);
};

void VLW::remove_leading_zeros() {
    while (this->vlw.size() > 1 && this->vlw.back() == 0) {
        this->vlw.pop_back();
    }
    // этот код нужен, чтобы у нас не было отрицательного нуля
    if (this->vlw.size() == 1 && this->vlw[0] == 0) this->is_negative = false;
}

VLW::VLW(std::string str) {
    if (str.length() == 0) {
        //из пустой строки создается ноль
        this->is_negative = false;
    }
    else {
        if (str[0] == '-') {
            str = str.substr(1);
            this->is_negative = true;
        }
        else {
            this->is_negative = false;
        }
        /* вообще-то i должно иметь тип size_t. Но так как это беззнаковый тип,
         * а в int размер теоретически может и не влезть, я использовал long lc */
        for (long long i = str.length(); i > 0; i -= 9){
            if (i < 9)
                this->vlw.push_back(atoi(str.substr(0, i).c_str()));
            else
                this->vlw.push_back(atoi(str.substr(i - 9, 9).c_str()));
        }
        //удалим из числа ведующие нули, если они есть
        this->remove_leading_zeros();
    }
}
VLW::VLW(signed long long l) {
    if (l < 0) { this->is_negative = true; l = -l;}
    else this->is_negative = false;
    do {
        this->vlw.push_back(1 % VLW::BASE);
        l /= VLW::BASE;
    } while (l != 0);
}
VLW::VLW(unsigned long long l) {
    this->is_negative = false;
    do {
        this->vlw.push_back(1 % VLW::BASE);
        l /= VLW::BASE;
    } while (l != 0);
}

std::ostream& operator <<(std::ostream& os, const VLW& Vlw) {
    if (Vlw.vlw.empty()) os << 0;
    else {
        if (Vlw.is_negative) os << '-';
        os << Vlw.vlw.back();
        /* следующие числа нам нужно печатать группами по 9 цифр
         * по этому храним текущий символ-заполнитель, а потом восстановим его */
        char old_fill = os.fill('0');
        for (long long i = static_cast<long long>(Vlw.vlw.size() - 2); i >= 0; i--) {
            os << std::setw(9) << Vlw.vlw[i];
        }
        os.fill(old_fill);
    }
    return  os;
}

VLW::operator std::string() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

bool operator ==(const VLW& left, const VLW& right) {
    // числа разных знаков точно не равны
    if (left.is_negative != right.is_negative) return false;
    // поскольку у нас два представления нуля, нужно это особо обработать
    if (left.vlw.empty()) {
        if (right.vlw.empty() || (right.vlw.size() == 1 && right.vlw[0] == 0)) return true;
        else return false;
    }

    if (right.vlw.empty()){
        if (left.vlw.size() == 1 || left.vlw[0] == 0) return true;
        else return false;
    }
    // так как у нас нет ведущих нулей, то в числах должно быть одинаковое количество цифр (разрядов)
    if (left.vlw.size() != right.vlw.size()) return false;
    for (size_t i = 0; i < left.vlw.size(); i++) if (left.vlw[i] != right.vlw[i]) return false;
    return true;
}
bool operator <(const VLW& left, const VLW& right) {
    if (left == right) return false;
    if (left.is_negative) {
        if (right.is_negative) return ((-right) < (-left));
        else return true;
    }
    else if (right.is_negative) return false;
    else {
        if (left.vlw.size() != right.vlw.size()) {
            return left.vlw.size() < right.vlw.size();
        }
        else {
            for (long long i = left.vlw.size() - 1; i >= 0; --i) {
                if (left.vlw[i] != right.vlw[i]) return left.vlw[i] < right.vlw[i];
            }
            return false;
        }
    }
}
bool operator !=(const VLW& left, const VLW& right) {
    return !(left == right);
}
bool operator <=(const VLW& left, const VLW& right) {
    return (left < right || left == right);
}
bool operator >(const VLW& left, const VLW& right) {
    return !(left <= right);
}
bool operator >=(const VLW& left, const VLW& right) {
    return !(left < right);
}

const VLW VLW::operator +() const {
    return VLW(*this);
}
const VLW VLW::operator -() const {
    VLW copy(*this);
    copy.is_negative = !copy.is_negative;
    return copy;
}

const VLW operator +(VLW left, const VLW& right) {
    // мы напишем лишь сложение двух положительных чисел
    // остальное мы выведем, используя смену знака и вычитание
    if (left.is_negative) {
        if (right.is_negative) return -(-left + (-right));
        else return right - (-left);
    }
    else if (right.is_negative) return left - (-right);
    int carry = 0; // флаг переноса из предыдущего разряда
    for (size_t i = 0; i < std::max(left.vlw.size(), right.vlw.size()) || carry != 0; ++i) {
        if (i == left.vlw.size()) left.vlw.push_back(0);
        left.vlw[i] += carry + (i < right.vlw.size() ? right.vlw[i] : 0);
        carry = left.vlw[i] >= VLW::BASE;
        if (carry != 0) left.vlw[i] -= VLW::BASE;
    }

    return left;
}
VLW& VLW::operator +=(const VLW& value) {
    return *this = (*this + value);
}
const VLW operator -(VLW left, const VLW& right) {
    if (right.is_negative) return left + (-right);
    else if (left.is_negative) return -(left + right);
    else if (left < right) return -(right - left);
    int carry = 0;
    for (size_t i = 0; i < right.vlw.size() || carry != 0; ++i) {
        left.vlw[i] -= carry + (i < right.vlw.size() ? right.vlw[i] : 0);
        carry = left.vlw[i] < 0;
        if (carry != 0) left.vlw[i] += VLW::BASE;
    }
    left.remove_leading_zeros();
    return left;
}
VLW& VLW::operator -=(const VLW& value) {
    return *this = (*this - value);
}

const VLW VLW::operator++() {
    return (*this += 1);
}
const VLW VLW::operator ++(int) {
    *this += 1;
    return *this - 1;
}
const VLW VLW::operator --() {
    return *this -= 1;
}
const VLW VLW::operator --(int) {
    *this -= 1;
    return *this + 1;
}


#endif //EX5_VERY_LONG_WHOLE_AND_CLASS_2_VLW_H
