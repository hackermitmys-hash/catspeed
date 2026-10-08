using System;

namespace JaggedArray
{
    class Program
    {
        static void Main()
        {
            int[][] myArray = new int[2][];
            myArray[0] = new int[5] { 1, 3, 5, 7, 9 };
            myArray[1] = new int[4] { 2, 4, 6, 8 };

            for (int row = 0; row < myArray.Length; row++)
            {
                Console.Write("Element({0}):", row);
                for (int col = 0; col < myArray[row].Length; col++)
                {
                    Console.Write("{0}{1}", myArray[row][col],
                        col == myArray[row].Length - 1 ? "" : " ");
                }
                Console.WriteLine();
            }
        }
    }
}