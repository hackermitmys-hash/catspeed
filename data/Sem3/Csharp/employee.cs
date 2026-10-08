using System;

class Employee
{
    private int _empId;
    private string _name;
    protected double _salary;

    public Employee()
    {
        _empId = 0;
        _name = "Unknown";
        _salary = 0.0;
    }

    public Employee(int empId, string name, double salary)
    {
        _empId = empId;
        _name = name;
        _salary = salary;
    }

    public int EmpId
    {
        get { return _empId; }
        set { _empId = value; }
    }

    public string Name
    {
        get { return _name; }
        set { _name = value; }
    }

    public double Salary
    {
        get { return _salary; }
        set { _salary = value; }
    }

    public void ShowDetails()
    {
        Console.WriteLine($"Employee ID: {_empId}");
        Console.WriteLine($"Name: {_name}");
        Console.WriteLine($"Salary: {_salary}");
    }
}

class Manager : Employee
{
    private double _travelAllowance;

    public Manager()
    {
        _travelAllowance = 0.0;
    }

    public Manager(int empId, string name, double salary, double travelAllowance)
        : base(empId, name, salary)
    {
        _travelAllowance = travelAllowance;
    }

    public void ShowSalary()
    {
        Console.WriteLine($"Salary: {_salary}");
    }

    public void ShowTotalSalary()
    {
        Console.WriteLine($"Total Salary: {_salary + _travelAllowance}");
    }
}

class Program
{
    static void Main()
    {
        Employee employee = new Employee(101, "Arjun", 50000.0);
        Console.WriteLine("Employee Details:");
        employee.ShowDetails();
        Console.WriteLine();

        Manager manager = new Manager(201, "Krishna", 70000.0, 20000.0);
        Console.WriteLine("Manager Details:");
        manager.ShowSalary();
        manager.ShowTotalSalary();
    }
}