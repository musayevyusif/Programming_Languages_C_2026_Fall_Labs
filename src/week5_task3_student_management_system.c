<<<<<<< HEAD
// week5_task3_student_management_system.c
// Name: ________  Surname: ________  Student ID: ________
//
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement the functions to load, save, add, and list students.
//
// Build: make lab5   Run: ./bin/week5_task3_student_management_system

=======
>>>>>>> 5a92af5 (Complete Lab 5)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
<<<<<<< HEAD
#define NAME_LEN 50
#define LINE_LEN 256
#define DATA_FILE "students.txt"

typedef struct Student {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes (do not change these signatures – the autograder calls them directly)
int  load_students(Student arr[], int max);          // returns number of records loaded
int  save_students(const Student arr[], int count);  // 0 on success, -1 on error
void add_student(Student arr[], int *count);
void list_students(const Student arr[], int count);
int  read_line(const char *prompt, char *buf, size_t size);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    char input[LINE_LEN];
    int running = 1;

    // TODO: Load existing data: count = load_students(students, MAX_STUDENTS);
    printf("Loaded %d student(s) from %s\n", count, DATA_FILE);
    (void)students;  // remove this line once you use the array

    while (running) {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");

        int choice;
        if (read_line("Select an option: ", input, sizeof input) != 0) {
            choice = 3;                         // end of input: save and exit instead of looping forever
        } else {
            char *end;
            long value = strtol(input, &end, 10);
            choice = (end != input && *end == '\0') ? (int)value : 0;   // non-numbers become invalid
        }

        switch (choice) {
            case 1:
                // TODO: Call list_students()
                break;
            case 2:
                // TODO: Call add_student()
                break;
            case 3:
                // TODO: Call save_students(). If it fails, print an error message.
                printf("Data saved. Goodbye!\n");
                running = 0;
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return EXIT_SUCCESS;
}

// Provided helper – prints a prompt and reads one line from stdin into buf.
// The trailing newline is removed. Returns 0 on success, -1 on end of input (EOF).
int read_line(const char *prompt, char *buf, size_t size) {
    printf("%s", prompt);
    fflush(stdout);
    if (fgets(buf, (int)size, stdin) == NULL) {
        return -1;
    }
    size_t len = strcspn(buf, "\r\n");
    if (buf[len] == '\0' && len == size - 1) {
        // Line was longer than the buffer: discard the rest of it.
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    buf[len] = '\0';
    return 0;
}

// TODO: Implement load_students()
// Open DATA_FILE for reading. If it cannot be opened (e.g. first run), return 0.
// Read the file line by line with fgets(); parse "name,id,gpa" with
// sscanf(line, "%49[^,],%d,%f", ...) and keep only lines where sscanf returned 3.
// Stop when max records have been loaded. Close the file and return the number loaded.
int load_students(Student arr[], int max) {
    (void)arr; (void)max;  // remove this line when you implement the function
    return 0;
}

// TODO: Implement save_students()
// Open DATA_FILE for writing ("w"), return -1 if fopen() fails.
// Write one line per student: fprintf(fp, "%s,%d,%.2f\n", ...). Close the file and return 0.
int save_students(const Student arr[], int count) {
    (void)arr; (void)count;  // remove this line when you implement the function
    return -1;
}

// TODO: Implement add_student()
// 1. If *count >= MAX_STUDENTS, print "Cannot add more students (limit reached)." and return.
// 2. Use read_line() to ask "Enter name: ", "Enter ID: " and "Enter GPA: ".
//    If read_line() returns -1 (end of input), just return.
// 3. Validate: name not empty, no ',' in name, ID is an integer, GPA is a number in 0.0–4.0
//    (strtol / strtof are useful). Otherwise print "Invalid input. Student not added." and return.
// 4. Store the student at arr[*count], increase *count, print "Student added successfully!"
void add_student(Student arr[], int *count) {
    (void)arr; (void)count;  // remove this line when you implement the function
}

// TODO: Implement list_students()
// If count is 0 print "No students found."; otherwise print a header and one line per student,
// e.g. printf("%-5d %-20s %.2f\n", id, name, gpa);
void list_students(const Student arr[], int count) {
    (void)arr; (void)count;  // remove this line when you implement the function
}
=======

typedef struct {
  char name[50];
  int id;
  float gpa;
} Student;

void read_line(char* buffer, int size) {
  if (fgets(buffer, size, stdin) != NULL) {
    buffer[strcspn(buffer, "\n")] = '\0';
  }
}

int load_students(Student arr[], int max) {
  FILE* fp = fopen("students.txt", "r");

  if (fp == NULL) {
    return 0;
  }

  char line[200];
  int count = 0;

  while (fgets(line, sizeof(line), fp) != NULL && count < max) {
    Student s;

    if (sscanf(line, "%49[^,],%d,%f", s.name, &s.id, &s.gpa) == 3) {
      arr[count] = s;
      count++;
    }
  }

  fclose(fp);

  return count;
}

int save_students(const Student arr[], int count) {
  FILE* fp = fopen("students.txt", "w");

  if (fp == NULL) {
    perror("Error opening students.txt");
    return -1;
  }

  for (int i = 0; i < count; i++) {
    fprintf(fp, "%s,%d,%.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
  }

  fclose(fp);

  return 0;
}

void add_student(Student arr[], int* count) {
  if (*count >= MAX_STUDENTS) {
    printf("Cannot add more students (limit reached).\n");
    return;
  }

  char name[50];
  char id_text[50];
  char gpa_text[50];

  printf("Enter name: ");
  read_line(name, sizeof(name));

  printf("Enter ID: ");
  read_line(id_text, sizeof(id_text));

  printf("Enter GPA: ");
  read_line(gpa_text, sizeof(gpa_text));

  if (strlen(name) == 0 || strchr(name, ',') != NULL) {
    printf("Invalid input. Student not added.\n");
    return;
  }

  char* end;

  long id = strtol(id_text, &end, 10);

  if (*id_text == '\0' || *end != '\0') {
    printf("Invalid input. Student not added.\n");
    return;
  }

  float gpa = strtof(gpa_text, &end);

  if (*gpa_text == '\0' || *end != '\0' || gpa < 0.0f || gpa > 4.0f) {
    printf("Invalid input. Student not added.\n");
    return;
  }

  strcpy(arr[*count].name, name);
  arr[*count].id = (int)id;
  arr[*count].gpa = gpa;

  (*count)++;

  printf("Student added successfully!\n");
}

void list_students(const Student arr[], int count) {
  if (count == 0) {
    printf("No students found.\n");
    return;
  }

  printf("ID    Name                 GPA\n");

  for (int i = 0; i < count; i++) {
    printf("%-5d %-20s %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
  }
}

int main(void) {
  Student students[MAX_STUDENTS];

  int count = load_students(students, MAX_STUDENTS);

  printf("Loaded %d student(s) from students.txt\n", count);

  char input[20];

  while (1) {
    printf("\n=== Student Management System ===\n");
    printf("1. List students\n");
    printf("2. Add student\n");
    printf("3. Save and Exit\n");
    printf("Select an option: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
      save_students(students, count);
      printf("Data saved. Goodbye!\n");
      break;
    }

    int option = atoi(input);

    if (option == 1) {
      list_students(students, count);
    } else if (option == 2) {
      add_student(students, &count);
    } else if (option == 3) {
      save_students(students, count);
      printf("Data saved. Goodbye!\n");
      break;
    } else {
      printf("Invalid option.\n");
    }
  }

  return 0;
}
>>>>>>> 5a92af5 (Complete Lab 5)
