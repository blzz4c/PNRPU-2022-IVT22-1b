using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Runtime.Intrinsics.X86;
using System.Threading.Channels;

namespace ThirdLabDiscrete
{
    internal class Program
    {
        static void Main()
        {
            string[] foundation4 =
            {
                "0000",
                "0001",
                "0010",
                "0011",
                "0100",
                "0101",
                "0110",
                "0111",
                "1000",
                "1001",
                "1010",
                "1011",
                "1100",
                "1101",
                "1110",
                "1111"
            };
            string vector;
            string rootProject = Directory.GetParent(Directory.GetCurrentDirectory()).Parent.Parent.FullName;
            string filePath;
            for (int i = 1; i <= 1; i++)
            {
                if (i != 1)
                {
                    Console.WriteLine('\n');
                }
                filePath = rootProject + $@"\Tests\v{i}.txt";
                vector = ReadVector(filePath);
                if (vector.Length == 16)
                {
                    Console.WriteLine("Таблица истинности:");
                    WriteIstinaTable(foundation4, vector);
                    var ParsedFoundation = ParseFoundation(foundation4, vector);
                    Console.WriteLine("\nСДНФ:");
                    WriteDNF(ParsedFoundation);
                    List<string> bonded = Bonding(ParsedFoundation);
                    Console.WriteLine("Неполное склеивание:");
                    WriteDNF(bonded);
                    Console.WriteLine("Карта Карно:");
                    WriteKarno(vector);
                    Console.WriteLine("МДНФ:");
                    WriteDNF(StartFindMinCoverage(CreateImplicantMatrix(bonded, ParsedFoundation)));
                }
                else
                {
                    Console.WriteLine("Ошибка! Неправильная длина вектора!");
                }
            }
        }
        public static string ReadVector(string filePath)
        {
            if (!File.Exists(filePath))
            {
                throw new FileNotFoundException("Файл не найден!");
            }

            string[] lines = File.ReadAllLines(filePath);//чтение строк
            string vector = lines[0];
            return vector;
        }
        public static void WriteIstinaTable(string[] foundation4, string vector)
        {
            Console.WriteLine("+----+-+");
            Console.WriteLine("|xyzw|F|");
            Console.WriteLine("+----+-+");
            for (int i = 0; i < vector.Length; i++)
            {
                Console.WriteLine($"|{foundation4[i]}|{vector[i]}|");
            }
            Console.WriteLine("+----+-+");
        }
        public static List<string> ParseFoundation(string[] foundation, string vector)
        {
            List<string> ParsedFoundation = new();
            for (int i = 0; i < vector.Length; i++)
            {
                if (vector[i] == '1')
                {
                    string str = "";
                    for(int j = 0; j < foundation[i].Length; j++)
                    {
                        str += foundation[i][j] == '1' ? (char)('1' + j) : (char)('5' + j);
                    }
                    ParsedFoundation.Add(str);
                }
            }
            return ParsedFoundation;
        }
        public static void WriteDNF(List<string> foundation)
        {
            for (int i = 0; i < foundation.Count; i++)
            {
                for (int j = 0; j < foundation[i].Length; j++)
                {
                    if (foundation[i][j] >= '1' && foundation[i][j] <= '4') { Console.Write(" "); }
                    else if (foundation[i][j] >= '5' && foundation[i][j] <= '8') { Console.Write("_"); }
                }
                Console.Write("   ");
            }
            Console.Write("\n");
            for (int i = 0; i < foundation.Count; i++)
            {
                Console.Write(foundation[i].Replace('1', 'x').Replace('2', 'y').Replace('3', 'z').Replace('4', 'w').Replace('5', 'x').Replace('6', 'y').Replace('7', 'z').Replace('8', 'w'));
                if (i != foundation.Count - 1)
                {
                    Console.Write(" v ");
                }
            }
            Console.WriteLine("\n");
        }
        public static List<string> Bonding(List<string> foundation)
        {
            int countVar = 3;
            List<string> parsedFoundation = new();
            parsedFoundation.AddRange(foundation);
            List<string> nextfoundation = new();
            List<string> result = new();
            while (parsedFoundation.Count > 0 && countVar > 0)
            {
                bool[] isBnded = new bool[parsedFoundation.Count];
                for (int i = 0; i < parsedFoundation.Count; i++)
                {
                    for (int j = i + 1; j < parsedFoundation.Count; j++)
                    {
                        string var = "";
                        int cnt = 0;
                        for (int k = 0; k < parsedFoundation[i].Length; k++)
                        {
                            if (parsedFoundation[i][k] == '-' && parsedFoundation[j][k] != '-' || parsedFoundation[i][k] != '-' && parsedFoundation[j][k] == '-') { --cnt; }
                            if (parsedFoundation[i][k] == parsedFoundation[j][k])
                            {
                                var += parsedFoundation[i][k];
                                ++cnt;
                            }
                            else { var += '-'; }
                        }
                        
                        if (cnt == countVar)
                        {
                            isBnded[i] = isBnded[j] = true;
                            nextfoundation.Add(var);
                        }
                    }
                    if (isBnded[i] == false)
                    {
                        result.Add(parsedFoundation[i]);
                    }
                }
                parsedFoundation.Clear();
                parsedFoundation.AddRange(nextfoundation);
                parsedFoundation = parsedFoundation.Union(parsedFoundation).ToList();
                nextfoundation.Clear();
            }
            for (int i = 0; i < result.Count; i++)
            {
                result[i] = result[i].Replace("-","");
            }
            return result;
        }
        public static void WriteKarno(string vector)
        {
            Console.WriteLine("      _   ");
            Console.WriteLine("      z       z ");
            Console.WriteLine("  + - + - + - + - + _");
            Console.WriteLine($"_ | {vector[0]} | {vector[1]} | {vector[3]} | {vector[2]} | y");
            Console.WriteLine("x + - + - + - + - +");
            Console.WriteLine($"  | {vector[4]} | {vector[5]} | {vector[7]} | {vector[6]} |");
            Console.WriteLine("  + - + - + - + - + y");
            Console.WriteLine($"  | {vector[12]} | {vector[13]} | {vector[15]} | {vector[14]} |");
            Console.WriteLine("x + - + - + - + - + _");
            Console.WriteLine($"  | {vector[8]} | {vector[9]} | {vector[11]} | {vector[10]} | y");
            Console.WriteLine("  + - + - + - + - +");
            Console.WriteLine("    _           _");
            Console.WriteLine("    w     w     w");
        }
        private static Dictionary<string, List<string>> CreateImplicantMatrix(List<string> rows, List<string> columns)
        {
            Dictionary<string, List<string>> matrix = new();
            for (int i = 0; i < columns.Count; i++)
            {
                for (int j = 0; j < rows.Count; j++)
                {
                    var isContains = true;

                    for (int k = 0; k < rows[j].Length && isContains; k++)
                    {
                        isContains = columns[i].Contains(rows[j][k]);
                    }

                    if (isContains)
                    {
                        if (matrix.ContainsKey(columns[i]))
                        {
                            matrix[columns[i]].Add(rows[j]);
                        }
                        else
                        {
                            matrix[columns[i]] = new() { rows[j] };
                        }
                    }
                }
            }

            return matrix;
        }
        private static List<string> StartFindMinCoverage(Dictionary<string, List<string>> matrix)
        {
            var keys = matrix.Keys.ToArray();

            return FindMinCoverage(matrix, keys, 0, new List<string>()).ToList();
        }

        private static HashSet<string> FindMinCoverage(Dictionary<string, List<string>> matrix, string[] keys, int index, List<string> coverage)
        {
            HashSet<string> Min = new();
            for (int i = 0; i < matrix[keys[index]].Count; i++)
            {
                coverage.Add(matrix[keys[index]][i]);

                if (index < keys.Length - 1)
                {
                    var posibleMin = FindMinCoverage(matrix, keys, index + 1, coverage);

                    if (Min.Count == 0 || posibleMin.Distinct().Count() < Min.Count)
                    {
                        Min = posibleMin.ToHashSet();
                    }
                }
                else
                {
                    if (Min.Count == 0 || coverage.Distinct().Count() < Min.Count)
                    {
                        Min = coverage.ToHashSet();
                    }
                }
                coverage.RemoveAt(coverage.Count - 1);
            }

            return Min;
        }
    }
}