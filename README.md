# Student Progress (C)

A command-line program in C that stores student marks and prints a progress report with total, average and grade.

## Features

- Add up to 10 students (name, admission number, marks)
- 3 exams for each student: FA, MID and FINAL
- 6 subjects for each exam: mat, tel, hin, eng, soc, sci
- Automatic total, average and grade for each exam
- Search a student by admission number and print the report
- Input check: letters in the menu do not stop the program

## Requirements

- A C compiler (for example, GCC)

## Build and run

```bash
gcc student_progress.c -o student_progress
./student_progress
```

On Windows:

```bash
gcc student_progress.c -o student_progress.exe
student_progress.exe
```

## Menu

```
1.Add a student
2.Print student Progress
3.Exit
choose a service:
```

## Grade scale

The grade uses the **average** marks of an exam.

| Average | Grade |
|---------|-------|
| 100 | 1 |
| Above 75 | 2 |
| Above 50 | 3 |
| 32 or more | 4 |
| Below 32 | 0 (fail) |

## Example output

```
progress report of Rudra:
admission number:101
mat		tel		hin		eng		soc		sci		total avg grade
080		075		070		085		090		078		478 079 002
...
```

## How it works

- Each student is a `struct` with a name, an admission number, and a `marks[3][9]` array.
- For each exam `k`:
  - `marks[k][0]` to `marks[k][5]`: the 6 subject marks
  - `marks[k][6]`: total
  - `marks[k][7]`: average (total / 6)
  - `marks[k][8]`: grade
- `caluclation()` finds the total and average. Then it calls `grade()`.

## Limits

- Maximum 10 students
- Data is not saved. It is lost when the program exits.
- Marks are not checked. Enter values from 0 to 100.

## Files

| File | Description |
|------|-------------|
| `student_progress.c` | Source code |
| `README.md` | This file |

## License

Free to use for learning.
