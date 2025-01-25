-- Creating the Employee table
CREATE TABLE Employee (
    employee_id NUMBER PRIMARY KEY,
    name VARCHAR2(100) NOT NULL,
    salary NUMBER,
    designation VARCHAR2(100) NOT NULL,
    branch_id NUMBER NOT NULL,
    contact VARCHAR2(15) NOT NULL,
    CONSTRAINT fk_employee_branch FOREIGN KEY (branch_id) REFERENCES Branch(branch_id)
);

-- Creating the Branch table
CREATE TABLE Branch (
    branch_id NUMBER PRIMARY KEY,
    branch_name VARCHAR2(100) NOT NULL,
    location VARCHAR2(100)
);

-- Creating the Course table
CREATE TABLE Course (
    course_id NUMBER PRIMARY KEY,
    course_name VARCHAR2(100) NOT NULL,
    branch_id NUMBER NOT NULL,
    CONSTRAINT fk_course_branch FOREIGN KEY (branch_id) REFERENCES Branch(branch_id)
);

-- Creating the Subject table
CREATE TABLE Subject (
    subject_id NUMBER PRIMARY KEY,
    subject_name VARCHAR2(100) NOT NULL,
    course_id NUMBER NOT NULL,
    CONSTRAINT fk_subject_course FOREIGN KEY (course_id) REFERENCES Course(course_id),
   
);

-- Creating the Student table
CREATE TABLE Student (
    student_id NUMBER PRIMARY KEY,
    name VARCHAR2(100) NOT NULL,
    dob DATE NOT NULL,
    address VARCHAR2(255),
    contact VARCHAR2(15) NOT NULL
);

-- Creating the Facilitates relationship table
CREATE TABLE Facilitates (
    employee_id NUMBER NOT NULL,
    subject_id NUMBER NOT NULL,
    PRIMARY KEY (employee_id, subject_id),
    CONSTRAINT fk_facilitates_employee FOREIGN KEY (employee_id) REFERENCES Employee(employee_id),
    CONSTRAINT fk_facilitates_subject FOREIGN KEY (subject_id) REFERENCES Subject(subject_id)
);

-- Creating the Registers relationship table
CREATE TABLE Registers (
    registration_id NUMBER PRIMARY KEY,
    student_id NUMBER NOT NULL,
    course_id NUMBER NOT NULL,
    CONSTRAINT fk_registers_student FOREIGN KEY (student_id) REFERENCES Student(student_id),
    CONSTRAINT fk_registers_course FOREIGN KEY (course_id) REFERENCES Course(course_id)
);
