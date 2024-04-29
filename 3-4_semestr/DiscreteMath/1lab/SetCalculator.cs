namespace DIff
{
    class MainProgram 
    {
        static public void Main()
        {
            Console.WriteLine("Размер универсума\n");
            Console.WriteLine("Введите левую границу: ");
            int LB = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите правую границу: ");
            int RB = Convert.ToInt32(Console.ReadLine());

            pSet[] sets = { new(), new(), new() };
            pSet RESULT;
            int selSet, selSet2; //selected set
            bool isQuit = false;

            char wrd;
            int a;

            while (!isQuit)
            {
                Console.WriteLine("Введите команду:\n1. Создать множество\n" +
                    "2. Пересечение\n" +
                    "3. Объединение\n" +
                    "4. Разница\n" +
                    "5. Симметрическая разница\n" +
                    "6. Дополнение\n" +
                    "7. Удаление числа из множества\n" +
                    "8. Добавление числа во множество\n" +
                    "9. Удаление всех элементов множества.\n" +
                    "10. Вывод всех множеств\n" +
                    "q.Выход");
                a = Convert.ToInt32(Console.ReadLine());

                switch (a)
                {
                    case 1:
                        selSet = InputSet();
                        sets[selSet] = sets[selSet].CreateSet(LB,RB);
                        wrd = 'A';
                        for (int i = 0; i < 3; i++)
                        {
                            Console.Write($"{wrd} = ");
                            wrd++;
                            sets[i].WriteSet();
                        }
                        break;
                    case 2:
                        selSet = InputSet();
                        selSet2 = InputSet();
                        RESULT = sets[selSet].Intersection(sets[selSet2]);
                        RESULT.WriteSet();
                        break;
                    case 3:
                        selSet = InputSet();
                        selSet2 = InputSet();
                        RESULT = sets[selSet].Union(sets[selSet2]);
                        RESULT.WriteSet();
                        break;
                    case 4:
                        selSet = InputSet();
                        selSet2 = InputSet();
                        RESULT = sets[selSet].Difference(sets[selSet2]);
                        RESULT.WriteSet();
                        break;
                    case 5:
                        selSet = InputSet();
                        selSet2 = InputSet();
                        RESULT = sets[selSet].SymmetricDifference(sets[selSet2]);
                        RESULT.WriteSet();
                        break;
                    case 6:
                        selSet = InputSet();
                        RESULT = sets[selSet].Addition(LB, RB);
                        RESULT.WriteSet();
                        break;
                    case 7:
                        selSet = InputSet();
                        Console.Write("Введите число: ");
                        int delNumber = Convert.ToInt32(Console.ReadLine());
                        sets[selSet].Remove(delNumber);
                        sets[selSet].WriteSet();
                        break;
                    case 8:
                        selSet = InputSet();
                        Console.Write("Введите число: ");
                        int addNumber = Convert.ToInt32(Console.ReadLine());
                        sets[selSet].Add(addNumber);
                        sets[selSet].WriteSet();
                        break;
                    case 9:
                        selSet = InputSet();
                        sets[selSet].Clear();
                        sets[selSet].WriteSet();
                        break;
                    case 10:
                        wrd = 'A';
                        for (int i = 0; i < 3; i++)
                        {
                            Console.Write($"{wrd} = ");
                            wrd++;
                            sets[i].WriteSet();
                        }
                        break;
                    default:
                        isQuit = true;
                        break;
                }
            }
        }
        static public int InputSet()
        {
            Console.WriteLine("Введите множество (0-A, 1-B, 2-C)");
            int result = Convert.ToInt32(Console.ReadLine());
            return result;
        }

    }

    internal class pSet
    {

        List<int> set = new List<int> { };
        
        public void WriteSet()
        {
            set.Sort();
            Console.Write("{");
            if (set.Count > 0)
            {
                Console.Write(set[0]);
            }
            for (var i = 1; i < set.Count; i++)
            {
                Console.Write($", {set[i]}");
            }
            Console.WriteLine("}\n");
        }
        public void Add(int value)
        {
            
            if (!set.Contains(value))
            {
                set.Add(value);
            }
        }
        public void Remove(int value) 
        {
            if(set.Contains(value))
            {
                set.Remove(value);
            }
        }
        public pSet CreateSet(int LB, int RB)
        {
            Console.WriteLine("Введите команду:\n +" +
                "1. Создать множество из случайных элементов\n" +
                "2. Создать множество в диапазоне(ЛевГраница;ПравГраница)\n" +
                "3. Создать множество вручную\n" +
                "4. Создать множество по условию");
            pSet result = new();
            int select = Convert.ToInt32(Console.ReadLine());
            int n;
            int UniversumRange = RB - LB + 1;
            switch (select)
            {
                case 1:
                    Console.WriteLine("Введите количество элементов: ");
                    n = Convert.ToInt32(Console.ReadLine());
                    if (n > UniversumRange)
                    {
                        Console.WriteLine("Ошибка! Количество элементов превысило универсум множетства!");
                        break;
                    }
                    int cnt = 0;
                    Random rnd = new();
                    while (cnt < n)
                    {
                        int x = rnd.Next(LB, RB);
                        if (!result.set.Contains(x))
                        {
                            result.set.Add(x);
                            cnt++;
                        }
                    }
                    break;
                case 2:
                    Console.WriteLine("Введите левую границу: ");
                    int LBi = Convert.ToInt32(Console.ReadLine());
                    if (LBi < LB) {
                        Console.WriteLine("Ошибка! Левая граница меньше левой границы универсума!");
                        break;
                    } //throw

                    Console.WriteLine("Введите правую границу: ");
                    int RBi = Convert.ToInt32(Console.ReadLine());
                    if (RBi > RB) {
                        Console.WriteLine("Ошибка! Правая граница больше правой границы универсума!");
                        break;
                    } //throw

                    while (LBi <= RBi)
                    {
                        result.set.Add(LBi);
                        LBi++;
                    }
                    break;
                case 3:
                    Console.WriteLine("Введите количество элементов которые вы хотите добавить: ");
                    n = Convert.ToInt32(Console.ReadLine());
                    if (n > UniversumRange)
                    {
                        Console.WriteLine("Ошибка! Количество элементов превысило универсум множетства!");
                        break;
                    }
                    for (int i = 0; i < n; i++)
                    {
                        Console.WriteLine("Введите элемент: ");
                        int value = Convert.ToInt32(Console.ReadLine());
                        if (!set.Contains(value))
                        {
                            result.set.Add(value);
                        }
                    }
                    break;
                case 4:
                    Console.WriteLine("Введите команду:\n" +
                        "1. Все числа положительные\n" +
                        "2. Все числа отрицательные\n" +
                        "3. Все числа четные\n" +
                        "4. Все числа нечетные\n" +
                        "5. Все числа кратные N");
                    select = Convert.ToInt32(Console.ReadLine());
                    if (select == 1)
                    {
                        for (int i = 0; i < RB; i++)
                        {
                            if (!result.set.Contains(i))
                            {
                                result.set.Add(i);
                            }
                        }
                    }
                    if (select == 2)
                    {
                        for (int i = LB; i < 0; i++)
                        {
                            if (!result.set.Contains(i))
                            {
                                result.set.Add(i);
                            }
                        }
                    }
                    if (select == 3)
                    {
                        while (LB <= RB)
                        {
                            if (LB % 2 == 0) 
                            { 
                                result.set.Add(LB);
                            }
                            LB++;
                        }
                    }
                    if (select == 4)
                    {
                        while (LB <= RB)
                        {
                            if (Math.Abs(LB % 2) == 1)
                            {
                                result.set.Add(LB);
                            }
                            LB++;
                        }
                    }
                    if (select == 5)
                    {
                        Console.WriteLine("Введите число: ");
                        int N = Convert.ToInt32(Console.ReadLine());
                        if (N > UniversumRange)
                        {
                            Console.WriteLine("Ошибка! Количество элементов превысило универсум множетства!");
                            break;
                        }
                        while (LB <= RB)
                        {
                            if (LB % N == 0)
                            {
                                result.set.Add(LB);
                            }
                            LB++;
                        }
                    }
                    break;
            }
            return result;
        }
        public pSet Intersection(pSet B)
        {
            pSet result = new();
            foreach (int x in set)
            {
                if (B.set.Contains(x))
                {
                    result.set.Add(x);
                }
            }
            return result;
        }

        public pSet Union(pSet B)
        {
            pSet result = new();
            foreach(int x in set)
            {
                result.set.Add(x);
            }
            foreach (int x in B.set)
            {
                result.set.Add(x);
            }
            result.set = result.set.Distinct().ToList();
            return result;
        }

        public pSet Difference(pSet B)
        {
            pSet result = new();
            foreach(int x in set)
            {
                if (!B.set.Contains(x))
                {
                    result.set.Add(x);
                }
            }
            return result;
        }

        public pSet SymmetricDifference(pSet B)
        {
            pSet result = new();
            foreach (int x in set)
            {
                result.set.Add(x);
            }
            foreach (int x in B.set)
            {
                result.set.Add(x);
            }
            foreach (int x in set)
            {
                if (B.set.Contains(x))
                {
                    result.set.Remove(x);
                    result.set.Remove(x);
                }
            }
            return result;
        }

        public pSet Addition(int lb, int rb)
        {
            pSet result = FullSet(lb, rb);
            foreach (int x in set)
            {
                if (result.set.Contains(x))
                {
                    result.set.Remove(x);
                }
            }
            return result;
        }
        public pSet FullSet(int lb, int rb)
        {
            pSet result = new();
            while (lb <= rb)
            {
                result.set.Add(lb);
                lb++;
            }
            return result;
        }
        public void Clear()
        {
            set.Clear();
        }
    }
}