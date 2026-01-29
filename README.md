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

## Bureaucrat Form (ex01)

in this exercise we implement a Form class, which we can use to assign to a bureaucrat. First we create an object with the class Form like:

    Form texForm("Tax Form", 100, 50);

100 being minimum grade for being signed and 50 minimum grade for being executed. (which we will apparently see in ex02)

After creating the Form object we use the signForm(Form &form) function to make a specific Bureaucrat sign the Form. Something like this:

    Bureaucrat joe("Joe", 50);

    joe.signForm(taxForm);

where inside the signForm function there is the function beSigned() called which does the check if the grade has the minimum requirements, if not it will throw an exception. If yes, the Form gets assigned to the Bureaucrat joe.

--------------------------------------------------------------------

## Initializing base class

Initializing a base class and the understanding behind it. At first I didn't really understand why we need to do this:

    ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery", 145, 137) {
        //some code...
    }

I do understand now, that through the inheritance of AForm and AForm being an abstract class as well - we need to construct the base class (AForm(...)) first, derived class second and then run the derived constructor body.

If we don't initalize the bas class, it's going to call "AForm" implicitly like this:

    class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(...) {
            // ❌ AForm() would be called implicitly
        }
    };

but since AForm() doesn't exist -> 💥compile error

Since our constructor looks like this: AForm(const std::string& name, int gradeToSign, int gradeToExecute), we need to initialize it like this : AForm("Shrubbery", 145, 137) if that makes sense!

Think of it as:

You **cannot build walls without a foundation**, and you **cannot change the foundation afterward**.

--------------------------------------------------------------------

## File creation

Creating a file in C++ (recap):

    #include <fstream>
    #include <iostream>

    std::ofstream outfile("file1.txt");

    outfile << "text here!" << std::endl;

    outfile.close();

ofstream ➔ creates and writes to files
ifstream ➔ reads from files
fstream ➔ a combination of ofstream and ifstream: creates, reads and writes to files (all in one)

--------------------------------------------------------------------

## Execute Form (ex02)

In this exercise class Form becomes an abstract class. We have several functions controlling several actions, so for example ➔ this function:

    virtual void executeAction() const = 0;

executes the action taken from the Form, for example the action of the "ShrubberyCreationForm" is that it creates a file and prints an ascii tree inside that file.

So this function implements the logic for that.

On the other hand this function:

    void execute(Bureaucrat const & executor);

does the error handling, makes sure to catch any errors if the code inside the try block doesn't work.

and this function:

    void executeForm(const AForm &form);

is in the Bureaucrat.hpp file, and is similar to signForm() from ex01 but for the execution. So it handles and checks if the BUreaucrat can execute the form and calls the execute function which then calls the execute action. This function also prints the necessary messages we have to print like:

    <bureaucrat> executed <form>

--------------------------------------------------------------------