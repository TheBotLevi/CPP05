# Readme CPP05

## Custom Exception handling

1. try-catch block

C++ has a builtin feature that handles exceptions using a try and catch block. It is an exception handling mechanism where the code that may cause an exception is placed inside the **try block** and the code that handles this exception is placed in the **catch block**

    try {
        // some code that might throw an exception
    }
    catch (ExceptionType& e) {
        // the code that handles the exception
    }

when you declare a variable inside a **try** block it only exits inside that block. So how do you delete leaks, when you call delete inside the catch block it will say something like "identifier "b" is undefined" so the solution is:

you create the pointer **outside** the try-catch block and initialize it with NULL. Then inside the try block you assign a class to it, something like this:

    int main() {
        Bureaucrat *bureaucrat = NULL;
        try {
            bureaucrat = new Bureaucrat("name", 30);
            ...
            delete bucreaucrat;
        }
        catch {
            delete bureaucrat;
        }
    }

So now even if it's a valid grade or not, it will delete the instance and you will have no memory leaks.

-------------------------------------------------------------------

## What are nested classes?

Nested classes are simply said, a class which is declared **inside** another class like so:

    class myClass {
        ...

        class myNestedClass {
            ...
        };
    };

to access a class in the nested class you do this:

    void myClass::myNestedClass::myFunction(char param, ...) {
        ...
    }

-------------------------------------------------------------------

## Exception specifications

Exception specifications is a feature in C++ that allows the user to specify if the function may or may not exit by an exception, by using an exception specification.

It used to be: (C++11)

    class myCass {
        public:
            virtual const char* what() const noexcept override;
    }

not it's: (C++98)

    class myCass {
        public:
            virtual const char* what() const throw();
    }

--------------------------------------------------------------------

## Bureaucrat Form

