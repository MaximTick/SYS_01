using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SYS_Sharp
{
    class Program
    {
         [DllImport("MYDDLA.dll", EntryPoint = "AddNumbers")]
         public static extern int AddNumbers(int x, int y);


        [DllImport("MyDDLA.dll", EntryPoint = "CurrentTime")]
        public static extern void  CurrentTime();
        [DllImport("user32.dll")]
        public static extern int MessageBox(int hWnd, String pText,
            String pCaption, int utype);

        [STAThread]
        static void Main(string[] args)
        {
            String pText = "Hello, programmer";
            String pCaption = "See dll in action";
            MessageBox(0, pText, pCaption, 0);
            Console.WriteLine("Sum of 2 and 3 is {0}", AddNumbers(2, 3));

            CurrentTime();
        }
        
    }
}
