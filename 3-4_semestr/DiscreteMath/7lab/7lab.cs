namespace DiscreteMathLab7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[][] matrix = new int[10][];
            string rootProject = Directory.GetParent(Directory.GetCurrentDirectory())!.Parent!.Parent!.FullName;
            for (int i = 1; i <= 3; i++)
            {
                if (i != 1) Console.WriteLine('\n');
                string filePath = $@"{rootProject}\Tests\g3{i}.txt";
                matrix = ReadMatrix(filePath);
                WriteMatrix(matrix);
                Console.WriteLine(" ");
                Console.WriteLine($"Количество цветов графа: {GetCountColorsGraph(matrix)}");
            }
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
        public static int GetCountColorsGraph(int[][] matrix)
        {
            Dictionary<int, List<int>> unconnectedVertices = [];
            for (int i = 0; i < matrix.Length; i++)
            {
                unconnectedVertices[i] = [];
                for (int j = 0; j < matrix[i].Length; j++)
                {
                    if (matrix[i][j] == 0 && i != j)
                    {
                        unconnectedVertices[i].Add(j);
                    }
                }
            }

            unconnectedVertices = unconnectedVertices.OrderBy(t => t.Value.Count).Select(
               t => (t.Key, t.Value.OrderBy(
                   x => unconnectedVertices[x].Count).ToList())).ToDictionary();

            List<List<int>> paintedGroups = [];
            while (unconnectedVertices.Count != 0)
            {
                List<int> painted = [unconnectedVertices.First().Key];
                List<int> possibleVerticesToPaint = unconnectedVertices.First().Value;
                while (possibleVerticesToPaint.Count != 0)
                {
                    int firstPainted = possibleVerticesToPaint[0];
                    if (!unconnectedVertices.ContainsKey(firstPainted))
                    {
                        possibleVerticesToPaint.Remove(firstPainted);
                        continue;
                    }

                    possibleVerticesToPaint = possibleVerticesToPaint.Where(
                        t => unconnectedVertices.ContainsKey(t) &&
                        unconnectedVertices[t].Contains(firstPainted)).ToList();

                    unconnectedVertices.Remove(firstPainted);
                    painted.Add(firstPainted);
                }
                unconnectedVertices.Remove(unconnectedVertices.First().Key);
                paintedGroups.Add(painted);
            }

            foreach (var i in paintedGroups)
            {
                for (int j = 0; j < i.Count - 1; j++)
                {
                    for (int k = j + 1; k < i.Count; k++)
                    {
                        if (matrix[i[j]][i[k]] != 0)
                        {
                            return -1;
                        }
                    }
                }
            }

            return paintedGroups.Count;
        }
    }
}
