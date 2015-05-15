/*
Lattice paths
Problem 15

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

https://projecteuler.net/project/images/p015.gif

How many such routes are there through a 20×20 grid?

*/

using System;

class Euler015
    {

        public static void Main(string[] args)
        {
            // length and width parameters must be nodes and not blocks
            Console.WriteLine(CalculatePaths(21, 21).ToString());
            Console.Read();
        }


        public static double CalculatePaths(int length, int width)
        {
            double[,] box = new double[length, width];

            if (length < 1 || width < 1)
            {
                return 0;
            }

            for (int i = 0; i < length; i++)
                box[i , 0] = 1;

            for (int i = 0; i < width; i++)
                box[0 , i] = 1;

            for (int i = 1; i < length; i++)
                for (int j = 1; j < width; j++)
                    box[i, j] = box[i - 1, j] + box[i, j - 1];

            //for (int i = 0; i < length; i++)
            //{
            //    for (int j = 0; j < width; j++)
            //    {
            //        Console.Write(box[i, j] + " ");
            //    }
            //    Console.WriteLine();
            //}

            return box[length-1,width-1];
        }
    }

