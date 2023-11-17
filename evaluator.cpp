//Azhar AMIR KIMANJE
//05/23/2021
//EXECUTES different functions that solve the postfix string

#include <iostream>
#include "evaluator.h"
#include <stack>
#include <string>
#include <cmath>
#include <sstream>



using std::endl;

using std::cout;

bool IsNumericDigit(string C) { // checks to make sure whichever digit i got is VAlid
    for (unsigned int i = 0; i < C.length(); i++) {
        if (!((C[i] >= '0' && C[i] <= '9') || C[i] == '.')) {
            return false;
    }
}

    return true;
}

void IsOperator(string C) { // this function was supposed to check to see whether the operators were
    std::stack<double> S;
    double operand1;
    double operand2;
    cout << "worked" ;
    if (C == "+") {//|| C == "-" || C == "*" || C == "/" || C == "^")
        S.push(operand2+ operand1);
    }else if (C== "-") S.push(operand2 - operand1);
    else if (C== "*") S.push(operand2 *  operand1);
    else if (C == "/") S.push(operand2 / operand1);
    else if (C == "^")  S.push(pow(operand2, operand1));

}
double Evaluate(const string& postfix, bool& error) { //this is where I my calculations
    std::stack<double> S;
    error = true; //beginning assumption that helped me pass my fast test

    string b;

    // for (int i = 0; i < postfix.length(); i++) {

    if (postfix.length() == 0) return -1;
    std::istringstream stk(postfix);
    getline(stk, b, ' ');

    double operand1 = 0;
    double operand2 = 0;

    //    for (int i = 0; i < postfix.length(); i++) {
    while (stk) {
         //   if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '^') {
        if (b == "+" || b == "-" || b == "*" || b == "^") {
                if (S.empty())return -1;

                operand2 = S.top();
                S.pop();

                if (S.empty())
                    return -1;
                operand1 = S.top();
                S.pop();

                //IsOperator(postfix);

                if(b==" " || b==",")
                    continue;

                else if (b == "+") { S.push(operand1 + operand2);


                } else if (b == "-") { S.push(operand1 - operand2);

                } else if (b== "*") { S.push(operand1 * operand2);

                } else if (b == "^") { S.push(pow(operand1, operand2));

                } else if (b == "/") { if (operand2 == 0) return -1;
                    S.push(operand1 / operand2);
                }
            } else if (IsNumericDigit(b)) {

            S.push(atof(b.c_str()));

            } else {
                return -1;
            }

            getline(stk, b, ' ');
    }
        if (S.empty()) return -1;
        operand1 = S.top();
        S.pop();

        error = false;
        return operand1;

}





//else if (IsOperator(postfix[i]) == '-') S.push(operand1 - operand2);
//    else if (IsOperator(postfix[i]) == '*') S.push(operand1 * operand2);
//   else if (IsOperator(postfix[i]) == '/') {
//       if (operand2 == 0) return -1;
//         S.push(operand1 / operand2);
//    } else if (IsOperator(postfix[i])== '^') S.push(pow(operand1, operand2));
//   }








    /*
        // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(postfix[i])) {

            // Pop two operands.
           double operand2 = S.top(); S.pop();
            double operand1 = S.top(); S.pop();

            // Perform operation
            int result = PerformOperation(postfix[i], operand1, operand2);
            //Push back result of operation on stack.
            S.push(result);
        }
        else if(IsNumericDigit(postfix[i])){


            // Extract the numeric operand from the string
            // Keep incrementing i as long as you are getting a numeric digit.
            int operand = 0;
            while(i<postfix.length() && IsNumericDigit(postfix[i])) {
                // For a number with more than one digits, as we are scanning from left to right.
                // Everytime , we get a digit towards right, we can multiply current total in operand by 10
                // and add the new digit.
                operand = (operand*10) + (postfix[i] - '0');
                i++;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
            // decrement i because it will be incremented in increment section of loop once again.
            // We do not want to skip the non-numeric character by incrementing i twice.
            i--;

            // Push operand on stack.
            S.push(operand);
        }



    }
    // If expression is in correct format, Stack will finally have one element. This will be the output.
    return S.top();
	//return -1;
} */
    //I worked with