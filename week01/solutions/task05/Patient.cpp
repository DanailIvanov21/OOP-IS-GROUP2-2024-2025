#include "Patient.h"
#include <cstring>

void printPatientStatus(const Patient& patient)
{
    switch (patient.status) 
    {
    case PatientStatus::HEALTHY: std::cout << "HEALTHY"; break;
    case PatientStatus::UNDER_TREATMENT: std::cout << "UNDER TREATMENT"; break;
    case PatientStatus::RECOVERED: std::cout << "RECOVERED"; break;
    case PatientStatus::CRITICAL: std::cout << "CRITICAL"; break;
    }

    std::cout << std::endl;
}

void printPatient(const Patient& patient)
{
    std::cout << patient.name << " | " << patient.age << " | " << patient.diagnosis << " | ";
    printPatientStatus(patient);
}

void initPatient(Patient& patient)
{
    std::cout << "Enter name, age, diagnosis, and status (0-HEALTHY, 1-UNDER_TREATMENT, 2-RECOVERED, 3-CRITICAL): ";
    std::cin >> patient.name >> patient.age >> patient.diagnosis;
    int status;
    std::cin >> status;
    patient.status = PatientStatus(status);
}

void addPatients(Patient patients[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        initPatient(patients[i]);
    }
}

void printPatients(const Patient patients[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printPatient(patients[i]);
    }
}

void sortPatientsByAge(Patient patients[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (patients[i].age > patients[j].age) 
            {
                std::swap(patients[i], patients[j]);
            }
        }
    }
}

int countCriticalPatients(const Patient patients[], int size) 
{
    int count = 0;

    for (int i = 0; i < size; i++) 
    {
        if (patients[i].status == PatientStatus::CRITICAL) 
        {
            count++;
        }
    }

    return count;
}

void filterByStatus(const Patient patients[], int size, PatientStatus status) 
{
    for (int i = 0; i < size; i++) 
    {
        if (patients[i].status == status) 
        {
            printPatient(patients[i]);
        }
    }
}

Patient findYoungestUnderTreatment(const Patient patients[], int size) 
{
    Patient youngest = { "", 1000, "", PatientStatus::HEALTHY };

    for (int i = 0; i < size; i++) 
    {
        if (patients[i].status == PatientStatus::UNDER_TREATMENT && patients[i].age < youngest.age) 
        {
            youngest = patients[i];
        }
    }

    return youngest;
}
