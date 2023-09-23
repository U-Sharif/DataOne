using System;
using System.Collections.Generic;
using System.Text;
using DataOneLib;

namespace SampleClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Starting index > ");
            int start = int.Parse(Console.ReadLine());
            Client c = new Client("127.0.0.1", 8375);
            Console.WriteLine(c.Fetch(start));
            Console.WriteLine("Done.");
            Console.ReadLine();
        }
    }
}
