using System;

class Program
{
    static void Main()
    {
        double[] array1 = { 10, 5, 2, 8, 4 };
        double[] array2 = { 2, 1, 0, 4, 2 };

        try
        {
            PerformElementwiseDivision(array1, array2);
        }
        catch (DivideByZeroException)
        {
            Console.WriteLine("Error: Cannot perform division, as there is an attempt to divide by zero.");
        }
        catch (IndexOutOfRangeException)
        {
            Console.WriteLine("Error: Arrays must have the same length for element-wise division.");
        }
        catch (Exception)
        {
            Console.WriteLine("An unexpected error occurred.");
        }
    }

    static void PerformElementwiseDivision(double[] array1, double[] array2)
    {
        if (array1.Length != array2.Length)
        {
            throw new IndexOutOfRangeException();
        }

        for (int i = 0; i < array1.Length; i++)
        {
            try
            {
                double result = CheckDivision(array1[i], array2[i]);
                Console.WriteLine($"{array1[i]} / {array2[i]} = {result}");
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine($"Error at index {i}: Cannot divide by zero.");
            }
        }
    }

    static double CheckDivision(double dividend, double divisor)
    {
        if (divisor == 0)
        {
            throw new DivideByZeroException();
        }

        return dividend / divisor;
    }
}