#pragma once
#include <iostream>
constexpr unsigned MAX_LENGHT = 64;

enum class PatientStatus {
    HEALTHY,
    UNDER_TREATMENT,
    RECOVERED,
    CRITICAL
};

struct Patient {
    char name[MAX_LENGHT];
    int age;
    char diagnosis[MAX_LENGHT];
    PatientStatus status;
};

void printPatientStatus(const Patient& patient);
void printPatient(const Patient& patient);
void initPatient(Patient& patient);
void addPatients(Patient patients[], int size);
void printPatients(const Patient patients[], int size);
void sortPatientsByAge(Patient patients[], int size);
int countCriticalPatients(const Patient patients[], int size);
void filterByStatus(const Patient patients[], int size, PatientStatus status);
Patient findYoungestUnderTreatment(const Patient patients[], int size);
