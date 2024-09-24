#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lyudyna {
    string pib;

public:
    Lyudyna() : pib("Unknown") {}
    Lyudyna(const string& name) : pib(name) {}
    Lyudyna(const Lyudyna& other) : pib(other.pib) {}
    ~Lyudyna() = default;

    void setPIB(const string& name) { pib = name; }
    string getPIB() const { return pib; }

    Lyudyna& operator=(const Lyudyna& other) {
        if (this != &other) {
            pib = other.pib;
        }
        return *this;
    }
};

class Kvartyra {
    vector<Lyudyna> people;

public:
    Kvartyra() = default;
    Kvartyra(const Kvartyra& other) = default;
    ~Kvartyra() = default;

    void addLyudyna(const Lyudyna& lyudyna) { people.push_back(lyudyna); }
    void removeLyudyna(int index) {
        if (index >= 0 && index < people.size())
            people.erase(people.begin() + index);
    }

    vector<Lyudyna> getPeople() const { return people; }

    Kvartyra& operator=(const Kvartyra& other) = default;
};

class Dim {
    vector<Kvartyra> kvartyrs;

public:
    Dim() = default;
    Dim(const Dim& other) = default;
    ~Dim() = default;

    void addKvartyra(const Kvartyra& kvartyra) { kvartyrs.push_back(kvartyra); }
    void removeKvartyra(int index) {
        if (index >= 0 && index < kvartyrs.size())
            kvartyrs.erase(kvartyrs.begin() + index);
    }

    vector<Kvartyra> getKvartyry() const { return kvartyrs; }

    Dim& operator=(const Dim& other) = default;
};

int main() {
    Lyudyna person1("Ivan Ivanov");
    Lyudyna person2("Petro Petrov");
    Lyudyna person3("Olena Shevchenko");

    Kvartyra kvartyra1;
    kvartyra1.addLyudyna(person1);
    kvartyra1.addLyudyna(person2);

    Kvartyra kvartyra2;
    kvartyra2.addLyudyna(person3);

    Dim dim;
    dim.addKvartyra(kvartyra1);
    dim.addKvartyra(kvartyra2);

    cout << "Кількість квартир у будинку: " << dim.getKvartyry().size() << endl;
    for (size_t i = 0; i < dim.getKvartyry().size(); ++i) {
        cout << "Квартира " << i + 1 << " має " << dim.getKvartyry()[i].getPeople().size() << " людей." << endl;
        for (const auto& person : dim.getKvartyry()[i].getPeople()) {
            cout << "  ПІБ: " << person.getPIB() << endl;
        }
    }

    return 0;
}
