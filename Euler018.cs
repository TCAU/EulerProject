using System;

/*
 * Maximum path sum I
Problem 18
Published on Friday, 31st May 2002, 06:00 pm; Solved by 84843; Difficulty rating: 5%

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 */

class ProjectEuler18
{
    static void Main(string[] args)
    {
        int[][] arr =    new int[15][];
             
		arr[0] = new int[] {75};
		arr[1] = new int[] {95,64};
		arr[2] = new int[] {17,47,82};
		arr[3] = new int[] {18,35,87,10};
		arr[4] = new int[] {20,04,82,47,65};
		arr[5] = new int[] {19,01,23,75,03,34};
		arr[6] = new int[] {88,02,77,73,07,63,67};
		arr[7] = new int[] {99,65,04,28,06,16,70,92};
		arr[8] = new int[] {41,41,26,56,83,40,80,70,33};
		arr[9] = new int[] {41,48,72,33,47,32,37,16,94,29};
		arr[10] = new int[] {53,71,44,65,25,43,91,52,97,51,14};
		arr[11] = new int[] {70,11,33,28,77,73,17,78,39,68,17,57};
		arr[12] = new int[] {91,71,52,38,17,14,91,43,58,50,27,29,48};
		arr[13] = new int[] {63,66,04,68,89,53,67,30,73,16,69,87,40,31};
		arr[14] = new int[] {04,62,98,27,23, 9,70,98,73,93,38,53,60,04,23};

        Console.WriteLine(GetMaximumPath(arr).ToString());
        Console.Read();
	}

    private static int GetMaximumPath(int[][] arr)
    {
        int[] temp = new int[arr[arr.Length - 1].Length];

        for (int i = arr.Length-1; i >0 ; i--)
        {
            for (int j = 0; j < arr[i].Length - 1; j++)
            {
                temp[j] = Math.Max(arr[i][j], arr[i][j + 1]);
            }

            for (int j = 0; j < arr[i].Length-1; j++)
            {
                arr[i-1][j] += temp[j];
            }
        }
        return arr[0][0];
    }
}

