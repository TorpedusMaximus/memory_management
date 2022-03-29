#include <iostream>
#include <stdexcept>

class MojError : public std::logic_error {
private:
    const char *tekst;
public:
    explicit MojError(const char *tekst) : std::logic_error(tekst) {
        this->tekst = tekst;
    }
};

void validateArguments(int argc) {
    if (argc != 2) {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class Resource {
private:
    const char *arg;
public:
    void use(const char *arg) {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd') {
            throw MojError("Passed d. d is prohibited.");
        }
    }

    ~Resource() {
        delete arg;
    }

};

int main(int argc, char* argv[])
{
    validateArguments(argc);
    const char* argument = argv[1];

    Resource *rsc = new Resource();
    try
    {
        rsc->use(argument);
    }
    catch (MojError &e) {
        std::cout << e.what() << std::endl;
    }
    delete rsc;
    return 0;
}

