using System;

namespace JaggedArray;

class Program

{

 static void Main()

 {

 // Declare and initialize a jagged array with two rows.

 // Note that the second dimension is not specified initially.

 int[][] myArray = new int[2][];

 // Initialize the first row with an array of 5 integers.

 myArray[0] = new int[5] { 1, 3, 5, 7, 9 };

 // Initialize the second row with an array of 4 integers.

 myArray[1] = new int[4] { 2, 4, 6, 8 };

 // Loop through each row of the jagged array.

 for (int row = 0; row < myArray.Length; row++)

 {

 // Print the row number.

 Console.Write("Element({0}):", row);

 // Loop through each element in the current row.

 for (int col = 0; col < myArray[row].Length; col++)

 {

 // Print the current element.

 Console.Write("{0}{1}", myArray[row][col],

 col == myArray[row].Length - 1 ? "" : " ");

 }

 // Move to the next line after printing all elements of the current row.

 Console.WriteLine();

 }

 }

}
