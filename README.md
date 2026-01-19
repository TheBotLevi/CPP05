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

