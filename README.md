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

