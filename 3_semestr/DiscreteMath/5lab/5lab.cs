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
            int[,] matrix = new int[10, 10];
            string rootProject = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.Parent.FullName;
            string filePath;
            for (int i = 1; i <= 4; i++)
            {
                if (i != 1)
                {
                    Console.WriteLine('\n');
                }
                filePath = rootProject + $@"\Tests\g1{i}.txt";
                matrix = ReadMatrix(filePath);
                WriteMatrix(matrix);
                Console.WriteLine(" ");
                int[,] RAMatrix = CreateReachAbilityMatrix(matrix);
                WriteMatrix(RAMatrix);
                WriteConnectivityComponents(RAMatrix);
            }
        }
        static int[,] ReadMatrix(string filePath)
        {
            if (!File.Exists(filePath))
            {
                throw new FileNotFoundException("Файл не найден!");
            }

            string[] lines = File.ReadAllLines(filePath);//чтение строк
            int M = lines.Length;
            int[,] matrix = new int[M, M];//инициализация

            for (int i = 0; i < M; i++)
            {
                string numbers = lines[i].Replace(" ", "");
                for (int j = 0; j < M; j++)
                {
                    matrix[i, j] = int.Parse(numbers[j].ToString());
                }
            }
            return matrix;
        }
        static int[,] CreateReachAbilityMatrix(int[,] matrix)
        {
            var resultMatrix = new int[matrix.GetLength(0), matrix.GetLength(1)];
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                resultMatrix[i, i] = 1;
            } // создание единичной матрицы
            var nextMatrix = (int[,])matrix.Clone();
            resultMatrix = MatrixAddition(resultMatrix, nextMatrix);
            for (int i = 0; i < matrix.GetLength(0) - 2; i++)
            {
                nextMatrix = MatrixMultiply(nextMatrix, matrix);
                resultMatrix = MatrixAddition(resultMatrix, nextMatrix);
            }
            return resultMatrix;
        }
        static int[,] MatrixAddition(int[,] first, int[,] second)
        {
            var resultMatrix = new int[first.GetLength(0), first.GetLength(1)];
            for (int i = 0; i < first.GetLength(0); i++)
            {
                for (int j = 0; j < second.GetLength(0); j++)
                {
                    resultMatrix[i, j] = first[i,j] + second[i,j];
                }
            }
            return resultMatrix;
        }
        static int[,] MatrixMultiply(int[,] first, int[,] second)
        {
            var resultMatrix = new int[first.GetLength(0), second.GetLength(1)];
            for (int i = 0; i < first.GetLength(0); i++)
            {
                for (int j = 0; j < second.GetLength(0); j++)
                {
                    resultMatrix[i, j] = 0;
                    for (int k = 0; k < second.GetLength(1); k++)
                    {
                        resultMatrix[i, j] += first[i, k] * second[k, j];
                    }
                }
            }
            return resultMatrix;
        }
        static void WriteMatrix(int[,] matrix)
        {
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    if (j != 0)
                    {
                        Console.Write('\t');
                    }
                    Console.Write(matrix[i, j]);
                }

                Console.WriteLine();
            }
        }
        static void WriteConnectivityComponents(int[,] matrix)
        {
            int j;
            Console.Write("Компоненты связности: ");
            for (int i = 0; i < matrix.GetLength(0);)
            {
                Console.Write('{');
                for (j = i; j != matrix.GetLength(0) && matrix[j,i] > 0; ++j)
                {
                    Console.Write((char)('A' + j));
                }
                Console.Write('}');
                i = j;
            }
        }
    }
}
