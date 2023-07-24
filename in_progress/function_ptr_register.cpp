#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <memory>

class FunctionWrapperBase 
{
    public:
        virtual void call() = 0;
};

template<typename ReturnType>
class FunctionWrapper : public FunctionWrapperBase 
{
    private:
        std::function<ReturnType()> _func_ptr;
    
    public:
        FunctionWrapper(
            std::function<ReturnType()> fptr
            ) 
        : _func_ptr(fptr) 
        {}

        void call() override 
        {
            _func_ptr();
        }
};

class FunctionRegistry 
{
    private:
        // map that is the registry
        std::map<std::string, std::unique_ptr<FunctionWrapperBase>> _function_registry;

    public:
        template<typename ReturnType>

        // add a function to the registry 
        void addFunction(
            const std::string& functionName, 
            ReturnType (*functionPtr)()
            ) 
        {
            _function_registry[functionName] = std::make_unique<FunctionWrapper<ReturnType>>(functionPtr);
        }

        // delete a function from the registry
        void deleteFunction(
            const std::string& functionName
            ) 
        {
            _function_registry.erase(functionName);
        }

        // return the ptr into the function if the function is in the registry else it return a null ptr
        FunctionWrapperBase* getFunction(
            const std::string& functionName
            ) 
        {
            return _function_registry.count(functionName) ? _function_registry[functionName].get() : nullptr;
        }
};

int coucou();
double toto_pls(); 
void die_pls();


int main() 
{
    // init the registry of function
    FunctionRegistry registry;
    std::string functionName;

    // adding function to registry
    registry.addFunction("coucou", &coucou);
    registry.addFunction("toto_pls", &toto_pls);
    registry.addFunction("die_pls", &die_pls);

    std::cout << "Enter function name: ";
    std::cin >> functionName;

    if (FunctionWrapperBase* ptr = registry.getFunction(functionName)) 
    {
        std::cout << "La fonction " << functionName << " à été trouvé et execute:\n";
        ptr->call();
    } else 
        std::cout << "La fonction demandée n'as pas été trouvé dans le registre.\n";

    return 0;
}


int coucou() 
{
    std::cout << "Coucou !\n";
    return 42;
}

double toto_pls() 
{
    std::cout << "Titi ou toto ? ou encore tata\n";
    return 3.14;
}

void die_pls() 
{
    std::cout << "Maxime je veux crever ! stp\n";
}

