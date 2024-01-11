using System.Numerics;
using System.Runtime.Intrinsics;

namespace _4labDiscrete
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] foundation8 =
            {
                "000",
                "001",
                "010",
                "011",
                "100",
                "101",
                "110",
                "111",
            };
            string[] foundation4 =
            {
                "00",
                "01",
                "10",
                "11",
            };
            string[] foundation2 =
            {
                "0",
                "1",
            };
            string[] vectors;
            string[] parsingFoundation;
            string rootProject = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.Parent.FullName;
            string filePath;
            for (int i = 1; i <= 1; i++)
            {
                if (i != 1)
                {
                    Console.WriteLine('\n');
                }
                filePath = rootProject + $@"\Tests\v{i}.txt";
                vectors = ReadFile(filePath);
                char[,] table = new char[vectors.Length, 5];
                bool[] checkFulness = new bool[5];
                bool isFulness = true;
                for(int j = 0; j < vectors.Length; j++)
                {
                    Console.WriteLine($"Таблица истинности v{j}");
                    if (vectors[j].Length == 8)
                    {
                        WriteIstinaTable(foundation8, vectors[j]);
                    }
                    else if (vectors[j].Length == 4)
                    {
                        WriteIstinaTable(foundation4, vectors[j]);
                    }
                    else if (vectors[j].Length == 2)
                    {
                        WriteIstinaTable(foundation2, vectors[j]);
                    }
                    else { Console.WriteLine("!!!!!Подан неправильный вектор!!!!!"); }
                }
                for (int j = 0;j < vectors.Length;j++)
                {
                    //check t0
                    table[j, 0] = CheckT0(vectors[j]);
                    //check t1
                    table[j, 1] = CheckT1(vectors[j]);
                    //check S
                    table[j, 2] = CheckS(vectors[j]);
                    //check M
                    table[j, 3] = CheckM(vectors[j]);
                    //check L
                    table[j, 4] = CheckL(vectors[j]);
                }
                WriteTable(table);
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0;  k < vectors.Length; k++)
                    {
                        if (table[k, j] == '-')
                        {
                            checkFulness[j] = true;
                        }
                    }
                }
                for (int j = 0; j < 5; j++)
                {
                    if (checkFulness[j] == false)
                    {
                        isFulness = false;
                    }
                }
                if (isFulness)
                {
                    Console.WriteLine("Система полная");
                }
                else
                {
                    Console.WriteLine("Система не полная");
                }
            }
        }
        public static void WriteTable(char[,] table)
        {
            Console.WriteLine("+ -- + -- + -- + - + - + - +");
            Console.WriteLine("|    | T0 | T1 | S | M | L |");
            Console.WriteLine("+ -- + -- + -- + - + - + - +");
            for(int i = 0; i < table.Length/5; i++)
            {
                Console.WriteLine($"| v{i} | {table[i,0]}  | {table[i, 1]}  | {table[i, 2]} | {table[i, 3]} | {table[i, 4]} |");
            }
            Console.WriteLine("+ -- + -- + -- + - + - + - +");
        }
        public static void WriteIstinaTable(string[] foundation, string vectors)
        {
            if (vectors.Length == 8)
            {
                Console.WriteLine("+---+-+");
                Console.WriteLine("|xyz|F|");
                Console.WriteLine("+---+-+");
                for (int i = 0; i < vectors.Length; i++)
                {
                    Console.WriteLine($"|{foundation[i]}|{vectors[i]}|");
                }
                Console.WriteLine("+---+-+");
            }
            if (vectors.Length == 4)
            {
                Console.WriteLine("+--+-+");
                Console.WriteLine("|xy|F|");
                Console.WriteLine("+--+-+");
                for (int i = 0; i < vectors.Length; i++)
                {
                    Console.WriteLine($"|{foundation[i]}|{vectors[i]}|");
                }
                Console.WriteLine("+--+-+");
            }
            if (vectors.Length == 2)
            {
                Console.WriteLine("+-+-+");
                Console.WriteLine("|x|F|");
                Console.WriteLine("+-+-+");
                for (int i = 0; i < vectors.Length; i++)
                {
                    Console.WriteLine($"|{foundation[i]}|{vectors[i]}|");
                }
                Console.WriteLine("+-+-+");
            }
        }
        public static string[] ReadFile(string filePath)
        {
            if (!File.Exists(filePath))
            {
                throw new FileNotFoundException("Файл не найден!");
            }

            string[] lines = File.ReadAllLines(filePath);//чтение строк
            return lines;
        }
        public static char CheckT0(string vector)
        {
            if (vector[0] == '0')
            {
                return '+';
            }
            return '-';
        }
        public static char CheckT1(string vector)
        {
            if (vector[vector.Length-1] == '1')
            {
                return '+';
            }
            return '-';
        }
        public static char CheckS(string vector)
        {
            for (int i = 0; i < vector.Length/2; i++)
            {
                if (vector[i] == vector[vector.Length-i-1]) { return '-'; }
            }
            return '+';
        }
        public static char CheckM(string vector)
        {
            for (int i = 0; i < vector.Length; i++)
            {
                if (vector[i] == '1')
                {
                    for (int j = i; j < vector.Length; j++)
                    {
                        if (vector[j] == '0') { return '-'; }
                    }
                }
            }
            return '+';
        }
        public static char CheckL(string vector)
        {
            bool[] C = new bool[vector.Length];
            if (vector.Length == 8)
            {
                C[0] = vector[0] == '1'; //0
                C[1] = C[0] ^ vector[1] == '1'; //z
                C[2] = C[0] ^ vector[2] == '1'; //y
                C[3] = C[0] ^ vector[4] == '1'; //x
                C[4] = C[0] ^ C[2] ^ C[1] ^ vector[3] == '1';//yz
                C[5] = C[0] ^ C[3] ^ C[1] ^ vector[5] == '1';//xz
                C[6] = C[0] ^ C[3] ^ C[2] ^ vector[6] == '1';//xy
                C[7] = C[0] ^ C[1] ^ C[2] ^ C[3] ^ C[4] ^ C[5] ^ C[6] ^ vector[7] == '1';//xyz
                if (C[4] == true || C[5] == true || C[6] == true || C[7] == true) { return '-'; }
            }
            if (vector.Length == 4) 
            {
                C[0] = vector[0] == '1';
                C[1] = C[0] ^ vector[1] == '1'; //y
                C[2] = C[0] ^ vector[2] == '1'; //x
                C[3] = C[0] ^ C[1] ^ C[2] ^ vector[3] == '1'; //xy
                if (C[3] == true) { return '-'; }
            }
            return '+';
        }
    }
}