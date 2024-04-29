namespace DiscreteMathLab6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[][] matrix = new int[10][];
            string rootProject = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.Parent.FullName;
            for (int i = 0; i <= 3; i++)
            {
                if (i != 0) Console.WriteLine('\n');
                string filePath = $@"{rootProject}\Tests\g2{i}.txt";
                matrix = ReadMatrix(filePath);
                WriteMatrix(matrix);
                Console.WriteLine(" ");
                WriteOstov(matrix);
            }
        }
        static void WriteOstov(int[][] matrix)
        {
            bool[] isVisited = new bool[matrix[0].Length];
            isVisited[0] = true;
            for (int i = 0; i < matrix.Length - 1; i++)
            {
                FindMin(matrix, ref isVisited);
            }
        }
        static void FindMin(int[][] matrix, ref bool[] isVisited)
        {
            int minValue = int.MaxValue;
            int minRow = 0;
            int minCol = 0;
            for(int i = 0;i < matrix.Length; i++)
            {
                if (isVisited[i])
                {
                    for (int j = 0; j < matrix[i].Length; j++)
                    {
                        if (!isVisited[j] && matrix[i][j] < minValue && matrix[i][j] != 0)
                        {
                            minValue = matrix[i][j];
                            minRow = i;
                            minCol = j;
                        }
                    }
                }
            }
            Console.WriteLine($"{minRow}->{minCol}");
            isVisited[minCol] = true;
        }
        static int[][] ReadMatrix(string fileName)
        {
            if (!File.Exists(fileName))
            {
                throw new FileNotFoundException("Файл не найден!");
            }
            return File.ReadAllLines(fileName).Select(
                t => t.Split().Select(x => int.Parse(x)).ToArray()).ToArray();
        }
        static void WriteMatrix(int[][] matrix)
        {
            for (int i = 0; i < matrix.Length; i++)
            {
                for (int j = 0; j < matrix[i].Length; j++)
                {
                    if (j != 0)
                    {
                        Console.Write('\t');
                    }
                    Console.Write(matrix[i][j]);
                }

                Console.WriteLine();
            }
        }
    }
}
        
