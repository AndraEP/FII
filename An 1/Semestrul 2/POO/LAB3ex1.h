class BigNumber 
{
  private:
    char Number[256];
    unsigned int CharactersCount;
  
  public:
    BigNumber(); //constructor implicit (creaza numarul 0 [field-ul Number contine "0", field-ul CharactersCount contine valoarea 1 - un caracter]
    BigNumber (int value); 
    BigNumber (const char *number); 
    BigNumber (const BigNumber &number); 
    bool Set (int value);
    bool Set (const char *number);
    BigNumber operator + (const BigNumber &number);
    BigNumber operator * (const BigNumber &number); 
    BigNumber operator - (const BigNumber &number);
    BigNumber operator / (const BigNumber &number); 
    friend bool operator == (const BigNumber &n1, const BigNumber &n2);
    friend bool operator != (const BigNumber &n1, const BigNumber &n2);
    friend bool operator <  (const BigNumber &n1, const BigNumber &n2);
    friend bool operator >  (const BigNumber &n1, const BigNumber &n2);
    friend bool operator >= (const BigNumber &n1, const BigNumber &n2);
    friend bool operator <= (const BigNumber &n1, const BigNumber &n2);
    operator int();
    int operator [] (unsigned int index); //returneaza caracterul de pe pozitia index sau \0 in rest
    BigNumber operator () (unsigned int start, unsigned int end); //returneaza numarul de la caracterul dat de pozitia "start" pana la caracterul dat de pozitia "end" sau "0" daca start/end nu sunt valide.
};
