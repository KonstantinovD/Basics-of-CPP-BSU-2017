#include <fstream>
#include <iostream>

void lineExpression(float varB, float varC)//If our square expression isn't square, because A member is 0
{
    if (varB != 0){
        float result = ((-varC) / varB);
        std::cout << result << std::endl;
    }
    else{
        if (varC == 0) {
            std::cout << "Any Real number is the root of the expression" << std::endl;
        }
        else{
            std::cout << "Expression has no roots" << std::endl;
        }
    }
}

void expression(std::ifstream& FIN) //Calculating the roots of square expression
{
    float result;
    float varA, 
          varB, 
          varC;
    
    if (!FIN.eof())
    {
        FIN >> varA >> varB >> varC;
    }
    
    if (varA != 0.0)
    {
        float discriminant = (varB*varB) - 4 * varA*varC;
        
        if (discriminant < 0.0)
        {
            std::cout << "Expression has no roots" << "  " << std::endl;
            return;
        }
        else if (discriminant == 0.0)
        {
            result = (-varB) / (2 * varA);
            std::cout << result << std::endl;
            return;
        }
        else
        {
            result = ((-varB) + std::sqrt(discriminant)) / (2 * varA);// + sqrt(D)
            std::cout << result << " ";
            result = ((-varB) - std::sqrt(discriminant)) / (2 * varA); // - sqrt(D)
            std::cout << result << std::endl;
            return;
        }	
    }
    else{
        lineExpression(varB, varC);
        return;
    }
    
    return;
}





void main()
{
    std::ifstream FIN;
    FIN.open("test2.txt");

    int numberOfTests;
    FIN >> numberOfTests;
    
    for (int i = 0; i < numberOfTests; i++)
    {
        expression(FIN);
    }
    
    system("pause");
}