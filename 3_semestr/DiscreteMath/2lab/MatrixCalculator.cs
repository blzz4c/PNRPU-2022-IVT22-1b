using System;
using System.Security.Cryptography;

namespace MatrixCalculator
{
    internal class MatrixCalc
    {
        public static void Main()
        {
            int[,] matrix = new int[6, 6];
            string rootProject = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.Parent.FullName;
            string filePath;
            for (int i = 1; i <= 8; i++)
            {
                if (i != 1)
                {
                    Console.WriteLine('\n');
                }
                filePath = rootProject + $@"\Tests\m{i}.txt";
                matrix = ReadMatrix(filePath);
                WriteMatrix(matrix);
                Console.WriteLine("Reflexivity: " + CalcReflexivity(matrix));
                Console.WriteLine("AntiReflexivity: " + CalcAntiReflexivity(matrix));
                Console.WriteLine("Symmetric: " + CalcSymmetric(matrix));
                Console.WriteLine("AntiSymmetric: " + CalcAntiSymmetric(matrix));
                Console.WriteLine("Asymmetric: " + CalcAsymmetric(matrix));
                Console.WriteLine("Transitivity: " + CalcTransitivity(matrix));
            }
        }
        public static int[,] ReadMatrix(string filePath)
        {
            if (!File.Exists(filePath))
            {
                throw new FileNotFoundException("Файл не найден!");
            }

            string[] lines = File.ReadAllLines(filePath);//чтение строк

            const int ROWS = 6;
            const int COLS = 6;

            int[,] matrix = new int[ROWS, COLS];//инициализация

            for (int i = 0; i < ROWS; i++)
            {
                string[] numbers = lines[i].Split(' ');
                for (int j = 0; j < COLS; j++)
                {
                    matrix[i, j] = int.Parse(numbers[j]);
                }
            }

            return matrix;
        }
        public static void WriteMatrix(int[,] matrix)
        {
            int ROWS = 6;
            int COLS = 6;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    if (j != 0)
                    {
                        Console.Write(' ');
                    }
                    Console.Write(matrix[i, j]);
                }

                Console.WriteLine();
            }
        }
        public static bool CalcReflexivity(int[,] matrix)
        {
            bool result = true;
            for (int i = 0; i < 6; i++)
            {
                result = matrix[i, i] == 1;
                if (!result) return result;
            }
            return result;
        }
        public static bool CalcAntiReflexivity(int[,] matrix)
        {
            bool result = true;
            for (int i = 0; i < 6; i++)
            {
                result = matrix[i, i] == 0;
                if (!result) return result;
            }
            return result;
        }
        public static bool CalcSymmetric(int[,] matrix)
        {
            bool result = true;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    result = matrix[i, j] == matrix[j, i];
                    if (!result) return result;
                }
            }
            return result;
        }
        public static bool CalcAntiSymmetric(int[,] matrix)
        {
            bool result = true;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (matrix[i, j] == 1 && i != j) result = matrix[i, j] != matrix[j, i];
                    if (!result) return result;
                }
            }
            return result;
        }
        public static bool CalcAsymmetric(int[,] matrix)
        {
            bool result = true;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (matrix[i,j] == 1) result = matrix[i, j] != matrix[j, i];
                    if (!result) return result;
                }
            }
            return result;
        }
        public static bool CalcTransitivity(int[,]matrix)
        {
            bool result = true;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    for (int k = 0; k < 6; k++)
                    {
                        result = matrix[i, j] >= Math.Min(matrix[i, k], matrix[k, j]);
                        if (!result) return result;
                    }
                }
            }
            return result;
        }
    }
}