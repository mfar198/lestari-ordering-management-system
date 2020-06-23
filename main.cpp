//This define will remove warning about time, if you want to do research remove the define and look into the error online
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
#include <sys/stat.h>
#include <iterator>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

// Global Variable
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

//sessionid will hold the username of the user logged in during the session
string sessionid = "";

// Global Variable End
class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");

        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "lestaridb", 3306, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            //getch();
            system("cls");

        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};


void ManagerLogin();
void EmployeeLogin();
void Prompt();
void EndPrompt();
void Exit();

//Functions for Manager
void MenuManager();
void RegManager();
void ViewManager();
void UpdateManager();
void DeleteManager();
void RegEmployee();
void ViewEmployee();
void UpdateEmployee();
void DeleteEmployee();
void AddMenu();
void ViewMenu();
void SearchMenu();
void UpdateMenu();
void DeleteMenu();
void Summary();

//Functions for Employee
void MenuEmployee();
void CreateOrder();
void ViewOrder();
void UpdateOrder();
void DeleteOrder();
void ViewMenuEmp();
void ViewProfile();
void UpdateProfile();





int main()
{
    // Initial Load
    system("cls");
    system("title LESTARI ORDERING MANAGEMENT SYSTEM");
    //Color 0f can be change into any color you want, hook up in the internet
    system("color 0f");
    // Initial Load End

    // Call Methods
    db_response::ConnectionFunction();
    // Call Methods End

    Prompt();


}
void Prompt()
{
    system("cls");
    // Variables
    int choose;
    // Variables End
    system("COLOR 0A");

    cout << "\n                   |*************************************************************************|";
    cout << "\n                   |                                                                         |";
    cout << "\n                   |              .:WELCOME TO LESTARI ORDERING MANAGEMENT SYSTEM:.          |";
    cout << "\n                   |             ===================================================         |";
    cout << "\n                   |                                                                         |";
    cout << "\n                   |                      PLEASE CHOOSE YOUR ACCOUNT TYPE:                   |";
    cout << "\n                   |                                                                         |";
    cout << "\n                   |                    (1. MANAGER | 2. EMPLOYEE | 3. EXIT)                 |";
    cout << "\n                   |                                                                         |";
    cout << "\n                   |*************************************************************************|";
    cout << "\n                                                  CHOOSE :";
    cin >> choose;

    system("cls");


    if (choose == 1)
    {
        ManagerLogin();
    }
    else if (choose == 2)
    {
        EmployeeLogin();
    }
    else if (choose == 3)
    {
        Exit();
    }
    else
    {
        cout << " UNKNOWN ANSWER. ENTER AGAIN !!! \n";
        Prompt();
    }

}

void ManagerLogin()
{
    // Variables
    string managerid, managerpass = "";
    //string cont;
    char c;
    // Variables End

    cout << "\n                   |******************************************************************|";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |           WELCOME TO LESTARI ORDERING MANAGEMENT SYSTEW          |";
    cout << "\n                   |        ==================================================        |";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |                PLEASE LOGIN TO ENTER THE SYSTEM                  |";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |******************************************************************|";
    cout << "\n                                                                  ";
    cout << "\n                               MANAGER ID :  "; cin >> managerid;
    cout << "                                 PASSWORD : ";

p:
    c = _getch();  //getch will read all the char input by user
    cout << "*";   //for printing * instead for password
    if (c != 13)
    {
        managerpass = managerpass + c;  //for concatenating the string
        goto p;
    }

    qstate = mysql_query(conn, "select Manager_Id, Manager_Pass, Manager_Name from manager_db");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {

            if (managerid == row[0] && managerpass == row[1])
            {
                system("cls");
                cout << "\n |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| ";
                cout << "\n |                                   ACCESS GRANTED!                                    |";
                cout << "\n |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n\n";
                system("PAUSE");
                system("cls");
                sessionid = row[2];  //Pass value of the current user logged in to variable sessionid
                cout << "Welcome " << sessionid;
                MenuManager();

            }
        }

        char ka;
        system("cls");
        cout << "\n |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| ";
        cout << "\n |           ACCESS DENIED!!! USERNAME AND PASSWORD NOT FOUND IN DATABASE!!!            |";
        cout << "\n |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| ";
        cout << "\n                        PRESS m TO GO BACK OR r TO LOGIN AGAIN. \n";
        cin >> ka;
        switch (ka)
        {
        case 'm':
        case 'M':
            system("cls");
            Prompt();
            break;
        case 'r':
        case 'R':
            system("cls");
            ManagerLogin();
            break;
        default:
            system("cls");
            cout << " ENTER AGAIN !!!!\n";
            MenuManager();
        }
    }
    else
    {
        cout << "\n\n Query Execution Problem!" << mysql_errno(conn) << endl;
    }

}
void EmployeeLogin()
{
    // Variables
    string empid, emppass = "";
    string cont;
    char c;
    // Variables End



    cout << "\n                   |******************************************************************|";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |           WELCOME TO LESTARI ORDERING MANAGEMENT SYSTEW          |";
    cout << "\n                   |        ==================================================        |";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |                PLEASE LOGIN TO ENTER THE SYSTEM                  |";
    cout << "\n                   |                                                                  |";
    cout << "\n                   |******************************************************************|";
    cout << "\n                                                                  ";
    cout << "\n                                 EMPLOYEE ID :  "; cin >> empid;
    cout << "                                   PASSWORD : ";

p:
    c = _getch(); //getch will read all the char input by user
    cout << "*";   //for printing * instead for password
    if (c != 13)
    {
        emppass = emppass + c;  //for concatenating the string
        goto p;
    }


    qstate = mysql_query(conn, "select Emp_Id, Emp_Pass, Emp_Name from employee_db");

    if (!qstate)
    {

        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            if (empid == row[0] && emppass == row[1])
            {
                system("cls");
                cout << "\n |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| ";
                cout << "\n |                                   ACCESS GRANTED!                                    |";
                cout << "\n |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n\n";
                cout << "\n";
                system("PAUSE");
                system("cls");
                sessionid = row[2];  //Pass value of the current user logged in to variable sessionid
                cout << "Welcome " << sessionid;
                MenuEmployee();
            }

        }
        char ka;
        system("cls");
        cout << "\n |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| ";
        cout << "\n |           ACCESS DENIED!!! USERNAME AND PASSWORD NOT FOUND IN DATABASE!!!            |";
        cout << "\n |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| ";
        cout << "\n                        PRESS m TO GO BACK OR r TO LOGIN AGAIN. \n";
        cin >> ka;
        switch (ka)
        {
        case 'm':
        case 'M':
            system("cls");
            Prompt();
            break;
        case 'r':
        case 'R':
            system("cls");
            EmployeeLogin();
            break;
        default:
            system("cls");
            cout << " ENTER AGAIN !!!!\n";
            MenuManager();
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

}
void EndPrompt()
{
    system("cls");
    cout << "\n|+++++++++++++++++++++++++++++++++++++++++++++++++|";
    cout << "\n|                    THANK YOU                    |";
    cout << "\n|                SEE YOU AGAIN...                 |";
    cout << "\n|+++++++++++++++++++++++++++++++++++++++++++++++++|";
    exit(3);
}

void Exit()
{
    system("cls");
    cout << "\n|+++++++++++++++++++++++++++++++++++++++++++++++++|";
    cout << "\n|                    THANK YOU                    |";
    cout << "\n|+++++++++++++++++++++++++++++++++++++++++++++++++|";
    exit(3);
}

void Logout()
{
    system("cls");
    cout << "\n|+++++++++++++++++++++++++++++++++++++++++++++++++|";
    cout << "\n|            YOU'VE BEEN LOGGED OUT.              |";
    cout << "\n|+++++++++++++++++++++++++++++++++++++++++++++++++|";
    Prompt();
}


//Employee Section
void MenuEmployee() {
    {
        system("cls");
        cout << "\n ____________________________________________________";
        cout << "\n|                                                    |";
        cout << "\n|           LESTARI ORDERING MANAGEMENT SYSTEM       |";
        cout << "\n|          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
        cout << "\n ____________________________________________________";
        cout << "\n           .: Welcome " << sessionid << " :.";
        int choose;
        cout << "\n";
        cout << "\n |**************************************************|";
        cout << "\n |                ---------------                   |";
        cout << "\n |                 EMPLOYEE MENU                    |";
        cout << "\n |                ---------------                   |";
        cout << "\n |                                                  |";
        cout << "\n | 1. CREATE ORDER.                                 |";
        cout << "\n | 2. VIEW ORDERS                                   |";
        cout << "\n | 3. DELETE ORDER                                  |";
        cout << "\n |                                                  |";
        cout << "\n | 4. VIEW MENU.                                    |";
        cout << "\n |                                                  |";
        cout << "\n | 5. VIEW PROFILE.                                 |";
        cout << "\n |                                                  |";
        cout << "\n | 6. LOGOUT.                                       |";
        cout << "\n | 7. EXIT.                                         |";
        cout << "\n |**************************************************|\n";
        cout << " \n\n PLEASE CHOOSE : ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            CreateOrder();
            break;
        case 2:
            ViewOrder();
            break;
            /*case 3:
                UpdateOrder();
                break;*/
        case 3:
            DeleteOrder();
            break;
        case 4:
            ViewMenuEmp();
            break;
        case 5:
            ViewProfile();
            break;
            /*case 6:
                UpdateProfile();
                break;*/
        case 6:
            Logout();
            break;
        case 7:
            exit(0);
            break;
        default:
            system("cls");
            cout << " ENTER AGAIN !!!!\n";
            MenuManager();
        }
    }
}

