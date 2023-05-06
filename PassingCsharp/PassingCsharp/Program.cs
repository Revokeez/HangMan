using System;
using System.IO;

class Program
{

    static void Main(string[] args)
    {
        string[] logs = new string[100];
        int position = 0;
        string words = "hola/pedro/juan";
        string pathWords = @"C:\Users\revok\OneDrive - Inter American University of Puerto Rico - Bayamon Campus\Documents\SQL\Proyect_Testing\HangManV2\HangManV2\words.txt"; //Proyect: Hangman / text document: words.txt

        try 
        {
            //To write in the file
           File.WriteAllText(pathWords, words);//path what do you want to wright in the file
           Console.WriteLine("Succesfuly send");
        }
        catch(Exception ex)
        {
            Console.WriteLine("Path not found");
        }

        string IsActive = "NA";//This menas Not Active
        string getServerStatus = @"C:\Users\revok\OneDrive - Inter American University of Puerto Rico - Bayamon Campus\Documents\SQL\Proyect_Testing\HangManV2\HangManV2\IsServerActive.txt";//Hangman/ IsServerActive path
        string check;

        string port = @"C:\Users\revok\OneDrive - Inter American University of Puerto Rico - Bayamon Campus\Documents\SQL\Proyect_Testing\HangManV2\HangManV2\SignalPort.txt";//Hangman/ SignalPort path
        string portStatus;

        string databasePasswordsPath= @"C:\Users\revok\OneDrive - Inter American University of Puerto Rico - Bayamon Campus\Documents\C++\DataBase\DataBase\Users_Passwords.txt";//DataBase/ Users_Passwords path
        string dataCollectionPasswords;

        string databaseUsernamePath = @"C:\Users\revok\OneDrive - Inter American University of Puerto Rico - Bayamon Campus\Documents\C++\DataBase\DataBase\Users_Usernames.txt";//DataBase/ Users_Usernames path
        string dataCollectionUsername;

        string usernamePath = @"C:\Users\revok\OneDrive - Inter American University of Puerto Rico - Bayamon Campus\Documents\SQL\Proyect_Testing\HangManV2\HangManV2\Usernames.txt";//Hangman/ Usernames path
        string usernameData;

        string passwordsPath = @"C:\Users\revok\OneDrive - Inter American University of Puerto Rico - Bayamon Campus\Documents\SQL\Proyect_Testing\HangManV2\HangManV2\passwords.txt";//Hangman/ passwords path
        string passwordsData;
        File.WriteAllText(getServerStatus, IsActive);
        File.WriteAllText(port, IsActive);

        TimeSpan currentTime = DateTime.Now.TimeOfDay;//To get current time
        while (!Console.KeyAvailable)// Do this until a key is pressed
        {
           
            check = File.ReadAllText(getServerStatus);
            portStatus = File.ReadAllText(port);

            if (check == "ActiveServer")
            {
                Console.WriteLine("Server Active");
            }
            else
            {
                Console.WriteLine("Server Inactive");
            }
            ////////////////////////////////////
            if(portStatus == "SendInformation")
            {
                Console.WriteLine("Client information send");
                Console.WriteLine($"Time: {currentTime}");
                logs[position] = $"Time: {currentTime}";

                passwordsData = File.ReadAllText(passwordsPath);
                File.WriteAllText(databasePasswordsPath, passwordsData);

                usernameData = File.ReadAllText(usernamePath);
                File.WriteAllText(databaseUsernamePath, usernameData);
                Thread.Sleep(4000);
                File.WriteAllText(port, IsActive);

                position += 1;

            }
            
            Thread.Sleep(3000);
            Console.Clear();
            Console.WriteLine("Press any key to stop the program");
        }
         for(int i = 0; i < position; i++) 
         {
           Console.WriteLine(logs[i]);
         }

    }
}