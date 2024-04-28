using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5_DiscreteMath
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[][] matrix = new int[10][];
            string rootProject = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.Parent.FullName;
            for (int i = 1; i <= 4; i++)
            {
                if (i != 1)
                {
                    Console.WriteLine('\n');
                }
                string filePath = $@"{rootProject}\Tests\g1{i}.txt";
                matrix = ReadMatrix(filePath);
                WriteMatrix(matrix);
                Console.WriteLine(" ");
                int[][] RAMatrix = CreateReachAbilityMatrix(matrix);
                WriteMatrix(RAMatrix);
                WriteConnectivityComponents(RAMatrix);
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
        static int[][] CreateReachAbilityMatrix(int[][] matrix)
        {
            var resultMatrix = new int[matrix.Length][];
            for (int i = 0; i < matrix.Length; i++)
            {
                resultMatrix[i] = new int[matrix.Length];
                resultMatrix[i][i] = 1;
            } // создание единичной матрицы
            var nextMatrix = matrix.Select(t => t.ToArray()).ToArray();
            resultMatrix = MatrixAddition(resultMatrix, nextMatrix);
            for (int i = 0; i < matrix.Length - 2; i++)
            {
                nextMatrix = MatrixMultiply(nextMatrix, matrix);
                resultMatrix = MatrixAddition(resultMatrix, nextMatrix);
            }
            return resultMatrix;
        }
        static int[][] MatrixAddition(int[][] first, int[][] second)
        {
            var resultMatrix = new int[first.Length][];
            for (int i = 0; i < first.Length; i++)
            {
                resultMatrix[i] = new int[second.Length];
                for (int j = 0; j < second.Length; j++)
                {
                    resultMatrix[i][j] = Math.Max(first[i][j], second[i][j]);
                }
            }
            return resultMatrix;
        }
        static int[][] MatrixMultiply(int[][] first, int[][] second)
        {
            var resultMatrix = new int[first.Length][];
            for (int i = 0; i < first.Length; i++)
            {
                resultMatrix[i] = new int[second.Length];
                for (int j = 0; j < second.Length; j++)
                {
                    resultMatrix[i][j] = 0;
                    for (int k = 0; k < second.Length; k++)
                    {
                        resultMatrix[i][j] = Math.Max(resultMatrix[i][j], first[i][k] * second[k][j]);
                    }
                }
            }
            return resultMatrix;
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
        static void WriteConnectivityComponents(int[][] matrix)
        {
            Dictionary<string, List<int>> dictionary = new Dictionary<string, List<int>>();
            for (int i = 0; i < matrix.Length; i++) 
            {
                string key = string.Join("", matrix[i]);
                if (dictionary.ContainsKey(key))
                {
                    dictionary[key].Add(i);
                }
                else
                {
                    dictionary[key] = new List<int>() { i };
                }
            }
            Console.WriteLine();
            int count = 1;
            foreach (var i in dictionary.Values) 
            {
                Console.WriteLine($"{count++} компонента связности: {string.Join(" ", i.Select(x => (char)(x + 'A')))}");
            }
        }
    }
}
