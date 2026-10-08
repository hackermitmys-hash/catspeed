using System;

namespace PointIndexer
{
    class PointIndexer
    {
        private int x;
        private int y;

        public int this[int index]
        {
            get
            {
                switch (index)
                {
                    case 0:
                        return x;
                    case 1:
                        return y;
                    default:
                        return 0;
                }
            }
            set
            {
                switch (index)
                {
                    case 0:
                        this.x = value;
                        break;
                    case 1:
                        this.y = value;
                        break;
                }
            }
        }

        public PointIndexer()
        {
            this.x = 10;
            this.y = 10;
        }

        public PointIndexer(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    class Program
    {
        static void Main()
        {
            PointIndexer point1 = new PointIndexer();
            PointIndexer point2 = new PointIndexer(20, 10);

            Console.WriteLine("Point 1 coordinates: ({0},{1})", point1[0], point1[1]);
            Console.WriteLine("Point 2 coordinates: ({0},{1})", point2[0], point2[1]);
        }
    }
}