void CreateOrder()
{
    system("cls");
    char choose;
    string getId = "";
    string itemId[50];
    string itemName[50];
    char chooseEditOrBuy;
    int itemIndex = 0;
    float totalPrice = 0.0;
    bool purchase{}, itemFalse = false;

    string storeid[50];
    string storetitle[50];
    string storecat[50];
    string storeprice[50];
    int storeIndex = 0, storeIndexN = 0;

    //declaring month and year
    time_t now = time(0);

    tm* ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;


    string nasi = "nasi";
    string air = "air";
    string mee = "mee";
    string special = "special";

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                     CREATE ORDER                    " << endl;

    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-50s | %-15s | %-15s |\n", "ID", "Item", "Category", "Price (RM)");

    //Nasi--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query = "select * from menu_db where menu_cat like '" + nasi + "%' ORDER BY menu_name";
    const char* qi = findbyid_query.c_str();
    qstate = mysql_query(conn, qi);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {

            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
            storeid[storeIndex] = row[0];
            storetitle[storeIndex] = row[1];
            storecat[storeIndex] = row[2];
            storeprice[storeIndex] = row[3];
            storeIndex++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Mee--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query1 = "select * from menu_db where menu_cat like '" + mee + "%' ORDER BY menu_name";
    const char* qi1 = findbyid_query1.c_str();
    qstate = mysql_query(conn, qi1);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {

            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
            storeid[storeIndex] = row[0];
            storetitle[storeIndex] = row[1];
            storecat[storeIndex] = row[2];
            storeprice[storeIndex] = row[3];
            storeIndex++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Air---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query2 = "select * from menu_db where menu_cat like '" + air + "%' ORDER BY menu_name";
    const char* qi2 = findbyid_query2.c_str();
    qstate = mysql_query(conn, qi2);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {

            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
            storeid[storeIndex] = row[0];
            storetitle[storeIndex] = row[1];
            storecat[storeIndex] = row[2];
            storeprice[storeIndex] = row[3];
            storeIndex++;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Special---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query3 = "select * from menu_db where menu_cat like '" + special + "%' ORDER BY menu_name";
    const char* qi3 = findbyid_query3.c_str();
    qstate = mysql_query(conn, qi3);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {

            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
            storeid[storeIndex] = row[0];
            storetitle[storeIndex] = row[1];
            storecat[storeIndex] = row[2];
            storeprice[storeIndex] = row[3];
            storeIndex++;

        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");

    for (itemIndex = 0;; itemIndex++)
    {
        cout << "Enter an Menu ID's (q to done choose): ";
        cin >> getId;
        if (getId == "q")
        {
            break;
        }
        else
        {
            for (int i = 0; i < storeIndex; i++)
            {
                if (getId == storeid[i])
                {
                    itemId[itemIndex] = getId;
                    itemFalse = false;
                    break;
                }
                else
                {
                    itemFalse = true;
                }
            }
            if (itemFalse == true)
            {
                cout << "Enter a valid number." << endl;
                itemIndex--;
                itemFalse = false;
            }
        }
    }

    cout << "\nYou choose this menu id's: ";
    for (int i = 0; i < itemIndex; i++)
    {
        cout << itemId[i] << " ";
    }

CHOOSEEDITORBUY:
    cout << endl << "\nDo you want to edit items(e) or buy this items(b): ";
    cin >> chooseEditOrBuy;

    if (chooseEditOrBuy == 'e')
    {
        for (int i = 0;; i++)
        {
            cout << "Remove item id's (q to exit): ";
            cin >> getId;
            if (getId == "q")
            {
                break;
            }
            else
            {
                for (int j = 0; j < itemIndex; j++)
                {
                    if (itemId[j] == getId)
                    {
                        for (int k = j; k < itemIndex; k++)
                        {
                            itemId[k] = itemId[k + 1];
                        }
                        itemId[itemIndex--] = "\0";
                    }
                }
            }
        }

        cout << "You choose this song id's: ";
        for (int i = 0; i < itemIndex; i++)
        {
            cout << itemId[i] << " ";
        }

        goto CHOOSEEDITORBUY;
    }
    else if (chooseEditOrBuy == 'b')
    {
        for (int i = 0; i < itemIndex; i++)
        {
            for (int j = 0; j < storeIndex; j++)
            {
                if (itemId[i] == storeid[j])
                {
                    totalPrice += stold((storeprice[j]).c_str(), 0);
                    string currmonth = to_string(month);
                    string curryear = to_string(year);

                    string insert_query = "insert into orders_db (order_name, order_month, order_year, order_price) values ('" + storetitle[j] + "','" + currmonth + "','" + curryear + "','" + storeprice[j] + "')";

                    purchase = true;

                    //cout << insert_query << endl;


                    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

                    qstate = mysql_query(conn, q);

                    if (!qstate)
                    {
                        purchase = true;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }



                }
            }
        }

        if (purchase == true)
        {
            cout << endl << "Purchase Successfully Done." << endl;
            cout << endl << "Total Price: " << totalPrice << endl;
        }
    }

    // Exit Code
    cout << endl << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuEmployee();
    }
    else
    {
        exit(0);
    }
}
void ViewOrder()
{
    //Clear screen
    system("cls");

    //Variables
    char choose;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                       VIEW ORDERS                  ";
    cout << "\n\n";

    qstate = mysql_query(conn, "select * from orders_db ORDER BY order_year DESC, order_month DESC");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        int c;
        string a;
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-30s | %-15s | %-10s | %-10s |\n", "ID", "Name", "Month", "Year", "Price (RM)");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-30s | %-15s | %-10s | %-10s |\n", row[0], row[1], row[2], row[3], row[4]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    // Exit Code
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuEmployee();
    }
    else
    {
        exit(0);
    }

}
/*void UpdateOrder()
{
    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
}*/
void DeleteOrder()
{
    //Clear screen
    system("cls");

    //Variables
    char choose;
    string itemId;
    string items[500];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;


    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                       DELETE ORDER                 ";
    cout << "\n\n";

    qstate = mysql_query(conn, "select * from orders_db ORDER BY order_year DESC, order_month DESC");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        int c;
        string a;
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-30s | %-15s | %-10s | %-10s |\n", "ID", "Name", "Month", "Year", "Price (RM)");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-30s | %-15s | %-10s | %-10s |\n", row[0], row[1], row[2], row[3], row[4]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    try
    {
        cout << endl;
        cout << "Enter Order ID (xN to cancel) : ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }
    if (itemId == "xN")
    {
        MenuEmployee();
    }

    if (HaveException == false)
    {
        string storeid = "";
        string respon = "";
        string findbyid_query = "select * from orders_db where order_id = '" + itemId + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "ID: " << row[0]
                    << "\nName: " << row[1]
                    << "\nMonth: " << row[2]
                    << "\nYear: " << row[3]
                    << "\nPrice: RM" << row[4]
                    << endl << endl;

                storeid = row[0];

            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
        if (storeid == "")
        {
            cout << "Invalid ID!" << endl;
            system("pause");
            DeleteMenu();
        }
    p:
        cout << "Do you want to delete this selected order? (Y/N)";
        cin >> respon;
        if (respon == "Y" | respon == "y")
        {
            string delete_query = "delete from orders_db where order_id = '" + storeid + "'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted From Database." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }
        }
        else if (respon == "N" | respon == "n")
        {
            DeleteOrder();
        }
        else
        {
            cout << "Unknown respond!" << endl;
            system("pause");
            goto p;
        }

        //```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

    }

    // Exit Code
ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuEmployee();
    }
    else if (choose == 'd' || choose == 'D')
    {
        DeleteOrder();
    }
    else
    {
        exit(0);
    }
}
void ViewMenuEmp()
{
    //Clear screen
    system("cls");

    //Variables
    char choose;
    string nasi = "nasi";
    string air = "air";
    string mee = "mee";
    string special = "special";

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                        MENU LIST                     " << endl << endl;

    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("| %-50s | %-15s | %-15s |\n", "Item", "Category", "Price (RM)");

    //Nasi--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query = "select * from menu_db where menu_cat like '" + nasi + "%' ORDER BY menu_name";
    const char* qi = findbyid_query.c_str();
    qstate = mysql_query(conn, qi);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-50s | %-15s | %-15s |\n", row[1], row[2], row[3]);
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Mee--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query1 = "select * from menu_db where menu_cat like '" + mee + "%' ORDER BY menu_name";
    const char* qi1 = findbyid_query1.c_str();
    qstate = mysql_query(conn, qi1);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-50s | %-15s | %-15s |\n", row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Air---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query2 = "select * from menu_db where menu_cat like '" + air + "%' ORDER BY menu_name";
    const char* qi2 = findbyid_query2.c_str();
    qstate = mysql_query(conn, qi2);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-50s | %-15s | %-15s |\n", row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Special---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query3 = "select * from menu_db where menu_cat like '" + special + "%' ORDER BY menu_name";
    const char* qi3 = findbyid_query3.c_str();
    qstate = mysql_query(conn, qi3);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-50s | %-15s | %-15s |\n", row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");

    // Exit Code
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuEmployee();
    }
    else
    {
        exit(0);
    }
}
void ViewProfile()
{
    //Clear screen
    system("cls");

    //Variables
    char choose;
    string pass;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                       MY PROFILE                     " << endl << endl;

    string findbyid_query = "select * from employee_db where Emp_Id like '" + sessionid + "%'";
    const char* qi = findbyid_query.c_str();
    qstate = mysql_query(conn, qi);
    if (!qstate)
    {
        res = mysql_store_result(conn);
        int c;
        string a;


        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-30s |\n", "ID", "Password", "Name");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            //Variable str will hold the value of password from database row[1]
            string str = row[1];
            // you can also use str.length() to count words of the password    
            c = str.length();
            string stars;
            for (int i = 0; i < c; i++)
                stars += '*';
            a = stars;

            printf("| %-30s | %-30s | %-30s |\n", row[0], a, row[2]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuEmployee();
    }
    else
    {
        exit(0);
    }
}
/*void UpdateProfile()
{
    system("cls");
    // Variables
    string id = "";
    string pass = "";
    string name = "";
    string items[500];
    char choose;
    string itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    // Store Variables
    string storeid = "";
    string storename = "";
    string storepass = "";
    char c;
    // Variables End
    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                     UPDATE PROFILE                   \n\n";

    string findbyid_query = "select * from employee_db where Emp_Id like '" + sessionid + "%'";
    const char* qi = findbyid_query.c_str();
    qstate = mysql_query(conn, qi);
    if (!qstate)
    {
        string a;
        int c;

        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-30s |\n", "ID", "Password", "Name");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {

            //Variable str will hold the value of password from database row[1]
            string str = row[1];
            // you can also use str.length() to count words of the password
            c = str.length();
            string stars;
            for (int i = 0; i < c; i++)
                stars += '*';
            a = stars;

            printf("| %-30s | %-30s | %-30s |\n", row[0], row[1], row[2]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    sessionid = itemId;



    if (HaveException == false)
    {


        string findbyid_query = "select * from employee_db where Emp_Id like '" + sessionid + "%'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {


                storeid = row[0];
                storepass = row[1];
                storename = row[2];

            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }

        cin.ignore(1, '\n');
        string defaultString = "xN";
        cout << "Enter ID (" << defaultString << "  to not change): ";
        getline(cin, id);
        if (id == defaultString)
        {
            id = storeid;
        }
        cout << endl;
        cout << "Enter Password (" << defaultString << "  to not change): ";
    p:
        c = _getch();
        cout << "*";   //for printing * instead for password
        if (c != 13)
        {
            pass = pass + c;  //for concatenating the string
            goto p;
        }
        if (pass == defaultString)
        {
            pass = storepass;
        }
        cout << endl;
        cout << endl;
        cout << "Enter Name (" << defaultString << "  to not change): ";
        getline(cin, name);
        if (name == defaultString)
        {
            name = storename;
        }

        string update_query = "update employee_db set Emp_Id = '" + id + "', Emp_Pass = '" + pass + "', Emp_Name = '" + name + "' where Emp_Id = '" + sessionid + "'";
        const char* qu = update_query.c_str();
        qstate = mysql_query(conn, qu);
        sessionid = "";
        sessionid = id;

        if (!qstate)
        {
            cout << endl << "Successfully Updated." << endl;

        }
        else
        {
            cout << "Failed To Update!" << mysql_errno(conn) << endl;
        }


    }

ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuEmployee();
    }
    else if (choose == 'e' || choose == 'E')
    {
        UpdateProfile();
    }
    else
    {
        exit(0);
    }
}*/



//Manager Section
void MenuManager()
{
    system("cls");
    cout << "\n ____________________________________________________";
    cout << "\n|                                                    |";
    cout << "\n|           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n|          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n|____________________________________________________|";
    cout << "\n           .: Welcome " << sessionid << " :.";
    int choose;
    cout << "\n";
    cout << "\n |**************************************************|";
    cout << "\n |                --------------                    |";
    cout << "\n |                 MANAGER MENU                     |";
    cout << "\n |                --------------                    |";
    cout << "\n |                                                  |";
    cout << "\n | 1. REGISTER NEW MANAGER ACCOUNT.                 |";
    cout << "\n | 2. VIEW ALL MANAGERS.                            |";
    cout << "\n | 3. UPDATE MANAGERS.                              |";
    cout << "\n | 4. DELETE MANAGERS                               |";
    cout << "\n |                                                  |";
    cout << "\n | 5. REGISTER NEW EMPLOYEE ACCOUNT.                |";
    cout << "\n | 6. VIEW ALL EMPLOYEES                            |";
    cout << "\n | 7. UPDATE EMPLOYEES.                             |";
    cout << "\n | 8. DELETE EMPLOYEES                              |";
    cout << "\n |                                                  |";
    cout << "\n | 9. ADD NEW MENU                                  |";
    cout << "\n | 10. VIEW ALL MENU.                               |";
    cout << "\n | 11. SEARCH MENU.                                 |";
    cout << "\n | 12. UPDATE MENU                                  |";
    cout << "\n | 13. DELETE MENU                                  |";
    cout << "\n |                                                  |";
    cout << "\n | 14. SUMMARY.                                     |";
    cout << "\n |                                                  |";
    cout << "\n | 15. LOGOUT.                                      |";
    cout << "\n | 16. EXIT.                                        |";
    cout << "\n |                                                  |";
    cout << "\n |**************************************************|\n";

    cout << " \n\n PLEASE CHOOSE : ";
    cin >> choose;

    switch (choose)
    {
    case 1:
        RegManager();
        break;
    case 2:
        ViewManager();
        break;
    case 3:
        UpdateManager();
        break;
    case 4:
        DeleteManager();
        break;
    case 5:
        RegEmployee();
        break;
    case 6:
        ViewEmployee();
        break;
    case 7:
        UpdateEmployee();
        break;
    case 8:
        DeleteEmployee();
        break;
    case 9:
        AddMenu();
        break;
    case 10:
        ViewMenu();
        break;
    case 11:
        SearchMenu();
        break;
    case 12:
        UpdateMenu();
        break;
    case 13:
        DeleteMenu();
        break;
    case 14:
        Summary();
        break;
    case 15:
        Logout();
        break;
    case 16:
        exit(0);
        break;
    default:
        system("cls");
        cout << " ENTER AGAIN !!!!\n";
        MenuManager();
    }
}

void RegManager()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string id = "";
    string name = "";
    string pass = "";
    char choose;
    char c;
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                    ADD NEW MANAGER                 " << endl << endl;

    cin.ignore(1, '\n');
    cout << " Enter Manager ID: ";
    getline(cin, id);
    cout << "\n Enter Manager Pass: ";
p:
    c = _getch();
    cout << "*";   //for printing * instead for password
    if (c != 13)
    {
        pass = pass + c;  //for concatenating the string
        goto p;
    }
    cout << "\n\n Enter Manager Name: ";
    getline(cin, name);


    string insert_query = "insert into manager_db (Manager_Id, Manager_Pass, Manager_Name) values ('" + id + "','" + pass + "','" + name + "')";

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'a' || choose == 'A')
    {
        RegManager();
    }
    else
    {
        exit(0);
    }
}
void ViewManager()
{
    //Clear screen
    system("cls");

    //Variables
    char choose;
    string pass;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                       MANAGER LIST                   " << endl << endl;

    qstate = mysql_query(conn, "select * from manager_db ORDER BY Manager_Id");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        int c;
        string a;

        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-30s |\n", "ID", "Password", "Name");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            //Variable str will hold the value of password from database row[1]
            string str = row[1];;
            // you can also use str.length() to count words of the password    
            c = str.length();
            string stars;
            for (int i = 0; i < c; i++)
                stars += '*';
            a = stars;

            printf("| %-30s | %-30s | %-30s |\n", row[0], a, row[2]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else
    {
        exit(0);
    }
}
void UpdateManager()
{
    system("cls");
    // Variables
    string id = "";
    string pass = "";
    string name = "";
    string items[500];
    char choose;
    string itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    // Store Variables
    string storeid = "";
    string storename = "";
    string storepass = "";
    char c;
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                       UPDATE MANAGER                   \n\n";

    qstate = mysql_query(conn, "select * from manager_db");
    if (!qstate)
    {
        string a;
        int c;

        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-30s |\n", "ID", "Password", "Name");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {

            //Variable str will hold the value of password from database row[1]
            string str = row[1];
            // you can also use str.length() to count words of the password    
            c = str.length();
            string stars;
            for (int i = 0; i < c; i++)
                stars += '*';
            a = stars;

            printf("| %-30s | %-30s | %-30s |\n", row[0], a, row[2]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;

        cout << "Enter Manager ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false) {


        string findbyid_query = "select * from manager_db where Manager_Id = '" + itemId + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "ID: " << row[0]
                    << "\nPassword: " << row[1]
                    << "\nName: " << row[2]
                    << endl << endl;

                storeid = row[0];
                storepass = row[1];
                storename = row[2];

            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }

        cin.ignore(1, '\n');
        string defaultString = "xN";
        cout << "Enter ID (" << defaultString << "  to not change): ";
        getline(cin, id);
        if (id == defaultString)
        {
            id = storeid;
        }
        cout << endl;
        cout << "Enter Password (" << defaultString << "  to not change): ";
    p:
        c = _getch();
        cout << "*";   //for printing * instead for password
        if (c != 13)
        {
            pass = pass + c;  //for concatenating the string
            goto p;
        }
        if (pass == defaultString)
        {
            pass = storepass;
        }
        cout << endl;
        cout << endl;
        cout << "Enter Name (" << defaultString << "  to not change): ";
        getline(cin, name);
        if (name == defaultString)
        {
            name = storename;
        }

        string update_query = "update manager_db set Manager_Id = '" + id + "', Manager_Pass = '" + pass + "', Manager_Name = '" + name + "' where Manager_Id = '" + itemId + "'";
        const char* qu = update_query.c_str();
        qstate = mysql_query(conn, qu);

        if (!qstate)
        {
            cout << endl << "Successfully Updated." << endl;
        }
        else
        {
            cout << "Failed To Update!" << mysql_errno(conn) << endl;
        }


    }

ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'e' || choose == 'E')
    {
        UpdateManager();
    }
    else
    {
        exit(0);
    }
}
void DeleteManager()
{
    system("cls");

    // Variables
    char choose;
    int confirm;
    string itemId;
    string items[500];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;
    string storeid, storepass, storename;
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                 DELETE MANAGER ACCOUNT             " << endl << endl;

    qstate = mysql_query(conn, "select * from manager_db");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s |\n", "ID", "Name");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-30s | %-30s |\n", row[0], row[2]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID (xN to cancel) : ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }
    if (itemId == "xN")
    {
        MenuManager();
    }

    if (HaveException == false)
    {
        string findbyid_query = "select * from manager_db where Manager_Id = '" + itemId + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "ID: " << row[0]

                    << "\nName: " << row[2]
                    << endl << endl;

                storeid = row[0];
                storename = row[2];

            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
        if (storeid == "")
        {
            cout << "Invalid ID!" << endl;
            system("pause");
            DeleteManager();
        }

    p:
        cout << "Do you want to delete the selected account? (1 = Confirm | 2 = Cancel | 3 = Exit)" << endl;
        cin >> confirm;
        if (confirm == 1)
        {
            string delete_query = "delete from manager_db where Manager_Id = '" + itemId + "'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "\n Successfully Deleted From Database." << endl;
            }
            else
            {
                cout << "\n Failed To Delete!" << mysql_errno(conn) << endl;
            }
        }
        else if (confirm == 2)
        {
            DeleteManager();
        }
        else if (confirm == 3)
        {
            Exit();
        }
        else
        {
            cout << " UNKNOWN ANSWER. ENTER AGAIN !!! \n";
            goto p;
        }
    }

    // Exit Code
ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'd' || choose == 'D')
    {
        DeleteManager();
    }
    else
    {
        exit(0);
    }
}
void RegEmployee()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string id = "";
    string name = "";
    string pass = "";
    char choose;
    char c;
    int confirm;
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                 REGISTER EMPLOYEE ACCOUNT           " << endl << endl;

