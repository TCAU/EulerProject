using System;
using System.Collections.Generic;
using System.IO;
class Euler017
{
    static void Main(String[] args)
    {
        Console.WriteLine(CountLettersInNumbers(1000));

        Console.Read();
    }

    private static int CountLettersInNumbers(int p)
    {
        int sum = 0, index = 1;

        while (index <= p)
        {
            sum += CountLettersInNumber(index);
            index++;
        }

        return sum;
    }

    private static int CountLettersInNumber(int index)
    {
        string str = "";

        int length = index.ToString().Length;

        bool includeAnd = (length > 2 && Convert.ToInt32(index.ToString().Substring(1, length-1)) > 0);

        if (index >= 1000)
        {
            str += getTextFromSingleOrDoubleDigitNumber(index / 1000) + "thousand";

            index = index % 1000;

            if (includeAnd && index %100 == 0)
            {
                str += "and"; 
            }
        }

        if (index >= 100)
        {
            str += getTextFromSingleOrDoubleDigitNumber(index/100) + "hundred";

            index = index % 100;

            if (includeAnd)
            {
                str += "and";
            }
        }

        if (index < 100)
        {
            str += getTextFromSingleOrDoubleDigitNumber(index) ;

            index = index % 100;
        }

        //Console.WriteLine(str);

        return str.Length;
    }

    private static string getTextFromSingleOrDoubleDigitNumber(int p)
    {
        string s = "";


        if (p > 19)
        {
            int tens = p / 10;
            p  = p % 10;
            
            switch (tens)
            {
                case 2:
                    s += "twenty";
                    break;
                case 3:
                    s += "thirty";
                    break;
                case 4:
                    s += "forty";
                    break;
                case 5:
                    s += "fifty";
                    break;
                case 6:
                    s += "sixty";
                    break;
                case 7:
                    s += "seventy";
                    break;
                case 8:
                    s += "eighty";
                    break;
                case 9:
                    s += "ninety";
                    break;
                default:
                    throw new Exception(p.ToString());
            }
        }

        switch (p)
        {
            case 0:
                break;
            case 1: 
                s += "one";
                break;
            case 2:
                s += "two";
                break;
            case 3:
                s += "three";
                break;
            case 4:
                s += "four";
                break;
            case 5:
                s += "five";
                break;
            case 6:
                s += "six";
                break;
            case 7:
                s += "seven";
                break;
            case 8:
                s += "eight";
                break;
            case 9:
                s += "nine";
                break;
            case 10:
                s += "ten";
                break;
            case 11:
                s += "eleven";
                break;
            case 12:
                s += "twelve";
                break;
            case 13:
                s += "thirteen";
                break;
            case 14:
                s += "fourteen";
                break;
            case 15:
                s += "fifteen";
                break;
            case 16:
                s += "sixteen";
                break;
            case 17:
                s += "seventeen";
                break;
            case 18:
                s += "eighteen";
                break;
            case 19:
                s += "nineteen";
                break;
            default:
                throw new Exception(p.ToString());
        }

        return s;
    }


}
