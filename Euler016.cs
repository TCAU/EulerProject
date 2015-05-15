using System;
using System.Collections.Generic;
using System.Linq;

class Euler016
{
    static void Main(string[] args)
    {            
        Console.WriteLine(PowerDigitSum(1000).ToString());
        Console.Read();
    }

    public static int PowerDigitSum (int reps)
    {
        List<int> List1 = new List<int>(){2};

        while (reps > 1)
        {
            for(int x = 0; x < List1.Count(); x++)
            {
                List1[x]*=2;
            }

            int lastIndex = List1.Count() - 1;

            for (int x = lastIndex; x >= 0 ; x--)
            {
                int value = List1[x];
                if (value  > 9 && x == lastIndex )
                {
                    List1[x] = value % 10;
                    List1.Add(value / 10);
                }
                else if (value  > 9)
                {
                    List1[x] = value % 10;
                    List1[x+1] += value / 10;
                }
            }

            reps--;                
        }

        int sum = 0;

        foreach(int x in List1)
            sum += x;

        return sum;
    }
}
