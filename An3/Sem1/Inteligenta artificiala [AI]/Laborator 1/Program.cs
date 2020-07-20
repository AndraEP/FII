using System;
using System.Collections.Generic;

namespace Lab1Remake
{
    class Program
    {
        static void Main(string[] args)
        {
            int misionari = 3;
            int canibali = 3;
            int barca = 2;
            State s = new State(barca, misionari, canibali);

            Generate possibilities = new Generate();
            possibilities.Initialization(barca, misionari, canibali, possibilities);
            //possibilities.GetAll(possibilities);
            RandomStrategy(s, possibilities);
        }

        public static void RandomStrategy(State s, Generate possibilities)
        {
            List<State> statesList = new List<State>();
            int misMoved, canMoved;
            State savedInitialState = s;
            //Console.WriteLine("NewState: \n" + savedInitialState.ToString(savedInitialState)+"\n\n");
            int runs = 0;
            int max_runs = 5;
            while (!s.isFinal(s))
            {
                if (runs == max_runs)
                {
                    s = savedInitialState;
                    runs = 0;
                    statesList.Clear();
                }
                int index = possibilities.ReturnElementsTupleRandom(possibilities);
                misMoved = possibilities[index];
                canMoved = possibilities[index + 1];
                if (s.Transitions(s, misMoved, canMoved).Validation(s, misMoved, canMoved) == true && statesList.Contains(s) == false)
                {
                    State newS = s.Transitions(s, misMoved, canMoved);
                    Console.WriteLine("NewState: \n" + newS.ToString(newS) + "\n\n");
                    statesList.Add(newS);
                    s = newS;
                }
                runs++;
            }

            Console.WriteLine("Result: \n" + s.ToString(s));
        }
    }

    class State
    {
        private int numOfMis1;
        private int numOfMis2;
        private int numOfCan1;
        private int numOfCan2;
        private int barca;
        private int mal;

        public State(int barca, int numMis1, int numCan1, int mal, int numMis2, int numCan2)
        {
            this.barca = barca;
            this.numOfMis1 = numMis1;
            this.numOfMis2 = numMis2;
            this.numOfCan1 = numCan1;
            this.numOfCan2 = numCan2;
            this.mal = mal;
        }

        public State(int barca, int numOfMis1, int numOfCan1)
        {
            this.barca = barca;
            this.numOfMis1 = numOfMis1;
            this.numOfCan1 = numOfCan1;
            this.mal = 1;
            this.numOfMis2 = 0;
            this.numOfCan2 = 0;
        }

        public State()
        {
        }

        public bool isFinal(State s)
        {
            if (s.numOfMis1 == 0 && s.numOfCan1 == 0 && s.mal == 2)
                return true;
            return false;
        }

        public State Transitions(State s, int misMoved, int canMoved)
        {
            State newState = new State();
            if (s.mal == 1)
            {
                newState = new State(s.barca, s.numOfMis1 - misMoved, s.numOfCan1 - canMoved, 2, s.numOfMis2 + misMoved, s.numOfCan2 + canMoved);
            }
            else if (s.mal == 2)
                newState = new State(s.barca, s.numOfMis1 + misMoved, s.numOfCan1 + canMoved, 1, s.numOfMis2 - misMoved, s.numOfCan2 - canMoved);
            return newState;
        }

        public bool Validation(State s, int misMoved, int canMoved)
        {
            
            State newState = Transitions(s, misMoved, canMoved);
            //Console.WriteLine("\n\n\nValid: \n\n" + newState.ToString(newState));
            if (newState.numOfMis1 < 0 || newState.numOfCan1 < 0 || newState.numOfMis2 < 0 || newState.numOfCan2 < 0)
            {
                //Console.WriteLine("First If");
                return false;
            }
            if (newState.numOfMis1 > 0 && newState.numOfMis1 < newState.numOfCan1)
            {
                //Console.WriteLine("Second If");
                return false;
            }
            if (newState.numOfMis2 > 0 && newState.numOfMis2 < newState.numOfCan2)
            {
                //Console.WriteLine("Third If");
                return false;
            }
            if (misMoved + canMoved > newState.barca)
                return false;
            
            return true;
        }

        public string ToString(State s)
        {
            return "Barca: " + s.barca.ToString() + ";\n" + "Misionari mal 1: " + s.numOfMis1.ToString() + ";\n" + "Canibali mal 1: " + s.numOfCan1.ToString() + ";\n" + "Mal: " + s.mal.ToString() + ";\n" + "Misionari mal 2: " + s.numOfMis2.ToString() + ";\n" + "Canibali mal 2: " + s.numOfCan2.ToString();
        }
    }

    class Generate : List<int>
    {
        private List<int> possibilities;

        public Generate()
        {
            this.possibilities = new List<int>();
        }

        public void Initialization (int barca, int misionari, int canibali, List<int> possibilities)
        {
            for (int i = 0; i <= misionari + 1; i++)
            {
                for (int j = 0; j <= canibali + 1; j++)
                {
                    if (i + j <= barca && (i + j) != 0)
                    {
                        possibilities.Add(i);
                        possibilities.Add(j);
                    }
                }
            }
        }

        public int ReturnElementsTupleRandom (List<int> possibilities)
        {
            Random r = new Random();

            return r.Next(0, (possibilities.Count-1)/2)*2;
        }

        public List<int> GetAll(List<int> possibilities)
        {
            var result = new List<int>();
            foreach (int value in possibilities)
                result.Add(possibilities[value]);
            return result;
        }

        public string GetElementsAsString(List<int> possibilities)
        {
            string result = "";
            for(int element = 0; element < this.possibilities.Count; element++)
            {
                if (element % 2 == 0)
                    result = result + "(" + this.possibilities[element].ToString() + ", ";
                else 
                    result = result + this.possibilities[element].ToString() + "); \n";
            }
            return result;
        }
    }
}
