using System;

public delegate void Calculation(decimal val1, decimal val2, ref decimal result);

namespace DelegateExample
{
    public class DelegateExample
    {
        public Calculation Mycalc1;
        public Calculation Mycalc2;

        public static void Add(decimal add1, decimal add2, ref decimal result)
        {
            result = add1 + add2;
            Console.WriteLine("add {0} + {1} = {2}", add1, add2, result);
        }

        public static void Sub(decimal sub1, decimal sub2, ref decimal result)
        {
            result = sub1 - sub2;
            Console.WriteLine("sub {0} - {1} = {2}", sub1, sub2, result);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            decimal result = 0.0m;
            DelegateExample del = new DelegateExample();

            del.Mycalc1 = new Calculation(DelegateExample.Add);
            del.Mycalc2 = new Calculation(DelegateExample.Sub);

            del.Mycalc1(10.5m, 5.2m, ref result);
            del.Mycalc2(10.5m, 5.2m, ref result);
        }
    }
}