# Municipal Financial Management System (MFMS)

**Group Members**
1. 226002306 - Elizabeth K Nauyoma
2. 226111733 - Ewan Lombaard
3. 225000725 - Brooklyn September
4. 226082075 - Max M.T. Kasinga
5. 226017060 - Mandlenkosi Sibanda
6. 226101177 - Monika Stefanus
7. 225163993 - Elifas Nantinda (Did not complete assigned task and left the group on the submission due date after approximately 95% of the project had been completed.)

## Project Description

The Municipal Financial Management System (MFMS) is a menu-driven C application developed as the foundation version of a municipal financial management system. The system provides a central application for managing employee information, departmental budgets, suppliers, and municipal assets, while also generating basic reports on those management areas.

The system was developed using ANSI C (C99) and demonstrates programming concepts such as variables, arrays, strings, functions, decision-making, loops, input validation, and modular program organization.

## System Features

- **Main Menu:** Provides central navigation to all system modules and the exit option.
- **Employee Management:** Allows users to add, display, search and manage employee information, including salary calculations.
- **Budget Management:** Allows users to add departmental budgets and expenditure, calculate remaining budget, and identify departments that exceed their allocated budget.
- **Supplier Management:** Allows users to add, display and search supplier information, as well as perform supplier-related string operations.
- **Asset Management:** Provides an asset register for adding, displaying and searching municipal assets.
- **Reports:** Generates basic reports for employee, budget, supplier and asset information.
- **Input Validation:** Handles invalid menu choices and validates relevant user input.

## Compilation Instructions

Open a terminal in the project directory and compile the program using GCC:
```bash
gcc main.c menu.c employees.c budget.c suppliers.c assets.c reports.c -o mfmsProjectA.exe
```

## How to Run the System

After compiling the program, run the executable file from the terminal using:
```powershelL
.\mfmsProjectA.exe
```

The main menu will be displayed, allowing the user to access Employee Management, Budget Management, Supplier Management, Asset Management and Reports modules, as well as the exit option.

## Individual Responsibilities

1. **Brooklyn Septermber** - Employee Management and testing.
2. **Max M.T Kasinga** - Budget Management and testing.
3. **Ewan Lombaard** - Supplier Management and testing.
4. **Monika Stefanus** - Asset Management and testing.
5. **Mandlenkosi Sibanda** - Reports and testing.
6. **Elizabeth K Nauyoma** - Functions, integration, validation, testing, documentation and GitHub coordination.











