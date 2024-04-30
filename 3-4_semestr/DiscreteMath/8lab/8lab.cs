namespace DiscreteMathLab8
{
    internal class Program
    {
        static void Main()
        {
            RunStateMachine();
        }

        static void RunStateMachine()
        {
            int currentState = 0;
            int[,] automat = new int[4, 3] 
            {
                {0, 0, 0},
                {0, 0, 0},
                {1, 2, 1},
                {0, 0, 0}
            };

            int i;
            while ((i = Console.In.Read()) != 13)
            {
                currentState = automat[i - 97, currentState];
            }

            if (currentState == 1)
            {
                Console.WriteLine("Слово принадлежит данному языку");
            }
            else
            {
                Console.WriteLine("Слово не принадлежит данному языку");
            }
            Console.ReadLine();
        }
    }
}