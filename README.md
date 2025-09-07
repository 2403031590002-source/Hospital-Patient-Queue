# Hospital Patient Queue

This project is a simple Hospital Patient Queue Management System implemented in C++. It allows hospital staff to manage emergency and regular patients efficiently using a priority queue for emergencies and a normal queue for regular cases.

## Features

- **Add Patient:** Enter patient name and specify if it is an emergency case.
- **Serve Next Patient:** Serve the next patient, prioritizing emergencies.
- **Display Queue:** View all waiting patients with estimated wait times.
- **Exit:** Quit the application.

## Project Structure

```
hospital-patient-queue
├── Untitled-1          # Source code (main.cpp)
└── README.md           # Documentation for the project
```

## How to Build

Compile the source code using g++:
```
g++ Untitled-1 -o hospital-patient-queue.exe
```

## How to Run

Run the executable:
```
hospital-patient-queue.exe
```

## Sample Output

```
Hospital Patient Queue
1. Add patient
2. Serve next patient
3. Display queue
4. Exit
Choose: 1
Enter patient name: Priya
Is this an emergency case? (y/n): n
Patient added.

Choose: 1
Enter patient name: Rahul
Is this an emergency case? (y/n): y
Patient added.

Choose: 3

Emergency Patients:
1. Rahul (Estimated wait: 0 min)

Regular Patients:
2. Priya (Estimated wait: 10 min)

Choose: 2
Serving emergency patient: Rahul

Choose: 2
Serving regular patient: Priya

Choose: 4
```

## License

This project is open-source and available
