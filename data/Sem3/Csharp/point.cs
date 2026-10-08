using System;

namespace Point
{
    class Point
    {
        private int x;
        private int y;
        private static int countPoint;

        static Point()
        {
            countPoint = 0;
        }

        public Point()
        {
            this.x = 10;
            this.y = 10;
            countPoint++;
        }

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
            countPoint++;
        }

        public int GetX()
        {
            return x;
        }

        public int GetY()
        {
            return y;
        }

        public static int GetCount()
        {
            return countPoint;
        }

        static void Main()
        {
            Point point1 = new Point();
            Console.WriteLine("Count of Point Objects Created: {0}", GetCount());

            Point point2 = new Point(20, 10);
            Console.WriteLine("Point 1 coordinates: ({0},{1})", point1.GetX(), point1.GetY());
            Console.WriteLine("Point 2 coordinates: ({0},{1})", point2.GetX(), point2.GetY());
            Console.WriteLine("Count of Point Objects Created: {0}", GetCount());

            point2 = new Point(1, 1);
            Console.WriteLine("Count of Point Objects Created: {0}", GetCount());
        }
    }
}