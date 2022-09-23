# UMT Programming Bookstore

This is a simple C console assignment for a programming bookstore POS system.

The program lets the user view book categories, enter book codes and quantities,
calculate payment, print receipt output, and check the daily sales report.

## Main Functions

- View software, web, and mobile programming books
- Take sales orders from book codes and quantities
- Calculate subtotal, discount, and final payment
- Print receipt-style output
- Show a daily sales report
- Validate wrong menu choices and sales input

## Build And Run

Open `Assignment.sln` in Visual Studio and build the project.

After building, run the generated `Assignment.exe` from the debug output folder.
If the console border text does not display correctly, change the command prompt
code page first:

```cmd
chcp 936
```

There is also a `run.cmd` helper script that can start the built program after
the executable exists.

## Project Files

- `Assignment/UMT Programming Bookstore.c` - main source code
- `Assignment.sln` - Visual Studio solution
- `run.cmd` - helper script for running the built program
