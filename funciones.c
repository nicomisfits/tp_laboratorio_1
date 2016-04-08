float Sum(float numb1, float numb2)//Implementacion de la suma (parametros actuales)
{
    float sumResult;
    sumResult = numb1 + numb2;
    return sumResult;
}

float Rest(float numb1, float numb2)//Implementacion de la resta (parametros actuales)
{
    float restResult;
    restResult = numb1 - numb2;
    return restResult;
}

float Div(float numb1, float numb2)//Implementacion de la division (parametros actuales)
{
    float divResult;
    divResult = numb1 / numb2;
    return divResult;
}

float Multiplication(float numb1, float numb2)//Implementacion de la multiplicacion (parametros actuales)
{
    float mulResult;
    mulResult = numb1 * numb2;
    return mulResult;
}

float Factorial(float numb1)//Implementacion del factorial (parametros actuales)
{
    float factResult;
    if(numb1 == 0)
    {
        return 1;
    }
    else
    {
        factResult = numb1 * Factorial(numb1-1);
        return factResult;
    }
    return factResult;
}