p:
    cout << "Press 1 to continue or 2 cancel" << endl;
    cin >> confirm;
    if (confirm == 1)
    {

    }
    else if (confirm == 2)
    {
        MenuManager();
    }
    else
    {
        cout << "\n Invalid input!";
        system("pause");
        goto p;
    }

    cin.ignore(1, '\n\n');
    cout << "Enter Employee ID: ";
    getline(cin, id);
    cout << "\nEnter Employee Pass: ";
r:
    c = _getch();
    cout << "*";   //for printing * instead for password
    if (c != 13)
    {
        pass = pass + c;  //for concatenating the string
        goto r;
    }
    cout << "\n\nEnter Employee Name: ";
    getline(cin, name);


    string insert_query = "insert into employee_db (Emp_Id, Emp_Pass, Emp_Name) values ('" + id + "','" + pass + "','" + name + "')";

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'a' || choose == 'A')
    {
        RegEmployee();
    }
    else
    {
        exit(0);
    }
}
void ViewEmployee()
{
    //Clear screen
    system("cls");

    //Variables
    char choose;
    string pass;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                       EMPLOYEE LIST                   " << endl << endl;

    qstate = mysql_query(conn, "select * from employee_db ORDER BY Emp_Id");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        int c;
        string a;


        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-30s |\n", "ID", "Password", "Name");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            //Variable str will hold the value of password from database row[1]
            string str = row[1];
            // you can also use str.length() to count words of the password    
            c = str.length();
            string stars;
            for (int i = 0; i < c; i++)
                stars += '*';
            a = stars;

            printf("| %-30s | %-30s | %-30s |\n", row[0], a, row[2]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else
    {
        exit(0);
    }
}
void UpdateEmployee()
{
    system("cls");
    // Variables
    string id = "";
    string pass = "";
    string name = "";
    string items[500];
    char choose;
    string itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    // Store Variables
    string storeid = "";
    string storename = "";
    string storepass = "";
    char c;
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                    UPDATE EMPLOYEE                 \n\n";

    qstate = mysql_query(conn, "select * from employee_db");
    if (!qstate)
    {
        int c;
        string a;
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-30s |\n", "ID", "Password", "Name");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            //Variable str will hold the value of password from database row[1]
            string str = row[1];
            // you can also use str.length() to count words of the password    
            c = str.length();
            string stars;
            for (int i = 0; i < c; i++)
                stars += '*';
            a = stars;

            printf("| %-30s | %-30s | %-30s |\n", row[0], a, row[2]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;

        cout << "Enter Employee ID (xN to cancel) : ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID." << endl;
        HaveException = true;
        goto ExitMenu;
    }
    if (itemId == "xNN")
    {
        MenuManager();
    }

    if (HaveException == false)
    {


        string findbyid_query = "select * from employee_db where Emp_Id = '" + itemId + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "ID: " << row[0]
                    << "\nPassword: " << row[1]
                    << "\nName: " << row[2]
                    << endl << endl;

                storeid = row[0];
                storepass = row[1];
                storename = row[2];

            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
        if (storeid == "")
        {
            cout << "Invalid ID!" << endl;
            system("pause");
            UpdateEmployee();
        }

        cin.ignore(1, '\n');
        string defaultString = "xN";
        cout << "Enter ID (" << defaultString << "  to not change): ";
        getline(cin, id);
        if (id == defaultString)
        {
            id = storeid;
        }
        cout << "Enter Password (" << defaultString << "  to not change): ";
    p:
        c = _getch();
        cout << "*";   //for printing * instead for password
        if (c != 13)
        {
            pass = pass + c;  //for concatenating the string
            goto p;
        }
        if (pass == defaultString)
        {
            pass = storepass;
        }
        cout << "\nEnter Name (" << defaultString << "  to not change): ";
        getline(cin, name);
        if (name == defaultString)
        {
            name = storename;
        }

        string update_query = "update employee_db set Emp_Id = '" + id + "', Emp_Pass = '" + pass + "', Emp_Name = '" + name + "' where Emp_Id = '" + itemId + "'";
        const char* qu = update_query.c_str();
        qstate = mysql_query(conn, qu);

        if (!qstate)
        {
            cout << endl << "Successfully Updated." << endl;
        }
        else
        {
            cout << "Failed To Update!" << mysql_errno(conn) << endl;
        }


    }

ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'e' || choose == 'E')
    {
        UpdateEmployee();
    }
    else
    {
        exit(0);
    }
}
void DeleteEmployee()
{
    system("cls");

    // Variables
    char choose;
    int confirm;
    string itemId;
    string items[500];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;
    string storeid, storepass, storename;
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                 DELETE EMPLOYEE ACCOUNT             " << endl << endl;

    qstate = mysql_query(conn, "select * from employee_db");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s |\n", "ID", "Name");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-30s | %-30s |\n", row[0], row[2]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Employee ID (xN to cancel) : ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID." << endl;
        HaveException = true;
        goto ExitMenu;
    }
    if (itemId == "xN")
    {
        MenuManager();
    }

    if (HaveException == false)
    {
        string findbyid_query = "select * from employee_db where Emp_Id = '" + itemId + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "ID: " << row[0]

                    << "\nName: " << row[2]
                    << endl << endl;

                storeid = row[0];
                storename = row[2];

            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
        if (storeid == "")
        {
            cout << "Invalid ID!" << endl;
            system("pause");
            DeleteMenu();
        }

    p:
        cout << "Do you want to delete the selected account? (1 = Confirm | 2 = Cancel | 3 = Exit)" << endl;
        cin >> confirm;
        if (confirm == 1)
        {
            string delete_query = "delete from employee_db where Emp_Id like '" + itemId + "%'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted From Database." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }
        }
        else if (confirm == 2)
        {
            DeleteEmployee();
        }
        else if (confirm == 3)
        {
            Exit();
        }
        else
        {
            cout << " UNKNOWN ANSWER. ENTER AGAIN !!! \n";
            goto p;
        }
    }

    // Exit Code
ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'd' || choose == 'D')
    {
        DeleteEmployee();
    }
    else
    {
        exit(0);
    }
}
void AddMenu()
{
    // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string category = "";
    string name = "";
    float price = 0.0;
    char choose;
    string pilihcat = "";
    int pilih;
    int confirm;
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                    ADD NEW MENU ITEM                 " << endl << endl;
    cout << "Press 1 to continue or 2 cancel" << endl;
p:
    cin >> confirm;
    if (confirm == 1)
    {

    }
    else if (confirm == 2)
    {
        MenuManager();
    }
    else
    {
        cout << "Invalid input! Input choice again: ";
        goto p;
    }
    cin.ignore(1, '\n');
    cout << "\nEnter Menu Name: ";
    getline(cin, name);
    cout << "\nEnter Menu Category (1. Nasi | 2. Mee | 3. Air | 4. Special) : ";
r:
    cin >> pilih;
    if (pilih == 1)
    {
        pilihcat = "Nasi";
    }
    else if (pilih == 2)
    {
        pilihcat = "Mee";
    }
    else if (pilih == 3)
    {
        pilihcat = "Air";
    }
    else if (pilih == 4)
    {
        pilihcat = "Special";
    }
    else
    {
        cout << " UNKNOWN ANSWER. ENTER AGAIN !!! \n";
        goto r;
    }
    cout << "\nEnter Price: ";
    cin >> price;
    category = pilihcat;

    stringstream streamPrice;
    string sprice;
    streamPrice << price;
    streamPrice >> sprice;


    string insert_query = "insert into menu_db (menu_name, menu_cat, menu_price) values ('" + name + "','" + category + "','" + sprice + "')";

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'a' || choose == 'A')
    {
        AddMenu();
    }
    else
    {
        exit(0);
    }
}
void ViewMenu()//done
{
    //Clear screen
    system("cls");

    //Variables
    char choose;
    string nasi = "nasi";
    string air = "air";
    string mee = "mee";
    string special = "special";

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                     ALL MENU LIST                   " << endl << endl;

    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("| %-50s | %-15s | %-15s |\n", "Item", "Category", "Price (RM)");

    //Nasi--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query = "select * from menu_db where menu_cat like '" + nasi + "%' ORDER BY menu_name";
    const char* qi = findbyid_query.c_str();
    qstate = mysql_query(conn, qi);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-50s | %-15s | %-15s |\n", row[1], row[2], row[3]);
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Mee--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query1 = "select * from menu_db where menu_cat like '" + mee + "%' ORDER BY menu_name";
    const char* qi1 = findbyid_query1.c_str();
    qstate = mysql_query(conn, qi1);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-50s | %-15s | %-15s |\n", row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Air---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query2 = "select * from menu_db where menu_cat like '" + air + "%' ORDER BY menu_name";
    const char* qi2 = findbyid_query2.c_str();
    qstate = mysql_query(conn, qi2);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-50s | %-15s | %-15s |\n", row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Special---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query3 = "select * from menu_db where menu_cat like '" + special + "%' ORDER BY menu_name";
    const char* qi3 = findbyid_query3.c_str();
    qstate = mysql_query(conn, qi3);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-50s | %-15s | %-15s |\n", row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");

    // Exit Code
    cout << "Press 'm' to Menu and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else
    {
        exit(0);
    }
}
void SearchMenu()
{
    system("cls");

    // Variables
    char choose;
    string input;
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                        SEARCH MENU                     " << endl << endl;

    cout << "Find by \n1. Name\n2. Category\n3. Price\nAny other number to Menu" << endl;
    cout << "Choose One: "; cin >> choose;
    system("cls");

    cin.ignore(1, '\n');
    if (choose == '1')
    {
        cout << "Enter Name: "; getline(cin, input);
        string findbyname_query = "select * from menu_db where menu_name like '" + input + "%'";
        const char* qn = findbyname_query.c_str();
        qstate = mysql_query(conn, qn);
    }
    else if (choose == '2')
    {
        cout << "Enter Category: "; getline(cin, input);
        string findbycategory_query = "select * from menu_db where menu_cat like '" + input + "%'";
        const char* qc = findbycategory_query.c_str();
        qstate = mysql_query(conn, qc);
    }
    else if (choose == '3')
    {
        cout << "Enter Price: "; getline(cin, input);
        string findbytype_query = "select * from menu_db where menu_price like '" + input + "%'";
        const char* qt = findbytype_query.c_str();
        qstate = mysql_query(conn, qt);
    }
    else
    {
        goto ExitMenu;
    }

    cout << endl;
    if (choose == '1' || choose == '2' || choose == '3')
    {
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                cout << "ID: " << row[0] << "\nName: " << row[1] << "\nCategory: " << row[2] << "\nPrice: RM" << row[3] << endl << endl;
            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }

ExitMenu:
    cout << "Press 'm' to Menu, 'a' to Search again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'a' || choose == 'A')
    {
        SearchMenu();
    }
    else
    {
        exit(0);
    }
}
void UpdateMenu()
{
    system("cls");

    // Variables
    string category = "";
    string name = "";
    string price = "";
    int id;
    string items[500];
    char choose;
    string itemId = "";
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;


    // Store Variables
    string storeid = "";
    string storecategory = "";
    string storename = "";
    string storeprice = "";
    string pilihcat = "";
    int pilih;
    string nasi = "nasi";
    string air = "air";
    string mee = "mee";
    string special = "special";
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                     UPDATE MENU ITEM                    " << endl << endl;

    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-50s | %-15s | %-15s |\n", "ID", "Item", "Category", "Price (RM)");

    //Nasi--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query = "select * from menu_db where menu_cat like '" + nasi + "%' ORDER BY menu_name";
    const char* qi = findbyid_query.c_str();
    qstate = mysql_query(conn, qi);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Mee--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query1 = "select * from menu_db where menu_cat like '" + mee + "%' ORDER BY menu_name";
    const char* qi1 = findbyid_query1.c_str();
    qstate = mysql_query(conn, qi1);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Air---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query2 = "select * from menu_db where menu_cat like '" + air + "%' ORDER BY menu_name";
    const char* qi2 = findbyid_query2.c_str();
    qstate = mysql_query(conn, qi2);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Special---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query3 = "select * from menu_db where menu_cat like '" + special + "%' ORDER BY menu_name";
    const char* qi3 = findbyid_query3.c_str();
    qstate = mysql_query(conn, qi3);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");

    try
    {
        cout << endl;
        cout << "Enter Menu ID (xN to cancel) : ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid ID." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (itemId == "xN")
    {
        MenuManager();
    }
    if (HaveException == false)
    {


        string findbyid_query = "select * from menu_db where menu_id = '" + itemId + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "ID: " << row[0]
                    << "\nName: " << row[1]
                    << "\nCategory: " << row[2]
                    << "\nPrice: " << row[3]
                    << endl << endl;

                storeid = row[0];
                storename = row[1];
                storecategory = row[2];
                storeprice = row[3];


            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }

        if (storeid == "")
        {
            cout << "Invalid ID!" << endl;
            system("pause");
            UpdateMenu();
        }


        cout << "Enter Category (1 = Nasi | 2 = Mee | 3 = Air | 4 = Special | 5 = to not change) : ";
    p:
        cin >> pilih;
        if (pilih == 1)
        {
            pilihcat = "Nasi";
        }
        else if (pilih == 2)
        {
            pilihcat = "Mee";
        }
        else if (pilih == 3)
        {
            pilihcat = "Air";
        }
        else if (pilih == 4)
        {
            pilihcat = "Special";
        }
        else if (pilih == 5)
        {
            pilihcat = storecategory;
        }
        else
        {
            cout << " UNKNOWN ANSWER. ENTER AGAIN !!! \n";
            goto p;
        }

        cin.ignore(1, '\n');
        string defaultString = "xN";
        cout << "Enter New Menu Name (" << defaultString << "  to not change): ";
        getline(cin, name);
        if (name == defaultString)
        {
            name = storename;
        }

        cout << "Enter Price (" << defaultString << "  to not change): ";
        getline(cin, price);
        if (price == defaultString)
        {
            price = storeprice;
        }

        string update_query = "update menu_db set menu_name = '" + name + "', menu_cat = '" + pilihcat + "', menu_price = '" + price + "' where menu_id = '" + storeid + "'";
        const char* qu = update_query.c_str();
        qstate = mysql_query(conn, qu);

        if (!qstate)
        {
            cout << endl << "Successfully Updated." << endl;
        }
        else
        {
            cout << "Failed To Update!" << mysql_errno(conn) << endl;
        }


    }



ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'e' || choose == 'E')
    {
        UpdateMenu();
    }
    else
    {
        exit(0);
    }
}
void DeleteMenu()
{
    system("cls");

    // Variables
    char choose;
    string itemId;
    string items[500];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;
    string nasi = "nasi";
    string air = "air";
    string mee = "mee";
    string special = "special";
    // Variables End

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                     DELETE MENU ITEM                " << endl << endl;

    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-50s | %-15s | %-15s |\n", "ID", "Item", "Category", "Price (RM)");

    //Nasi--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query = "select * from menu_db where menu_cat like '" + nasi + "%' ORDER BY menu_name";
    const char* qi = findbyid_query.c_str();
    qstate = mysql_query(conn, qi);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Mee--------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query1 = "select * from menu_db where menu_cat like '" + mee + "%' ORDER BY menu_name";
    const char* qi1 = findbyid_query1.c_str();
    qstate = mysql_query(conn, qi1);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Air---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query2 = "select * from menu_db where menu_cat like '" + air + "%' ORDER BY menu_name";
    const char* qi2 = findbyid_query2.c_str();
    qstate = mysql_query(conn, qi2);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    //Special---------------------------------------------------------------------------------------------------------------------------------
    string findbyid_query3 = "select * from menu_db where menu_cat like '" + special + "%' ORDER BY menu_name";
    const char* qi3 = findbyid_query3.c_str();
    qstate = mysql_query(conn, qi3);
    if (!qstate)
    {
        res = mysql_store_result(conn);

        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-50s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3]);
        }

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");

    try
    {
        cout << endl;
        cout << "Enter Item ID (xN to cancel) : ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }
    if (itemId == "xN")
    {
        MenuManager();
    }

    if (HaveException == false)
    {
        string storeid = "";
        string respon = "";
        string findbyid_query = "select * from menu_db where menu_id = '" + itemId + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "ID: " << row[0]
                    << "\nName: " << row[1]
                    << "\nCategory: " << row[2]
                    << "\nPrice: " << row[3]
                    << endl << endl;

                storeid = row[0];

            }
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
        if (storeid == "")
        {
            cout << "Invalid ID!" << endl;
            system("pause");
            DeleteMenu();
        }
    p:
        cout << "Do you want to delete this selected menu? (Y/N)";
        cin >> respon;
        if (respon == "Y" | respon == "y")
        {
            string delete_query = "delete from menu_db where menu_id = '" + storeid + "'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted From Database." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }
        }
        else if (respon == "N" | respon == "n")
        {
            DeleteMenu();
        }
        else
        {
            cout << "Unknown respond!" << endl;
            system("pause");
            goto p;
        }

        //```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

    }

    // Exit Code
ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'd' || choose == 'D')
    {
        DeleteMenu();
    }
    else
    {
        exit(0);
    }
}
void Summary()
{
    //Clear screen
    system("cls");

    //Variables
    char choose;
    string input;

    cout << "\n                                 ____________________________________________________";
    cout << "\n                                |                                                    |";
    cout << "\n                                |           LESTARI ORDERING MANAGEMENT SYSTEM       |";
    cout << "\n                                |          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      |";
    cout << "\n                                |____________________________________________________|";
    cout << "\n                                                        SUMMARY                       ";
    cout << "\n\n";

    cout << "Find by \n1. Name\n2. Year\n3. Month\nAny other number to Menu" << endl;
    cout << "Choose One: "; cin >> choose;
    system("cls");

    cin.ignore(1, '\n');
    if (choose == '1')
    {
        string findbyname_query = "select count(order_id), order_name, order_month, order_year, sum(order_price) from orders_db group by order_name";
        const char* qn = findbyname_query.c_str();
        qstate = mysql_query(conn, qn);
        if (!qstate)
        {
            cout << endl;
            res = mysql_store_result(conn);
            printf("------------------------------------------------------------------------------------------------------------- \n");
            printf("| %-15s | %-30s | %-15s |\n", "Total Orders", "Name", "Price");
            printf("------------------------------------------------------------------------------------------------------------- \n");
            while ((row = mysql_fetch_row(res)))
            {
                printf("| %-15s | %-30s | %-15s |\n", row[0], row[1], row[4]);
            }
            cout << endl;
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == '2')
    {
        string findbyyear_query = "select count(order_id), order_name, order_month, order_year, sum(order_price) from orders_db group by order_year";
        const char* qc = findbyyear_query.c_str();
        qstate = mysql_query(conn, qc);
        if (!qstate)
        {
            cout << endl;
            res = mysql_store_result(conn);
            printf("------------------------------------------------------------------------------------------------------------- \n");
            printf("| %-15s | %-15s | %-15s |\n", "Total Orders", "Year", "Price");
            printf("------------------------------------------------------------------------------------------------------------- \n");
            while ((row = mysql_fetch_row(res)))
            {
                printf("| %-15s | %-15s | %-15s |\n", row[0], row[3], row[4]);
            }
            cout << endl;
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else if (choose == '3')
    {
        string findbymonth_query = "select count(order_id), order_name, order_month, order_year, sum(order_price) from orders_db group by order_month";
        const char* qt = findbymonth_query.c_str();
        qstate = mysql_query(conn, qt);
        if (!qstate)
        {
            cout << endl;
            res = mysql_store_result(conn);
            printf("------------------------------------------------------------------------------------------------------------- \n");
            printf("| %-15s | %-15s | %-10s |\n", "Total Orders", "Month", "Price");
            printf("------------------------------------------------------------------------------------------------------------- \n");
            while ((row = mysql_fetch_row(res)))
            {
                printf("| %-15s | %-15s | %-10s |\n", row[0], row[2], row[4]);
            }
            cout << endl;
        }
        else
        {
            cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
    }
    else
    {
        goto ExitMenu;
    }

    cout << endl;

ExitMenu:
    cout << "Press 'm' to Menu, 'a' to view summary again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        MenuManager();
    }
    else if (choose == 'a' || choose == 'A')
    {
        Summary();
    }
    else
    {
        exit(0);
    }
}